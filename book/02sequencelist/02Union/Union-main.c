#include <stdio.h>
#include "Union.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqList La,Lb;
	int a[5] = {5, 2, 1, 3, 9};
	int b[7] = {7, 2, 6, 9, 11, 3, 10};
	
	InitList_Sq(&La);
	for(int i=1; i<=5; i++)
		ListInsert_Sq(&La, i, a[i-1]);
	InitList_Sq(&Lb);
	for(int i=1; i<=7; i++)
		ListInsert_Sq(&Lb, i, b[i-1]);
		
	printf("La = ");
	ListTraverse_Sq(La, PrintElem);
	printf("\n");
	
	printf("Lb = ");
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n");
	
	printf("La + Lb = ");
	Union(&La, Lb);
	ListTraverse_Sq(La, PrintElem);
	
	
	
	return 0;
}

void PrintElem(int e)
{
	printf("%d ", e);
}
