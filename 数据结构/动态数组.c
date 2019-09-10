#define _CRT_SECURE_NO_WARNINGS
#include"DynamicArray.h"

struct Person
{
	char name[64];
	int age;
};
void print(void *data)
{
	struct Person* person = (struct Person*)data;
	printf("name:%s\n age:%d\n", person->name, person->age);
}

int compare(void* d1, void* d2)
{
	struct Person* p1 = (struct Person*)d1;
	struct Person* p2 = (struct Person*)d2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{
	DynamicArray *arr = Init_DynamicArray(5);
	struct Person p1={"aaa",18 };
	struct Person p2 = { "aba",18 };
	struct Person p3 = { "fff",16 };
	struct Person p4 = { "dss",13 };
	struct Person p5 = { "tfe",19 };
	struct Person p6 = { "htt",17 };
	Insert_DynamicArray(arr, 100, &p1);
	Insert_DynamicArray(arr, 100, &p2);
	Insert_DynamicArray(arr, 100, &p3);
	Insert_DynamicArray(arr, 100, &p4);
	Insert_DynamicArray(arr, 100, &p5);
	printf("capacity:%d\n", arr->capacity);
	Insert_DynamicArray(arr, 100, &p6);
	printf("capacity:%d\n", arr->capacity);
	Foreach_DynamicArray(arr, print);
	printf("------------------------\n");
	RemoveByPos_DynamicArray(arr, 1);
	Foreach_DynamicArray(arr, print);
	printf("------------------------\n");
	struct Person p = { "aaa",18 };
	RemoveByValue(arr, &p, compare);
	Foreach_DynamicArray(arr, print);
	Destroy_DynamicArray(arr);
}
int main() {

	test();
	system("pause");
	return 0;
}