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
	//��ʼ��ջ
	Stack Init_SeqStack();
	//��ջ
	void Push_SeqStack(Stack stack,void* data);
	//��ջ
	void Pop_SeqStack(Stack stack);
	//��ȡջ��
	void* Top_SeqStack(Stack stack);
	//��ȡջ�Ĵ�С
	int Size_SeqStack(Stack stack);
	//����ջ
	void Destroy_SeqStack(Stack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
