#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define _ISM_DEBUG_

#define MAXN 110000

int n, m;

class SegTree
{
public:
	int left, right;
	int arr[MAXN*4];

	void input_build_seg_tree (int lp, int rp, int id);
	int get_or_value_seg (int lp, int rp, int tlp, int trp, int id);
	int get_right_most_index (int lp, int left_most, int right_most);
};

int SegTree::get_or_value_seg (int lp, int rp, int tlp, int trp, int id)
{
	if (tlp == lp && trp == rp)
	{
		return this->arr[id];
	}
	else
	{
		int mid = (tlp + trp) / 2;
		if (rp <= mid)
		{
			return this->get_or_value_seg (lp, rp, tlp, mid, id * 2);
		}
		else if (lp >= (mid + 1))
		{
			return this->get_or_value_seg (lp, rp, mid + 1, trp, id * 2);
		}
		else
		{
			return  this->get_or_value_seg (lp, mid, tlp, mid, id * 2) 
				  | this->get_or_value_seg (mid + 1, rp, mid + 1, trp, id * 2 + 1);
		}
	}
}

void SegTree::input_build_seg_tree (int lp, int rp, int id)
{
	if (lp == rp)
	{
		scanf ("%d", &this->arr[id]);
	}
	else
	{
		int mid = (lp + rp) / 2;
		this->input_build_seg_tree (lp, mid, id * 2);
		this->input_build_seg_tree (mid+1, rp, id * 2 + 1);
		this->arr[id] = this->arr[id*2] | this->arr[id*2+1];
	}
}

int SegTree::get_right_most_index (int lp, int left_most, int right_most)
{
	if (left_most == right_most)
	{
		int value_tmp;
		value_tmp = this->get_or_value_seg (left_most, left_most, this->left, this->right, 1);
		if (value_tmp < m)
		{
			return left_most;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		int value_tmp;
		int mid = (left_most + right_most) / 2;
		value_tmp = this->get_or_value_seg (left_most, mid, this->left, this->right, 1);
		if (value_tmp < m)
		{
			value_tmp = this->get_or_value_seg (left_most, mid + 1, this->left, this->right, 1);
			if (value_tmp >= m)
			{
				return mid;
			}
			else
			{
				return this->get_right_most_index (lp, mid + 1, right_most);
			}
		}
		else
		{
			return this->get_right_most_index (lp, left_most, mid);
		}
	}
}


int main ()
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d%d", &n, &m);
		SegTree seg_tree;
		seg_tree.left = 1; seg_tree.right = n;
		seg_tree.input_build_seg_tree (1, n, 1); 
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			int right_most_value;
			right_most_value = seg_tree.get_right_most_index (i, i, n);
			if (-1 != right_most_value)
			{
				#ifdef _ISM_DEBUG_
				cout << i << " " << right_most_value << endl;
				#endif
				count += (right_most_value - i + 1);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

