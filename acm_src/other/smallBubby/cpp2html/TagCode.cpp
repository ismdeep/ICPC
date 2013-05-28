/*|
|*| CPP-to-HTML Finite State Machine
|*| 'fsm' namespace implementation
|*| by AngleWyrm, 2002
|*/
#include "TagCode.h"
#include <list>        // lists

namespace fsm {

////////////////////////////////////////////////////////////////////////////////
// Namespace variables
typedef enum { eNormal, eMacro, eBlockComment, 
               eLineComment,  eCharLiteral, eStringLiteral } state_t;

state_t currentState = eNormal;
state_t newState = eNormal;
string alphabet = "0123456789_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define NUM_KEYWORDS 74
string keywords[NUM_KEYWORDS] = {
    "and_eq", "and", "asm", "auto", "bitand",
    "bitor", "bool", "break", "case", "catch", 
    "char", "class", "compl", "const_cast", "const",
    "continue", "default", "delete", "do", "double", 
    "dynamic_cast",  "else", "enum", "explicit", "export",
    "extern", "false", "float", "for", "friend", 
    "goto", "if", "inline", "int", "long", 
    "mutable", "namespace", "new", "not_eq", "not", 
    "operator", "or_eq", "or", "private", "protected", 
    "public", "register", "reinterpret_cast", "return", "short", 
    "signed", "sizeof", "static", "static_cast", "struct", 
    "switch", "template", "this", "throw", "true", 
    "try", "typedef", "typeid", "typename", "union", 
    "unsigned", "using", "virtual", "void", "volatile", 
    "wchar_t", "while", "xor_eq", "xor"
};

string numeric = "01234567890";
string numberCodes = ".01234567890abcdefABCDEFxX";
string::size_type wordBegin, wordEnd;
string word;

////////////////////////////////////////////////////////////////////////////////
// TagCode
void TagCode( std::string & code )
{
    /*
     * Tag sections of code as comment, macro, literal
     */
    string output;
    int stepSize = 1;
    bool endSpan = false;
    for( int i = 0; i < code.length(); i += stepSize )
    {
        stepSize = 1; // reset
        
        /* add tags */
        switch( currentState )
        {
            case eNormal:
                /* Enter a block comment? */
                if( code[i] == '/' && code[i+1] == '*' ) 
                {
                    stepSize = 2;
                    output += "<span class=\"comment\">";
                    newState = eBlockComment;
                    break;
                }
                /* Enter a line comment? */
                if( code[i] == '/' && code[i+1] == '/' )
                {
                    stepSize = 2;
                    output += "<span class=\"comment\">";
                    newState = eLineComment;
                    break;
                }
                /* Enter a preprocessor macro? */
                if( code[i] == '#' )
                {
                    output += "<span class=\"macro\">";
                    newState = eMacro;
                    break;
                }
                
                /* Enter an Escape sequence? */
                if( code[i] == '\\' )
                {
                    stepSize = 2;
                    break;
                }
                
                /* Enter a char literal? */
                if( code[i] == '\'' )
                {
                    output += "<span class=\"literal\">";
                    newState = eCharLiteral;
                    break;
                }
                /* Enter a string literal? */
                if( code[i] == '\"' )
                {
                    stepSize = 1; 
                    output += "<span class=\"literal\">";
                    newState = eStringLiteral;
                    break;
                } 
                /* Possible Number? [must be done before keyword search]*/
                for( int j = 0; j < numeric.length(); j++ )
                {
                    if( code[i] == numeric[j] )
                    { // it's a number
                        wordEnd = code.find_first_not_of( numberCodes, i );
                        output += "<span class=\"numeric\">";
                        stepSize = wordEnd - i;
                        endSpan = true;
                        break;
                    }
                }
                /* Possible keyword? */
                wordBegin = code.find_first_of( alphabet, i );
                if ( wordBegin == i ) 
                { // alpha
                    wordEnd = code.find_first_not_of( alphabet, i );
                    word = code.substr( wordBegin, wordEnd - wordBegin );       
                    // loop through keywords and test each
                    for( int j = 0; j < NUM_KEYWORDS; j++ )
                    {
                        if( word == keywords[j] ) // substring matches
                        {
                            output += "<span class=\"keyword\">";
                            endSpan = true;
                            stepSize = word.length();
                            break;
                        }
                    }
                    stepSize = word.length(); // not keyword
                    break;
                }
                
                break; // eNormal
                
            case eBlockComment:
                /* exit a block comment? */
                if( code[i] == '*' && code[i+1] == '/' )
                {
                    stepSize = 2;
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                break; // eBlockComment
                
            case eLineComment:
                /* Exit a line comment? */
                if( code[i] == '\n' )
                {
                    stepSize = 1;
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                break; // eLineComment
                
            case eMacro:
                /* Exit macro via EOL? */
                if( code[i] == '\n' )
                {
                    stepSize = 1;
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                /* Exit macro because of comment? */
                if( (code[i] == '/' && code[i+1] == '/')
                  ||(code[i] == '*' && code[i+1] == '/') )
                {
                    stepSize = 0;
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                break; // eMacro
                
            case eCharLiteral:
                /* Enter an Escape sequence? */
                if( code[i] == '\\' )
                {
                    stepSize = 2;
                    break;
                }
                /* Exit a char literal? */
                if( code[i] == '\'' )
                {
                    stepSize = 1;
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                break; // eCharLiteral
                
            case eStringLiteral:
                /* Enter an Escape sequence? */
                if( code[i] == '\\' )
                {
                    stepSize = 2;
                    break;
                }
                /* Exit a string literal? */
                if( code[i] == '\"' )
                {
                    endSpan = true;
                    newState = eNormal;
                    break;
                }
                break;
                
            default:
                cerr << "Illegal state" << endl;
                exit(-1);
        } // state switch
        
        /* add character(s) */
        for( int j = 0; j < stepSize; j++ ) 
        {
                output += code[i+j];
        }
        
        /* append closing tag */
        if( endSpan )
        {
            output += "</span>";
            endSpan = false;
        }
        currentState = newState;
    } // char loop
    
    code = output;

} // TagCode

} // fsm namespace
