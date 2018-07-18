#include "MGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	MGraph G;
	
	
	printf("CreateMGraph����\n");
	{
		FILE* fp;
		printf("��ʼ������ͼ\n");
		fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_M(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut����\n");
	{
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("Adj����\n");
	{
		int j = FirstAdjVertex_M(G, G.vertex[1]);
		printf("�õ��ĵ�һ���ھӵ������%d\n", j);
		printf("������A�����%c����һ������\n", G.vertex[j]);
		
		
		
		
		
		j = NextAdjVertex_M(G, G.vertex[3], G.vertex[1]);
		printf("�õ���C�����A����һ���ھӵ������%d\n", j);
		printf("��һ���ھӵ�ֵ�ǣ�%c", G.vertex[j]);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
