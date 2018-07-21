#include "SpanningTree.c"

int main(int argc, char** argv)
{
	MGraph G;
	
	printf("创建并输出无向图\n");
	{
		FILE* fp = fopen("TestDataUnDirectGraph1.txt", "r");
		CreateGraph_M(fp, &G);
		fclose(fp);
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DFSForest测试\n");
	{
		CSNode* T;
		DFSForest(G, &T);
		Print_CS(T);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
