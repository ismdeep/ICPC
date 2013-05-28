/*
 * Project Name : Hill
 *
 * File    Name : hill.cpp
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012年 11月 21日 星期三 11:01:30 CST
 *
 * */

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

// #define _ISM_DEBUG_

#ifndef _DEFAULT_MATRIX_SIZE_
#define _DEFAULT_MATRIX_SIZE_ 110
#endif

#ifndef _CHAR_COUNT_
#define _CHAR_COUNT_ 256
#endif

#ifndef _SPAN_SIZE_
#define _SPAN_SIZE_ 2
#endif


//-------------------------------------------------------------------------------------//
string strKey;
//-------------------------------------------------------------------------------------//
int encode_matrix[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_];
int decode_matrix[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_];
int matrix_size;
//-------------------------------------------------------------------------------------//
int src_matrix[_DEFAULT_MATRIX_SIZE_];
int des_matrix[_DEFAULT_MATRIX_SIZE_];
//-------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------//
void show_encode_matrix ()
{
	cout << "------------------ encode_matrix [][] ------------------" << endl;
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cout << encode_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//-------------------------------------------------------------------------------------//
void show_decode_matrix ()
{
	cout << "------------------ decode_matrix [][] ------------------" << endl;
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cout << decode_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//-------------------------------------------------------------------------------------//
bool show_encode_matrix_mul_decode_matrix ()
{
	void EncodeMatrix_to_DecodeMatrix ();
	EncodeMatrix_to_DecodeMatrix ();
#ifdef _ISM_DEBUG_
	cout << "-------------------- mul_matrix [][] --------------------" << endl;
#endif
	int iTmpMatrix[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_];
	memset (iTmpMatrix, 0, sizeof(iTmpMatrix));
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			for (int k = 0; k < matrix_size; k++)
			{
				iTmpMatrix[i][j] += (
					encode_matrix[i][k] * decode_matrix[k][j]
				);
				iTmpMatrix[i][j] %= _CHAR_COUNT_;
			}
			iTmpMatrix [i][j] %= _CHAR_COUNT_;
		}
	}
	bool iFlag = true;
	//-------------------------------- show iTmpMatrix --------------------------------//
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
#ifdef _ISM_DEBUG_
			cout << iTmpMatrix[i][j] << " ";
#endif
			if (i == j)
			{
				if (1 != iTmpMatrix[i][j])
				{
					iFlag = false;
				}
			}
			else
			{
				if (0 != iTmpMatrix[i][j])
				{
					iFlag = false;
				}
			}
		}
#ifdef _ISM_DEBUG_
		cout << endl;
#endif
	}
	return iFlag;
}


//-------------------------------------------------------------------------------------//
void init_src_matrix ()
{
	memset (src_matrix, 0, sizeof(src_matrix));
}

//-------------------------------------------------------------------------------------//
void init_des_matrix ()
{
	memset (des_matrix, 0, sizeof(des_matrix));
}

//-------------------------------------------------------------------------------------//
void matrix__src_2_des ()
{
	//--------------- encode_matrix * src_matrix -> des_matrix ------------------------//
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			int iTmpSum = 0;
			for (int k = 0; k < matrix_size; k++)
			{
				iTmpSum += (encode_matrix[i][k] * src_matrix[k]);
				iTmpSum %= _CHAR_COUNT_;
			}
			iTmpSum %= _CHAR_COUNT_;
			des_matrix[i] = iTmpSum;
		}
	}
}

//-------------------------------------------------------------------------------------//
void matrix__des_2_src ()
{
	//--------------- decode_matrix * des_matrix -> src_matrix ------------------------//
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			int iTmpSum = 0;
			for (int k = 0; k < matrix_size; k++)
			{
				iTmpSum += (decode_matrix[i][k] * des_matrix[k]);
				iTmpSum %= _CHAR_COUNT_;
			}
			iTmpSum %= _CHAR_COUNT_;
			src_matrix[i] = iTmpSum;
		}
	}
}


//-------------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------------//
int injust_nValue (int nNum)
{
	if (nNum < 0)
	{
		nNum = 0 - nNum;
		nNum = _CHAR_COUNT_ - nNum;
	}
	return nNum;
}

//-------------------------------------------------------------------------------------//
int iGcd (int a, int b)
{
	int iTmpGcdValue;
	while (b)
	{
		iTmpGcdValue = a % b;
		a            = b;
		b            = iTmpGcdValue;
	}
	return a;
}

//-------------------------------------------------------------------------------------//
int cal_strKey_int_value (string iTmpStr)
{
	int iTmpSum = 0;
	for (int i = 0; i < iTmpStr.length(); i++)
	{
		iTmpSum += (int)iTmpStr[i];
	}
	return iTmpSum;
}


//-------------------------------------------------------------------------------------//
int char_2_int (char chTmp)
{
	int nNum;
	nNum = chTmp;
	nNum = injust_nValue (nNum);
	return nNum;
}


