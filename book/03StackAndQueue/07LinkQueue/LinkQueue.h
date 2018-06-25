#include <stdio.h>
#include <stdlib.h>

#include "../../01intro/Status.h"

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* front;
	QNode* rear;
}LinkQueue;

int InitQueue_L(LinkQueue *Q);

int ClearQueue_L(LinkQueue *Q);

int DestroyQueue_L(LinkQueue *Q);

int QueueEmpty_L(LinkQueue Q);

int QueueLength_L(LinkQueue Q);

int GetHead_L(LinkQueue Q, int *e);

int EnQueue_L(LinkQueue *Q, int e);

int DeQueue_L(LinkQueue *Q, int *e);

int QueueTraverse_L(LinkQueue Q, void(Visit)(int));

