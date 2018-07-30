#include "BinSearch.c"

int main(int argc, char** argv)
{
	Table T;
	
	printf("创建并输出一个查找表\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 100);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("二分查找测试\n");
	{
		printf("关键字39在有序查找表中的位置为：");
		printf("%d\n", Search_Bin(T, 39));
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
