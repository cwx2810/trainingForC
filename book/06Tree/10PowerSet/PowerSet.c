#include "PowerSet.h"

int CreatePowerSet_PS(FILE* fp, LNode** A)
{
	InitList_L(A);
	int n;//元素个数 
	Scanf(fp, "%d", &n);
	printf("录入集合A的元素个数为%d\n", n);
	int e;//录入的元素 
	for(int i=1; i<=n; i++)
	{
		Scanf(fp, "%d", &e);
		ListInsert_L(*A, i, e);
		printf("录入的第%d个元素%d\n", i, e);
	}
	return 1;
}

int GetPowerSet_PS(int i, LNode* A, LNode* B)
{
	int len;//临时记住B的长度用 
	int e;//临时存放元素 
	if(i<=ListLength_L(A))
	{
		GetElem_L(A, i, &e);//获取集合A的第i个元素赋给e 
		len = ListLength_L(B);
		
		// 只要记住这样 (插入、递归) 紧接着 (删除、递归) 会输出集合所有的可能性就行了
		ListInsert_L(B, len+1, e);
		GetPowerSet_PS(i+1, A, B); 
		ListDelete_L(B, len+1, &e);
		GetPowerSet_PS(i+1, A, B); 
	}
	else
		Output_PS(B);
	return 1;
}

int Output_PS(LNode* A)
{
	if(!ListLength_L(A))
		printf("空");
	else
	{
		LNode* p = A->next;//初始化游标p为第一个有意义的节点 
		while(p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}
