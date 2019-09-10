#include "_Tree.h"
#include <stdio.h>
#include <stdlib.h>
void print()
{

}
void test()
{
	SearchTree tree=NULL;
	tree = insert(6, tree);
	tree = insert(7, tree);
	tree = insert(3, tree);
	tree = insert(4, tree);
	tree = insert(2, tree);
	proorder_foreach(tree);
}
int main()
{
	test();
	system("pause");
	return 0;
}