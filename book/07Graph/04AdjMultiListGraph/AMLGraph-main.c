#include "AMLGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	AMLGraph G;
	
	printf("CreateAMLGraph����\n");
	{
		FILE* fp;

		printf("��ʼ������ͼ\n");
		fp = fopen("TestDataUnDirectGraph.txt", "r");
		CreateUnDirectGraph_AML(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut����\n");
	{
		Output_AML(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