//-------------------------------------------------------------------------------------//
char int_2_char (int nTmp)
{
	nTmp = injust_nValue (nTmp);
	char chTmp;
	chTmp = nTmp;
	return chTmp;
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
int cal_algebraic_cofactor_recursion (
		int iMap[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_],
		int iSize
)
{
	if (1 == iSize)
	{
		return iMap[0][0];
	}
	else
	{
		int iTmpMap[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_];
		int iSum = 0;
		for (int k = 0; k < iSize; k++)
		{
			for (int i = 1; i < iSize; i++)
			{
				for (int j = 0; j < k; j++)
				{
					iTmpMap[i-1][j]   = iMap[i][j];
				}
				for (int j = k + 1; j < iSize; j++)
				{
					iTmpMap[i-1][j-1] = iMap[i][j];
				}
			}
			int iTmpSumValue = 
				cal_algebraic_cofactor_recursion (
					iTmpMap,
					iSize - 1
				);
			iTmpSumValue *= iMap[0][k];
			if (0 == k % 2)
			{
				iSum += iTmpSumValue;
			}
			else
			{
				iSum -= iTmpSumValue;
			}
		}
		return iSum;
	}
}


//-------------------------------------------------------------------------------------//
int cal_algebraic_cofactor_value (int x, int y)
{
	//---------------- just copy ------------------------------------------------------//
	int iTmpMap[_DEFAULT_MATRIX_SIZE_][_DEFAULT_MATRIX_SIZE_];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			iTmpMap[i][j] = encode_matrix[i][j];
		}
		for (int j = y + 1; j < matrix_size; j++)
		{
			iTmpMap[i][j-1] = encode_matrix[i][j];
		}
	}
	for (int i = x + 1; i < matrix_size; i++)
	{
		for (int j = 0; j < y; j++)
		{
			iTmpMap[i-1][j] = encode_matrix[i][j];
		}
		for (int j = y + 1; j < matrix_size; j++)
		{
			iTmpMap[i-1][j-1] = encode_matrix[i][j];
		}
	}
	//---------------------------------------------------------------------------------//
	int iTmpMapSum = 0;
	iTmpMapSum = cal_algebraic_cofactor_recursion (iTmpMap, matrix_size - 1);
	if (1 == (x + y) % 2)
	{
		iTmpMapSum = 0 - iTmpMapSum;
	}
	else
	{
		iTmpMapSum = iTmpMapSum;
	}
	return iTmpMapSum;
}


//-------------------------------------------------------------------------------------//
void strKey_to_encode_matrix (string strKey)
{
	//------ cal out matrix_size by strKey's length------------------------------------//
	matrix_size = strKey.length ();
	matrix_size = sqrt ((double)matrix_size);
	matrix_size += _SPAN_SIZE_;
	//---------------------------------------------------------------------------------//
	memset (encode_matrix, 0, sizeof(encode_matrix));
	for (int iIndex = 0; iIndex < strKey.length (); iIndex++)
	{
		encode_matrix[iIndex / matrix_size][iIndex % matrix_size] = strKey[iIndex];
	}
}

//-------------------------------------------------------------------------------------//
void turn_encode_matrix_right ()
{
	srand (cal_strKey_int_value (strKey));
	int iSumAllAlgebraicConfactor;
	iSumAllAlgebraicConfactor=cal_algebraic_cofactor_recursion(encode_matrix,matrix_size);
	while (iSumAllAlgebraicConfactor < 0)
	{
		iSumAllAlgebraicConfactor += _CHAR_COUNT_;
	}
	while (    1 != iGcd (iSumAllAlgebraicConfactor, _CHAR_COUNT_) 
			|| !show_encode_matrix_mul_decode_matrix()
	)
	{
		// chang encode_matrix //
		int iIndexI;
		int iIndexJ;
		iIndexI = rand () % matrix_size;
		iIndexJ = rand () % matrix_size;
		int iAddValue;
		iAddValue = rand () % matrix_size;
		encode_matrix [iIndexI][iIndexJ] = iAddValue;
		encode_matrix [iIndexI][iIndexJ] %= _CHAR_COUNT_;
		//
		iSumAllAlgebraicConfactor = 
			cal_algebraic_cofactor_recursion (encode_matrix, matrix_size);
		while (iSumAllAlgebraicConfactor < 0)
		{
			iSumAllAlgebraicConfactor += _CHAR_COUNT_;
		}
		//
		//
		//
	}
}

//-------------------------------------------------------------------------------------//
void EncodeMatrix_to_DecodeMatrix ()
{
	int iSumAllAlgebraicConfactor;
	iSumAllAlgebraicConfactor=cal_algebraic_cofactor_recursion(encode_matrix,matrix_size);
	while (iSumAllAlgebraicConfactor < 0)
	{
		iSumAllAlgebraicConfactor += _CHAR_COUNT_;
	}
	//---------------------------------------------------------------------------------//
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			decode_matrix[j][i] = cal_algebraic_cofactor_value (i, j);
			while (decode_matrix[j][i] <= 0)
			{
				decode_matrix[j][i] += _CHAR_COUNT_;
			}
			decode_matrix[j][i] *= iSumAllAlgebraicConfactor;
			decode_matrix[j][i] %= _CHAR_COUNT_;
		}
	}
}


