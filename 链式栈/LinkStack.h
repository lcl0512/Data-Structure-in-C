#pragma once

#include<stdlib.h>
#ifdef __cplusplus
extern"C" {
#endif // __cplusplus

	//����ڵ�
	struct LinkNode
	{
		struct LinkNode* next;
	};
	//ͷ�ڵ�
	struct LinkStack
	{
		struct LinkNode head;
		int size;
	};
	typedef void* Stack;
	//��ʼ��ջ
	Stack Init_LinkStack();
	//��ջ
	void Push_LinkStack(Stack stack,void* data);
	//��ջ
	void Pop_LinkStack(Stack stack);
	//��ȡջ��
	void* Top_LinkStack(Stack stack);
	//��ȡջ�Ĵ�С
	int Size_LinkStack(Stack stack);
	//����ջ
	void Destroy_LinkStack(Stack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
