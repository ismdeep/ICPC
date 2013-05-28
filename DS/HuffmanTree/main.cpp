/*
 * Project Name : HuffmanTree
 * File    Name : HuffmanTreeNode.cpp
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
