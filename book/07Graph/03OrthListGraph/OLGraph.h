#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

typedef struct {}ArcInfo;

//弧节点 
typedef struct ArcNode
{
	int headVex, tailVex;//弧的头尾节点序号 
	struct ArcNode* headLink;//弧头相同的弧的链域，在十字链表中是同一行 
	struct ArcNode* tailLink;//弧尾相同的弧的链域，在十字链表中是同一列 
	ArcInfo info;
}ArcNode;

//顶点 
typedef struct VexNode
{
	char data;
	ArcNode* firstin;//该顶点第一条入弧和出弧 
	ArcNode* firstout;
}VexNode;

typedef struct
{
	VexNode vertex[21];//表头小容器 
	int vexNum, arcNum;
	int arcInfo;
}OLGraph;

int CreateDirectGraph_OL(FILE* fp, OLGraph *G);

int LocateVertex_OL(OLGraph G, char e);

int Output_OL(OLGraph G);

int Input_OL(FILE* fp, ArcInfo* info);
