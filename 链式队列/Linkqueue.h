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
	//链表队列数据类型
	struct LinkQueue
	{
		struct QueueNode  head;//头结点
		int size;
		struct QueueNode* rear;//尾结点
	};

	typedef void* Queue;
	//初始化
	Queue Init_LinkQueue();
	//入队
	void Push_LinkQueue(Queue queue,void* data);
	//出队
	void Pop_LinkQueue(Queue queue);
	//获取队头元素
	void* Top_LinkQueue(Queue queue);
	//获取队尾元素
	void* Back_LinkQueue(Queue queue);
	//获取队列大小
	int Size_LinkQueue(Queue queue);
	//销毁队列
	void Destroy_LinkQueue(Queue queue);
#ifdef __cplusplus
}
#endif