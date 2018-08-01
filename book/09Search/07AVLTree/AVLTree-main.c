#include "AVLTree.c"

int main(int argc, char** argv)
{
	Table T;
	AVLTNode* AVLT;
	
	printf("���������һ�����ұ�\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 7);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("����ƽ���������������������������ؼ���\n");
	{
		CreateAVLTree(&AVLT, T);
		InOrderTraverse_AVL(AVLT, PrintKey);
		printf("\n");
		printf("������״Ϊ\n");
		PrintAVLTree(AVLT);
		printf("\n");
	}
	PressEnter;
	
	printf("����ƽ������������е���key�Ľڵ㲢������ָ�����\n");
	{
		printf("�ؼ���%2d", T.elem[1].key);
		SearchAVLTree(AVLT, T.elem[1].key)==NULL ? printf("����ƽ�������������") : printf("��ƽ�������������");
		printf("\n");
	}
	PressEnter;
	

	
	return 0;
}
