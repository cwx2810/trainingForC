#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int i,j;//非零元素下标
	int e;//非零元素值 
}TNode;

typedef struct
{
	TNode data[401];//三元组非零元素节点数组，0号空出，从1开始放数值 
	int rows,cols,nozeros;// 矩阵的行数，列数，非零元素个数 
}TMatrix;

int CreateMatrix_T(FILE *fp, int n, ...);//可变参数是矩阵个数和矩阵，比如2个矩阵，就是2，A，B 

int DestroyMatrix_T(TMatrix *M);

int PrintMatrix_T(TMatrix M);

int CopyMatrix_T(TMatrix M, TMatrix *T);

int TransposeMatrix_T(TMatrix M, TMatrix *T);//矩阵转置

int FastTransposeMatrix_T(TMatrix M, TMatrix *T); 
