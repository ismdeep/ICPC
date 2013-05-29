/*\
|*| Testing web-safe characters (&, <, and >)
\*/
#include <map>   // display .macro, .comment
map<string,int> test["Whatever"] = 2.5; // display .keyword, .literal, .numeric

int &amp; // address of int -> ampersand?
vector<char> chars; // vector of chars -> hypothetical "char" tag?
