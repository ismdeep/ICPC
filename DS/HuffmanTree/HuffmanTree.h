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


