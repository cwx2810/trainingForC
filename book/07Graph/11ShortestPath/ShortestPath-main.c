#include "ShortestPath.c"

int main(int argc, char** argv)
{
	MGraph G1;
	MGraph G2; 
	int v0=2;
	
	printf("创建并输出有向网G1\n");
	{
		FILE* fp = fopen("TestDataDirectNetG1.txt", "r");
		CreateGraph_M(fp, &G1);
		fclose(fp);
		Output_M(G1);
		printf("\n");
	}
	PressEnter;
	
	printf("最短路径Dijkstra算法测试\n");
	{
		int path[21][21];
		int dist[21];
		
		printf("计算并输出%c到各点的最短距离：\n", G1.vertex[v0]);
		ShortestPath_Dijkstra(G1, v0, path, dist);
		OutputPath_Dijkstra(G1, v0, path, dist);
		printf("\n");
	}
	PressEnter;
	
	printf("创建并输出有向网G2\n");
	{
		FILE* fp = fopen("TestDataDirectNetG2.txt", "r");
		CreateGraph_M(fp, &G2);
		fclose(fp);
		Output_M(G2);
		printf("\n");
	}
	PressEnter;
	
	printf("最短路径Floyd算法测试\n");
	{
		int path[21][21][21];
		int dist[21][21];
		printf("计算并输出各对顶点之间的最短路径：\n");
		ShortestPath_Floyd(G2, path, dist);
		OutputPath_Floyd(G2, path, dist);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
