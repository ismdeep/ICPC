/*
 * Project     : sort
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep  7 14:59:25 2012 
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

typedef long long int longint;

bool cmp(int a, int b)
{
    return (a > b) ? true : false;
}

int main()
{
	int n;
    cin >> n;
    int* data;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    //
    //
    sort(data, data + n, cmp);
	//
    //
    // output result 
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}

// end 
// iCoding@CodeLab
//

