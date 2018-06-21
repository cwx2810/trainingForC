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
	
	*((*S).top) = e;//Ϊʲô��ջ�ȸ�ֵ����ͼ��top�������һ��Ԫ�ص�β����Ҳ�����¸�Ԫ�ص�ͷ�� 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, int *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//Ϊʲô�ȵݼ�ָ�룬��ͼ������ȸ�ֵ�ˣ���top��ʱ��û�������ˣ��ǿյ�β�� 
	*e = *((*S).top);
	return 1;
}

int StackTraverse_Sq(SqStack S, void(Visit)(int))
{
	int *p = S.base;//�����ƻ�ջ��������ʱָ�� 
	while(p<S.top)
	{
		Visit(*p);
		p++;
	}
	return 1;
}

