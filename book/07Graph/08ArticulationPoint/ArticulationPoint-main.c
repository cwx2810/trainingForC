#include "ArticulationPoint.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("创建并输出无向图\n");
	{
		FILE* fp = fopen("TestDataUnDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("FindArticulationPoint测试\n");
	{
		FindArticulation(G);
		OutputPoint(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
