// Project name : 1234 ( 开门人和关门人 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul  5 17:29:33 2012


#include <iostream>
#include <stdio.h>
using namespace std;

class MyTime
{
public:
	int hour;
	int min;
	int sec;
	void setTime(int, int, int);
	bool operator > (MyTime b_time);
};

bool MyTime::operator > (MyTime b_time)
{
    bool yes = false;
	if (this->hour > b_time.hour)
	{
	    yes = true;
	}
	else if (this->hour == b_time.hour && this->min > b_time.min)
	{
	    yes = true;
	}
	else if (this->min == b_time.min && this->sec > b_time.sec)
	{
	    yes = true;
	}
	
	return yes;
}

void MyTime::setTime(int hour, int min, int sec)
{
	this->hour = hour;
	this->min  = min;
	this->sec  = sec;
}
/***********************************************************************/
class StuInfo
{
public:
	string str_id;
	MyTime come;
	MyTime leave;
};


/***********************************************************************/
int main()
{
    int t;
	scanf("%d", &t);
	while (t--)
	{
	    int n;
		cin >> n;
		StuInfo* stu;
		stu = new StuInfo[n];

		for (int i = 0; i < n; i++)
		{
		    cin >> stu[i].str_id;
			int hour, min, sec;
			scanf("%d%*c%d%*c%d", &hour, &min, &sec);
			stu[i].come.setTime(hour, min, sec);
			scanf("%d%*c%d%*c%d", &hour, &min, &sec);
			stu[i].leave.setTime(hour, min, sec);
		}

		int comer, leaver;
		comer  = 0;
		leaver = 0;

		/* find comer  */
		for (int i = 1; i < n; i++)
		{
			if (stu[comer].come > stu[i].come)
			{
			    comer = i;
			}
		}

		/* find leaver */
		for (int i = 1; i < n; i++)
		{
		    if (stu[i].leave > stu[leaver].leave)
			{
			    leaver = i;
			}
		}

		cout << stu[comer].str_id << " " << stu[leaver].str_id << endl;
		delete[] stu;
	}
    return 0;
}

// end 
// ism 

