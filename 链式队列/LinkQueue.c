#pragma once
#include"LinkQueue.h"
//��ʼ��
Queue Init_LinkQueue()
{
	struct LinkQueue* queue = malloc(sizeof(struct LinkQueue));
	if (NULL == queue)
	{
		return NULL;
	}
	queue->head.next = NULL;
	queue->rear = &(queue->head);
	queue->size = 0;
	return queue;
}
//���
void Push_LinkQueue(Queue queue, void* data)
{
	if (NULL == queue)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	struct QueueNode* NewNode = (struct QueueNode*)data;

	node->rear->next = NewNode;
	node->rear = NewNode;
	++(node->size);
}
//����
void Pop_LinkQueue(Queue queue)
{
	if (NULL == queue)
	{
		return;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	if (node->size == 0)
	{
		return;
	}
	if (node->size == 1)
	{
		node->head.next = NULL;
		node->rear = &(node->head);
		node->size--;
		return;
	}
	struct QueueNode* p = node->head.next;
	node->head.next = p->next;
	node->size--;
}
//��ȡ��ͷԪ��
void* Top_LinkQueue(Queue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	if (node->size == 0)
	{
		return NULL;
	}
	return node->head.next;
}
//��ȡ��βԪ��
void* Back_LinkQueue(Queue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	if (node->size == 0)
	{
		return NULL;
	}
	return node->rear;
}
//��ȡ���д�С
int Size_LinkQueue(Queue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	return node->size;
}
//���ٶ���
void Destroy_LinkQueue(Queue queue)
{

	if (NULL == queue)
	{
		return;
	}
	free(queue);
	queue = NULL;
}