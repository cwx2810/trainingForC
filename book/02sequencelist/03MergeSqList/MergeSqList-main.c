#include <stdio.h>
#include "MergeSqList.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqList La, Lb, Lc;
	int a[4] = {3, 5, 8, 11};
	int b[7] = {2, 6, 8, 9, 11, 15, 20};
	
	InitList_Sq(&La);
	for(int i=1; i<=4; i++)
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
	

	MergeSqList(La, Lb, &Lc);
	printf("La merge Lb = Lc = ");
	ListTraverse_Sq(Lc, PrintElem);
	printf("\n");
	
	return 0;
}


void PrintElem(int e)
{
	printf("%d ", e);
}
