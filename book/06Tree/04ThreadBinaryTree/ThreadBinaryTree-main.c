#include "ThreadBinaryTree.c"

void PrintElem(char e);

int main(int argc, char **argv)
{
	FILE* fp = fopen("TestData.txt", "r");
	TriBiNode* P;
	CreateBiTree_Tri(fp, &P);
	fclose(fp);
	printf("������Tag�ķ�����������P\n");
	
	printf("��������P����ȫ������ΪT\n");
	TriBiNode* T;
	InOrderThreading_Tri(&T, P);
	printf("�����������������T = ");
	InOrderTraverse_Tri(T, PrintElem);
	printf("\n");
	
	return 0;
}

void PrintElem(char e)
{
	printf("%c ", e);
}