//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//---------------------------- encode files from infile -------------------------------//
void hill_encode (char* argv[], string strKey)
{
	//----------------------------- open files ----------------------------------------//
	ifstream infile;
	ofstream oufile;
	string infile_str;
	string oufile_str;
	infile_str = argv[2];
	oufile_str = infile_str + ".en";
	infile.open (&infile_str[0], ios::in );
	oufile.open (&oufile_str[0], ios::out);
	//---------------------------------------------------------------------------------//
	strKey_to_encode_matrix (strKey);
	turn_encode_matrix_right ();
	//---------------------------------------------------------------------------------//
	int file_volume_value = 0;
	char chTmp;
	while (infile.get (chTmp))
	{
		file_volume_value++;
	}
	// file_volume_value %= _CHAR_COUNT_;
	oufile << file_volume_value << endl;
	//------------------ re-open infile -----------------------------------------------//
	infile.close ();
	infile.open  (&infile_str[0], ios::in);
	//---------------------------------------------------------------------------------//
	//--------------------- read data and encode it, then output. ---------------------//
	chTmp;
	int count_serize = 0;
	init_src_matrix ();
	init_des_matrix ();
	while (infile.get (chTmp))
	{
		int nNum;
		nNum = char_2_int (chTmp);
		src_matrix[count_serize] = nNum;
		count_serize++;
		if (0 == count_serize % matrix_size)
		{
			// encode and output, then init 
			matrix__src_2_des ();
			for (int i = 0; i < matrix_size; i++)
			{
				char chOutputTmp;
				chOutputTmp = int_2_char (des_matrix[i]);
				oufile << chOutputTmp;
			}
			count_serize = 0;
			init_src_matrix ();
			init_des_matrix ();
		}
	}
	for (int i = 0; i < matrix_size; i++)
	{
		char chOutputTmp;
		chOutputTmp = int_2_char (des_matrix[i]);
		oufile << chOutputTmp;
	}
	//---------------------------------------------------------------------------------//
	//---------------- in the end, let's close all files. -----------------------------//
	infile.close ();
	oufile.close ();
}

//-------------------------------------------------------------------------------------//
//---------------------------- decode files from infile -------------------------------//
void hill_decode (char* argv[], string strKey)
{
	//----------------------------- open files ----------------------------------------//
	ifstream infile;
	ofstream oufile;
	string infile_str;
	string oufile_str;
	infile_str = argv[2];
	oufile_str = infile_str + ".de";
	infile.open (&infile_str[0], ios::in );
	oufile.open (&oufile_str[0], ios::out);
	//---------------------------------------------------------------------------------//
	strKey_to_encode_matrix (strKey);
	turn_encode_matrix_right ();
	EncodeMatrix_to_DecodeMatrix ();
	//---------------------------------------------------------------------------------//
	//---------------------------------------------------------------------------------//
	//--------------------- read data and encode it, then output. ---------------------//
	int file_volume_value = 0;
	infile >> file_volume_value;
	char chTmp0;
	chTmp0 = infile.get ();
	int decode_time = file_volume_value / matrix_size;
	while (decode_time--)
	{
		for (int i = 0; i < matrix_size; i++)
		{
			char chTmp;
			infile.get (chTmp);
			des_matrix[i] = char_2_int (chTmp);
		}
		matrix__des_2_src ();
		for (int i = 0; i < matrix_size; i++)
		{
			char chTmp;
			chTmp = int_2_char (src_matrix[i]);
			oufile << chTmp;
		}
	}
	if (0 != file_volume_value % matrix_size)
	{
		for (int i = 0; i < matrix_size; i++)
		{
			char chTmp;
			infile.get (chTmp);
			des_matrix[i] = char_2_int (chTmp);
		}
		matrix__des_2_src ();
		for (int i = 0; i < (file_volume_value % matrix_size); i++)
		{
			char chTmp;
			chTmp = int_2_char (src_matrix[i]);
			oufile << chTmp;
		}
	}
	//---------------- in the end, let's close all files. -----------------------------//
	infile.close ();
	oufile.close ();
}

//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------------//
int main (int argc, char* argv[])
{
	//---------------------------------------------------------------------------------//
	//------------- Judge if the comman is OK. ----------------------------------------//
	if (argc < 3)
	{
		cout << " Error!" << endl;
		return 0;
	}
	//---------- Everything prepared. Start! ------------------------------------------//
	string strInstruc;
	strInstruc = argv[1];
	if ("-en" == strInstruc)
	{
		//------------------ Encode ---------------------------------------------------//
		cout << "Input passwd:";
		cin >> strKey;
		hill_encode (argv, strKey);
	}
	else if ("-de" == strInstruc)
	{
		//------------------ Decode ---------------------------------------------------//
		cout << "Input passwd:";
		cin >> strKey;
		hill_decode (argv, strKey);
	}
	else
	{
		//---------------- Something is wrong! ----------------------------------------//
		cout << " Error!" << endl;
	}
	return 0;
}


// end
// ismdeep
// CodeLab

