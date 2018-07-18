#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

typedef enum
{
	UnVisit, Visit
}VisitIf;

typedef struct {} ArcInfo;

//边节点 
typedef struct ArcNode
{
	VisitIf mark;//访问标记 
	int headVex, tailVex;//该边的头尾节点 
	struct ArcNode* headLink;//该边的头尾指针 
	struct ArcNode* tailLink;
	ArcInfo info;
}ArcNode;

//顶点 
typedef struct VexNode
{
	char data;
	ArcNode* firstArc;//连接的第一条边 
}VexNode;

typedef struct
{
	VexNode vertex[21];//表头小容器，存放了一整行数据 
	int vexNum, arcNum;
	int arcInfo;
}AMLGraph;

//全局变量 
ArcNode* arcPtr[21];//弧指针数组 

int CreateUnDirectGraph_AML(FILE* fp, AMLGraph *G);

int LocateVertex_AML(AMLGraph G, char e);

int Output_AML(AMLGraph G);
int ClearMark(AMLGraph G);

int Input_AML(FILE* fp, ArcInfo* info);


