#include "SequenceArray.h"

int InitArray(Array *A, int dim, ...)
{
	if(dim<1 || dim>8)//数组维度有限制 
		return 0;
	A->dim = dim;
	
	A->bounds = (int*)malloc(dim*sizeof(int));
	if(!A->bounds)
		return 0;
	int elemtotal = 1;//此时总元素为1，保存了dim信息
	va_list ap;//保存传入的可变参数 
	va_start(ap, dim);//初始化ap，dim是可变参数的第一个参数 
	for(int i=0; i<dim; i++)
	{
		A->bounds[i] = va_arg(ap, int);//返回int型的可变参数：数组行列信息
		if(A->bounds[i]<=0)
			return 0;
		elemtotal = elemtotal*A->bounds[i]; 
	} 
	va_end(ap);//ap使命完成，置空 
	
	A->base = (int*)malloc(elemtotal*sizeof(int));//初始化数组空间 
	if(!A->base)
		return 0;
		
	A->constants = (int*)malloc(dim*sizeof(int));//初始化跨越元素数组 
	if(!A->constants)
		return 0;
	A->constants[dim-1] = 1;//因为是倒着的，所以先初始化数组最后一个元素，也就是最底层每次跨越1个元素
	for(int i=dim-2; i>=0; i--)
		A->constants[i] = A->bounds[i+1]*A->constants[i+1];//这个公式画图才能明白，反正这俩相乘刚好可以得到结果 
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
	
	A->dim = 0;//ps:这里也可以用(*A).dim = 0 
	
	return 1;
	
}

int LocateArray(Array A, va_list ap, int* off)
{
	*off = 0;
	int arg;
	for(int i=0; i<A.dim; i++)
	{
		arg = va_arg(ap, int);
		if(arg<0 || arg>=A.bounds[i])//可变参数给的当前维度大节点数目，也就是行列信息越界 
			return 0;
		*off = *off + A.constants[i]*arg;//比如2维，节点的位置是每行元素数目乘以行数 
	}
	return 1;
}

int ValueArray(Array A, int *e, ...)
{
	va_list ap;
	va_start(ap, *e);//初始化ap 
	int off;
	int result = LocateArray(A, ap, &off); //得到要取得元素的相对位置 
	if(!result)
		return 0;
	*e = *(A.base+off);//从绝对位置取到值
	return 1; 
}

int AssignArray(Array *A, int e, ...)
{
	va_list ap;
	va_start(ap, e);//初始化ap 
	int off;
	int result = LocateArray(*A, ap, &off);//得到赋值元素要摆放的相对位置 
	if(!result)
		return 0;
	*(A->base + off) = e;//赋值到绝对位置 
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

