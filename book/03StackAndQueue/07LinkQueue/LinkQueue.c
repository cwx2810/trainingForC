#include "LinkQueue.h"

int InitQueue_L(LinkQueue *Q)
{
	(*Q).front = (QNode*)malloc(sizeof(QNode));
	if(!(*Q).front)
		return 0;
	(*Q).front->next = NULL;
	(*Q).rear = (*Q).front;
	return 1;
}

int ClearQueue_L(LinkQueue *Q)
{
	(*Q).rear = (*Q).front->next;//尾指针指向除头结点外的第一个节点 
	while((*Q).rear)//利用尾指针删掉所有除头结点意外的节点 
	{
		(*Q).front->next = (*Q).rear->next;
		free((*Q).rear);
		(*Q).rear = (*Q).front->next;
	}
	(*Q).rear = (*Q).front;//尾指针最后归置到头结点上 
	return 1;
}


int DestroyQueue_L(LinkQueue *Q)
{
	while((*Q).front)//利用头尾指针删掉每个节点 
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return 1;
}

int QueueEmpty_L(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

int QueueLength_L(LinkQueue Q)
{
	int count = 0;
	QNode* p = Q.front->next;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

int GetHead_L(LinkQueue Q, int *e)
{
	if(Q.front==Q.rear)
		return 0;
	*e = Q.front->next->data;
	return 1;
}

int EnQueue_L(LinkQueue *Q, int e)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if(!p)
		return 0;
	p->data = e;
	p->next = NULL;//前面都是构造一个存e的node 
	
	(*Q).rear->next = p;//从队尾入队 
	(*Q).rear = p;
	return 1;
}

int DeQueue_L(LinkQueue *Q, int *e)
{
	if((*Q).front==(*Q).rear)
		return 0;
		
	QNode* p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;//从队头删除 
	if((*Q).rear == p)//如果删的是最后一个节点，要处理尾指针 
		(*Q).rear = (*Q).front;
	free(p);
	return 1;
}


int QueueTraverse_L(LinkQueue Q, void(Visit)(int))
{
	QNode* p = Q.front->next;
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
	return 1;
}

