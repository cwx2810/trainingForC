#include "MGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	MGraph G;
	
	
	printf("CreateMGraph测试\n");
	{
		FILE* fp;
		printf("初始化有向图\n");
		fp = fopen("TestDataDirectGraph.txt", "r");
		CreateGraph_M(fp, &G);
		fclose(fp);
		
		printf("\n");
	}
	PressEnter;
	
	printf("OutPut测试\n");
	{
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("Adj测试\n");
	{
		int j = FirstAdjVertex_M(G, G.vertex[1]);
		printf("得到的第一个邻居的序号是%d\n", j);
		printf("下面求A相对于%c的下一个顶点\n", G.vertex[j]);
		
		
		
		
		
		j = NextAdjVertex_M(G, G.vertex[3], G.vertex[1]);
		printf("得到的C相对于A的下一个邻居的序号是%d\n", j);
		printf("下一个邻居的值是：%c", G.vertex[j]);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
