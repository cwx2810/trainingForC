#include "QuickSort.c"

void PrintKey(int e);

int main(int argc, char** argv)
{
	SqSortList L;
	printf("º¯ÊıCreateSortList²âÊÔ\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		TraverseList(L, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("¿ìËÙÅÅĞò²âÊÔ\n");
	{
		QuickSort(&L);
		TraverseList(L, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintKey(int e)
{
	printf("%d ", e);
}
