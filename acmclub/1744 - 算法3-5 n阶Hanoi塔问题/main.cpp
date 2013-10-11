/* 
 * Project Name : 1744
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Oct 11 08:31:14 2013 
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

int step_count;


// 这个题目有一些抽象。需要好好理解。。。就是如何移动盘子。。
// 你可以这样理解，对于n个盘子，你先把之上n-1个盘子全部移动到中间过度的那个柱子，然后把最下面，也就是最大的
// 移动到目标柱子。然后你继续移动之前全部移动到过去柱子上那n-1个盘子到目标柱子。。
// 这一段思路里面就包含了递归调用的思想。递归调用就是把大问题抽象出来自己包含自己的算法。
void show_honi_move (int n, char X, char Y, char Z)
{
	// 首先表示X上有n个圆盘，Y上面没有，要将所有X上的都移动到Z上面
	if (1 == n)
	{
		step_count++;
		printf ("%2d. Move disk %d from %c to %c\n", step_count, n, X, Z); 
	}
	else // n >= 2时
	{
		show_honi_move (n-1, X, Z, Y); // 先把上面n-1个全部移动到Y
		step_count++;
		printf ("%2d. Move disk %d from %c to %c\n", step_count, n, X, Z); // 然后将最下面的移动至Z上面
		show_honi_move (n-1, Y, X, Z); // 再把Y上面的全部移动到Z
	}
}

int main () 
{
	int n;
	while (scanf ("%d", &n) != EOF)
	{
		step_count = 0;
		show_honi_move (n, 'X', 'Y', 'Z'); // 调用，不多说。
		printf ("\n");
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

