#define _CRT_SECURE_NO_WANRNINGS

#ifdef __cplusplus
extern "C" {
#endif

#include<stdio.h>
#include<stdlib.h>

	struct LinkNode
	{
		void** data;
		struct LinkNode* pre;
		struct LinkNode* next;
	};

	struct LinkList
	{
		struct LinkNode Node;
		int size;
	};
	//初始化链表
	void* Init_LinkList();
	//插入节点
	void Insert_LinkList(void* list, int pos, void* data);
	//遍历链表
	void Foreach_LinkList(void* list, void(*_callback)(void*));
	//删除节点
	void Remove_LinkList(void* list, int pos);

#ifdef __cplusplus
}
#endif