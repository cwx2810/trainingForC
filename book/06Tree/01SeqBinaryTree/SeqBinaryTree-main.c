#include "SeqBinaryTree.c"

void PrintElem(char c);

int main(int argc, char **argv)
{
	SqBiTree T;
	
	printf("InitSqBiTree����...\n");
	{
		InitBiTree_Sq(T);
		printf("��ʼ����������ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("BiTreeEmpty����...\n");
	{
		BiTreeEmpty_Sq(T)? printf("��������\n") : printf("�������ǿ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("CreateBiTree����...\n");
	{
		FILE *fp;
		fp = fopen("TestData_Level.txt", "r");
		CreateBiTree_Level(fp, T);
		fclose(fp);
		printf("�������������ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	/*
	printf("CreateBiTree����...\n");
	{
		FILE *fp;
		fp = fopen("TestData_Pre.txt", "r");
		CreateBiTree_Pre(fp, T, 1);//i����ڵ���ţ��ӵ�1���ڵ㿪ʼ���� 
		fclose(fp);
		printf("�������������ɹ�\n");
		printf("\n");
	}
	PressEnter;
	*/
	
	printf("Print����...\n");
	{
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;
	
	printf("Length,Depth����...\n");
	{
		printf("������ռ������ĳ���Ϊ%d�����Ϊ%d\n", BiTreeLength_Sq(T), BiTreeDepth_Sq(T));
		printf("\n");
	}
	PressEnter;
	
	printf("LeverOrderTraverse����...\n");
	{
		printf("�������������T��");
		LevelOrderTraverse_Sq(T, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("PreOrderTraverse����...\n");
	{
		printf("�������������T��");
		PreOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("InOrderTraverse����...\n");
	{
		printf("�������������T��");
		InOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("PostOrderTraverse����...\n");
	{
		printf("�������������T��");
		PostOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("Root_Sq����...\n");
	{
		char r;
		Root_Sq(T, &r);
		printf("�������ĸ��ڵ�Ϊ%c \n", r);
		printf("\n");
	}
	PressEnter;
	
	printf("Value_Sq����...\n");
	{
		Position p = {4, 3};
		printf("������T�е�4���3���ڵ��ֵΪ��%c", Value_Sq(T, p));
		printf("\n");
	}
	PressEnter;
	
	printf("Assign_Sq����...\n");
	{
		Position p = {4, 3};
		Assign_Sq(T, p, 'X');
		printf("��������T�ĵ�4���3���ڵ㸳ֵΪX��\n");
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;
	
	printf("Parent_Sq����...\n");
	{
		printf("�ڵ�X��˫��Ϊ��%c \n", Parent_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;
	
	printf("LeftChild,RightChild����...\n");
	{
		printf("E�����ӽڵ�ֵΪ��%c���Һ��ӽڵ�ֵΪ��%c\n", LeftChild_Sq(T, 'E'), RightChild_Sq(T, 'E'));
		printf("\n");
	}
	PressEnter;
	
	printf("LeftBrother����...\n");
	{
		printf("I�����ֵܽڵ�ֵΪ��%c\n", LeftBrother_Sq(T, 'I'));
		printf("\n");
	}
	PressEnter;
	
	printf("RightBrother����...\n");
	{
		printf("X�����ֵܽڵ�ֵΪ��%c\n", RightBrother_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;
	
	printf("ClearBiTree����...\n");
	{
		ClearBiTree_Sq(T);
		BiTreeEmpty_Sq(T)? printf("��������\n") : printf("�������ǿ�\n"); 
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
