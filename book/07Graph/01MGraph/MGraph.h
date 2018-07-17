#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <time.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/07LinkQueue/LinkQueue.c"

//ͼ������ö�� 
typedef enum
{
	DirectGraph, DirectNet, UnDirectGraph, UnDirectNet
}GraphKind;

//������Ϣ 
typedef struct {}ArcInfo;
//��λ�� 
typedef struct ArcCell
{
	int vertexRelation;//������ϵ����Ȩͼ��ʾȨֵ����Ȩͼ��0��1��ʾ�Ƿ�����
	ArcInfo info;//�������Ϣ�����Ժ��� 
}ArcCell;
typedef ArcCell AdjMatrix[21][21];//���嵥λ��Ϊ�ڽӾ������ʽ��adj��adjustment�ھӵ���˼
									//����һ����ArcCell�ͱ�����ڽӾ����е�һ�������Ľṹ�� 

//ͼ�Ľṹ 
typedef struct 
{
	char vertex[21];//�������涥������� 
	AdjMatrix matrix;//�ڽӾ��󣬱��满���ö�ά���鱣�����������ʾ�� 
	int vexNum, arcNum;//ͼ�Ķ�����������
	int info;//infoΪ0�����������������Ϣ 
	GraphKind kind;//ͼ������ 
}MGraph;

//ȫ�ֱ��� 
int Visited[21];//��־����
void (*VisitFunc)(char e);//����ָ�����




int CreateGraph_M(FILE* fp, MGraph *G);//����ͼ������switch��ͬ�ĺ�������ͼ 

int CreateDirectGraph_M(FILE* fp, MGraph *G);//��������ͼ 

int CreateDirectNet_M(FILE* fp, MGraph *G);//����������

int CreateUnDirectGraph_M(FILE* fp, MGraph *G);//��������ͼ 

int CreateUnDirectNet_M(FILE* fp, MGraph *G);//���������� 

int ClearGraph_M(MGraph *G);

int LocateVertex_M(MGraph G, char e);//���ض���e��λ�ӣ�order�� 

char GetVertex_M(MGraph G, int order);//���ص�order�������ֵ 

int PutVertex_M(MGraph *G, char e, char value);//�Զ���e��ֵvalue

int FirstAdjVertex_M(MGraph G, char e);//���ض���e�ĵ�һ���ڽӵ�����

int NextAdjVertex_M(MGraph G, char e, char w);//���ض���e������ڶ���w����һ���������

int InsertVertex_M(MGraph *G, char e);//���붥��e��ͼ��

int DeleteVertex_M(MGraph *G, char e);

int InsertArc_M(MGraph *G, char e, char w, int vertexRelation, ...);//���뻡<e, w>��ͼ�У����������Ϣ��ѡ

int DeleteArc_M(MGraph *G, char e, char w);

void DFSTraverse_M(MGraph G, void(Visit)(char));
void DFS_M(MGraph G, int i);//DFS���ĺ�����i��������±� 

int BFSTraverse_M(MGraph G, void(Visit)(char));

int Output_M(MGraph G);

int Input_M(FILE* fp, ArcInfo* info);//¼�뻡�������Ϣ 

 


