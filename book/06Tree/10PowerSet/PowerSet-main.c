#include "PowerSet.c"

int main(int argc, char** argv)
{
	LNode* A;
	printf("CreatePowerSet����\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreatePowerSet_PS(fp, &A);
		fclose(fp);
		printf("��������A�ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("Output����\n");
	{
		Output_PS(A);
		printf("\n");
	}
	PressEnter;
	
	printf("GetPowerSet����\n");
	{
		LNode* B;
		InitList_L(&B);
		GetPowerSet_PS(1, A, B);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
