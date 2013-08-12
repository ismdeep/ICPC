#include <iostream>
#include <stdio.h>
using namespace std;

class Project
{
public:
	double mark;
	double score;
	int point;
	double result;
	//
	//
	void CCalPoint();
	void CCalResult();
	double CGetResult();
	double CGetMark();
	void CSetMark();
	void CSetScore();
};

int n;

/**************************************************************/

void Project::CCalPoint()
{
	if ((int)score >= 90)
	{
		point = 4;
	}
	else if ((int)score >= 80)
	{
		point = 3;
	}
	else if ((int)score >= 70)
	{
		point = 2;
	}
	else if ((int)score >= 60)
	{
		point = 1;
	}
	else
	{
		point = 0;
	}
}

void Project::CCalResult()
{
	result = mark * (double)point;
}

double Project::CGetResult()
{
	return result;
}

double Project::CGetMark()
{
	return mark;
}

void Project::CSetMark()
{
	cin >> mark;
}

void Project::CSetScore()
{
	cin >> score;
}

/**************************************************************/
int main()
{
	while (cin >> n)
	{
		Project* pro;
		pro = new Project[n];
		double sum  = 0;
		double mark = 0;
		bool down = false;
		for (int i = 0; i < n; i++)
		{
			pro[i].CSetMark();
			pro[i].CSetScore();
			if (pro[i].score != -1)
			{
				pro[i].CCalPoint();
				pro[i].CCalResult();
				mark += pro[i].CGetMark();
				sum  += pro[i].CGetResult();
			}
			else
			{
				down = true;
			}
		}
		if (down)
		{
			cout << "-1" << endl;
		}
		else
		{
			printf("%.2f\n", sum / mark);
		}
	}
	return 0;
}

// end 
// iCoding
//

