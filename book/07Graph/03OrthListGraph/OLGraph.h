#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

typedef struct {}ArcInfo;

//���ڵ� 
typedef struct ArcNode
{
	int headVex, tailVex;//����ͷβ�ڵ���� 
	struct ArcNode* headLink;//��ͷ��ͬ�Ļ���������ʮ����������ͬһ�� 
	struct ArcNode* tailLink;//��β��ͬ�Ļ���������ʮ����������ͬһ�� 
	ArcInfo info;
}ArcNode;

//���� 
typedef struct VexNode
{
	char data;
	ArcNode* firstin;//�ö����һ���뻡�ͳ��� 
	ArcNode* firstout;
}VexNode;

typedef struct
{
	VexNode vertex[21];//��ͷС���� 
	int vexNum, arcNum;
	int arcInfo;
}OLGraph;

int CreateDirectGraph_OL(FILE* fp, OLGraph *G);

int LocateVertex_OL(OLGraph G, char e);

int Output_OL(OLGraph G);

int Input_OL(FILE* fp, ArcInfo* info);
