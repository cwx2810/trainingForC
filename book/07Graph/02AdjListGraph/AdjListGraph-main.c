#include "AdjListGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("CreateALGraph测试\n");
	{
		FILE* fp;
		
		srand((unsigned)time(NULL));
		int random = rand()%2;//模2取余，会得到0、1

		switch(random)
		{
			case DirectGraph:
				printf("初始化有向图\n");
				fp = fopen("TestDataDirectGraph.txt", "r");
				break;
			case UnDirectGraph:
				printf("初始化无向图\n");
				fp = fopen("TestDataUnDirectGraph.txt", "r");
				break;
		} 
		CreateGraph_AL(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut测试\n");
	{
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
