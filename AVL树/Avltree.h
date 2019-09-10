#include <stdlib.h>
#ifndef _Avltree_H
#ifdef __cplusplus
extern "C" {
#endif 
	struct AvlNode;
	typedef struct AvlNode* Position;
	typedef struct AvlNode* AvlTree;
	typedef int ElementType;
	//��AVL���ÿ�
	AvlTree make_empty(AvlTree tree);
	//AVL���Ĳ���
	Position find(ElementType x, AvlTree tree);
	//����AVL������Сֵ
	Position find_Min(AvlTree tree);
	//����AVL�������ֵ
	Position find_Max(AvlTree tree);
	//AVL���Ĳ���
	AvlTree insert(ElementType x, AvlTree tree);
	//AVL���ڵ��ɾ��
	AvlTree _delete(ElementType x, AvlTree tree);
	//��ȡAVL���ڵ������
	ElementType retrieve(Position p);
	//AVL���ҵ���ת
	Position SingleRotateWithRight(Position p1);
	//AVL������ת
	Position SingleRotateWithLeft(Position p1);
	//AVL������˫��ת
	Position DoubleRotateWithRight(Position p1);
	//AVL������˫��ת
	Position DoubleRotateWithLeft(Position p1);
	//��ȡAVL���ĸ߶�
	int get_height(Position p);
	//����ƽ�������
	//void proorder_foreach(AvlTree tree, void(*Foreach)(ElementType));
	void proorder_foreach(AvlTree tree);
	////�������������ֵ
	//int max(int a, int b);

#ifdef __cplusplus
}
#endif 
#endif // !_Avltree_H

