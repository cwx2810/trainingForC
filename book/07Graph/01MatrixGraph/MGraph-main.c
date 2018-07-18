#include "MGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	MGraph G;
	
	printf("CreateMGraph测试\n");
	{
		FILE* fp;
		
		srand((unsigned)time(NULL));
		int random = rand()%4;//模4取余，会得到0、1、2、3

		switch(random)
		{
			case DirectGraph:
				printf("初始化有向图\n");
				fp = fopen("TestDataDirectGraph.txt", "r");
				break;
			case DirectNet:
				printf("初始化有向网\n");
				fp = fopen("TestDataDirectNet.txt", "r");
				break;
			case UnDirectGraph:
				printf("初始化无向图\n");
				fp = fopen("TestDataUnDirectGraph.txt", "r");
				break;
			case UnDirectNet:
				printf("初始化无向网\n");
				fp = fopen("TestDataUnDirectNet.txt", "r");
				break;
		} 
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
	
	printf("LocateVertex测试\n");
	{
		printf("顶点%c的位置为%d\n", 'C', LocateVertex_M(G, 'C'));
		printf("\n");
	}
	PressEnter;
	
	printf("GetVertex测试\n");
	{
		printf("第%d个顶点的值为%c\n", 3, GetVertex_M(G, 3));
		printf("\n");
	}
	PressEnter;
	
	printf("FirstAdj测试\n");
	{
		printf("%c的第一个邻接点的序号为%d\n", 'B', FirstAdjVertex_M(G, 'B'));
		printf("\n");
	}
	PressEnter;
	
	printf("NextAdj测试\n");
	{
		printf("%c相对于%c的下一个顶点的序号为%d\n", 'A', 'B', NextAdjVertex_M(G, 'A', 'B'));
		printf("\n");
	}
	PressEnter;
	
	printf("PutVertex测试\n");
	{
		printf("对顶点%c赋值%c\n", 'A', 'X');
		PutVertex_M(&G, 'A', 'X');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("InsertVertex测试\n");
	{
		printf("插入顶点%c\n", 'H');
		InsertVertex_M(&G, 'H');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("InsertArc测试\n");
	{
		printf("依次插入弧<%c, %c, 1>,<%c, %C, 1>,<%c, %c, 1>\n", 'H', 'X', 'H', 'C', 'D', 'H');
		InsertArc_M(&G, 'H', 'X', 1);
		InsertArc_M(&G, 'H', 'C', 1);
		InsertArc_M(&G, 'D', 'H', 1);
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteArc测试\n");
	{
		printf("删除弧<%c, %c>\n", 'H', 'X');
		DeleteArc_M(&G, 'H', 'X');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteVertex测试\n");
	{
		printf("删除顶点%c\n", 'H');
		DeleteVertex_M(&G, 'H');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DFSTraverse测试\n");
	{
		DFSTraverse_M(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("BFSTraverse测试\n");
	{
		BFSTraverse_M(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("ClearMGraph测试\n");
	{
		ClearGraph_M(&G);
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
