#include "AdjListGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("CreateALGraph����\n");
	{
		FILE* fp;
		
		srand((unsigned)time(NULL));
		int random = rand()%2;//ģ2ȡ�࣬��õ�0��1

		switch(random)
		{
			case DirectGraph:
				printf("��ʼ������ͼ\n");
				fp = fopen("TestDataDirectGraph.txt", "r");
				break;
			case UnDirectGraph:
				printf("��ʼ������ͼ\n");
				fp = fopen("TestDataUnDirectGraph.txt", "r");
				break;
		} 
		CreateGraph_AL(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut����\n");
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
