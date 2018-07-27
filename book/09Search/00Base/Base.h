#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
	float weight;
}ElemType;//���ұ�Ԫ������ 

typedef struct
{
	ElemType* elem;//��ַ
	int length; 
}Table;//���ұ� 

int CreateTable(FILE* fp, Table* T, int n);

int DestoryTable(Table* T);

int TraverseTable(Table T, void(Visit)(ElemType));

void PrintKey(ElemType e);//������ұ���Ԫ��e��key�� 
