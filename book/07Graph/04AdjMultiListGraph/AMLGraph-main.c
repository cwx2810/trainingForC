#include "AMLGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	AMLGraph G;
	
	printf("CreateAMLGraph测试\n");
	{
		FILE* fp;

		printf("初始化无向图\n");
		fp = fopen("TestDataUnDirectGraph.txt", "r");
		CreateUnDirectGraph_AML(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut测试\n");
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
