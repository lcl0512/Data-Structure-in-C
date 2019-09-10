#include <stdio.h>
#include <stdlib.h>
#include "Linkstack.h"

struct Person
{
	struct LinkNode head;
	int age;
	struct Person* left;
	struct Person* right;
};
//中序遍历
void inorderTraversal(struct Person* root)
{
	if (NULL == root)
	{
		return;
	}
	struct Person* r = root;
	//创建初始化堆栈
	Stack stack = Init_LinkStack();

	while (r || !isEmpty(stack))
	{
		//一直向左将节点压入栈中
		while (r)
		{
			Push_LinkStack(stack, r);
			r = r->left;
		}
		//如果栈非空，弹出栈顶，节点向右子树移动
		if (!isEmpty(stack))
		{
			r=Top_LinkStack(stack);
			Pop_LinkStack(stack);
			printf("%d  ", r->age);  
			r = r->right;
		}
	}
}
//先序遍历
void preorderTraversal(struct Person* root)
{
	if (NULL == root)
	{
		return;
	}
	struct Person* r = root;
	//创建初始化堆栈
	Stack stack = Init_LinkStack();

	while (r || !isEmpty(stack))
	{
		//一直向左将左子树压入栈中
		while (r)
		{
			printf("%d  ", r->age);
			Push_LinkStack(stack, r);
			r = r->left;
		}
		//如果栈非空，弹出栈顶，节点向右子树移动
		if (!isEmpty(stack))
		{
			r = Top_LinkStack(stack);
			Pop_LinkStack(stack);
			r = r->right;
		}
	}
}

//后序遍历
void postorderTraversal(struct Person* root)
{
	if (NULL == root)
	{
		return;
	}
	struct Person* r = root;
	//作为节点是否访问的标志
	struct Person* p = NULL;
	//创建初始化堆栈
	Stack stack = Init_LinkStack();

	while (r || !isEmpty(stack))
	{
		//一直向左将左子树压入栈中
		while (r)
		{
			Push_LinkStack(stack, r);
			r = r->left;
		}
		//如果栈非空，获取栈顶
		r = Top_LinkStack(stack);
		if (r->right && r->right != p)//右子树存在，未被访问
		{
			r = r->right;
		}
		else 
		{
			Pop_LinkStack(stack);
			printf("%d  ", r->age);
			p = r;         //记录最近访问过的节点
			r = NULL;    //节点访问完后，重置r指针
		}
	}
}
void test()
{
	struct Person p1 = { 0,1,NULL,NULL };
	struct Person p2 = { 0,2,NULL,NULL };
	struct Person p3 = { 0,3,NULL,NULL };
	struct Person p4 = { 0,4,NULL,NULL };
	struct Person p5 = { 0,5,NULL,NULL };
	struct Person p6 = { 0,6,NULL,NULL };
	struct Person p7 = { 0,7,NULL,NULL };
	struct Person p8 = { 0,8,NULL,NULL };
	struct Person p9 = { 0,9,NULL,NULL };
	struct Person p10 = { 0,10,NULL,NULL };
	struct Person p11 = { 0,11,NULL,NULL };
	struct Person p12 = { 0,12,NULL,NULL };
	struct Person p13 = { 0,13,NULL,NULL };
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
	printf("---------非递归先序遍历二叉树---------\n");
	preorderTraversal(&p1);
	printf("\n");
	printf("---------非递归中序遍历二叉树---------\n");
	inorderTraversal(&p1);
	printf("\n");
	printf("---------非递归后序遍历二叉树---------\n");
	postorderTraversal(&p1);
	printf("\n");
}
int main(int argc, char** argv)
{
	test();
	system("pause");
	return 0;
}