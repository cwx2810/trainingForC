#include "ArticulationPoint.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("�������������ͼ\n");
	{
		FILE* fp = fopen("TestDataUnDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("FindArticulationPoint����\n");
	{
		FindArticulation(G);
		OutputPoint(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
