#include "BTree.c"

int main(int argc, char** argv)
{
	Table T;
	BTNode* BT;
	
	printf("创建并输出一个查找表\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 15);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("构造B树\n");
	{
		CreateBTree(&BT, T);
		printf("\n");
	}
	PressEnter;
	
	
	return 0;
}
