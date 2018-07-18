#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

//图类型和弧携带的信息 
typedef enum
{
	DirectGraph, UnDirectGraph
}GraphKind;
typedef struct
{
	int info;
}ArcInfo;

//表节点 
typedef struct ArcNode
{
	int order;
	struct ArcNode* nextArc;
	ArcInfo info;
}ArcNode;

//头结点 
typedef struct VexNode
{
	char data;
	ArcNode* firstArc;
}VexNode;
typedef VexNode AdjList[21];//把头结点定义为邻接表，并给与容量，使头结点变为图中的一个小结构，这个容器包含了头结点和这个节点能连上的所有节点 

typedef struct
{
	AdjList vertex;//邻接表小容器 
	int vexNum, arcNum;//顶点和边数量 
	int arcInfo;//弧信息 
	GraphKind kind;//图类型  
}ALGraph;

int CreateGraph_AL(FILE* fp, ALGraph *G);

int CreateDirectGraph_AL(FILE* fp, ALGraph *G);

int CreateUnDirectGraph_AL(FILE* fp, ALGraph *G);

int LocateVertex_AL(ALGraph G, char e);

int Output_AL(ALGraph G);

int Input_AL(FILE* fp, ArcInfo* info);
