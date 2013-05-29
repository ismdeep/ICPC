/*\
|*|  CPP2HTML commandline transcoder
|*|          by AngleWyrm
\*/
#include <string>  
using std::string;

#include <iostream> 
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "TagCode.h"

void DisplayUsage(void); // Print usage help text
bool CreateStyleSheet(void); // Create default style sheet cpp.css

///////////////////////////////////////////////////////////////////////////////
// Main
int main(int argc, char *argv[])
{
    // Print banner
    cout << "\nCPP2HTML transcoder v1.2"
         << "\n    by AngleWyrm"
         << endl;
    
    // verify command line    
    // If no filenames on command line, then display usage and bail
    if( argc < 2 ){ 
        DisplayUsage();
        return 1;
    } // else command line populated (presumably with filenames)
    
    // Process each file
    ifstream inFile;
    ofstream outFile;
    string fileName;
    for(int fileCounter = 1; fileCounter < argc; fileCounter++){
        
        // print progress indicator
        cout << endl << fileCounter << "/" << argc - 1 << " \"" 
             << fileName << "\"";

        // open input file
        inFile.close();
        inFile.clear(); // reset error messages
        inFile.open( argv[fileCounter] );
        if( ! inFile ){ // If fail, proceed to next file
            cout << " *** FAILED TO OPEN INPUT ***";
            continue;
        } // else opened input file ok
        
        // open output file
        outFile.close();
        outFile.clear(); // reset error messages
        fileName = (string)argv[fileCounter] + ".htm";
        
        outFile.open( fileName.c_str() );
        if( ! outFile ){ // If fail, proceed to next file
            cout << " *** FAILED TO OPEN OUTPUT ***" 
                 << " \"" << fileName << "\"";
            continue;
        } // else opened output file ok
        
        // convert web-interpretable codes to web-safe versions
        string webSafe; 
        while( inFile ){
            char inChar;
            inFile.get( inChar );
            switch ( inChar ){
                case '&':
                    webSafe += "&amp;"; 
                    break;
                case '<':
                    webSafe += "&lt;";
                    break;
                case '>':
                    webSafe += "&gt;";
                    break;
                default:
                    webSafe += inChar;
            }
        }
        inFile.close();
        
        fsm::TagCode( webSafe );
        
        // assemble HTML 
        string header = "<html>\n<head>\n\t<title>";
        header += argv[fileCounter];
        header += "</title>\n";
        header += "\t<LINK href=\"cpp.css\" rel=\"stylesheet\" type=\"text/css\">\n";
        header += "</head>\n<body>\n<pre>";
        
        webSafe = header + webSafe + "</pre>\n</body>\n</html>";
              
        // save to new file
        outFile << webSafe;
        outFile.close();
        
        cout << " -> \"" << fileName << "\"";
    } // next fileCounter
    
    // create CPP.CSS if necessary
    ifstream cppCss("cpp.css");
    if(!cppCss){
        CreateStyleSheet();
        cout << "\nCPP.CSS created.";
    }
    
    cout << "\n\nDone." << endl;
} // main

///////////////////////////////////////////////////////////////////////////////
// DisplayUsage
void DisplayUsage(void)
{
    // Display command line usage screen
    cout << "Usage: cpp2html filename1.ext\n"
         << endl;
} // DisplayUsage

///////////////////////////////////////////////////////////////////////////////
// cpp.css stylesheet template
bool CreateStyleSheet( void ){
    ofstream styleSheet("cpp.css");
    if( styleSheet ){
        styleSheet 
               << ".comment {\n	color:DarkGray;\n	font-style:italic;\n}\n"
               << ".macro {\n	color:ForestGreen;\n}\n"
               << ".literal {\n	color:Red;\n}\n"
               << ".keyword {\n	color:Black;\n	font-weight:bold;\n}\n"
               << ".numeric {\n	color:RoyalBlue;\n}"
               << endl;
    } // else failed to create cpp.css
    return styleSheet.good();
} // CreateStyleSheet


