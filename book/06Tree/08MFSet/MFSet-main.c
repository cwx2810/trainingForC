#include "MFSet.c"

int main(int argc, char **argv)
{
	FILE* fp;
	MFSet S;
	
	printf("函数InitMFSet测试\n");
	{
		fp = fopen("TestData_S.txt", "r");
		printf("初始化集合开始\n");
		InitMFSet(fp, &S);
		printf("初始化集合完成，录入10个单个元素集合\n");
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("函数ShowMFSet测试\n");
	{
		printf("S = ");
		ShowSetMFSet(S);
		printf("\n");
	}
	PressEnter;
	
	printf("函数EquivalenceClass测试\n");
	{
		Relation R;
		printf("录入4个二元关系\n");
		fp = fopen("TestData_R.txt", "r");
		BuildRelationMFSet(fp, &R);
		fclose(fp);
		printf("录入等价关系完成\n");
		printf("求S中满足等价关系的等价类\n");
		EquivalenceClassMFSet(&S, R);
		printf("展示等价类S = ");
		ShowSetMFSet(S);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
