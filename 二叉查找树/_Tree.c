#include "_Tree.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode
{
	Element x;
	struct TreeNode* left;
	struct TreeNode* right;
};

SearchTree make_Empty(SearchTree tree)
{
	if (tree != NULL)
	{
		make_Empty(tree->left);
		make_Empty(tree->right);
		free(tree);
	}
	else
		return NULL;

}
Position find(Element x, SearchTree tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (x > tree->x)
	{
		return find(x,tree->right);
	}
	else if(x < tree->x)
	{
		return find(x,tree->left);
	}
	else
	{
		return tree;
	}
}
Position find_Max(SearchTree tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else if (tree->right)
	{
		return find_Max(tree->right);
	}
	else
	{
		return tree;
	}
}
Position find_Min(SearchTree tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else if (tree->left)
	{
		return find_Min(tree->left);
	}
	else
	{
		return tree;
	}
}
SearchTree insert(Element x, SearchTree tree)
{
	//�����Ϊ�գ��򴴽������������ݴ���
	if (tree == NULL)
	{
		tree = malloc(sizeof(struct TreeNode));
		if (tree == NULL)
		{
			printf("Out of space!!!");
			return NULL;
		}
		else
		{
			tree->x = x;
			tree->left = tree->right=NULL;
		}
	}//��������ֵС�ڵ�ǰ�ڵ��ֵ����ݹ�ز��뵽��������
	if (x < tree->x)
	{
		tree->left = insert(x, tree->left);
	}//��������ֵ���ڵ�ǰ�ڵ��ֵ����ݹ�ز��뵽��������
	else if (x > tree->x)
	{
		tree->right = insert(x, tree->right);
	}//else x�������Ѿ�����
	return tree;
}
SearchTree _delete(Element x, SearchTree tree)
{
	Position temp;
	if (tree == NULL)
	{
		printf("Element not fount!!!");
	}
	else if (x < tree->x)
	{
		tree->left = _delete(x, tree->left);
	}
	else if (x > tree->x)
	{
		tree->right = _delete(x, tree->right);
	}
	else if(tree->left && tree->right)
	{
		temp = find_Min(tree->right);
		tree->x = temp->x;
		tree->right = _delete(temp->x, tree->right);
	}
	else
	{
		temp = tree;
		if (tree->left == NULL)
		{
			tree = tree->right;
		}
		else if (tree->right == NULL)
		{
			tree = tree->left;
		}
		free(temp);
	}
	return tree;
}
Element Retrieve(Position p)
{
	return p->x;
}

void proorder_foreach(SearchTree tree)
{
	if (tree != NULL)
	{
		printf("%d  ", tree->x);
		proorder_foreach(tree->left);
		proorder_foreach(tree->right);
	}
}