#include "RadixSort.c"


int main(int argc, char** argv)
{
	SLList L;
	printf("����CreateSortList����\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateSLList(fp, &L);
		TraverseSLList(L);
		printf("\n");
	}
	PressEnter;
	
	printf("�����������\n");
	{
		RadixSort(&L);
		TraverseSLList(L);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

