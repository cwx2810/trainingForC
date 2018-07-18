#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

//ͼ���ͺͻ�Я������Ϣ 
typedef enum
{
	DirectGraph, UnDirectGraph
}GraphKind;
typedef struct
{
	int info;
}ArcInfo;

//��ڵ� 
typedef struct ArcNode
{
	int order;
	struct ArcNode* nextArc;
	ArcInfo info;
}ArcNode;

//ͷ��� 
typedef struct VexNode
{
	char data;
	ArcNode* firstArc;
}VexNode;
typedef VexNode AdjList[21];//��ͷ��㶨��Ϊ�ڽӱ�������������ʹͷ����Ϊͼ�е�һ��С�ṹ���������������ͷ��������ڵ������ϵ����нڵ� 

typedef struct
{
	AdjList vertex;//�ڽӱ�С���� 
	int vexNum, arcNum;//����ͱ����� 
	int arcInfo;//����Ϣ 
	GraphKind kind;//ͼ����  
}ALGraph;

int CreateGraph_AL(FILE* fp, ALGraph *G);

int CreateDirectGraph_AL(FILE* fp, ALGraph *G);

int CreateUnDirectGraph_AL(FILE* fp, ALGraph *G);

int LocateVertex_AL(ALGraph G, char e);

int Output_AL(ALGraph G);

int Input_AL(FILE* fp, ArcInfo* info);
