#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void binary_to_ascii(unsigned int value);
long factorial2(int a);
long factorial(int a);
int main()
{

	binary_to_ascii(1234);
	printf("\n");
	system("pause");
	return 0;
}

void binary_to_ascii(unsigned int value)
{
	unsigned int quotient;
	quotient = value / 10;
	if (quotient != 0)
		binary_to_ascii(quotient);
	putchar(value % 10 + '0');
}
//递归计算阶乘
long factorial(int a)
{
	if (a <= 0)
		return 1;
	else
		return a * factorial(a - 1);
}

//迭代计算阶乘
long factorial2(int a)
{
	int result = 1;
	while (a > 0)
	{
		result *= a;
		--a;
	}
	return result;
}

//用递归计算斐波那契数
long fibonacci(int n)
{
	if (n <= 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

//用迭代计算斐波那契数
//时间复杂度O(n)，空间复杂度O(1)
long fibonacci2(int n)
{
	int result;
	int previous_result;
	int next_order_result;
	result = previous_result = 1;

	while (n > 2)
	{
		n -= 1;
		next_order_result = previous_result;
		previous_result = result;
		result = previous_result + next_order_result;
	}
	return result;


}