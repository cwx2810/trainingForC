#include "OLGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	OLGraph G;
	
	printf("CreateOLGraph����\n");
	{
		FILE* fp;

		printf("��ʼ������ͼ\n");
		fp = fopen("TestDataDirectGraph.txt", "r");
		CreateDirectGraph_OL(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut����\n");
	{
		Output_OL(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
