#include "SequenceStack.h"

int InitStack_Sq(SqStack *S)
{
	(*S).base = (int*)malloc(100*sizeof(int));
	if(!(*S).base)
		return 0;
	(*S).top = (*S).base;
	(*S).stacksize = 100;
	
	return 1;
}

int ClearStack_Sq(SqStack *S)
{
	(*S).top = (*S).base;
	
	return 1;
}

int DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	return 1;
}

int StackEmpty_Sq(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

int StackLength_Sq(SqStack S)
{
	return S.top - S.base;
}

int GetTop_Sq(SqStack S, int *e)
{
	if(S.base==S.top)
		return 0;
	*e = *(S.top-1);
	return 1;
}

int Push_Sq(SqStack *S, int e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base = (int*)realloc((*S).base, ((*S).stacksize+10)*sizeof(int));
		if(!(*S).base)
			return 0;
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += 10;
	}
	
	*((*S).top) = e;//为什么进栈先赋值，想图，top是在最后一个元素的尾部，也就是下个元素的头部 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, int *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//为什么先递减指针，想图，如果先赋值了，那top此时就没有意义了，是空的尾部 
	*e = *((*S).top);
	return 1;
}

int StackTraverse_Sq(SqStack S, void(Visit)(int))
{
	int *p = S.base;//不能破坏栈，设置临时指针 
	while(p<S.top)
	{
		Visit(*p);
		p++;
	}
	return 1;
}

