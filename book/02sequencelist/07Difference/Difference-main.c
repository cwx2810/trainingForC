#include <stdio.h>
#include "Difference.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	int L;
	FILE *fp;
	int A[100],B[100];
	int len_A = 3;
	int len_B = 5;
	
	fp = fopen("TestData.txt", "r");//读文本文件赋值给数组AB 
	for(int i=0; i<len_A; i++)
		Scanf(fp, "%d", &A[i]);
	for(int i=0; i<len_B; i++)
		Scanf(fp, "%d", &B[i]);
	fclose(fp);
	
	printf("A = ");//打印AB 
	for(int i=0; i<len_A; i++)
		PrintElem(A[i]);
	printf("\n");
	printf("B = ");
	for(int i=0; i<len_B; i++)
		PrintElem(B[i]);
	printf("\n");
	
	printf("S = (A-B) U (B-A) = ");//打印Difference 
	Difference(&L, A, len_A, B, len_B);
	ListTraverse_SL(L, PrintElem);
	printf("\n");	
	
	
	
	return 0;
}



void PrintElem(int e)
{
	printf("%d ", e);
}

