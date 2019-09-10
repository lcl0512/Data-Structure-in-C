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
	//�洢����Ԫ���׵�ַ
	void** addr;
	//�洢�����ڴ�����������ɶ��ٸ�Ԫ��
	int capacity;
	//�洢����Ԫ�ظ���
	int size;
}DynamicArray;

//��ʼ������
DynamicArray* Init_DynamicArray(int capacity);
//�������
void Insert_DynamicArray(DynamicArray *arr, int pos, void* data);
//��������
void Foreach_DynamicArray(DynamicArray *arr, void(*_callback)(void*));
//��λ��ɾ������Ԫ��
void RemoveByPos_DynamicArray(DynamicArray* arr, int pos);
//��ֵɾ������Ԫ��
void RemoveByValue(DynamicArray *arr, void* data, int(*compare)(void*, void*));
//��������
void Destroy_DynamicArray(DynamicArray *arr);
#ifdef __cplusplus
}
#endif

#endif // !DYNAMICARRAY_H