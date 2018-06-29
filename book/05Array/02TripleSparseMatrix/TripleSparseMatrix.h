#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int i,j;//����Ԫ���±�
	int e;//����Ԫ��ֵ 
}TNode;

typedef struct
{
	TNode data[401];//��Ԫ�����Ԫ�ؽڵ����飬0�ſճ�����1��ʼ����ֵ 
	int rows,cols,nozeros;// ���������������������Ԫ�ظ��� 
}TMatrix;

int CreateMatrix_T(FILE *fp, int n, ...);//�ɱ�����Ǿ�������;��󣬱���2�����󣬾���2��A��B 

int DestroyMatrix_T(TMatrix *M);

int PrintMatrix_T(TMatrix M);

int CopyMatrix_T(TMatrix M, TMatrix *T);

int TransposeMatrix_T(TMatrix M, TMatrix *T);//����ת��

int FastTransposeMatrix_T(TMatrix M, TMatrix *T); 
