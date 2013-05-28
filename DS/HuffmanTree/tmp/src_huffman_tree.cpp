/********************************************************************************/
//----------------------------- Head.h -----------------------------------------//
/*
 * Project Name : HuffmanTree
 * File    Name : Head.h
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <time.h>


#ifndef _HUFFMAN_TREE_DEFAULT_SIZE_
#define _HUFFMAN_TREE_DEFAULT_SIZE_ 11000
#endif

#define _ISM_DEBUG_



/********************************************************************************/
//-------------------------HuffmanTreeNode.h -----------------------------------//

/*
 * Project Name : HuffmanTree
 * File    Name : HuffmanTreeNode.h
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */

#include "Head.h"

class HuffmanTreeNode
{
	public:
		//------------------ data setion ---------------//
		int              nValue;
		HuffmanTreeNode* pLeft;
		HuffmanTreeNode* pRight;
		HuffmanTreeNode* pParent;
		//------------------ function setction ---------//
		HuffmanTreeNode ();
};

/********************************************************************************/
//--------------------------- HuffmanTreeNode.cpp ------------------------------//

/*
 * Project Name : HuffmanTree
 * File    Name : HuffmanTreeNode.cpp
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */


#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode ()
{
	this->pLeft   = NULL;
	this->pRight  = NULL;
	this->pParent = NULL;
	this->nValue  = 0;
}

/********************************************************************************/
//----------------------- HuffmanTree.h ----------------------------------------//

/*
 * Project Name : HuffmanTree
 * File    Name : HuffmanTree.h
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */

#include "HuffmanTreeNode.cpp"

class HuffmanTree
{
	private:
		HuffmanTreeNode iData[
			_HUFFMAN_TREE_DEFAULT_SIZE_ * 2
			];
		int nNodeCount;
		int iTop;
		int iMinIndexLeft;
		int iMinIndexRight;
	public:
		HuffmanTree ();
		void input_tree_node_iData ();
		void get_min_index ();
			void manage_min_index ();
			void show_min_index ();
		void create_huffman_tree ();
		void show_huffman_tree ();
			void show_huffman_tree_node (HuffmanTreeNode* tNodeIndex, int tDepth);
};


/********************************************************************************/
//---------------------------- HuffmanTree.cpp ---------------------------------//

/*
 * Project Name : HuffmanTree
 * File    Name : HuffmanTree.cpp
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */

#include "HuffmanTree.h"

HuffmanTree::HuffmanTree ()
{
	this->nNodeCount = 0;
	this->iTop       = -1;
}


void HuffmanTree::input_tree_node_iData ()
{
	std::cin >> this->nNodeCount;
	this->iTop = this->nNodeCount - 1;
	//----------input data one by one ------------------//
	for (
		int tIndex = 0;
		tIndex < this->nNodeCount;
		tIndex++
	)
	{
		std::cin >> this->iData[tIndex].nValue;
	}
}


void HuffmanTree::get_min_index ()
{
	//---------------------------------------------------//
	bool tFound = false;
	for (
		int tIndex = 0;
		!tFound && tIndex <= this->iTop;
		tIndex++
	)
	{
		if (NULL == this->iData[tIndex].pParent)
		{
			tFound = true;
			this->iMinIndexLeft  = tIndex;
			this->iMinIndexRight = tIndex;
		}
	}
	//---------------------------------------------------//
	for (
		int tIndex = iMinIndexLeft + 1;
		tIndex <= this->iTop;
		tIndex++
	)
	{
		if (
			(
					this->iData[tIndex].nValue
				<= 	this->iData[this->iMinIndexRight].nValue
				||
					this->iMinIndexLeft
				== 	this->iMinIndexRight
			)
			&& 
				NULL == this->iData[tIndex].pParent
		)
		{
			this->iMinIndexRight = tIndex;
			this->manage_min_index ();
		}
	}
}

void HuffmanTree::manage_min_index ()
{
	if (
		  this->iData[this->iMinIndexLeft].nValue
		> this->iData[this->iMinIndexRight].nValue
	)
	{
		int tTmpMinIndex;
		tTmpMinIndex         = this->iMinIndexLeft;
		this->iMinIndexLeft  = this->iMinIndexRight;
		this->iMinIndexRight = tTmpMinIndex;
	}
}

void HuffmanTree::show_min_index ()
{
	std::cout << this->iMinIndexLeft  << " "
		      << this->iMinIndexRight << std::endl;
}

void HuffmanTree::create_huffman_tree ()
{
	//---- That will be nNodeCount - 1 time of merger ---//
	for (
		int tMergerTime = 1;
		tMergerTime <= nNodeCount - 1;
		tMergerTime++
	)
	{
		this->get_min_index ();
		this->iTop++;
		//--------- link parent and sons together -------//
		//
		this->iData[this->iMinIndexLeft ].pParent = 
			&this->iData[this->iTop];
		this->iData[this->iMinIndexRight].pParent = 
			&this->iData[this->iTop];
		//
		this->iData[this->iTop].pLeft  = 
			&this->iData[this->iMinIndexLeft];
		this->iData[this->iTop].pRight = 
			&this->iData[this->iMinIndexRight];
		this->iData[this->iTop].nValue = 
			  this->iData[this->iMinIndexLeft ].nValue
			+ this->iData[this->iMinIndexRight].nValue;
	}
}

void HuffmanTree::show_huffman_tree ()
{
	this->show_huffman_tree_node (&this->iData[this->iTop], 0);
}

void HuffmanTree::show_huffman_tree_node (HuffmanTreeNode* tNodeIndex, int tDepth)
{
	if (NULL != tNodeIndex)
	{
		for (
			int tSlashCount = 1;
			tSlashCount <= tDepth;
			tSlashCount++
		)
		{
			std::cout << "   ";
		}
		std::cout << (*tNodeIndex).nValue << std::endl;
		this->show_huffman_tree_node ((*tNodeIndex).pLeft , tDepth + 1);
		this->show_huffman_tree_node ((*tNodeIndex).pRight, tDepth + 1);
	}
}




/********************************************************************************/
//----------------------------- main.cpp ---------------------------------------//

/*
 * Project Name : HuffmanTree
 * File    Name : main.cpp
 * Author       : ismdeep
 * Date & Time  : 2012年 11月 20日 星期二 12:48:45 CST
 * */


#include "HuffmanTree.cpp"


int main ()
{
#ifdef _ISM_DEBUG_
	HuffmanTree huffman_tree;
	huffman_tree.input_tree_node_iData ();
	huffman_tree.create_huffman_tree ();
	huffman_tree.show_huffman_tree ();
#endif
	return 0;
}


/********************************************************************************/
//------------------------------ Makefile --------------------------------------//

all:
	g++ -g main.cpp -o main


/********************************************************************************/
//---------------------------- in.dat ------------------------------------------//
10
1 2 3 4 5 6 7 8 9 10 

