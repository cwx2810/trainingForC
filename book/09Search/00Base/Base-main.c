#include "Base.c"


void Print(ElemType e);

int main(int argc, char** argv)
{
	FILE* fp;
	Table T;
	
	printf("函数CreateTable测试\n");
	{
		fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 10);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("函数TraverseTable测试\n");
	{
		TraverseTable(T, Print);
		printf("\n");
	}
	PressEnter;
	
	printf("函数PrintKey测试\n");
	{
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("函数DestoryTable测试\n");
	{
		DestoryTable(&T);
		T.elem==NULL && T.length==0 ? printf("有序表已被销毁\n") : printf("有序表未被销毁\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void Print(ElemType e)
{
	printf("(%3d, %.1f) ", e.key, e.weight);
}
