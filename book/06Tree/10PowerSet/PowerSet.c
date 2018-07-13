#include "PowerSet.h"

int CreatePowerSet_PS(FILE* fp, LNode** A)
{
	InitList_L(A);
	int n;//Ԫ�ظ��� 
	Scanf(fp, "%d", &n);
	printf("¼�뼯��A��Ԫ�ظ���Ϊ%d\n", n);
	int e;//¼���Ԫ�� 
	for(int i=1; i<=n; i++)
	{
		Scanf(fp, "%d", &e);
		ListInsert_L(*A, i, e);
		printf("¼��ĵ�%d��Ԫ��%d\n", i, e);
	}
	return 1;
}

int GetPowerSet_PS(int i, LNode* A, LNode* B)
{
	int len;//��ʱ��סB�ĳ����� 
	int e;//��ʱ���Ԫ�� 
	if(i<=ListLength_L(A))
	{
		GetElem_L(A, i, &e);//��ȡ����A�ĵ�i��Ԫ�ظ���e 
		len = ListLength_L(B);
		
		// ֻҪ��ס���� (���롢�ݹ�) ������ (ɾ�����ݹ�) ������������еĿ����Ծ�����
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
		printf("��");
	else
	{
		LNode* p = A->next;//��ʼ���α�pΪ��һ��������Ľڵ� 
		while(p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}
