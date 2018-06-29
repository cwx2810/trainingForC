#include "SequenceArray.c"

int main(int argc, char **argv)
{
	Array A;
	
	printf("InitArray测试，以二维数组为例...\n");
	{
		printf("初始化一个2行3列的二维数组A\n");
		InitArray(&A, 2, 2, 3);
		printf("\n");
	}
	PressEnter;
	
	printf("AssignArray测试...\n");
	{
		int e = 1;
		for(int i=0; i<A.bounds[0]; i++)
		{
			for(int j=0; j<A.bounds[1]; j++)
			{
				printf("赋值：A[%d][%d] = %d\n", i, j, e);
				AssignArray(&A, e, i, j);
				e++;
			}
		}
		printf("\n");
	}
	PressEnter;
	
	printf("AssignPrint测试...\n");
	{
		printf("A = ");
		ArrayPrint(A);
		printf("\n");
	}
	PressEnter;
	
	printf("LocateArray,ValueArray测试...\n");
	{
		int e;
		printf("获取下标为(1,1)的元素的值\n");
		ValueArray(A, &e, 1, 1);
		printf("A[1][1] = %d\n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("DestroyArray测试...\n");
	{
		DestroyArray(&A);
		A.dim ? printf("存在\n") : printf("不存在\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
