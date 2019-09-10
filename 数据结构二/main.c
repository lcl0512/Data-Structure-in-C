#include"SeqStack.h"
#include<stdio.h>

struct Person
{
	char name[64];
	int age;
};

void print(void *data)
{
	struct Person* pdata = (struct Person*)data;
	printf("name:%s\nage:%d\n", pdata->name, pdata->age);
}
void test()
{
	struct SeqStack* stack= Init_SeqStack();
	//初始化数据
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "bbb",20 };
	struct Person p3 = { "ccc",30 };
	struct Person p4 = { "ddd",40 };
	struct Person p5 = { "eee",50 };
	struct Person p6 = { "fff",60 };
	//插入数据
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);
	Push_SeqStack(stack, &p6);
	
	//打印数据
	while (stack->size > 0)
	{
		struct Person* p = Top_SeqStack(stack);
		print(p);
		Pop_SeqStack(stack);
	}
	Destroy_SeqStack(stack);

}

int main()
{
	test();
	system("pause");
	return 0;
}