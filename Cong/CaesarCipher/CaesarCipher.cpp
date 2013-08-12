/*
 * Project Name : CaesarCipher
 *
 * File    Name : CaesarCipher.h
 * 
 * Author       : ismdeep
 * 
 * Date & Time  : 2012年 11月 20日 星期二 23:07:31 CST
 * 
 * */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

int cal_key_value (string strKey)
{
	int iKeyValue = 0;
	for (
		int i = 0;
			i < strKey.length ();
			i++
	)
	{
		iKeyValue += strKey[i];
	}
	return iKeyValue;
}

char caesar_cipher_encode_char (char ch, int key)
{
	int iTmp;
	if (ch >= 'a' && ch <= 'z')
	{
		iTmp = ch - 'a';
		iTmp = (iTmp + key) % 26;
		ch = iTmp + 'a';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		iTmp = ch - 'A';
		iTmp = (iTmp + key) % 26;
		ch = iTmp + 'A';
	}
	else
	{
		//----------- Nice! Just doing nothing. --------//
	}
	return ch;
}


char caesar_cipher_decode_char (char ch, int key)
{
	int iTmp;
	if (ch >= 'a' && ch <= 'z')
	{
		iTmp = ch - 'a';
		iTmp -= key;
		while (iTmp <= 0)
		{
			iTmp += 26;
		}
		iTmp = iTmp % 26;
		ch = iTmp + 'a';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		iTmp = ch - 'A';
		iTmp -= key;
		while (iTmp <= 0)
		{
			iTmp += 26;
		}
		iTmp = iTmp % 26;
		ch = iTmp + 'A';
	}
	else
	{
		//----------- Nice! Just doing nothing. --------//
	}
	return ch;
}


//---------------- caesar_cipher_encode ----------------//
void caesar_cipher_encode (char* argv[], int key)
{
	ifstream infile;
	ofstream oufile;
	//---------------- open files ----------------------//
	string infile_str, oufile_str;
	infile_str = argv[2];
	oufile_str = infile_str + ".en";
	infile.open (&infile_str[0], ios::in );
	oufile.open (&oufile_str[0], ios::out);
	//--------------------------------------------------//
	char chSrc;
	char chDes;
	while (infile.get(chSrc))
	{
		chDes = caesar_cipher_encode_char (chSrc, key);
		oufile << chDes;
	}
	//--------------------------------------------------//
	//---------------- close files ---------------------//
	infile.close ();
	oufile.close ();
}



//---------------- caesar_cipher_decode ----------------//
void caesar_cipher_decode (char* argv[], int key)
{
	ifstream infile;
	ofstream oufile;
	//---------------- open files ----------------------//
	string infile_str, oufile_str;
	infile_str = argv[2];
	oufile_str = infile_str + ".de";
	infile.open (&infile_str[0], ios::in );
	oufile.open (&oufile_str[0], ios::out);
	//--------------------------------------------------//
	char chSrc;
	char chDes;
	while (infile.get(chSrc))
	{
		chDes = caesar_cipher_decode_char (chSrc, key);
		oufile << chDes;
	}
	//--------------------------------------------------//
	//---------------- close files ---------------------//
	infile.close ();
	oufile.close ();
}

int main (int argc, char* argv[])
{
	//-------------- Judge if the commad is OK. --------//
	if (argc < 3)
	{
		std::cout << "  Error! " << endl;
		return 0;
	}
	string strKey;
	std::cout << "Input Key:";
	cin >> strKey;
	int iKey = cal_key_value (strKey);
	string strInstruc = argv[1];
	if (strInstruc == "-en")
	{
		caesar_cipher_encode (argv, iKey);
	}
	else if (strInstruc == "-de")
	{
		caesar_cipher_decode (argv, iKey);
	}
	else
	{
		//------------ Something is wrong. -------------//
		std::cout << "  Error! " << endl;
	}
	return 0;
}



