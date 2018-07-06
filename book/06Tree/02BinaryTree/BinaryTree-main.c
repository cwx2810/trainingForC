#include "BinaryTree.c"

void PrintElem(char e);
int PrintElement(char e);

int main(int argc, char **argv)
{
	BiTNode* T;
	InitBiTree(&T);
	FILE* fp = fopen("TestData.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	
	printf("������������� T = ");
	LevelOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("ǰ����������� T = ");
	PreOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("������������� T = ");
	InOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("�ǵݹ�������������� T = ");
	InOrderTraverseNonRecursive1(T, PrintElement);
	printf("\n");
	
	printf("�ǵݹ�������������� T = ");
	InOrderTraverseNonRecursive2(T, PrintElement);
	printf("\n");
	
	printf("������������� T = ");
	PostOrderTraverse(T, PrintElem);
	printf("\n");
}

void PrintElem(char e)
{
	printf("%c ", e);
}

int PrintElement(char e)
{
	printf("%c ", e);
	return 1;
}
