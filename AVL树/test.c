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
	//ƽ��������ı���
	proorder_foreach(tree);
	//AVL���ڵ��ɾ��
	tree = _delete(5,tree);
	//ƽ��������ı���
	printf("\n-----------------ɾ��5�ڵ��-----------------\n");
	proorder_foreach(tree);
	//AVL���Ĳ���
	struct AvlNode* node = find(2,tree);
	printf("\n���ҵ�2�ڵ㣺%d\n", retrieve(node));
	//����AVL������Сֵ
	struct AvlNode* node_min = find_Min(tree);
	printf("���ҵ���Сֵ�ڵ㣺%d\n", retrieve(node_min));
	//����AVL�������ֵ
	struct AvlNode* node_max = find_Max(tree);
	printf("���ҵ����ֵ�ڵ㣺%d\n", retrieve(node_max));
	printf("���ĸ߶ȣ�%d \n", get_height(tree));
	//��AVL���ÿ�
	make_empty(tree);
	printf("--------------ƽ����������ÿպ�--------------\n");
	printf("���ĸ߶ȣ�%d \n", get_height(tree));
}

int main()
{
	test();
	system("pause");
	return 0;
}