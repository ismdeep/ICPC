#include <iostream>
#include "Maze.cpp"
using namespace std;

int main ()
{
	Maze maze;
	// set all Point to block
	maze.set_all_block ();
	// input iMap data for maze
	maze.input_iMap ();
	// search all route in iMap
	maze.search_route ();
	return 0;
}

// end 
// iCoding@CodeLab
//

