#include "MST.c"

int main(int argc, char** argv)
{
	MGraph G;
	
	printf("��ʼ�������������\n");
	{
		FILE* fp = fopen("TestDataUnDirectNet.txt", "r");
		CreateGraph_M(fp, &G);
		fclose(fp);
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("Prim�㷨����\n");
	{
		MiniSpanTree_Prim(G, 'A');
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
