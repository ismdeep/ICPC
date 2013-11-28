#include <iostream>
#include <cstdlib>
using namespace std;

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
	cout << "Error!" << endl;
	return 0;
    }
    string file_name = argv[1];
    string instuc = "dot -Tps " + file_name + " -o " + file_name + ".ps";
    cout << instuc << endl;
    system (&instuc[0]);
    return 0;
}
