#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdarg.h>

float average(int n_values, ...);
int main()
{
	int aver=average(1, 2, 3, 4, 5, 6, 7, 8);
	//printf("%d\n", aver);
	system("pause");
}

float average(int n_values, ...)
{
	va_list var_arg;
	int count;
	float sum = 0;
	//准备访问可变参数
	va_start(var_arg, n_values);

	//添加取自可变参数列表的值
	for (count = 0; count < n_values; count += 1)
	{
		sum += va_arg(var_arg, int);
	}

	//完成处理可变参数
	va_end(var_arg);
	
	return sum / n_values;
}