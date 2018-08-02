#include "SelectSort.c"

void PrintKey(int e);

int main(int argc, char** argv)
{
	SqSortList L;
	printf("����CreateSortList����\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateSortList(fp, &L);
		TraverseList(L, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("��ѡ���������\n");
	{
		SelectSort(&L);
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
