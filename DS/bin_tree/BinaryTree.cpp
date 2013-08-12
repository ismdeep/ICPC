/*
 * Project Name : BinaryTree
 *
 * File Name    : BinaryTree.cpp
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012-11-22 星期四 10:20:38.93
 *
 * */


#include "BinaryTree.h"

BinaryTree::BinaryTree ()
{
	this->iTop = -1;
}


void BinaryTree::input_binary_tree ()
{
	this->iTop = 0;
	this->input_binary_tree_node(
		&this->iData[this->iTop]
	);
}


bool BinaryTree::input_binary_tree_node (
	BinaryTreeNode* iBinNode
)
{
	int iTmp;
	cin >> iTmp;
	if (-1 == iTmp)
	{
		return false;
	}
	else
	{
		(*iBinNode).nValue = iTmp;
		bool iFlag;
		//----------------------------------------------//
		this->iTop++;
		(*iBinNode).pLeft = & this->iData[this->iTop];
		iFlag = this->input_binary_tree_node (
			(*iBinNode).pLeft
		);
		if (!iFlag)
		{
			(*iBinNode).pLeft = NULL;
		}
		//----------------------------------------------//
		this->iTop++;
		(*iBinNode).pRight = &this->iData[this->iTop];
		iFlag = this->input_binary_tree_node (
			(*iBinNode).pRight
		);
		if (!iFlag)
		{
			(*iBinNode).pRight = NULL;
		}
		//----------------------------------------------//
		return true;
	}
}


void BinaryTree::show_binary_tree ()
{
	show_binary_tree_node (
		&this->iData[0],
		0
	);
}


void BinaryTree::show_binary_tree_node (
	BinaryTreeNode* iBinNode,
	int             iDepth
)
{
	//--------------------------------------------------//
	for (int i = 1; i <= iDepth; i++)
	{
		cout << "   ";
	}
	cout << (*iBinNode).nValue << endl;
	//--------------------------------------------------//
	if (NULL != (*iBinNode).pLeft)
	{
		this->show_binary_tree_node (
			(*iBinNode).pLeft,
			iDepth + 1
		);
	}
	//--------------------------------------------------//
	if (NULL != (*iBinNode).pRight)
	{
		this->show_binary_tree_node (
			(*iBinNode).pRight,
			iDepth + 1
		);
	}
	//--------------------------------------------------//
}


