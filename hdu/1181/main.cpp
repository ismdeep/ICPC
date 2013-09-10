// Project name : 1181 ( 变形课 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 11:22:44 2012


#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 30
bool map[MAXN][MAXN];

const bool cango  = true;
const bool cantgo = false;

void CInitMap()
{
    for (int i = 0; i <= 26; i++)
	{
		for (int j = 0; j <= 26; j++)
		{
		    map[i][j] = cantgo;
		}
	}
}

void CWarShell()
{
	int n = 26;

	for (int k = 0; k < n; k++)
	{
	    for (int i = 0; i < n; i++)
		{
		    if (map[i][k] == cango)
			{
			    for (int j = 0; j < n; j++)
				{
					if (map[k][j] == cango)
					{
					    map[i][j] = cango;
					}
				}
			}
		}
	}
}

void CStoreLink(string link)
{
	int top = 0;
	while (link[top] != '\0')
	{
	    top++;
	}
	top--;

	map[link[0] - 'a'][link[top] - 'a'] = cango;
}

int main()
{
	string s;
	while (cin >> s)
	{
	    CInitMap();
		CStoreLink(s);
		while (cin >> s && s != "0")
		{
		    CStoreLink(s);
		}

		CWarShell();

		if (map['b' - 'a']['m' - 'a'] == cango)
		{
		    cout << "Yes." << endl;
		}

		else
		{
		    cout << "No."  << endl;
		}
	}
    return 0;
}

// end 
// ism 

