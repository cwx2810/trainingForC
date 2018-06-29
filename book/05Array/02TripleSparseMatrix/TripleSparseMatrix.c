#include "TripleSparseMatrix.h"

int CreateMatrix_T(FILE *fp, int n, ...)
{
	if(n<1)
		return 0;
	
	va_list ap;
	va_start(ap, n);//��ʼ��ap
	TMatrix *M;//��������ָ��
	for(int count=1; count<=n; count++)
	{
		M = va_arg(ap, TMatrix*);//�õ�����ָ�����
		Scanf(fp, "%d%d%d", &((*M).rows), &((*M).cols), &((*M).nozeros));//��������Ԫ�����ж�����Ϣ 
		for(int k=1; k<=(*M).nozeros; k++)
			Scanf(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));//��ÿ��node�ж�����Ϣ 
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
	int k = 1;//������ֵ�������еĴ洢��� 
	for(rows=1; rows<=M.rows; rows++)//����Ԫ��һ��һ�б�������ЩԪ���е��Ƿ�0���е���0 
	{
		for(cols=1; cols<=M.cols; cols++)
		{
			if(rows==M.data[k].i && cols==M.data[k].j)//����Ƿ���Ԫ�ص�����λ�þʹ���� 
			{
				printf("%3d ", M.data[k].e);
				k++;
			}
			else
				printf("  0 ");
		}
		printf("\n");//�к���֮���һ�� 
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
		
	int p = 1;//��ʼ��T�����еķ�������Ԫ�ر�� 
	for(int colsM=1; colsM<=M.cols; colsM++)
	{
		for(int k=1; k<=M.nozeros; k++)
		{
			if(colsM==M.data[k].j)//�����M�������еķ���Ԫ�أ�Ҳ����T���еķ���Ԫ�� 
			{
				T->data[p].i = M.data[k].j;//M�������Ԫ���±���T�������Ԫ���±�
				T->data[p].j = M.data[k].i;//ͬ��
				T->data[p].e = M.data[k].e;//ֵ����
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
		nozeroNum[colM] = 0;//��ʼ�����鱣��M����ÿ�з���Ԫ�ظ��� 
	
	for(int t=1; t<=M.nozeros; t++)
		nozeroNum[M.data[t].j]++;//ͳ��M����ÿ�з���Ԫ�ظ���
		
	int pos[M.cols];
	pos[1] = 1;
	for(colM=2; colM<=M.cols; colM++)
	 	pos[colM] = pos[colM-1] + nozeroNum[colM-1];//ͳ��M����ÿ�е�һ������Ԫ����T�����е�����Ԫ���±� 
	
	for(int p=1; p<=M.nozeros; p++)
	{
		colM = M.data[p].j;//�õ�M�������Ԫ�ص���
		int k = pos[colM];//�õ�M�������Ԫ����T�е�����Ԫ���±� 
		
		T->data[k].i = M.data[p].j;
		T->data[k].j = M.data[p].i;
		T->data[k].e = M.data[p].e;
		pos[colM]++; 
	} 
	return 1;
}
