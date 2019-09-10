#include "Linkqueue.h"

struct Person
{
	struct QueueNode node;
	char name[64];
	int age;
};
void test()
{
	Queue queue = Init_LinkQueue();

	//初始化数据
	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL, "bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL, "eee",50 };
	struct Person p6 = { NULL,"fff",60 };
	//插入数据
	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);
	Push_LinkQueue(queue, &p6);

	struct Person* p = (struct Person*)Top_LinkQueue(queue);
	while (Size_LinkQueue(queue)>0)
	{
		struct Person* p = (struct Person*)Top_LinkQueue(queue);
		printf("name: %s  age: %d  \n", p->name, p->age);
		Pop_LinkQueue(queue);
	}
	Destroy_LinkQueue(queue);
}
int main()
{
	test();
	system("pause");
	return 0;
}