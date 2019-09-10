#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#pragma

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct DynamicArray {
	//存储数组元素首地址
	void** addr;
	//存储数据内存中最大能容纳多少个元素
	int capacity;
	//存储数组元素个数
	int size;
}DynamicArray;

//初始化数组
DynamicArray* Init_DynamicArray(int capacity);
//数组插入
void Insert_DynamicArray(DynamicArray *arr, int pos, void* data);
//遍历数组
void Foreach_DynamicArray(DynamicArray *arr, void(*_callback)(void*));
//按位置删除数组元素
void RemoveByPos_DynamicArray(DynamicArray* arr, int pos);
//按值删除数组元素
void RemoveByValue(DynamicArray *arr, void* data, int(*compare)(void*, void*));
//销毁数组
void Destroy_DynamicArray(DynamicArray *arr);
#ifdef __cplusplus
}
#endif

#endif // !DYNAMICARRAY_H