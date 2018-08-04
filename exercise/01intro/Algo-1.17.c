#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"

int Fibonacci(int k, int m)//递归求k阶斐波那契数列的第m位 
{
	if(k<1 || m<0)//边界检查 
 		return 0;
 		
	if(m < k-1)//倒数第二位之前的都是0 
		return 0;
	else if(m == k-1)//倒数第二位是1 
		return 1;
	else
	{
		int value = 0;
		for(int i=1; i<=k; i++)
			value += Fibonacci(k, m-i);
		return value;
	}
}

int Fibonacci2(int k, int m)//迭代求 
{
	int fib[m+1];
	if(k<1 || m<0)
		return 0;
	
	int i=0;
	while(i<k-1)//倒数第二位之前的都是0 
	{
		fib[i] = 0;
		i++;
	}
	fib[i] = 1;//倒数第二位k-1是1 
	i++;
	
	while(i<=m)
	{
		fib[i] = 0;
		for(int j=i-1; j>=i-k; j--)
			fib[i] += fib[j];
		i++;
	}
	return fib[m];
}

int main(int argc, char** argv)
{
	int k=3;
	int m=10;
	printf("%d\n", Fibonacci2(3, 10));
	return 0;
}
