#include "NearlyOptimalSearchTree.c"

void Print(ElemType e);

int main(int argc, char** argv)
{
	Table T;
	BiTNode* BT;
	
	printf("���������һ�����ұ�\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 10);
		TraverseTable(T, Print);
		printf("\n");
	}
	PressEnter;
	
	printf("�������Ų�����\n");
	{
		CreateNearlyOptimal(&BT, T);
		PrintTree(BT);
		printf("\n");
	}
	PressEnter;
	
	printf("SearchKey����\n");
	{
		printf("�ؼ���%c", ch[3]);
		SearchKey(BT, 3) ? printf("�ڴ��Ų�������") : printf("���ڴ��Ų�������");
		printf("\n");
	}
	PressEnter;
	
	
	
	return 0;
}

void Print(ElemType e)
{
	printf("(%c, %.1f) ", ch[e.key], e.weight);
}
