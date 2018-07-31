#include "BinarySearchTree.c"

int main(int argc, char** argv)
{
	Table T;
	BSTNode* BST;
	
	printf("创建并输出一个查找表\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 7);
		TraverseTable(T, PrintKey);
		printf("\n");
	}
	PressEnter;
	
	printf("创建二叉排序树，并中序遍历输出其关键字\n");
	{
		CreateBSTree(&BST, T);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n");
		printf("数的形状为\n");
		PrintBST(BST);
		printf("\n");
	}
	PressEnter;
	
	printf("搜索二叉排序树中等于key的节点并返回其指针测试\n");
	{
		printf("关键字24");
		SearchBST_Ptr(BST, 24)==NULL ? printf("不在二叉排序树中") : printf("在二叉排序树中");
		printf("\n");
	}
	PressEnter;
	
	printf("删除二叉排序树测试\n");
	{
		printf("删除关键字24后的二叉排序树中序遍历输出为：\n");
		DeleteBST_Key(&BST, 24);
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n");
		printf("数的形状为\n");
		PrintBST(BST);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
