#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"

typedef struct
{
	int *base;//栈底指针，相当于原来顺序表的elem，基址 
	int *top;//栈顶指针 
	int stacksize;//栈中元素个数 
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

