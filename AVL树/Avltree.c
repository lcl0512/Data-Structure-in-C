#include "Avltree.h"
#include <stdio.h>
struct AvlNode
{
	ElementType Element;
	struct AvlNode *left;
	struct AvlNode *right;
	int height;
};
//获取AVL树的高度
int get_height(Position p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
}
//将AVL树置空
AvlTree make_empty(AvlTree tree)
{
	if (tree != NULL)
	{
		make_empty(tree->left);
		make_empty(tree->right);
		free(tree);
	}
	return NULL;
}
//AVL树的查找
Position find(ElementType x, AvlTree tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (x > tree->Element)
	{
		return find(x, tree->right);
	}
	else if (x < tree->Element)
	{
		return find(x, tree->left);
	}
	else
	{
		return tree;
	}
}

//查找AVL树的最小值
Position find_Min(AvlTree tree)
{
	if (tree != NULL)
		while (tree->left)
			tree = tree->left;
	return tree;
}
//查找AVL树的最小值
Position find_Max(AvlTree tree)
{
	if (tree != NULL)
		while (tree->right)
			tree = tree->right;
	return tree;
}
//AVL树右单旋转
Position SingleRotateWithRight(Position p1)
{
	Position p2;
	p2 = p1->right;  //保存右子树
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(get_height(p1->left), get_height(p1->right)) + 1;
	p2->height = max(get_height(p2->left), get_height(p2->right)) + 1;
	return p2;
}
//AVL树左单旋转
Position SingleRotateWithLeft(Position p1)
{
	Position p2;
	p2 = p1->left;  //保存左子树
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(get_height(p1->left), get_height(p1->right)) + 1;
	p2->height = max(get_height(p2->left), get_height(p2->right)) + 1;
	return p2;
}
//AVL树的右双旋转
Position DoubleRotateWithRight(Position p1)
{
	p1->right = SingleRotateWithLeft(p1->right);
	return SingleRotateWithRight(p1);
}
//AVL树的左双旋转
Position DoubleRotateWithLeft(Position p1)
{
	p1->left = SingleRotateWithRight(p1->left);
	return SingleRotateWithLeft(p1);
}
//AVL树的插入
AvlTree insert(ElementType x, AvlTree tree)
{
	//如果树为空，则创建树，并将数据存入
	if (tree == NULL)
	{
		tree = malloc(sizeof(struct AvlNode));
		if (tree == NULL)
		{
			printf("Out of space!!!");
			return NULL;
		}
		else
		{
			tree->Element = x;
			tree->left = tree->right = NULL;
			tree->height = 0;
		}
	}//如果插入的值小于当前节点的值，则递归地插入到左子树中
	if (x < tree->Element)
	{
		tree->left = insert(x, tree->left);
		if (get_height(tree->left) - get_height(tree->right) == 2)
		{
			if (x < tree->left->Element)
				tree = SingleRotateWithLeft(tree);
			else
				tree = DoubleRotateWithLeft(tree);
		}
	}//如果插入的值大于当前节点的值，则递归地插入到右子树中
	else if (x > tree->Element)
	{
		tree->right = insert(x, tree->right);
		if (get_height(tree->right) - get_height(tree->left) == 2)
		{
			if (x > tree->right->Element)
				tree = SingleRotateWithRight(tree);
			else
				tree = DoubleRotateWithRight(tree);
		}
	}//else x在树中已经存在
	//更新树的高度
	tree->height = max(get_height(tree->left), get_height(tree->right)) + 1;
	return tree;
}
//AVL树节点的删除
AvlTree _delete(ElementType x, AvlTree tree)
{
	if (tree == NULL)
	{
		printf("Element not found!!!");
	}
	if (x < tree->Element)
	{
		tree->left = _delete(x, tree->left);
	}
	else if (x > tree->Element)
	{
		tree->right = _delete(x, tree->right);
	}//如果左右子树都不为空
	else if (tree->left&&tree->right)
	{
		struct AvlNode* temp=find_Min(tree->right);
		tree = temp;
		tree->right = _delete(tree->Element, tree->right);
		if (get_height(tree->left) - get_height(tree->right) == 2)
		{
			tree = SingleRotateWithLeft(tree);
		}
	}//如果左子树为空
	else if (tree->left == NULL)
	{
		tree = tree->right;
	}//如果右子树为空
	else if (tree->right == NULL)
	{
		tree = tree->left;
	}
	return tree;
}
//获取AVL树节点的数据
ElementType retrieve(Position p)
{
	return p->Element;
}
//遍历平衡二叉树
//void proorder_foreach(AvlTree tree, void(*Foreach)(ElementType))
//{
//	if (tree != NULL)
//	{
//		Foreach(tree->Element);
//		proorder_foreach(tree->left, Foreach);
//		proorder_foreach(tree->right, Foreach);
//	}
//}
void proorder_foreach(AvlTree tree)
{
	if (tree != NULL)
	{
		printf("%d  ", tree->Element);
		proorder_foreach(tree->left);
		proorder_foreach(tree->right);
	}
}
