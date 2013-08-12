#include <iostream>
#include <cmath>
#include <fstream>
#include "define_head.h"

namespace icoding
{
	using namespace std;
	ifstream cin("in.dat", ios::in);
}

using icoding::cin;
//using std::cin;
using std::cout;
using std::string;
using std::endl;

class Matrix
{
public:
	// data 
	int** a;
	int line, row;
	// Constructors
	Matrix();
	Matrix(int line, int row);
	// Destructors
	~Matrix();
	// Member functions
	void CConstruct();
	void CDeleteMem();
	void CGetValue();
	void CShowMat();
	//
	friend bool CCanMulTogether(Matrix, Matrix);
	friend Matrix operator * (Matrix mat_a, Matrix mat_b);
};

// end 
// iCoding@CodeLab

