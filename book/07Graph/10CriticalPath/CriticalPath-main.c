#include "CriticalPath.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("���������������\n");
	{
		FILE* fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("���������ؼ�·��\n");
	{
		CriticalPath(G);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
