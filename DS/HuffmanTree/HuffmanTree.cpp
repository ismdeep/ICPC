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


