/*
 * Project     : B
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Oct 18 22:05:31 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

// #define _ISM_DEBUG_

// RXCY : numeration
// XY   : concatenation

bool is_numeration (string str)
{
    int iChangeCount = 0;
    for (int i = 1; i < str.length (); i++)
    {
	if (
	       (str[i] >= 'A' && str[i] <= 'Z' && str[i-1] >= '0' && str[i-1] <= '9')
	    || (str[i] >= '0' && str[i] <= '9' && str[i-1] >= 'A' && str[i-1] <= 'Z')
	)
	{
	    iChangeCount++;
	}
    }
    return (iChangeCount >= 3);
}

// XY -> RXCY : BC23 -> R23C55
void translate_concatenation_to_numeration (string str)
{
    #ifdef _ISM_DEBUG_
    cout << "XY -> RXCY" << endl;
    #endif
    int index_x = 0;
    int index_y = 0;
    int index = 0;
    while (str[index] >= 'A' && str[index] <= 'Z')
    {
	index_x = index_x * 26 + (str[index] - 'A' + 1);
	index++;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
	index_y = index_y * 10 + (str[index] - '0');
	index++;
    }
    cout << "R" << index_y << "C" << index_x << endl;
}

// RXCY -> XY : R23C55 -> BC23
void translate_numeration_to_concatenation (string str)
{
    #ifdef _ISM_DEBUG_
    cout << "RXCY -> XY" << endl;
    #endif
    int index_x = 0;
    int index_y = 0;
    int index = 1;
    while (str[index] >= '0' && str[index] <= '9')
    {
	index_x = index_x * 10 + (str[index] - '0');
	index++;
    }
    index++;
    while (str[index] >= '0' && str[index] <= '9')
    {
	index_y = index_y * 10 + (str[index] - '0');
	index++;
    }
    void number_to_char (int num);
    number_to_char (index_y);
    cout << index_x << endl;
}

void number_to_char (int num)
{
    if (num)
    {
	int tmp;
	tmp = num % 26;
	tmp--;
	number_to_char (num / 26);
	cout << (char)(tmp + 'A');
    }
}

int main()
{
    int iCaseCount;
    cin >> iCaseCount;
    while (iCaseCount--)
    {
	string str;
	cin >> str;
	if (is_numeration (str))
	{
	    translate_numeration_to_concatenation (str);
	}
	else
	{
	    translate_concatenation_to_numeration (str);
	}
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

