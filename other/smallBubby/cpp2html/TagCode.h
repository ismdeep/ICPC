/*|
|*| TagCode Finite State Machine
|*| Namespace header (public interface)
|*/
#ifndef TAGCODE_H
#define TAGCODE_H
#include <string>
using std::string;

#include <iostream>
using std::cerr;
using std::endl;

namespace fsm {

void TagCode( std::string & code );

} // fsm namespace;

#endif
