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

//�߽ڵ� 
typedef struct ArcNode
{
	VisitIf mark;//���ʱ�� 
	int headVex, tailVex;//�ñߵ�ͷβ�ڵ� 
	struct ArcNode* headLink;//�ñߵ�ͷβָ�� 
	struct ArcNode* tailLink;
	ArcInfo info;
}ArcNode;

//���� 
typedef struct VexNode
{
	char data;
	ArcNode* firstArc;//���ӵĵ�һ���� 
}VexNode;

typedef struct
{
	VexNode vertex[21];//��ͷС�����������һ�������� 
	int vexNum, arcNum;
	int arcInfo;
}AMLGraph;

//ȫ�ֱ��� 
ArcNode* arcPtr[21];//��ָ������ 

int CreateUnDirectGraph_AML(FILE* fp, AMLGraph *G);

int LocateVertex_AML(AMLGraph G, char e);

int Output_AML(AMLGraph G);
int ClearMark(AMLGraph G);

int Input_AML(FILE* fp, ArcInfo* info);


