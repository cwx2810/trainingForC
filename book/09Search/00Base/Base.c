#include "Base.h"

int CreateTable(FILE* fp, Table* T, int n)
{
	T->elem = (ElemType*)malloc((n+1)*sizeof(ElemType));//初始化表T 
	if(!(T->elem))
		return 0;
	(*T).length = 0;
	
	int a;
	float b;
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d%f", &a, &b)==2)//如果能读到key和weight，则更新表T 
		{
			(*T).elem[i].key = i;
			(*T).elem[i].weight = b;
			(*T).length++;
		}
	}
	return 1;
}

int DestoryTable(Table* T)
{
	if(T->elem)
		free(T->elem);
	T->elem = NULL;//避免野指针 
	T->length = 0;
	return 1;
}

int TraverseTable(Table T, void(Visit)(ElemType))
{
	for(int i=0; i<T.length; i++)
	{
		if(i && !(i%10))//如果不是整数，直接跳过，只遍历key 
			printf("\n");
		Visit(T.elem[i+1]);
	}
	printf("\n");
	return 1;
}

void PrintKey(ElemType e)
{
	printf("%3d ", e.key);
}
