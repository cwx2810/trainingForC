#include "AVLTree.c"

int main(int argc, char** argv)
{
	Table T;
	AVLTNode* AVLT;
	
	printf("创建并输出一个查找表\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 7);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("创建平衡二叉排序树，并中序遍历输出其关键字\n");
	{
		CreateAVLTree(&AVLT, T);
		InOrderTraverse_AVL(AVLT, PrintKey);
		printf("\n");
		printf("数的形状为\n");
		PrintAVLTree(AVLT);
		printf("\n");
	}
	PressEnter;
	
	printf("搜索平衡二叉排序树中等于key的节点并返回其指针测试\n");
	{
		printf("关键字%2d", T.elem[1].key);
		SearchAVLTree(AVLT, T.elem[1].key)==NULL ? printf("不在平衡二叉排序树中") : printf("在平衡二叉排序树中");
		printf("\n");
	}
	PressEnter;
	

	
	return 0;
}
