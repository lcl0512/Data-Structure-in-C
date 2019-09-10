#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LinkNode
{
	struct LinkNode *next;
};
struct Person
{
	struct LinkNode node;
	char name[64];
	int age;
};

void test()
{
	struct Person p1 = { NULL,"hhh",1 };
	struct Person p2 = { NULL,"aaa",2 };
	struct Person p3 = { NULL,"bbb",3 };
	struct Person p4 = { NULL,"ccc",4};
	struct Person p5 = { NULL,"ddd",5};
	
	struct LinkNode* p_p1 = (struct LinkNode*)&p1;
	struct LinkNode* p_p2 = (struct LinkNode*)&p2;
	struct LinkNode* p_p3 = (struct LinkNode*)&p3;
	struct LinkNode* p_p4 = (struct LinkNode*)&p4;
	struct LinkNode* p_p5 = (struct LinkNode*)&p5;

	p_p1->next = p_p2;
	p_p2->next = p_p3;
	p_p3->next = p_p4;
	p_p4->next = p_p5;
	p_p5->next = NULL;

	struct LinkNode* pCurrent = p_p1;
	while (pCurrent != NULL)
	{
		struct Person* p = (struct Person*)pCurrent;
		printf("name:%s\nage:%d\n", p->name, p->age);
		pCurrent = pCurrent->next;
	}

}
int main()
{
	test();
	system("pause");
	return 0;
}