#include <stdio.h>
#include <stdlib.h>

struct Person
{
	int age;
	struct Person* left;
	struct Person* right;
};
//先序遍历
void preorderTravaersal(struct Person *p)
{
	if (p)
	{
		printf("%d  ", p->age);
		preorderTravaersal(p->left);
		preorderTravaersal(p->right);
	}
}
//中序遍历
void inorderTravaersal(struct Person *p)
{
	if (p)
	{
		inorderTravaersal(p->left);
		printf("%d  ", p->age);
		inorderTravaersal(p->right);
	}
}
//后序遍历
void postorderTravaersal(struct Person *p)
{
	if (p)
	{
		postorderTravaersal(p->left);
		postorderTravaersal(p->right);
		printf("%d  ", p->age);
	}
}

//求二叉树的叶子数
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

//求树的高度
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

//二叉树的拷贝
struct Person* copy_bintree(struct Person* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	//递归遍历左右子树
	struct Person* lNode=copy_bintree(root->left);
	struct Person* rNode=copy_bintree(root->right);
	//创建新的二叉树根节点
	struct Person *node = (struct Person*)malloc(sizeof(struct Person));
	node->left = lNode;
	node->right = rNode;
	node->age = root->age;

	return node;
}
//二叉树的销毁
void Remove_BinTree(struct Person* root)
{
	if (NULL == root)
	{
		return;
	}
	//递归销毁左右子树
	Remove_BinTree(root->left);
	Remove_BinTree(root->right);
	//释放根节点
	free(root);
}
void test()
{
	//节点初始化
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
	//二叉树的建立
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

	printf("--------先序遍历--------\n");
	preorderTravaersal(&p1);
	printf("\n");
	printf("--------中序遍历--------\n");
	inorderTravaersal(&p1);
	printf("\n");
	printf("--------后序遍历--------\n");
	postorderTravaersal(&p1);
	printf("\n");
	//struct Person* pnew = copy_bintree(&p1);
	//printf("--------先序遍历新拷贝的子树--------\n");
	//preorderTravaersal(pnew);
	//printf("\n");
	////二叉树的销毁
	//Remove_BinTree(pnew);

	//int count = 0;
	//treeLives(&p1,&count);
	//printf("二叉树的叶子数：%d\n", count);
	//int h=treeHeight(&p1);
	//printf("树的深度：%d\n", h);
}
int main()
{
	test();
	system("pause");
	return 0;
}