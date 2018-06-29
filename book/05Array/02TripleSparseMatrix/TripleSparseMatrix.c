#include "TripleSparseMatrix.h"

int CreateMatrix_T(FILE *fp, int n, ...)
{
	if(n<1)
		return 0;
	
	va_list ap;
	va_start(ap, n);//初始化ap
	TMatrix *M;//声明矩阵指针
	for(int count=1; count<=n; count++)
	{
		M = va_arg(ap, TMatrix*);//得到矩阵指针参数
		Scanf(fp, "%d%d%d", &((*M).rows), &((*M).cols), &((*M).nozeros));//往非零三元数组中读入信息 
		for(int k=1; k<=(*M).nozeros; k++)
			Scanf(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));//往每个node中读入信息 
	}
	va_end(ap);
	return 1; 
}

int DestroyMatrix_T(TMatrix *M)
{
	(*M).rows = 0;
	(*M).cols = 0;
	(*M).nozeros = 0;
	return 1;
}

int PrintMatrix_T(TMatrix M)
{
	int rows,cols;
	int k = 1;//非零数值在数组中的存储编号 
	for(rows=1; rows<=M.rows; rows++)//挨个元素一行一行遍历，这些元素有的是非0，有的是0 
	{
		for(cols=1; cols<=M.cols; cols++)
		{
			if(rows==M.data[k].i && cols==M.data[k].j)//如果是非零元素的行列位置就打出来 
			{
				printf("%3d ", M.data[k].e);
				k++;
			}
			else
				printf("  0 ");
		}
		printf("\n");//行和行之间空一行 
	}
	return 1;
}

int CopyMatrix_T(TMatrix M, TMatrix *T)
{
	(*T) = M;
	return 1;
}

int TransposeMatrix_T(TMatrix M, TMatrix *T)
{
	T->rows = M.rows;
	T->cols = M.cols;
	T->nozeros = M.nozeros;
	if(!T->nozeros)
		return 0;
		
	int p = 1;//初始化T矩阵中的非零数组元素编号 
	for(int colsM=1; colsM<=M.cols; colsM++)
	{
		for(int k=1; k<=M.nozeros; k++)
		{
			if(colsM==M.data[k].j)//如果是M矩阵列中的非零元素，也就是T中行的非零元素 
			{
				T->data[p].i = M.data[k].j;//M矩阵的列元素下标变成T矩阵的行元素下标
				T->data[p].j = M.data[k].i;//同上
				T->data[p].e = M.data[k].e;//值不变
				p++; 
			} 
		}
	}
	return 1;
}

int FastTransposeMatrix_T(TMatrix M, TMatrix *T)
{
	T->rows = M.rows;
	T->cols = M.cols;
	T->nozeros = M.nozeros;
	if(!T->nozeros)
		return 0;
	
	int colM;
	int nozeroNum[M.cols];
	for(colM=1; colM<=M.cols; colM++)
		nozeroNum[colM] = 0;//初始化数组保存M矩阵每列非零元素个数 
	
	for(int t=1; t<=M.nozeros; t++)
		nozeroNum[M.data[t].j]++;//统计M矩阵每列非零元素个数
		
	int pos[M.cols];
	pos[1] = 1;
	for(colM=2; colM<=M.cols; colM++)
	 	pos[colM] = pos[colM-1] + nozeroNum[colM-1];//统计M矩阵每列第一个非零元素在T矩阵中的数组元素下标 
	
	for(int p=1; p<=M.nozeros; p++)
	{
		colM = M.data[p].j;//得到M矩阵非零元素的列
		int k = pos[colM];//得到M矩阵非零元素在T中的数组元素下标 
		
		T->data[k].i = M.data[p].j;
		T->data[k].j = M.data[p].i;
		T->data[k].e = M.data[p].e;
		pos[colM]++; 
	} 
	return 1;
}
