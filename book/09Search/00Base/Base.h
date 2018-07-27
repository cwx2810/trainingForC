#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
	float weight;
}ElemType;//查找表元素类型 

typedef struct
{
	ElemType* elem;//基址
	int length; 
}Table;//查找表 

int CreateTable(FILE* fp, Table* T, int n);

int DestoryTable(Table* T);

int TraverseTable(Table T, void(Visit)(ElemType));

void PrintKey(ElemType e);//输出查找表中元素e的key域 
