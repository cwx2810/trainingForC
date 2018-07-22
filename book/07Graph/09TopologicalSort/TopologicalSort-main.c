#include "TopologicalSort.c"

int main(int argc, char** argv)
{
	ALGraph G;
	
	printf("�������������ͼ\n");
	{
		FILE* fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		Output_AL(G);
		printf("\n");
	}
	PressEnter;
	
	printf("�����������\n");
	{
		int topo[21];
		if(!TopologicalSort(G, topo))
			printf("������ͼ�л�·\n");
		else
		{
			printf("������ͼ����������Ϊ��");
			for(int i=1; i<=G.vexNum; i++)
				printf("%c ", G.vertex[topo[i]].data);
		}
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
