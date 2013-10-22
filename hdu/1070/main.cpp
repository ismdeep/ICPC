// Project name : 1070 ( Milks ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 17:00:51 2012


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Milk
{
	int volume;
	int price;
	int days;
	string name;
	void CSetValue(string _name, int _price, int _volume)
	{
	    name   = _name;
		price  = _price;
		volume = _volume;
		days   = _volume / 200;
		if (days > 5)
		{
		    days = 5;
		}
	}
};

bool operator < (const Milk& lh, const Milk& rh)
{
    if (lh.price * rh.days < rh.price * lh.days)
	{
		return true;
	}
	return (lh.price * rh.days == rh.price * lh.days && lh.volume > rh.volume);
}
int main()
{
    int t, n, i, p, v;
	string name;
	vector<Milk> milks;
	Milk tmp;
	cin >> t;
	while (t--)
	{
	    cin >> n;
		milks.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> name >> p >> v;
			if (v < 200)
			{
				continue;
			}
			tmp.CSetValue(name, p, v);
			milks.push_back(tmp);
		}
		sort(milks.begin(), milks.end());
		cout << milks.front().name << endl;
	}
    return 0;
}

// end 
// ism 

