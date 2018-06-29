#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../01intro/Status.h"

typedef struct
{
	int dim;//数组维度 
	int* bounds;//每个维度中的节点个数
	int* base;//数组基址  
	int* constants;//一个维度中两个节点之间跨越的元素个数 
}Array;

int InitArray(Array *A, int dim, ...);//...是不确定需要传哪些参数 

int DestroyArray(Array *A);

int LocateArray(Array A, va_list ap, int* off);

int ValueArray(Array A, int *e, ...);

int AssignArray(Array *A, int e, ...);

int ArrayPrint(Array A);

