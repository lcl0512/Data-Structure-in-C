#include <stdlib.h>
#ifndef _Avltree_H
#ifdef __cplusplus
extern "C" {
#endif 
	struct AvlNode;
	typedef struct AvlNode* Position;
	typedef struct AvlNode* AvlTree;
	typedef int ElementType;
	//将AVL树置空
	AvlTree make_empty(AvlTree tree);
	//AVL树的查找
	Position find(ElementType x, AvlTree tree);
	//查找AVL树的最小值
	Position find_Min(AvlTree tree);
	//查找AVL树的最大值
	Position find_Max(AvlTree tree);
	//AVL树的插入
	AvlTree insert(ElementType x, AvlTree tree);
	//AVL树节点的删除
	AvlTree _delete(ElementType x, AvlTree tree);
	//获取AVL树节点的数据
	ElementType retrieve(Position p);
	//AVL树右单旋转
	Position SingleRotateWithRight(Position p1);
	//AVL树左单旋转
	Position SingleRotateWithLeft(Position p1);
	//AVL树的右双旋转
	Position DoubleRotateWithRight(Position p1);
	//AVL树的左双旋转
	Position DoubleRotateWithLeft(Position p1);
	//获取AVL树的高度
	int get_height(Position p);
	//遍历平衡二叉树
	//void proorder_foreach(AvlTree tree, void(*Foreach)(ElementType));
	void proorder_foreach(AvlTree tree);
	////求两个数的最大值
	//int max(int a, int b);

#ifdef __cplusplus
}
#endif 
#endif // !_Avltree_H

