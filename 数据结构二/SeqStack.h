#pragma once

#include<stdlib.h>
#ifdef __cplusplus
extern"C" {
#endif // __cplusplus

#define MAX 1024
	struct SeqStack
	{
		void *data[MAX];
		int size;
	};
	typedef void* Stack;
	//初始化栈
	Stack Init_SeqStack();
	//入栈
	void Push_SeqStack(Stack stack,void* data);
	//出栈
	void Pop_SeqStack(Stack stack);
	//获取栈顶
	void* Top_SeqStack(Stack stack);
	//获取栈的大小
	int Size_SeqStack(Stack stack);
	//销毁栈
	void Destroy_SeqStack(Stack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
