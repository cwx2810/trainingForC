#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"

int Fibonacci(int k, int m)//�ݹ���k��쳲��������еĵ�mλ 
{
	if(k<1 || m<0)//�߽��� 
 		return 0;
 		
	if(m < k-1)//�����ڶ�λ֮ǰ�Ķ���0 
		return 0;
	else if(m == k-1)//�����ڶ�λ��1 
		return 1;
	else
	{
		int value = 0;
		for(int i=1; i<=k; i++)
			value += Fibonacci(k, m-i);
		return value;
	}
}

int Fibonacci2(int k, int m)//������ 
{
	int fib[m+1];
	if(k<1 || m<0)
		return 0;
	
	int i=0;
	while(i<k-1)//�����ڶ�λ֮ǰ�Ķ���0 
	{
		fib[i] = 0;
		i++;
	}
	fib[i] = 1;//�����ڶ�λk-1��1 
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
