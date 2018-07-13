#include "HuffmanTree.c"

int main(int argc, char** argv)
{
	HTNode* T;
	char** Code;
	
	printf("InitTree测试\n");
	{
		InitTree_HT(&T);
		printf("初始化哈夫曼树成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("CreateHuffmanTree测试\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateHuffmanTree_HT(fp, &T);
		fclose(fp);
		printf("创建哈夫曼树成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("ShowHuffmanTree测试\n");
	{
		ShowHuffmanTree(T);
		printf("\n");
	}
	PressEnter;
	/*
	printf("HuffmanCode逆序计算测试\n");
	{
		HuffmanCode_Invert(T, &Code);
		printf("\n");
	}
	PressEnter;
	*/
	printf("HuffmanCode先序遍历计算测试\n");
	{
		HuffmanCode_Pre(T, &Code);
		printf("\n");
	}
	PressEnter;
	
	printf("ShowHuffmanCode测试\n");
	{
		ShowHuffmanCode(T, Code);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
