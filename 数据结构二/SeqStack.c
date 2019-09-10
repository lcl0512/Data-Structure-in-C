#include"SeqStack.h"

typedef void* Stack;
//初始化栈
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
//入栈
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
//出栈
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

//获取栈顶
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
//销毁栈
void Destroy_SeqStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	free(stack);
	stack = NULL;

}