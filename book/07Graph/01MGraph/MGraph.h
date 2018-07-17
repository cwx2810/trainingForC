#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <time.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

//图的类型枚举 
typedef enum
{
	DirectGraph, DirectNet, UnDirectGraph, UnDirectNet
}GraphKind;

//弧的信息 
typedef struct {}ArcInfo;
//单位弧 
typedef struct ArcCell
{
	int vertexRelation;//顶点间关系，带权图表示权值，无权图用0、1表示是否相邻
	ArcInfo info;//弧相关信息，可以忽略 
}ArcCell;
typedef ArcCell AdjMatrix[21][21];//定义单位弧为邻接矩阵的形式，adj是adjustment邻居的意思
									//这样一定义ArcCell就变成了邻接矩阵中的一个坐标点的结构体 

//图的结构 
typedef struct 
{
	char vertex[21];//用来保存顶点的数组 
	AdjMatrix matrix;//邻接矩阵，保存弧，用二维数组保存两个顶点表示弧 
	int vexNum, arcNum;//图的顶点数、弧数
	int info;//info为0则各弧不包含其他信息 
	GraphKind kind;//图的类型 
}MGraph;

//全局变量 
int Visited[21];//标志数组
void (*VisitFunc)(char e);//函数指针变量




int CreateGraph_M(FILE* fp, MGraph *G);//根据图的类型switch不同的函数创建图 

int CreateDirectGraph_M(FILE* fp, MGraph *G);//创建有向图 

int CreateDirectNet_M(FILE* fp, MGraph *G);//创建有向网

int CreateUnDirectGraph_M(FILE* fp, MGraph *G);//创建无向图 

int CreateUnDirectNet_M(FILE* fp, MGraph *G);//创建无相网 

int ClearGraph_M(MGraph *G);

int LocateVertex_M(MGraph G, char e);//返回顶点e的位子（order） 

char GetVertex_M(MGraph G, int order);//返回第order个顶点的值 

int PutVertex_M(MGraph *G, char e, char value);//对顶点e赋值value

int FirstAdjVertex_M(MGraph G, char e);//返回顶点e的第一个邻接点的序号

int NextAdjVertex_M(MGraph G, char e, char w);//返回顶点e的相对于顶点w的下一个顶点序号

int InsertVertex_M(MGraph *G, char e);//插入顶点e到图中

int DeleteVertex_M(MGraph *G, char e);

int InsertArc_M(MGraph *G, char e, char w, int vertexRelation, ...);//插入弧<e, w>到图中，弧的相关信息可选

int DeleteArc_M(MGraph *G, char e, char w);

void DFSTraverse_M(MGraph G, void(Visit)(char));
void DFS_M(MGraph G, int i);//DFS核心函数，i代表访问下标 

int BFSTraverse_M(MGraph G, void(Visit)(char));

int Output_M(MGraph G);

int Input_M(FILE* fp, ArcInfo* info);//录入弧的相关信息 

 


