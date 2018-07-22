#include "TopologicalSort.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("创建并输出有向图\n");
	{
		FILE* fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("拓扑排序测试\n");
	{
		int topo[21];
		if(!TopologicalSort(G, topo))
			printf("该有向图有回路\n");
		else
		{
			printf("该有向图的拓扑序列为：");
			for(int i=1; i<=G.vexNum; i++)
				printf("%c ", G.vertex[topo[i]].data);
		}
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
