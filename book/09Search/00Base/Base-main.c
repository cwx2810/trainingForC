#include "Base.c"


void Print(ElemType e);

int main(int argc, char** argv)
{
	FILE* fp;
	Table T;
	
	printf("����CreateTable����\n");
	{
		fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 10);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("����TraverseTable����\n");
	{
		TraverseTable(T, Print);
		printf("\n");
	}
	PressEnter;
	
	printf("����PrintKey����\n");
	{
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("����DestoryTable����\n");
	{
		DestoryTable(&T);
		T.elem==NULL && T.length==0 ? printf("������ѱ�����\n") : printf("�����δ������\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void Print(ElemType e)
{
	printf("(%3d, %.1f) ", e.key, e.weight);
}
