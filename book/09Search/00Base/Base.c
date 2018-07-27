#include "Base.h"

int CreateTable(FILE* fp, Table* T, int n)
{
	T->elem = (ElemType*)malloc((n+1)*sizeof(ElemType));//��ʼ����T 
	if(!(T->elem))
		return 0;
	(*T).length = 0;
	
	int a;
	float b;
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d%f", &a, &b)==2)//����ܶ���key��weight������±�T 
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
	T->elem = NULL;//����Ұָ�� 
	T->length = 0;
	return 1;
}

int TraverseTable(Table T, void(Visit)(ElemType))
{
	for(int i=0; i<T.length; i++)
	{
		if(i && !(i%10))//�������������ֱ��������ֻ����key 
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
