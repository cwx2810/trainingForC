#include "BTree.c"

int main(int argc, char** argv)
{
	Table T;
	BTNode* BT;
	
	printf("���������һ�����ұ�\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 15);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("����B��\n");
	{
		CreateBTree(&BT, T);
		printf("\n");
	}
	PressEnter;
	
	
	return 0;
}
