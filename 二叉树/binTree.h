#pragma once
#include <stdlib.h>
#ifdef __cplusplus
extern"C" {
#endif

	struct TreeNode
	{
		struct TreeNode* left;
		struct TreeNode* right;
	};
	struct BinTree
	{
		void* data;
		struct TreeNode point;
	};
	typedef void* bin_tree;
	bin_tree Init_BinTree()
	{
		struct BinTree* tree = (struct BinTree*)malloc(sizeof(struct BinTree));
		if (tree == NULL)
		{
			return NULL;
		}
		tree->data = NULL;
		tree->point.left = NULL;
		tree->point.right = NULL;
		return tree;
	}
	void Insert_TreeNode(bin_tree tree,void* data)
	{
		if (NULL == tree)
		{
			return;
		}
		if (NULL == data)
		{
			return;
		}
		struct BinTree* Mytree = (struct BinTree*)tree;
		struct BinTree* node = (struct BinTree*)malloc(sizeof(struct BinTree*));
		node->data = data;
		Mytree->data = data;

	}

#ifdef __cplusplus
}
#endif
