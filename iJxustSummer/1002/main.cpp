#include <stdio.h>
#include <stdlib.h>
typedef int InfoType;
typedef int KeyType;			//假定关键字类型为整数
typedef struct node				//结点类型
{
	KeyType key;				//关键字项
	InfoType otherinfo;			//其它数据域，InfoType视应用情况而定 下面不处理它
	struct node *lchild,*rchild;//左右孩子指针
}BSTNode;
typedef BSTNode *BSTree;     	//BSTree是二叉排序树的类型

BSTNode *SearchBST(BSTree T,KeyType key)
{	                                 //在二叉排序树T上查找关键字为key的结点，成功时返回该结点位置，否则返回NULL
	if(T==NULL||key==T->key)	     //递归的终结条件
		return T;				     //若T为空，查找失败；否则成功，返回找到的结点位置
	if(key<T->key)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);	//继续在右子树中查找
}

void InsertBST(BSTree *T,int key)
{                               //插入一个值为key的节点到二叉排序树中
	BSTNode *p,*q;
	if((*T)==NULL)
	{                           //树为空树
		(*T)=(BSTree)malloc(sizeof(BSTNode));
		(*T)->key=key;
		(*T)->lchild=(*T)->rchild=NULL;
	}
	else
	{
		p=(*T);
		while(p)
		{
			q=p;
			if(p->key>key)
			  p=q->lchild;
			else if(p->key<key)
			  p=q->rchild;
			else
			{
				printf("\n该二叉排序树中含有关键字为%d的节点!\n",key);
				return;
			}
		}
		p=(BSTree)malloc(sizeof(BSTNode));
		p->key=key;
		p->lchild=p->rchild=NULL;
	    if(q->key>key)
	      q->lchild=p;
	    else
	      q->rchild=p;
	}
}

BSTree CreateBST(void)
{	                            //输入一个结点序列，建立一棵二叉排序树，将根结点指针返回
	BSTree T=NULL;				//初始时T为空树
	KeyType key;
	scanf("%d",&key);			//读入一个关键字
	while(key)
	{					        //假设key=0是输入结束标志
		InsertBST(&T,key);		//将key插入二叉排序树T
		scanf("%d",&key);		//读入下一关键字
	}
	return T;					//返回建立的二叉排序树的根指针
}

void ListBinTree(BSTree T)       //用广义表表示二叉树
{
	if (T!=NULL)
	{
		printf("%d",T->key);
		if (T->lchild!=NULL||T->rchild!=NULL)
		{
			printf("(");
			ListBinTree(T->lchild);
			if (T->rchild!=NULL)
				printf(",");
			ListBinTree(T->rchild);
			printf(")");
		}
	}
}

void main()
{
	BSTNode *SearchBST(BSTree T,KeyType key);
	void InsertBST(BSTree *Tptr,KeyType key);
	BSTree CreateBST();
	void ListBinTree(BSTree T);		//用广义表表示二叉树
	BSTree T;
	BSTNode *p;
	int key;
	printf("请输入关键字（输入0为结束标志）：\n");
	T=CreateBST();
	ListBinTree(T);
	printf("\n");
	printf("请输入欲查找关键字：");
	scanf("%d",&key);
	p=SearchBST(T,key);
	if(p==NULL)
		printf("没有找到%d！\n",key);
	else
		printf("找到%d！\n",key);
	ListBinTree(p);
	printf("\n");
}
