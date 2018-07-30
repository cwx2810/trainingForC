#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
	float weight;
}ElemType;//查找表元素类型，就是类似(1，1.0)的小结构 

typedef struct
{
	ElemType* elem;//基址，0号单元弃用，从1开始存key和weight 
	int length; 
}Table;//查找表，无数小结构的组合 

int CreateTable(FILE* fp, Table* T, int n);

int DestoryTable(Table* T);

int TraverseTable(Table T, void(Visit)(ElemType));

void PrintKey(ElemType e);//输出查找表中元素e的key域 
