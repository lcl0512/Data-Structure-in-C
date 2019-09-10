#pragma once
#include"LinkQueue.h"
//初始化
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
//入队
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
//出队
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
//获取队头元素
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
//获取队尾元素
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
//获取队列大小
int Size_LinkQueue(Queue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	struct LinkQueue* node = (struct LinkQueue*)queue;
	return node->size;
}
//销毁队列
void Destroy_LinkQueue(Queue queue)
{

	if (NULL == queue)
	{
		return;
	}
	free(queue);
	queue = NULL;
}