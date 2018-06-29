#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../01intro/Status.h"

typedef struct
{
	int dim;//����ά�� 
	int* bounds;//ÿ��ά���еĽڵ����
	int* base;//�����ַ  
	int* constants;//һ��ά���������ڵ�֮���Խ��Ԫ�ظ��� 
}Array;

int InitArray(Array *A, int dim, ...);//...�ǲ�ȷ����Ҫ����Щ���� 

int DestroyArray(Array *A);

int LocateArray(Array A, va_list ap, int* off);

int ValueArray(Array A, int *e, ...);

int AssignArray(Array *A, int e, ...);

int ArrayPrint(Array A);

