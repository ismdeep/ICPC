#include <iostream>
using namespace std;

/* 特殊数据定义，，我开了64位的数据，防止我优化的方法还是溢出了。 */
typedef unsigned long long int longint;

int main()
{
	int t;
	/* 输入第一行的数据，表示有几组数据嘛~~~ */
	cin >> t;
	while (t--)
	{
		longint sum = 1;
		int n, m;
		/* 输入n和m咯。表示一共有多少人，和需要表演节目的人数 */
		cin >> n >> m;
		if (n < m)/* 如果是要表演节目的同学人数多于一共有的同学人数 */
		{
			/* 人都没有，，直接没有节目不就得了。 */
			cout << "0" << endl;
		}
		else
		{
			for (int i = 1; i <= m; i++)
			{
				/* 这里就是核心代码了..*/
				/* 先乘以分子最大的，然后再除以分母最小的，并且可以保证最后答案不会出错 */
				sum *= (n-i+1);
				sum /= i;
			}
			/* 输出结果 */
			cout << sum << endl;
		}
	}
	return 0;
}

// end 
//
