#include "RadixSort.c"


int main(int argc, char** argv)
{
	SLList L;
	printf("º¯ÊıCreateSortList²âÊÔ\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateSLList(fp, &L);
		TraverseSLList(L);
		printf("\n");
	}
	PressEnter;
	
	printf("»ùÊıÅÅĞò²âÊÔ\n");
	{
		RadixSort(&L);
		TraverseSLList(L);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

