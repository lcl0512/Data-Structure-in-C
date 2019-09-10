#include"dblist.h"

void* Init_LinkList()
{
	struct LinkList* list = malloc(sizeof(struct LinkList));
	if (NULL == list)
	{
		return NULL;
	}
	list->Node.data = NULL;
	list->Node.next = NULL;
	list->Node.pre = NULL;
	list->size = 0;
	return list;
}

void Insert_LinkList(void* list, int pos, void* data)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LinkList* Mylist = (struct LinkList*)list;
	if (pos < 0 || pos > Mylist->size)
	{
		pos = Mylist->size;
	}
	struct LinkNode* pCurrent = &(Mylist->Node);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->pre = NULL;
	newNode->next = NULL;

	newNode->next = pCurrent->next;
	newNode->pre = pCurrent;
	pCurrent->next = newNode;
	++(Mylist->size);
}

void Foreach_LinkList(void* list, void(*_callback)(void*))
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == _callback)
	{
		return;
	}
	struct LinkList* Mylist = (struct LinkList*)list;
	struct LinkNode* pCurrent = &(Mylist->Node);
	while (pCurrent != NULL)
	{
		_callback(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void Remove_LinkList(void* list, int pos)
{
	if (NULL == list)
	{
		return;
	}
	struct LinkList* Mylist = (struct LinkList*)list;
	if (pos<0 || pos>Mylist->size)
	{
		pos = Mylist->size;
	}
	struct LinkNode* pCurrent = (Mylist->Node.next);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	pCurrent->pre->next = pCurrent->next;
	pCurrent->next->pre = pCurrent->pre;
	free(pCurrent);
	--(Mylist->size);

	pCurrent->data = NULL;
	pCurrent->next = NULL;
	pCurrent->pre = NULL;
}