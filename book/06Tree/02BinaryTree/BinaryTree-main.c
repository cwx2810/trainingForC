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
	
	printf("层序遍历二叉树 T = ");
	LevelOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("前序遍历二叉树 T = ");
	PreOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("中序遍历二叉树 T = ");
	InOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("非递归中序遍历二叉树 T = ");
	InOrderTraverseNonRecursive1(T, PrintElement);
	printf("\n");
	
	printf("非递归中序遍历二叉树 T = ");
	InOrderTraverseNonRecursive2(T, PrintElement);
	printf("\n");
	
	printf("后序遍历二叉树 T = ");
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
