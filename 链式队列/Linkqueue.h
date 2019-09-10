#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifdef __cplusplus
extern"C" {
#endif
	struct QueueNode
	{
		struct QueueNode *next;
	};
	//���������������
	struct LinkQueue
	{
		struct QueueNode  head;//ͷ���
		int size;
		struct QueueNode* rear;//β���
	};

	typedef void* Queue;
	//��ʼ��
	Queue Init_LinkQueue();
	//���
	void Push_LinkQueue(Queue queue,void* data);
	//����
	void Pop_LinkQueue(Queue queue);
	//��ȡ��ͷԪ��
	void* Top_LinkQueue(Queue queue);
	//��ȡ��βԪ��
	void* Back_LinkQueue(Queue queue);
	//��ȡ���д�С
	int Size_LinkQueue(Queue queue);
	//���ٶ���
	void Destroy_LinkQueue(Queue queue);
#ifdef __cplusplus
}
#endif