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
	(*Q).rear = (*Q).front->next;//βָ��ָ���ͷ�����ĵ�һ���ڵ� 
	while((*Q).rear)//����βָ��ɾ�����г�ͷ�������Ľڵ� 
	{
		(*Q).front->next = (*Q).rear->next;
		free((*Q).rear);
		(*Q).rear = (*Q).front->next;
	}
	(*Q).rear = (*Q).front;//βָ�������õ�ͷ����� 
	return 1;
}


int DestroyQueue_L(LinkQueue *Q)
{
	while((*Q).front)//����ͷβָ��ɾ��ÿ���ڵ� 
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
	p->next = NULL;//ǰ�涼�ǹ���һ����e��node 
	
	(*Q).rear->next = p;//�Ӷ�β��� 
	(*Q).rear = p;
	return 1;
}

int DeQueue_L(LinkQueue *Q, int *e)
{
	if((*Q).front==(*Q).rear)
		return 0;
		
	QNode* p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;//�Ӷ�ͷɾ�� 
	if((*Q).rear == p)//���ɾ�������һ���ڵ㣬Ҫ����βָ�� 
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

