#pragma

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	//链表节点类型
	struct LinkNode
	{
		void* data;
		struct LinkNode *next;
	};

	//链表数据类型
	struct LList
	{
		struct LinkNode head;
		int size;
	};

	typedef void* LinkList;
	typedef void(*FOREACH)(void*);
	typedef int(*COMPARE)(void* ,void*);

	//初始化链表
	LinkList Init_LinkList();

	//插入节点
	void Insert_LinkList(LinkList list,int pos,void *data );

	//遍历链表
	void Foreach(LinkList list, FOREACH MyForeach);

	//按位置删除
	void RemoveByPos_LinkList(LinkList list, int pos);

	//按值删除
	void RemoveByValue_LinkList(LinkList list, void* data,COMPARE compare);

	//清空链表
	void Clear_LinkList(LinkList list);

	//链表大小
	int Size_LinkList(LinkList list);

	//销毁链表
	void Destroy_LinkList(LinkList list);

#ifdef __cplusplus
 }
#endif // __cplusplus