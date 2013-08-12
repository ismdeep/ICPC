#include <iostream>
#include <cmath>
#include <fstream>
//using namespace std;

namespace icoding
{
	using namespace std;
	ifstream cin("in.dat", ios::in);
}

using icoding::cin;
using std::cout;
using std::string;
using std::endl;

#ifndef DEFAULT_LENGTH
#define DEFAULT_LENGTH 100
#endif


class Matrix
{
public:
	int** a;
	Matrix();
	Matrix(int line, int row);
	~Matrix();
	int line, row;
	void CConstruct();
	void CDeleteMem();
	void CGetValue();
	void CShowMat();
	friend Matrix operator * (Matrix mat_a, Matrix mat_b);
};

Matrix::Matrix()
{
	line = DEFAULT_LENGTH;
	row  = DEFAULT_LENGTH;
	
	CConstruct();
}

Matrix::Matrix(int line, int row)
{
	this -> line = line;
	this -> row  = row;
	CConstruct();
}

Matrix::~Matrix()
{
	for (int i = 0; i < line; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void Matrix::CConstruct()
{
	a = new int*[line];
	for (int i = 0; i < line; i++)
	{
		a[i] = new int[row];
	}
}

void Matrix::CDeleteMem()
{
	for (int i = 0; i < line; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}


void Matrix::CGetValue()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> a[i][j];
		}
	}
}

void Matrix::CShowMat()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0;  j < row; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


Matrix operator * (Matrix mat_a, Matrix mat_b)
{
	Matrix mat_sum;
	mat_sum.CDeleteMem();
	mat_sum.line = mat_a.line;
	mat_sum.row  = mat_b.row;
	mat_sum.CConstruct();
	for (int i = 0; i < mat_sum.line; i++)
	{
		for (int j = 0; j < mat_sum.row; j++)
		{
			int sum_tmp;
			sum_tmp = 0;
			for (int k  = 0; k < mat_a.row; k++)
			{
				sum_tmp += (mat_a.a[i][k] * mat_b.a[k][j]);
			}
			mat_sum.a[i][j] = sum_tmp;
		}
	}
	return mat_sum;
}


// end 
// iCoding@CodeLab

