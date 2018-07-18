#include "OLGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	OLGraph G;
	
	printf("CreateOLGraph测试\n");
	{
		FILE* fp;

		printf("初始化有向图\n");
		fp = fopen("TestDataDirectGraph.txt", "r");
		CreateDirectGraph_OL(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut测试\n");
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
