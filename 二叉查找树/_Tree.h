#ifndef _TREE_H
#ifdef __cplusplus
extern "C" {
#endif
	struct TreeNode;
	typedef struct TreeNode *Position;
	typedef struct TreeNode *SearchTree;
	typedef int Element;

	SearchTree make_Empty(SearchTree tree);
	Position find(Element x, SearchTree tree);
	Position find_Max(SearchTree tree);
	Position find_Min(SearchTree tree);
	SearchTree insert(Element x, SearchTree tree);
	SearchTree _delete(Element x, SearchTree tree);
	Element Retrieve(Position p);
	void proorder_foreach(SearchTree tree);
#if __cplusplus
}
#endif
#endif // !_TREE_H
