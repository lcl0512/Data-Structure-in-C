#define _CRT_SECURE_NO_WARNINGS
#include"linkList.h"

struct Person
{
	char name[64];
	int age;
};

void print(void* data)
{
	struct Person* p = (struct Person*)data;
	printf("name:%s\n age:%d\n", p->name, p->age);
}

int compare(void* d1, void* d2)
{
	struct Person* p1 = (struct Person*)d1;
	struct Person* p2 = (struct Person*)d2;
	return  strcmp(p1->name , p2->name)==0&&p1->age == p2->age;
}
void test()
{
	//创建链表
	LinkList list = Init_LinkList();

	//创建数据
	struct Person p1 = { "dhfa",1 };
	struct Person p2 = { "afds",2 };
	struct Person p3 = { "aaa",3};
	struct Person p4 = { "edd",4 };
	struct Person p5 = { "yeks",5};
	struct Person p6 = { "qwer",6 };
	struct Person p7 = { "zcfd",7 };

	//插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 3, &p2);
	Insert_LinkList(list, 2, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 5, &p5);
	Insert_LinkList(list, 5, &p6);
	Insert_LinkList(list, 7, &p7);//4 1 2 3  5 6 7
	//遍历链表
	Foreach(list, print);
	
	struct Person p = { "qwer",6 };
	RemoveByValue_LinkList(list, &p, compare);
	printf("--------------------\n");
	Foreach(list, print);

	Clear_LinkList(list);
	printf("--------------------\n");
	printf("size:%d\n", Size_LinkList(list));

	Destroy_LinkList(list);

}
int main()
{
	test();
	system("pause");
	return 0;
}