#include <stdio.h>
#include <stdlib.h>

#include "../../01intro/Status.h"

//ѭ�����е�˳��洢�ṹ 
typedef struct
{
	int* base;
	int front;//ָ���ͷԪ�� 
	int rear;//ָ���βԪ�ص���һ��λ�� 
}SqQueue;

int InitQueue_Sq(SqQueue *Q);

int ClearQueue_Sq(SqQueue *Q);

int DestroyQueue_Sq(SqQueue *Q);

int QueueEmpty_Sq(SqQueue Q);

int QueueLength_Sq(SqQueue Q);

int GetHead_Sq(SqQueue Q, int *e);

int EnQueue_Sq(SqQueue *Q, int e);

int DeQueue_Sq(SqQueue *Q, int *e);

int QueueTraverse_Sq(SqQueue Q, void(Visit)(int));




