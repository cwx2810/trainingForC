#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
	float weight;
}ElemType;//���ұ�Ԫ�����ͣ���������(1��1.0)��С�ṹ 

typedef struct
{
	ElemType* elem;//��ַ��0�ŵ�Ԫ���ã���1��ʼ��key��weight 
	int length; 
}Table;//���ұ�����С�ṹ����� 

int CreateTable(FILE* fp, Table* T, int n);

int DestoryTable(Table* T);

int TraverseTable(Table T, void(Visit)(ElemType));

void PrintKey(ElemType e);//������ұ���Ԫ��e��key�� 
