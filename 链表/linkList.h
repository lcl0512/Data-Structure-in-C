#pragma

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	//����ڵ�����
	struct LinkNode
	{
		void* data;
		struct LinkNode *next;
	};

	//������������
	struct LList
	{
		struct LinkNode head;
		int size;
	};

	typedef void* LinkList;
	typedef void(*FOREACH)(void*);
	typedef int(*COMPARE)(void* ,void*);

	//��ʼ������
	LinkList Init_LinkList();

	//����ڵ�
	void Insert_LinkList(LinkList list,int pos,void *data );

	//��������
	void Foreach(LinkList list, FOREACH MyForeach);

	//��λ��ɾ��
	void RemoveByPos_LinkList(LinkList list, int pos);

	//��ֵɾ��
	void RemoveByValue_LinkList(LinkList list, void* data,COMPARE compare);

	//�������
	void Clear_LinkList(LinkList list);

	//�����С
	int Size_LinkList(LinkList list);

	//��������
	void Destroy_LinkList(LinkList list);

#ifdef __cplusplus
 }
#endif // __cplusplus