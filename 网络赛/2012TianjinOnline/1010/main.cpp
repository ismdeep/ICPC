/*
 * Project     : 1010
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep  9 13:01:00 2012 
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

#define MAXN 6000

int char_num[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

struct InputKey
{
	longint key;
	longint count;
	longint id;
};

int n;
InputKey input[MAXN];
/////////////////////////////////////////////////////////////////////
bool cmp_by_key (InputKey a, InputKey b)
{
	return (a.key < b.key);
}
/////////////////////////////////////////////////////////////////////
bool cmp_by_id  (InputKey a, InputKey b)
{
	return (a.id  < b.id );
}
/////////////////////////////////////////////////////////////////////
longint translate_words_to_key(string str)
{
	longint ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		ans *= 10;
		ans += char_num[str[i] - 'a'];
	}
	return ans;
}
/////////////////////////////////////////////////////////////////////
void insert(int start, int end, int id_key)
{
	if (start == end)
	{
		if (input[start].key == id_key)
		{
			input[start].count++;
		}
		else
		{
			// keep silence
			// Doing nothing
		}
	}
	else
	{
		int mid_index = (start + end) / 2;
		if (id_key >= input[start].key && id_key <= input[mid_index].key)
		{
			insert(start, mid_index, id_key);
		}
		if (id_key >= input[mid_index+1].key && id_key <= input[end].key)
		{
			insert(mid_index+1, end, id_key);
		}
	}
}
/////////////////////////////////////////////////////////////////////
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m;
		scanf("%d%d", &n, &m);
		// input n data 
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &input[i].key);
			input[i].count = 0;
			input[i].id    = i;
		}
		// sort input by key
		sort (input, input + n, cmp_by_key);
		// input m words and change the value of input if there got id = it
		string str_word;
		for (int i = 0; i < m; i++)
		{
			cin >> str_word;
			longint id_key = translate_words_to_key(str_word);
			insert(0, n-1, id_key);
		}
		// sort input by id
		sort (input, input + n, cmp_by_id );
		// output result
		for (int i = 0; i < n; i++)
		{
			// cout << input[i].id << " ";
			cout << input[i].count << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

