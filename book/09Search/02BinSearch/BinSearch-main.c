#include "BinSearch.c"

int main(int argc, char** argv)
{
	Table T;
	
	printf("���������һ�����ұ�\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 100);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("���ֲ��Ҳ���\n");
	{
		printf("�ؼ���39��������ұ��е�λ��Ϊ��");
		printf("%d\n", Search_Bin(T, 39));
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
