#include"SeqStack.h"

typedef void* Stack;
//��ʼ��ջ
Stack Init_SeqStack()
{
	struct SeqStack* stack = malloc(sizeof(struct SeqStack));
	if (NULL == stack)
	{
		return NULL;
	}
	stack->size = 0;
	return stack;

}
//��ջ
void Push_SeqStack(Stack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct SeqStack* mystack = (struct SeqStack*)stack;
	mystack->data[mystack->size++] = data;
}
//��ջ
void Pop_SeqStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	struct SeqStack* mystack = (struct SeqStack*)stack;
	if (mystack->size == 0)
	{
		return;
	}
	mystack->data[--(mystack->size)] = NULL;
}

//��ȡջ��
void* Top_SeqStack(Stack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	struct SeqStack* mystack = (struct SeqStack*)stack;
	if (mystack->size == 0)
	{
		return NULL;
	}
	return mystack->data[mystack->size-1];
}
//����ջ
void Destroy_SeqStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	free(stack);
	stack = NULL;

}