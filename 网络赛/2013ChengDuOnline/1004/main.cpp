#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

#ifndef MAXN
#define MAXN 23
#endif

#ifndef MAXM
#define MAXM 20
#endif

#ifndef BLANK
#define BLANK ""
#endif

string _map_[MAXN];
int shortest_length[MAXN];

void show_map ()
{
	for (int i = 2; i < 20; i++)
	{
		cout << i << " " << shortest_length[i] << " -> ";
		cout << _map_[i] << endl;
	}
}

void init_map ()
{
	for (int i = 0; i < MAXN; i++)
	{
		_map_[i] = "";
		shortest_length[i] = 22020;
	}
}

void insert_map (string str)
{
	int get_longest_palindrome = 0;
	for (int p_length = str.length(); get_longest_palindrome == 0 && p_length >= 1; p_length--)
	{
		for (int i = 0; get_longest_palindrome == 0 && i <= str.length() - p_length; i++)
		{
			bool is_palindrome = true;
			// i ~~~~ i + p_length - 1
			for (int j = 0; is_palindrome && j < p_length; j++)
			{
				if (str[i+j] != str[i+p_length-1-j])
				{
					is_palindrome = false;
				}
			}
			if (is_palindrome)
			{
				get_longest_palindrome = p_length;
			}
		}
	}
	//
	if (get_longest_palindrome < shortest_length[str.length()] && get_longest_palindrome != 0)
	{
		_map_[str.length()] = str;
		shortest_length[str.length()] = get_longest_palindrome;
	}
}

void search_string (string str, int depth)
{
	if (depth <= 20)
	{
		insert_map (str);
		// TODO 继续
		string tmp_string_1;
		string tmp_string_2;
		
		tmp_string_1 = str + "a";
		search_string (tmp_string_1, depth + 1);

		tmp_string_2 = str + "b";
		search_string (tmp_string_2, depth + 1);
	}
}

int main ()
{
	init_map ();
	search_string ("a", 1);
	search_string ("b", 1);
	show_map ();
	return 0;
}

