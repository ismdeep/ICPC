/*
 * Project Name : BinaryTree
 *
 * File Name    : BinaryTree.h
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012-11-22 星期四 10:20:38.93
 *
 * */

#include "BinaryTreeNode.cpp"



class BinaryTree
{
	private:
		BinaryTreeNode iData[_DEFAULT_BIN_TREE_SIZE];
		int iTop;
	public:
		BinaryTree ();
		void input_binary_tree ();
			bool input_binary_tree_node (
				BinaryTreeNode* iBinNode
			);
		void show_binary_tree ();
			void show_binary_tree_node (
				BinaryTreeNode* iBinNode,
				int             iDepth
			);
};


