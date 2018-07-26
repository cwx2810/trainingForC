#include "ShortestPath.c"

int main(int argc, char** argv)
{
	MGraph G1;
	MGraph G2; 
	int v0=2;
	
	printf("���������������G1\n");
	{
		FILE* fp = fopen("TestDataDirectNetG1.txt", "r");
		CreateGraph_M(fp, &G1);
		fclose(fp);
		Output_M(G1);
		printf("\n");
	}
	PressEnter;
	
	printf("���·��Dijkstra�㷨����\n");
	{
		int path[21][21];
		int dist[21];
		
		printf("���㲢���%c���������̾��룺\n", G1.vertex[v0]);
		ShortestPath_Dijkstra(G1, v0, path, dist);
		OutputPath_Dijkstra(G1, v0, path, dist);
		printf("\n");
	}
	PressEnter;
	
	printf("���������������G2\n");
	{
		FILE* fp = fopen("TestDataDirectNetG2.txt", "r");
		CreateGraph_M(fp, &G2);
		fclose(fp);
		Output_M(G2);
		printf("\n");
	}
	PressEnter;
	
	printf("���·��Floyd�㷨����\n");
	{
		int path[21][21][21];
		int dist[21][21];
		printf("���㲢������Զ���֮������·����\n");
		ShortestPath_Floyd(G2, path, dist);
		OutputPath_Floyd(G2, path, dist);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
