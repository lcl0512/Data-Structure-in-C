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
	//��ʼ������
	void* Init_LinkList();
	//����ڵ�
	void Insert_LinkList(void* list, int pos, void* data);
	//��������
	void Foreach_LinkList(void* list, void(*_callback)(void*));
	//ɾ���ڵ�
	void Remove_LinkList(void* list, int pos);

#ifdef __cplusplus
}
#endif