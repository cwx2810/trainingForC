#include "MGraph.c"

void PrintElem(char c);

int main(int argc, char** argv)
{
	MGraph G;
	
	printf("CreateMGraph����\n");
	{
		FILE* fp;
		
		srand((unsigned)time(NULL));
		int random = rand()%4;//ģ4ȡ�࣬��õ�0��1��2��3

		switch(random)
		{
			case DirectGraph:
				printf("��ʼ������ͼ\n");
				fp = fopen("TestDataDirectGraph.txt", "r");
				break;
			case DirectNet:
				printf("��ʼ��������\n");
				fp = fopen("TestDataDirectNet.txt", "r");
				break;
			case UnDirectGraph:
				printf("��ʼ������ͼ\n");
				fp = fopen("TestDataUnDirectGraph.txt", "r");
				break;
			case UnDirectNet:
				printf("��ʼ��������\n");
				fp = fopen("TestDataUnDirectNet.txt", "r");
				break;
		} 
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
	
	printf("LocateVertex����\n");
	{
		printf("����%c��λ��Ϊ%d\n", 'C', LocateVertex_M(G, 'C'));
		printf("\n");
	}
	PressEnter;
	
	printf("GetVertex����\n");
	{
		printf("��%d�������ֵΪ%c\n", 3, GetVertex_M(G, 3));
		printf("\n");
	}
	PressEnter;
	
	printf("FirstAdj����\n");
	{
		printf("%c�ĵ�һ���ڽӵ�����Ϊ%d\n", 'B', FirstAdjVertex_M(G, 'B'));
		printf("\n");
	}
	PressEnter;
	
	printf("NextAdj����\n");
	{
		printf("%c�����%c����һ����������Ϊ%d\n", 'A', 'B', NextAdjVertex_M(G, 'A', 'B'));
		printf("\n");
	}
	PressEnter;
	
	printf("PutVertex����\n");
	{
		printf("�Զ���%c��ֵ%c\n", 'A', 'X');
		PutVertex_M(&G, 'A', 'X');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("InsertVertex����\n");
	{
		printf("���붥��%c\n", 'H');
		InsertVertex_M(&G, 'H');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("InsertArc����\n");
	{
		printf("���β��뻡<%c, %c, 1>,<%c, %C, 1>,<%c, %c, 1>\n", 'H', 'X', 'H', 'C', 'D', 'H');
		InsertArc_M(&G, 'H', 'X', 1);
		InsertArc_M(&G, 'H', 'C', 1);
		InsertArc_M(&G, 'D', 'H', 1);
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteArc����\n");
	{
		printf("ɾ����<%c, %c>\n", 'H', 'X');
		DeleteArc_M(&G, 'H', 'X');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteVertex����\n");
	{
		printf("ɾ������%c\n", 'H');
		DeleteVertex_M(&G, 'H');
		Output_M(G);
		printf("\n");
	}
	PressEnter;
	
	printf("DFSTraverse����\n");
	{
		DFSTraverse_M(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("BFSTraverse����\n");
	{
		BFSTraverse_M(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("ClearMGraph����\n");
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
