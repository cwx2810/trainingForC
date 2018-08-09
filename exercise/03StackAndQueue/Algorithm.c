#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/03StackAndQueue/01SequenceStack/SequenceStack.h"
#include "../../book/03StackAndQueue/07LinkQueue/LinkQueue.h"

//用栈和队列判断字符串是不是回文数
//abcdedcba@ 
int Palindrome(char c[])
{
	SqStack S;
	InitStack_Sq(&S);
	LinkQueue Q;
	InitQueue_L(&Q);
	
	for(int i=1; c[i]!='@'; i++)//将字符读入栈和队列 
	{
		Push_Sq(&S, c[i]);
		EnQueue_L(&Q, c[i]);
	}
	
	int e1, e2;
	while(!StackEmpty_Sq(S) && !QueueEmpty_L(Q))//栈从后往前读，队列从前往后读，不一样说明不是回文 
	{
		Pop_Sq(&S, &e1);
		DeQueue_L(&Q, &e2);
		if(e1!=e2)
			return 0;
	}
	
	if(StackEmpty_Sq(S) && QueueEmpty_L(Q))
		return 1;
	
}

