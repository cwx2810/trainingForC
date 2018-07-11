#include "MFSet.c"

int main(int argc, char **argv)
{
	FILE* fp;
	MFSet S;
	
	printf("����InitMFSet����\n");
	{
		fp = fopen("TestData_S.txt", "r");
		printf("��ʼ�����Ͽ�ʼ\n");
		InitMFSet(fp, &S);
		printf("��ʼ��������ɣ�¼��10������Ԫ�ؼ���\n");
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("����ShowMFSet����\n");
	{
		printf("S = ");
		ShowSetMFSet(S);
		printf("\n");
	}
	PressEnter;
	
	printf("����EquivalenceClass����\n");
	{
		Relation R;
		printf("¼��4����Ԫ��ϵ\n");
		fp = fopen("TestData_R.txt", "r");
		BuildRelationMFSet(fp, &R);
		fclose(fp);
		printf("¼��ȼ۹�ϵ���\n");
		printf("��S������ȼ۹�ϵ�ĵȼ���\n");
		EquivalenceClassMFSet(&S, R);
		printf("չʾ�ȼ���S = ");
		ShowSetMFSet(S);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
