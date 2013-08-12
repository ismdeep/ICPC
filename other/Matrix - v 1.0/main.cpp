#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "Matrix.h"

int main()
{
	int a_tmp, b_tmp, c_tmp;
	while (cin >> a_tmp >> b_tmp >> c_tmp)
	{
		cout << a_tmp << " " << b_tmp << " " << c_tmp << endl;
		
		Matrix A(a_tmp, b_tmp);
		Matrix B(b_tmp, c_tmp);
		A.CGetValue();
		B.CGetValue();
		Matrix Sum(a_tmp, c_tmp);
		Sum = A * B;
		Sum.CShowMat();
		cout << "--debug--" << endl;
	}
	cout << "--debug--" << endl;
	//
	//
	//
	return 0;
}

// end 
// iCoding

