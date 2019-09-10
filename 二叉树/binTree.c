#include <stdio.h>
#include <stdlib.h>

struct Person
{
	int age;
	struct Person* left;
	struct Person* right;
};
//�������
void preorderTravaersal(struct Person *p)
{
	if (p)
	{
		printf("%d  ", p->age);
		preorderTravaersal(p->left);
		preorderTravaersal(p->right);
	}
}
//�������
void inorderTravaersal(struct Person *p)
{
	if (p)
	{
		inorderTravaersal(p->left);
		printf("%d  ", p->age);
		inorderTravaersal(p->right);
	}
}
//�������
void postorderTravaersal(struct Person *p)
{
	if (p)
	{
		postorderTravaersal(p->left);
		postorderTravaersal(p->right);
		printf("%d  ", p->age);
	}
}

//���������Ҷ����
void treeLives(struct Person* node,int *count)
{
	if (node)
	{
		if (!(node->left) && !(node->right))
			++*count;
	}
	if(node->left)
	    treeLives(node->left,count);
	if(node->right)
		treeLives(node->right,count);
}

//int treeLives(struct Person* node)
//{
//	int num=0;
//	if (node)
//	{
//		if (!(node->left) && !(node->right))
//			++num;
//	}
//	if (node->left)
//		treeLives(node->left);
//	if (node->right)
//		treeLives(node->right);
//	return num;
//}

//�����ĸ߶�
int treeHeight(struct Person* node)
{
	int hl=0, hr=0, maxh=0;
	if (node)
	{
		hl = treeHeight(node->left);
		hr = treeHeight(node->right);
		maxh = hl > hr ? hl : hr;
		return maxh + 1;
	}
	else
	{
		return 0;
	}
}

//�������Ŀ���
struct Person* copy_bintree(struct Person* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	//�ݹ������������
	struct Person* lNode=copy_bintree(root->left);
	struct Person* rNode=copy_bintree(root->right);
	//�����µĶ��������ڵ�
	struct Person *node = (struct Person*)malloc(sizeof(struct Person));
	node->left = lNode;
	node->right = rNode;
	node->age = root->age;

	return node;
}
//������������
void Remove_BinTree(struct Person* root)
{
	if (NULL == root)
	{
		return;
	}
	//�ݹ�������������
	Remove_BinTree(root->left);
	Remove_BinTree(root->right);
	//�ͷŸ��ڵ�
	free(root);
}
void test()
{
	//�ڵ��ʼ��
	struct Person p1 = { 1,NULL,NULL };
	struct Person p2 = { 2,NULL,NULL };
	struct Person p3 = { 3,NULL,NULL };
	struct Person p4 = { 4,NULL,NULL };
	struct Person p5 = { 5,NULL,NULL };
	struct Person p6 = { 6,NULL,NULL };
	struct Person p7 = { 7,NULL,NULL };
	struct Person p8 = { 8,NULL,NULL };
	struct Person p9 = { 9,NULL,NULL };
	struct Person p10 = { 10,NULL,NULL };
	struct Person p11 = { 11,NULL,NULL };
	struct Person p12 = { 12,NULL,NULL };
	struct Person p13 = { 13,NULL,NULL };
	//�������Ľ���
	p1.left = &p2;
	p1.right = &p3;
	p2.left = &p4;
	p2.right = &p5;
	p3.left = &p6;
	p3.right = &p7;
	p4.left = &p8;
	p4.right = &p9;
	p5.left = &p10;
	p5.right = &p11;
	p6.left = &p12;
	p6.right = &p13;

	printf("--------�������--------\n");
	preorderTravaersal(&p1);
	printf("\n");
	printf("--------�������--------\n");
	inorderTravaersal(&p1);
	printf("\n");
	printf("--------�������--------\n");
	postorderTravaersal(&p1);
	printf("\n");
	//struct Person* pnew = copy_bintree(&p1);
	//printf("--------��������¿���������--------\n");
	//preorderTravaersal(pnew);
	//printf("\n");
	////������������
	//Remove_BinTree(pnew);

	//int count = 0;
	//treeLives(&p1,&count);
	//printf("��������Ҷ������%d\n", count);
	//int h=treeHeight(&p1);
	//printf("������ȣ�%d\n", h);
}
int main()
{
	test();
	system("pause");
	return 0;
}