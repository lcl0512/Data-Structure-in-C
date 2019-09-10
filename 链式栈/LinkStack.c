#include"LinkStack.h"

typedef void* Stack;
//��ʼ��ջ
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
//��ջ
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
//��ջ
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

//��ȡջ��
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
//����ջ
void Destroy_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return;
	}
	free(stack);
	stack = NULL;
}

//��ȡջ�Ĵ�С
int Size_LinkStack(Stack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LinkStack* st = (struct LinkStack*)stack;
	return st->size;
}
