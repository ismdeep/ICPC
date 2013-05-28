/*
 * Project     : 1013
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep 15 10:45:43 2012 
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

#define _DEBUG_

void iGcd( int a, int b )
  {
    int a, b;
    while ( b )
      {
        int tmp;
        tmp = a % b;
        a   = b;
        b   = tmp;
      }
    return a;
  }
// end 
// iCoding@CodeLab
//

str
