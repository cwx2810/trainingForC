#include "BinarySearchTree.c"

int main(int argc, char** argv)
{
	Table T;
	BSTNode* BST;
	
	printf("���������һ�����ұ�\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 7);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("������������������������������ؼ���\n");
	{
		CreateBSTree(&BST, T);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n");
		printf("������״Ϊ\n");
		PrintBST(BST);
		printf("\n");
	}
	PressEnter;
	
	printf("���������������е���key�Ľڵ㲢������ָ�����\n");
	{
		printf("�ؼ���24");
		SearchBST_Ptr(BST, 24)==NULL ? printf("���ڶ�����������") : printf("�ڶ�����������");
		printf("\n");
	}
	PressEnter;
	
	printf("ɾ����������������\n");
	{
		printf("ɾ���ؼ���24��Ķ�������������������Ϊ��\n");
		DeleteBST_Key(&BST, 24);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n");
		printf("������״Ϊ\n");
		PrintBST(BST);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
