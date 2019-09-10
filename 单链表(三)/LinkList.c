#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ڵ�ṹ
struct LinkNode
{
	struct LinkNode *next;
};

//�������ݽṹ
struct LList
{
	struct LinkNode head;//ͷ���
	int size;
};
 
typedef void* LinkList;

//��ʼ������
LinkList Init_LinkList()
{
	struct LList* list =malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}
	list->head.next = NULL;
	list->size = 0;
	return list;
}

//����ڵ�
void Insert_LinkList(LinkList list,int pos,void* data)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LList* Mylist = (struct LList*)list;
	struct LinkNode* Mynode = (struct LinkNode*)data;
	if (pos<0 || pos>Mylist->size)
	{
		pos = Mylist->size;
	}

	struct LinkNode* pCurrent = &(Mylist->head);

	for (int i = 0; i <pos; ++i)
	{
		pCurrent = pCurrent->next;
	}
	
	Mynode->next = pCurrent->next;
	pCurrent->next = Mynode;
	Mylist->size++;
}

//��������
void Foreach_LinkList(LinkList list,void(*foreach)(void*))
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == foreach)
	{
		return;
	}
	struct LList* mylist = (struct LList*)list;
	struct LinkNode* pCurrent = mylist->head.next;

	while (pCurrent != NULL)
	{
		struct LinkNode* pNext = pCurrent->next;
		foreach(pCurrent);
		pCurrent = pNext;
	}
}

//ͨ��λ��ɾ���ڵ�
void RemoveByPos_LinkList(LinkList *list, int pos)
{
	if (NULL == list)
	{
		return;
	}
	struct LList* Mylist = (struct LList*)list;
	if (pos<0 || pos>Mylist->size-1)
	{
		return;
	}
	struct LinkNode* pCurrent = &(Mylist->head);
	//�ҵ���ɾ���Ľڵ��ǰһ���ڵ�
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�����ɾ���Ľڵ�
	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;
	Mylist->size--;
}

void Destroy_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}
	free(list);
	list = NULL;
	
}
struct Person
{
	struct LinkNode node;
	char name[64];
	int age;
};

void print(void* list)
{
	struct Person* p = (struct Person*)list;
	printf("name:%s \n age:%d\n", p->name, p->age);

}

void test()
{
	//��ʼ��
	LinkList list = Init_LinkList();
	//��������
	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL,"bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL,"eee",50 };
	struct Person p6 = { NULL,"fff",60 };
	//��������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);
	//��������
	Foreach_LinkList(list, print);
	//ɾ���ڵ�
	RemoveByPos_LinkList(list, 3);
	printf("-------------------------\n");
	Foreach_LinkList(list, print);
}

int main()
{
	test();
	system("pause");
	return 0;
}

