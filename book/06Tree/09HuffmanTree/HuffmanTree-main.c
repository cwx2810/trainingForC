#include "HuffmanTree.c"

int main(int argc, char** argv)
{
	HTNode* T;
	char** Code;
	
	printf("InitTree����\n");
	{
		InitTree_HT(&T);
		printf("��ʼ�����������ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("CreateHuffmanTree����\n");
	{
		FILE* fp = fopen("TestData.txt", "r");
		CreateHuffmanTree_HT(fp, &T);
		fclose(fp);
		printf("�������������ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("ShowHuffmanTree����\n");
	{
		ShowHuffmanTree(T);
		printf("\n");
	}
	PressEnter;
	/*
	printf("HuffmanCode����������\n");
	{
		HuffmanCode_Invert(T, &Code);
		printf("\n");
	}
	PressEnter;
	*/
	printf("HuffmanCode��������������\n");
	{
		HuffmanCode_Pre(T, &Code);
		printf("\n");
	}
	PressEnter;
	
	printf("ShowHuffmanCode����\n");
	{
		ShowHuffmanCode(T, Code);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
