#include "Matrix.h"
#include "define_head.h"
//#include <ism_debug>

/*******************************************************************************************************************/
Matrix::Matrix()
{
	line = DEFAULT_LENGTH;
	row  = DEFAULT_LENGTH;
	CConstruct();
}
/*******************************************************************************************************************/
Matrix::Matrix(int line, int row)
{
	this -> line = line;
	this -> row  = row;
	CConstruct();
}
/*******************************************************************************************************************/
Matrix::~Matrix()
{
	// silence is gold
	CDeleteMem();
}
/*******************************************************************************************************************/
void Matrix::CConstruct()
{
	a = new int*[line];
	for (int i = 0; i < line; i++)
	{
		a[i] = new int[row];
	}
	// memset(a, 0, sizeof(a));
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			a[i][j] = 0;
		}
	}
}
/*******************************************************************************************************************/
void Matrix::CDeleteMem()
{
	//
	for (int i = 0; i < line; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}
/*******************************************************************************************************************/
void Matrix::CGetValue()
{
	// get value for a[line][row]
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> a[i][j];
		}
	}
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/
void Matrix::CShowMat()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
/*******************************************************************************************************************/
bool CCanMulTogether(Matrix mat_a, Matrix mat_b)
{
	return (mat_a.row == mat_b.line) ? true : false ;
}
/*******************************************************************************************************************/
Matrix operator * (const Matrix mat_a, const Matrix mat_b)
{
	//
	//
	// cout << "Define Sucessfully!" << endl;
	Matrix mat_sum(mat_a.line, mat_b.row);
	for (int i = 0; i < mat_sum.line; i++)
	{
		for (int j = 0; j < mat_sum.row; j++)
		{
			mat_sum.a[i][j] = 0;
			for (int k = 0; k < mat_a.row; k++)
			{
				mat_sum.a[i][j] += (mat_a.a[i][k] * mat_b.a[k][j]);
			}
		}
	}
	//cout << "--debug--" << endl;
	return mat_sum;
}
/*******************************************************************************************************************/


// end 
// iCoding@CodeLab
//

