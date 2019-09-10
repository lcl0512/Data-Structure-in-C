#include"linkList.h"
LinkList Init_LinkList()
{
	struct LList* list = malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}
	list->head.next = NULL;
	list->size = 0;
	return list;
}

//插入节点
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LList *MyList = (struct LList*)list;
	if (pos<0 || pos>MyList->size)
	{
		pos = MyList->size;
	}

	//查找节点
	struct LinkNode* pCurrent = &(MyList->head);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = pCurrent->next;
	pCurrent->next= newNode;
	MyList->size++;
}

//遍历链表FOREACH
void Foreach(LinkList list, FOREACH MyForeach)//回调函数
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == MyForeach)
	{
		return;
	}

	struct LList *MyList = (struct LList*)list;
	struct LinkNode *pCurrent= MyList->head.next;
	while(pCurrent!=NULL)
	{
		MyForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//按位置删除
void RemoveByPos_LinkList(LinkList list, int pos)
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

	struct LinkNode *pCurrent = &(Mylist->head);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;
	Mylist->size--;
}

//按值删除
void RemoveByValue_LinkList(LinkList list, void* data, COMPARE compare)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	struct LList* Mylist = (struct LList*)list;
	struct LinkNode* pre = (&Mylist->head);
	struct LinkNode* pCurrent = pre->next;

	while (pCurrent != NULL)
	{
		if(compare(pCurrent->data,data))
		{
			pre->next= pCurrent->next;
			free(pCurrent);
			pCurrent = NULL;
			Mylist->size--;
			break;
		}
		pre = pCurrent;
		pCurrent = pre->next;
	}
}

//清空链表
void Clear_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}
	struct LList* mylist = (struct LList*)list;
	struct LinkNode* pCurrent = mylist->head.next;

	while (pCurrent != NULL)
	{
		struct LinkNode  *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	mylist->size = 0;
}

//获取链表大小
int Size_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return -1;
	}
	struct LList* mylist = (struct LList*)list;

	mylist->head.next = NULL;
	return mylist->size;
}

//销毁链表
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}
	
	Clear_LinkList(list);
	free(list);
	list = NULL;
}