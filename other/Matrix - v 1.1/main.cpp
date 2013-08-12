#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include "define_head.h"
#include "Matrix.cpp"
#include <ism_debug>


int main()
{
	int a_tmp, b_tmp, c_tmp;
	while (cin >> a_tmp >> b_tmp >> c_tmp)
	{
		Matrix mat_a(a_tmp, b_tmp);
		Matrix mat_b(b_tmp, c_tmp);
		//
		mat_a.CGetValue();
		mat_b.CGetValue();
		//
		// mat_a.CShowMat();
		// mat_b.CShowMat();
		//
		if (CCanMulTogether(mat_a, mat_b))
		{
			Matrix mat_sum(mat_a.line, mat_b.row);
			mat_sum = mat_a * mat_b;
			mat_sum.CShowMat();
		}
		else
		{
			cout << "They Can't mul! " << endl;
		}
	}
	return 0;
}

// end 
// iCoding

