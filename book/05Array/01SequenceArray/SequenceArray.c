#include "SequenceArray.h"

int InitArray(Array *A, int dim, ...)
{
	if(dim<1 || dim>8)//����ά�������� 
		return 0;
	A->dim = dim;
	
	A->bounds = (int*)malloc(dim*sizeof(int));
	if(!A->bounds)
		return 0;
	int elemtotal = 1;//��ʱ��Ԫ��Ϊ1��������dim��Ϣ
	va_list ap;//���洫��Ŀɱ���� 
	va_start(ap, dim);//��ʼ��ap��dim�ǿɱ�����ĵ�һ������ 
	for(int i=0; i<dim; i++)
	{
		A->bounds[i] = va_arg(ap, int);//����int�͵Ŀɱ����������������Ϣ
		if(A->bounds[i]<=0)
			return 0;
		elemtotal = elemtotal*A->bounds[i]; 
	} 
	va_end(ap);//apʹ����ɣ��ÿ� 
	
	A->base = (int*)malloc(elemtotal*sizeof(int));//��ʼ������ռ� 
	if(!A->base)
		return 0;
		
	A->constants = (int*)malloc(dim*sizeof(int));//��ʼ����ԽԪ������ 
	if(!A->constants)
		return 0;
	A->constants[dim-1] = 1;//��Ϊ�ǵ��ŵģ������ȳ�ʼ���������һ��Ԫ�أ�Ҳ������ײ�ÿ�ο�Խ1��Ԫ��
	for(int i=dim-2; i>=0; i--)
		A->constants[i] = A->bounds[i+1]*A->constants[i+1];//�����ʽ��ͼ�������ף�����������˸պÿ��Եõ���� 
	return 1;
}

int DestroyArray(Array *A)
{
	if(!A->base)
		return 0;
	free(A->base);
	A->base = NULL;
	
	if(!A->bounds)
		return 0;
	free(A->bounds);
	A->bounds = NULL;
	
	if(!A->constants)
		return 0;
	free(A->constants);
	A->constants = NULL;
	
	A->dim = 0;//ps:����Ҳ������(*A).dim = 0 
	
	return 1;
	
}

int LocateArray(Array A, va_list ap, int* off)
{
	*off = 0;
	int arg;
	for(int i=0; i<A.dim; i++)
	{
		arg = va_arg(ap, int);
		if(arg<0 || arg>=A.bounds[i])//�ɱ�������ĵ�ǰά�ȴ�ڵ���Ŀ��Ҳ����������ϢԽ�� 
			return 0;
		*off = *off + A.constants[i]*arg;//����2ά���ڵ��λ����ÿ��Ԫ����Ŀ�������� 
	}
	return 1;
}

int ValueArray(Array A, int *e, ...)
{
	va_list ap;
	va_start(ap, *e);//��ʼ��ap 
	int off;
	int result = LocateArray(A, ap, &off); //�õ�Ҫȡ��Ԫ�ص����λ�� 
	if(!result)
		return 0;
	*e = *(A.base+off);//�Ӿ���λ��ȡ��ֵ
	return 1; 
}

int AssignArray(Array *A, int e, ...)
{
	va_list ap;
	va_start(ap, e);//��ʼ��ap 
	int off;
	int result = LocateArray(*A, ap, &off);//�õ���ֵԪ��Ҫ�ڷŵ����λ�� 
	if(!result)
		return 0;
	*(A->base + off) = e;//��ֵ������λ�� 
	return 1;
}

int ArrayPrint(Array A)
{
	int elemtotal = 1;
	for(int i=0; i<A.dim; i++)
		elemtotal = elemtotal*A.bounds[i];
	for(int i=0; i<elemtotal; i++)
		printf("%d ", A.base[i]);
}

