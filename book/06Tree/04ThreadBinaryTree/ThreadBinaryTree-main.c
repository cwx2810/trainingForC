#include "ThreadBinaryTree.c"

void PrintElem(char e);

int main(int argc, char **argv)
{
	FILE* fp = fopen("TestData.txt", "r");
	TriBiNode* P;
	CreateBiTree_Tri(fp, &P);
	fclose(fp);
	printf("创建带Tag的非线索二叉树P\n");
	
	printf("将二叉树P中序全线索化为T\n");
	TriBiNode* T;
	InOrderThreading_Tri(&T, P);
	printf("中序遍历线索二叉树T = ");
	InOrderTraverse_Tri(T, PrintElem);
	printf("\n");
	
	return 0;
}

void PrintElem(char e)
{
	printf("%c ", e);
}
