#include <stdio.h>
#include "MergeList.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	FILE *fp;
	LNode* La;
	LNode* Lb;
	LNode* Lc;
	
	fp = fopen("TestData_HL.txt", "r");//¸øLaºÍLb¸³Öµ 
	CreateList_HL(fp, &La, 5);
	fclose(fp);
	fp = fopen("TestData_TL.txt", "r");
	CreateList_TL(fp, &Lb, 5);
	fclose(fp);
	
	printf("La = ");
	ListTraverse_L(La, PrintElem);
	printf("\n");
	printf("Lb = ");
	ListTraverse_L(Lb, PrintElem);
	printf("\n");
	PressEnter;
	
	MergeList_L(&La, &Lb, &Lc);
	printf("La + Lb = ");
	ListTraverse_L(Lc, PrintElem);
	printf("\n");
	PressEnter;
	
	
	return 0;
}


void PrintElem(int e)
{
	printf("%d ", e);
}

