#include <stdio.h>
#include <stdlib.h>

#include "../../01intro/Status.h"

//循环队列的顺序存储结构 
typedef struct
{
	int* base;
	int front;//指向队头元素 
	int rear;//指向队尾元素的下一个位置 
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




