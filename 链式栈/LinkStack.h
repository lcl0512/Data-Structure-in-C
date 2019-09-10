#pragma once

#include<stdlib.h>
#ifdef __cplusplus
extern"C" {
#endif // __cplusplus

	//链表节点
	struct LinkNode
	{
		struct LinkNode* next;
	};
	//头节点
	struct LinkStack
	{
		struct LinkNode head;
		int size;
	};
	typedef void* Stack;
	//初始化栈
	Stack Init_LinkStack();
	//入栈
	void Push_LinkStack(Stack stack,void* data);
	//出栈
	void Pop_LinkStack(Stack stack);
	//获取栈顶
	void* Top_LinkStack(Stack stack);
	//获取栈的大小
	int Size_LinkStack(Stack stack);
	//销毁栈
	void Destroy_LinkStack(Stack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
