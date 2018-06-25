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
	(*Q).base = NULL;//����Ұָ�� 
	(*Q).front = (*Q).rear = 0;
	return 1;
}

int QueueEmpty_Sq(SqQueue Q)
{
	if(Q.front == Q.rear)//�ӿձ�־ 
		return 1;
	else
		return 0;
}

int QueueLength_Sq(SqQueue Q)
{
	return (Q.rear-Q.front+1000)%1000; //���г��ȣ�+1000��ת��ת��rear��frontС��1000ȡ����ָ��Ӳ���0����ת������0 
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
	if(((*Q).rear+1)%1000==(*Q).front)//��������ͬ����ֹ�ߵ�0Ҫȡ��1000�������������׷��front 
		return 0;
	(*Q).base[(*Q).rear] = e;//��β׷��
	(*Q).rear = ((*Q).rear+1)%1000;//�ƶ���β��ֻҪ���мӼ�����Ҫȡ��
	return 1; 
}

int DeQueue_Sq(SqQueue *Q, int *e)
{
	if((*Q).front == (*Q).rear)//�ӿձ�־ 
		return 0;
	*e = (*Q).base[(*Q).front];//��ͷ����
	(*Q).front = ((*Q).front+1)%1000;
	return 1; 
}

int QueueTraverse_Sq(SqQueue Q, void(Visit)(int))
{
	int p = Q.front;//�����αֻ꣬����������������ض��У���int�±����ָ��
	while(p!=Q.rear)//���û���ӿգ���һֱ���� 
	{
		Visit(Q.base[p]);
		p = (p+1)%1000;
	} 
	return 1;
}



