#include "Avltree.h"
#include <stdio.h>
struct AvlNode
{
	ElementType Element;
	struct AvlNode *left;
	struct AvlNode *right;
	int height;
};
//��ȡAVL���ĸ߶�
int get_height(Position p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
}
//��AVL���ÿ�
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
//AVL���Ĳ���
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

//����AVL������Сֵ
Position find_Min(AvlTree tree)
{
	if (tree != NULL)
		while (tree->left)
			tree = tree->left;
	return tree;
}
//����AVL������Сֵ
Position find_Max(AvlTree tree)
{
	if (tree != NULL)
		while (tree->right)
			tree = tree->right;
	return tree;
}
//AVL���ҵ���ת
Position SingleRotateWithRight(Position p1)
{
	Position p2;
	p2 = p1->right;  //����������
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(get_height(p1->left), get_height(p1->right)) + 1;
	p2->height = max(get_height(p2->left), get_height(p2->right)) + 1;
	return p2;
}
//AVL������ת
Position SingleRotateWithLeft(Position p1)
{
	Position p2;
	p2 = p1->left;  //����������
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(get_height(p1->left), get_height(p1->right)) + 1;
	p2->height = max(get_height(p2->left), get_height(p2->right)) + 1;
	return p2;
}
//AVL������˫��ת
Position DoubleRotateWithRight(Position p1)
{
	p1->right = SingleRotateWithLeft(p1->right);
	return SingleRotateWithRight(p1);
}
//AVL������˫��ת
Position DoubleRotateWithLeft(Position p1)
{
	p1->left = SingleRotateWithRight(p1->left);
	return SingleRotateWithLeft(p1);
}
//AVL���Ĳ���
AvlTree insert(ElementType x, AvlTree tree)
{
	//�����Ϊ�գ��򴴽������������ݴ���
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
	}//��������ֵС�ڵ�ǰ�ڵ��ֵ����ݹ�ز��뵽��������
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
	}//��������ֵ���ڵ�ǰ�ڵ��ֵ����ݹ�ز��뵽��������
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
	}//else x�������Ѿ�����
	//�������ĸ߶�
	tree->height = max(get_height(tree->left), get_height(tree->right)) + 1;
	return tree;
}
//AVL���ڵ��ɾ��
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
	}//���������������Ϊ��
	else if (tree->left&&tree->right)
	{
		struct AvlNode* temp=find_Min(tree->right);
		tree = temp;
		tree->right = _delete(tree->Element, tree->right);
		if (get_height(tree->left) - get_height(tree->right) == 2)
		{
			tree = SingleRotateWithLeft(tree);
		}
	}//���������Ϊ��
	else if (tree->left == NULL)
	{
		tree = tree->right;
	}//���������Ϊ��
	else if (tree->right == NULL)
	{
		tree = tree->left;
	}
	return tree;
}
//��ȡAVL���ڵ������
ElementType retrieve(Position p)
{
	return p->Element;
}
//����ƽ�������
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
