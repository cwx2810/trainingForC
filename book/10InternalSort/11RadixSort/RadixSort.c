#include "RadixSort.h"

int CreateSLList(FILE* fp, SLList* L)
{
	Scanf(fp, "%d", &(L->keyNum));//��ȡÿ���ؼ����е�λ�� 
	L->length = 0;
	char s[1000];
	while(Scanf(fp, "%s", &s)==1)//��ȡ�ؼ��� 
	{
		L->length++;
		for(int i=0; i<L->keyNum; i++)//�ӵ͵��߽��ؼ���ÿһλ�洢��keys��123���321 
			L->space[L->length].keys[L->keyNum-1-i] = s[i];
	}
	
	for(int i=0; i<L->length; i++)//���洢�Ĺؼ��ֱ�����ѭ������ 
		L->space[i].next = i+1;
	L->space[L->length].next = 0;
	
	return 1;
}

int TraverseSLList(SLList L)
{
	for(int i=L.space[0].next; i; i=L.space[i].next)//����ÿ���ؼ��� 
	{
		for(int j=L.keyNum-1; j>=0; j--)//����ÿ���ؼ����е�ÿһλ��321�����123 
			printf("%c", L.space[i].keys[j]);
		printf(" ");
	}
	printf("\n");
	
	return 1;
}

int RadixSort(SLList* L)
{
	int f[10];
	int e[10];
	for(int i=0; i<L->keyNum; i++)//��321��3��ʼ���ζԹؼ��ֵĸ�λ���з�����ռ� 
	{
		Distribute(L->space, i, f, e);
		Collect(L->space, i, f, e);
	}
	
	return 1;
}

int Distribute(SLKey space[], int i, int f[], int e[])//�Ե�iλ���з��䣬���򲻶� 
{
	int j;
	for(j=0; j<10; j++)// ���ӱ��ʼ��Ϊ�ձ� 
	{
		f[j] = 0;
		e[j] = 0;
	}
	//�㷨���� 
	for(int p=space[0].next; p; p=space[p].next)
	{
		j = ord(space[p].keys[i]); 
		if(f[j]==0)
			f[j] = p;
		else
			space[e[j]].next = p;
		e[j] = p;
	}
	return 1;
}

int Collect(SLKey space[], int i, int f[], int e[])
{
	int j;
	for(j=0; j<10&&!f[j]; j=succ(j))//�ҵ���һ���ǿ��ӱ� 
		;
	if(j<10)
	{
		space[0].next = f[j];//ָ���һ���ǿ��ӱ�ĵ�һ���ڵ� 
		int t = e[j];
		while(j<10)
		{
			for(j=succ(j); j<9&&!f[j]; j=succ(j))//Ѱ����һ���ǿ��ӱ� 
				;
			if(f[j]&&j<=9)//���������ǿ��ӱ� 
			{
				space[t].next = f[j];
				t = e[j];
			}
		}
		space[t].next = 0;//ָ�����һ���ǿ��ӱ�����һ���ڵ� 
	}
	return 1;
}
