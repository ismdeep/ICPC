#include <iostream>
#include "Point.cpp"

using namespace std;

#define MAX_MAXE_SIZE 30

class Maze
{
	private:
		Point iMap[MAX_MAXE_SIZE+2][MAX_MAXE_SIZE+2];
		int n, m;
	public:
		Maze ();
		void set_all_block ();
		void input_iMap ();
		void search_route ();
};


