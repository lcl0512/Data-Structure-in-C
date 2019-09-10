#include"LinkStack.h"

typedef void* Stack;
//初始化栈
Stack Init_LinkStack()
{
	struct LinkStack* stack = malloc(sizeof(struct LinkStack));
	if (NULL == stack)
	{
		return NULL;
	}
	stack->head.next= NULL;
	stack->size = 0;
	return stack;
}
//入栈
void Push_LinkStack(Stack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct LinkStack* pstack = (struct LinkStack*)stack;
	struct LinkNode* p = (struct LinkNode*)data;

	p->next = pstack->head.next;
	pstack->head.next = p;

	++(pstack->size);
}
//出栈
void Pop_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	struct LinkStack* pstack = (struct LinkStack*)stack;
	if (pstack->size == 0)
	{
		return;
	}
	struct LinkNode* node = pstack->head.next;
	pstack->head.next = node->next;
	--(pstack->size);
}

//获取栈顶
void* Top_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	struct LinkStack* pstack = (struct LinkStack*)stack;
	if (pstack->size == 0)
	{
		return NULL;
	}
	return pstack->head.next;
}

int Size_Link(Stack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LinkStack* pstack = (struct LinkStack*)stack;
	return pstack->size;
}
//销毁栈
void Destroy_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	free(stack);
	stack = NULL;
}

//获取栈的大小
int Size_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LinkStack* st = (struct LinkStack*)stack;
	return st->size;
}
