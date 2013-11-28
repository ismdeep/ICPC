/*
 * Project Name : BinaryTree Traversal
 *
 * File    Name : BinaryTreeNode.h
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012 - 11 - 06 20:07
 *
 * */

class BinaryTreeNode
{
	private:
		int node_value;
		BinaryTreeNode *pLeft;
		BinaryTreeNode *pRight;
		BinaryTreeNode *pParent;
	public:
		BinaryTreeNode ();
		int             get_node_value ();
		BinaryTreeNode* get_pLeft_point ();
		BinaryTreeNode* get_pRight_point ();
		BinaryTreeNode* get_pParent_point ();
};


// end 
// ismdeep
// CodeLab
//

