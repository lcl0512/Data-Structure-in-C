#define _CRT_SECURE_NO_WANRNINGS
#include<stdio.h>
#include<stdlib.h>
#include"dblist.h"

struct Person
{
	char name[8];
	int age;
};

void print(void *data)
{
	struct Person* pdata = (struct Person*)data;
	if(pdata != NULL)
	{
		printf("name:%s\n age:%d\n", pdata->name, pdata->age);
	}
}
void test()
{
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "aaa",20 };
	struct Person p3 = { "aaa",30 };
	struct Person p4 = { "aaa",40 };

	void* list = Init_LinkList();
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	printf("------------------------\n");
	Foreach_LinkList(list, print);

	Remove_LinkList(list, 1);
	printf("-----------------------------\n");
	Foreach_LinkList(list, print);
}
int main()
{
	test();
	system("pause");
	return 0;
}