#define _CRT_SECURE_NO_WARNINGS
#include"DynamicArray.h"
DynamicArray* Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	arr->capacity = capacity;
	arr->addr = malloc(sizeof(void*)*arr->capacity);
	arr->size = 0;
	return arr;

}

//数组插入
void Insert_DynamicArray(DynamicArray *arr, int pos, void* data)
{

	if (NULL == data)
	{
		return;
	}
	if (NULL == arr)
	{
		return;
	}
	if (pos < 0 || pos>arr->size)
	{
		pos = arr->size;
	}
	if (arr->size >= arr->capacity)
	{
		int newCapacity = arr->capacity * 2;
		void *newspace = malloc(sizeof(void*)*newCapacity);
		memcpy(newspace, arr->addr, sizeof(void*)*arr->capacity);
		free(arr->addr);
		arr->addr = newspace;
		arr->capacity = newCapacity;
	}
	//移动元素
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}
	arr->addr[pos] = data;
	arr->size++;
}

//遍历数组
void Foreach_DynamicArray(DynamicArray *arr, void(*_callback)(void*))
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL == _callback)
	{
		return;
	}
	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}

}

//按位置删除数组元素
void RemoveByPos_DynamicArray(DynamicArray* arr, int pos)
{
	if (NULL == arr)
	{
		return;
	}
	if (pos<0 || pos>arr->size - 1)
	{
		return;
	}
	for (int i = pos; i < arr->size - 1; ++i)
	{
		arr->addr[i] = arr->addr[i + 1];
	}
	arr->size--;
}

//按值删除数组元素
void RemoveByValue(DynamicArray *arr, void* data, int(*compare)(void*, void*))
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	if (NULL == compare)
	{
		return;
	}
	for (int i = 0; i < arr->size; ++i)
	{
		if (compare(arr->addr[i], data))
		{
			RemoveByPos_DynamicArray(arr, i);
			break;
		}
	}
}

//销毁数组
void Destroy_DynamicArray(DynamicArray *arr)
{
	if (NULL == arr)
	{
		return;
	}
	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}
	free(arr);
	arr = NULL;
}