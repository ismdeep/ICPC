/* 
 * Project Name : 1060
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 15:42:11 2013 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

int ans[] = 
{
	0, 3,7,17,41,99,239,577,1393,3363,8119,19601,47321,114243,275807,665857,1607521,3880899,9369319,22619537,54608393,131836323
};

int main () 
{ 
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

