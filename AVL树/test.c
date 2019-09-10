#include "Avltree.h"
#include <stdio.h>
void print(ElementType em)
{
	printf("%d  ",em);
}
void test()
{
	struct AvlNode* tree=NULL;
	tree = insert(2, tree);
	tree = insert(6, tree);
	tree = insert(7, tree);
	tree = insert(3, tree);
	tree = insert(4, tree);
	tree = insert(5, tree);
	//平衡二叉树的遍历
	proorder_foreach(tree);
	//AVL树节点的删除
	tree = _delete(5,tree);
	//平衡二叉树的遍历
	printf("\n-----------------删除5节点后-----------------\n");
	proorder_foreach(tree);
	//AVL树的查找
	struct AvlNode* node = find(2,tree);
	printf("\n查找到2节点：%d\n", retrieve(node));
	//查找AVL树的最小值
	struct AvlNode* node_min = find_Min(tree);
	printf("查找到最小值节点：%d\n", retrieve(node_min));
	//查找AVL树的最大值
	struct AvlNode* node_max = find_Max(tree);
	printf("查找到最大值节点：%d\n", retrieve(node_max));
	printf("树的高度：%d \n", get_height(tree));
	//将AVL树置空
	make_empty(tree);
	printf("--------------平衡二叉树被置空后--------------\n");
	printf("树的高度：%d \n", get_height(tree));
}

int main()
{
	test();
	system("pause");
	return 0;
}