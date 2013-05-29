/*
 * Project     : 1710
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Wed Sep  5 16:42:57 2012 
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

int preorder[1005];
int inorder[1005];

void dfs(int pre,int in,int size,bool flag)
{
    int i;
    if(size == 1) //如果有左子树或右子树，就直接输出
    {
        printf("%d ",preorder[pre]); //不是根节点，所以是空格
        return ;
    }
    if(size<=0) //没有左子树或右子树，则返回上层，遍历右子树或者根
        return ;
    for(i=0;preorder[pre]!=inorder[in+i];i++);//查找根节点在中序中的位置
    dfs(pre+1,in,i,false);              //左子树的遍历
    dfs(pre+i+1,in+i+1,size-i-1,false); //右子树的遍历
    if(flag)                           //输出根节点
        printf("%d\n",preorder[pre]);  //整个树的根节点
    else
        printf("%d ",preorder[pre]);   //一般的根节点
}

int main()
{
    int n,i;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&preorder[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&inorder[i]);
        dfs(1,1,n,true);
    }
    return 0;
}

// end
//
// iCoding@CodeLab
//

