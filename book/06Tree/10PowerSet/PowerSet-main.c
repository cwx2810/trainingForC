#include "PowerSet.c"

int main(int argc, char** argv)
{
	LNode* A;
	printf("CreatePowerSet测试\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreatePowerSet_PS(fp, &A);
		fclose(fp);
		printf("创建集合A成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("Output测试\n");
	{
		Output_PS(A);
		printf("\n");
	}
	PressEnter;
	
	printf("GetPowerSet测试\n");
	{
		LNode* B;
		InitList_L(&B);
		GetPowerSet_PS(1, A, B);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
