#include "CylSeqQueue.h"

int InitQueue_Sq(SqQueue *Q)
{
	(*Q).base = (int*)malloc(1000*sizeof(int));
	if(!(*Q).base)
		return 0;
	(*Q).front = (*Q).rear = 0;
	return 1;
}

int ClearQueue_Sq(SqQueue *Q)
{
	(*Q).front = (*Q).rear = 0;
	return 1;
}

int DestroyQueue_Sq(SqQueue *Q)
{
	if((*Q).base)
		free((*Q).base);
	(*Q).base = NULL;//避免野指针 
	(*Q).front = (*Q).rear = 0;
	return 1;
}

int QueueEmpty_Sq(SqQueue Q)
{
	if(Q.front == Q.rear)//队空标志 
		return 1;
	else
		return 0;
}

int QueueLength_Sq(SqQueue Q)
{
	return (Q.rear-Q.front+1000)%1000; //队列长度，+1000是转盘转到rear比front小，1000取余是指针加不到0，但转盘上有0 
}

int GetHead_Sq(SqQueue Q, int *e)
{
	if(Q.front == Q.rear)
		return 0;
	*e = Q.base[Q.front];
	return 1;
}

int EnQueue_Sq(SqQueue *Q, int e)
{
	if(((*Q).rear+1)%1000==(*Q).front)//队列满，同样防止走到0要取余1000，这样才是真的追到front 
		return 0;
	(*Q).base[(*Q).rear] = e;//队尾追加
	(*Q).rear = ((*Q).rear+1)%1000;//移动队尾，只要是有加减法都要取余
	return 1; 
}

int DeQueue_Sq(SqQueue *Q, int *e)
{
	if((*Q).front == (*Q).rear)//队空标志 
		return 0;
	*e = (*Q).base[(*Q).front];//队头出队
	(*Q).front = ((*Q).front+1)%1000;
	return 1; 
}

int QueueTraverse_Sq(SqQueue Q, void(Visit)(int))
{
	int p = Q.front;//设置游标，只不过这里用数组承载队列，用int下标承载指针
	while(p!=Q.rear)//如果没到队空，就一直遍历 
	{
		Visit(Q.base[p]);
		p = (p+1)%1000;
	} 
	return 1;
}



