#include "CriticalPath.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("创建并输出有向网\n");
	{
		FILE* fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("求有向网关键路径\n");
	{
		CriticalPath(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
