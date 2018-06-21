#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"

typedef struct
{
	int *base;//ջ��ָ�룬�൱��ԭ��˳����elem����ַ 
	int *top;//ջ��ָ�� 
	int stacksize;//ջ��Ԫ�ظ��� 
}SqStack;

int InitStack_Sq(SqStack *S);

int ClearStack_Sq(SqStack *S);

int DestroyStack_Sq(SqStack *S);

int StackEmpty_Sq(SqStack S);

int StackLength_Sq(SqStack S);

int GetTop_Sq(SqStack S, int *e);

int Push_Sq(SqStack *S, int e);

int Pop_Sq(SqStack *S, int *e);

int StackTraverse_Sq(SqStack S, void(Visit)(int));

