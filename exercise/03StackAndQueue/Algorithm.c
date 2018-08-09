#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/03StackAndQueue/01SequenceStack/SequenceStack.h"
#include "../../book/03StackAndQueue/07LinkQueue/LinkQueue.h"

//��ջ�Ͷ����ж��ַ����ǲ��ǻ�����
//abcdedcba@ 
int Palindrome(char c[])
{
	SqStack S;
	InitStack_Sq(&S);
	LinkQueue Q;
	InitQueue_L(&Q);
	
	for(int i=1; c[i]!='@'; i++)//���ַ�����ջ�Ͷ��� 
	{
		Push_Sq(&S, c[i]);
		EnQueue_L(&Q, c[i]);
	}
	
	int e1, e2;
	while(!StackEmpty_Sq(S) && !QueueEmpty_L(Q))//ջ�Ӻ���ǰ�������д�ǰ���������һ��˵�����ǻ��� 
	{
		Pop_Sq(&S, &e1);
		DeQueue_L(&Q, &e2);
		if(e1!=e2)
			return 0;
	}
	
	if(StackEmpty_Sq(S) && QueueEmpty_L(Q))
		return 1;
	
}

