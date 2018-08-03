#include "RadixSort.h"

int CreateSLList(FILE* fp, SLList* L)
{
	Scanf(fp, "%d", &(L->keyNum));//读取每个关键字中的位数 
	L->length = 0;
	char s[1000];
	while(Scanf(fp, "%s", &s)==1)//读取关键字 
	{
		L->length++;
		for(int i=0; i<L->keyNum; i++)//从低到高将关键字每一位存储到keys，123存成321 
			L->space[L->length].keys[L->keyNum-1-i] = s[i];
	}
	
	for(int i=0; i<L->length; i++)//将存储的关键字表改造成循环链表 
		L->space[i].next = i+1;
	L->space[L->length].next = 0;
	
	return 1;
}

int TraverseSLList(SLList L)
{
	for(int i=L.space[0].next; i; i=L.space[i].next)//遍历每个关键字 
	{
		for(int j=L.keyNum-1; j>=0; j--)//遍历每个关键字中的每一位，321输出成123 
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
	for(int i=0; i<L->keyNum; i++)//从321的3开始依次对关键字的各位进行分配和收集 
	{
		Distribute(L->space, i, f, e);
		Collect(L->space, i, f, e);
	}
	
	return 1;
}

int Distribute(SLKey space[], int i, int f[], int e[])//对第i位进行分配，看球不懂 
{
	int j;
	for(j=0; j<10; j++)// 各子表初始化为空表 
	{
		f[j] = 0;
		e[j] = 0;
	}
	//算法核心 
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
	for(j=0; j<10&&!f[j]; j=succ(j))//找到第一个非空子表 
		;
	if(j<10)
	{
		space[0].next = f[j];//指向第一个非空子表的第一个节点 
		int t = e[j];
		while(j<10)
		{
			for(j=succ(j); j<9&&!f[j]; j=succ(j))//寻找下一个非空子表 
				;
			if(f[j]&&j<=9)//连接两个非空子表 
			{
				space[t].next = f[j];
				t = e[j];
			}
		}
		space[t].next = 0;//指向最后一个非空子表的最后一个节点 
	}
	return 1;
}
