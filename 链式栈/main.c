#include"LinkStack.h"
#include<stdio.h>


struct Person
{
	struct LinkNode next;
	char name[64];
	int age;
};

void test()
{
	Stack stack=Init_LinkStack();

	//初始化数据
	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL, "bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL, "eee",50 };
	struct Person p6 = { NULL,"fff",60 };
	//插入数据
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);
	Push_LinkStack(stack, &p4);
	Push_LinkStack(stack, &p5);
	Push_LinkStack(stack, &p6);

	struct Person* p = (struct Person*)Top_LinkStack(stack);
	//输出栈中所有元素
	//打印数据
	while (Size_LinkStack(stack) > 0)
	{
		struct Person* p = (struct Person*)Top_LinkStack(stack);
		printf("name: %s \nage: %d\n", p->name, p->age);
		Pop_LinkStack(stack);
	}
	printf("Size:%d", Size_LinkStack(stack));
	Destroy_LinkStack(stack);
}
int main()
{
	test();
	system("pause");
	return 0;
}