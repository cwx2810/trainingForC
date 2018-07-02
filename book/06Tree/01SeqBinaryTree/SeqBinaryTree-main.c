#include "SeqBinaryTree.c"

void PrintElem(char c);

int main(int argc, char **argv)
{
	SqBiTree T;
	
	printf("InitSqBiTree测试...\n");
	{
		InitBiTree_Sq(T);
		printf("初始化二叉空树成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("BiTreeEmpty测试...\n");
	{
		BiTreeEmpty_Sq(T)? printf("二叉树空\n") : printf("二叉树非空\n");
		printf("\n");
	}
	PressEnter;
	
	printf("CreateBiTree测试...\n");
	{
		FILE *fp;
		fp = fopen("TestData_Level.txt", "r");
		CreateBiTree_Level(fp, T);
		fclose(fp);
		printf("层序建立二叉树成功\n");
		printf("\n");
	}
	PressEnter;
	
	/*
	printf("CreateBiTree测试...\n");
	{
		FILE *fp;
		fp = fopen("TestData_Pre.txt", "r");
		CreateBiTree_Pre(fp, T, 1);//i代表节点序号，从第1个节点开始建立 
		fclose(fp);
		printf("先序建立二叉树成功\n");
		printf("\n");
	}
	PressEnter;
	*/
	
	printf("Print测试...\n");
	{
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;
	
	printf("Length,Depth测试...\n");
	{
		printf("二叉树占用数组的长度为%d，深度为%d\n", BiTreeLength_Sq(T), BiTreeDepth_Sq(T));
		printf("\n");
	}
	PressEnter;
	
	printf("LeverOrderTraverse测试...\n");
	{
		printf("层序遍历二叉树T：");
		LevelOrderTraverse_Sq(T, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("PreOrderTraverse测试...\n");
	{
		printf("先序遍历二叉树T：");
		PreOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("InOrderTraverse测试...\n");
	{
		printf("中序遍历二叉树T：");
		InOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("PostOrderTraverse测试...\n");
	{
		printf("中序遍历二叉树T：");
		PostOrderTraverse_Sq(T, PrintElem, 0);
		printf("\n");
	}
	PressEnter;
	
	printf("Root_Sq测试...\n");
	{
		char r;
		Root_Sq(T, &r);
		printf("二叉树的根节点为%c \n", r);
		printf("\n");
	}
	PressEnter;
	
	printf("Value_Sq测试...\n");
	{
		Position p = {4, 3};
		printf("二叉树T中第4层第3个节点的值为：%c", Value_Sq(T, p));
		printf("\n");
	}
	PressEnter;
	
	printf("Assign_Sq测试...\n");
	{
		Position p = {4, 3};
		Assign_Sq(T, p, 'X');
		printf("将二叉树T的第4层第3个节点赋值为X后：\n");
		Print_Sq(T);
		printf("\n");
	}
	PressEnter;
	
	printf("Parent_Sq测试...\n");
	{
		printf("节点X的双亲为：%c \n", Parent_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;
	
	printf("LeftChild,RightChild测试...\n");
	{
		printf("E的左孩子节点值为：%c，右孩子节点值为：%c\n", LeftChild_Sq(T, 'E'), RightChild_Sq(T, 'E'));
		printf("\n");
	}
	PressEnter;
	
	printf("LeftBrother测试...\n");
	{
		printf("I的左兄弟节点值为：%c\n", LeftBrother_Sq(T, 'I'));
		printf("\n");
	}
	PressEnter;
	
	printf("RightBrother测试...\n");
	{
		printf("X的右兄弟节点值为：%c\n", RightBrother_Sq(T, 'X'));
		printf("\n");
	}
	PressEnter;
	
	printf("ClearBiTree测试...\n");
	{
		ClearBiTree_Sq(T);
		BiTreeEmpty_Sq(T)? printf("二叉树空\n") : printf("二叉树非空\n"); 
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
