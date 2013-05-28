/*
 * Project     : 1007
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Oct 15 16:28:57 2012 
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// #define _ISM_DEBUG_

#ifndef MAXN
#define MAXN 1100
#endif


class DNA
{
public:
    string iStrDNA;
    int iStrLength;
    int value;
    void cal_value ();
};

void DNA::cal_value ()
{
    int iValueTmp = 0;
    this->value = 0;
    for (int i = 0; i < iStrLength; i++)
    {
	iValueTmp = 0;
	for (int j = i + 1; j < iStrLength; j++)
	{
	    if (this->iStrDNA[i] > this->iStrDNA[j])
	    {
		iValueTmp++;
	    }
	}
	this->value += iValueTmp;
    }
}

bool cmp_DNA (DNA dna_a, DNA dna_b)
{
    return dna_a.value < dna_b.value;
}

///////////////////////////////////////////////////
// data
DNA list[MAXN];
int iLengthDNAGlobal;
int n;

void input_list ()
{
    for (int index = 0; index < n; index++)
    {
	cin >> list[index].iStrDNA;
	list[index].iStrLength = iLengthDNAGlobal;
	list[index].cal_value ();
    }
}

void sort_DNA_list ()
{
    sort (list, list + n, cmp_DNA);
}

void show_DNA_list ()
{
    for (int i = 0; i < n; i++)
    {
	cout << list[i].iStrDNA;
	#ifdef _ISM_DEBUG_
	cout << " " << list[i].value;
	#endif
	cout << endl;
    }
}

int main()
{
    while (cin >> iLengthDNAGlobal >> n)
    {
	input_list ();
	sort_DNA_list ();
	show_DNA_list ();
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

