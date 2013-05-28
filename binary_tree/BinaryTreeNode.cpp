/*
 * Project Name : BinaryTree Traversal
 *
 * File    Name : BinaryTreeNode.cpp
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012 - 11 - 06 20:08
 *
 * */


#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode ()
{
	pLeft   = NULL;
	pRight  = NULL;
	pParent = NULL;
}

/*********************************************************/
/* get binary tree node's value */
int             BinaryTreeNode::get_node_value ()
{
	return this->node_value;
}


/*********************************************************/
/* get binary tree node's left point */
BinaryTreeNode* BinaryTreeNode::get_pLeft_point ()
{
	return this->pLeft;
}

BinaryTreeNode* BinaryTreeNode::get_pRight_point ()
{
	return this->pRight;
}

BinaryTreeNode* BinaryTreeNode::get_pParent_point ()
{
	return this->pParent;
}



// end 
// ismdeep
// CodeLab
//

