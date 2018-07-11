#include "MFSet.h"

int InitMFSet(FILE* fp, MFSet* S)
{
	Scanf(fp, "%d", &(S->n));//��ȡ���鼯���� 
	for(int i=1; i<=S->n; i++)//node[0]���� 
	{
		Scanf(fp, "%d", &i);//��ȡ���鼯Ԫ�ظ�����ʱ����i 
		S->node[i].data = i;//����������˸ոպõ��漼���ɣ���Ϊ���Լ��������1~10������iҲ��1~10������˵i�����±�����data 
		S->node[i].parent = -1; //parent��ͳһ��ʼ��Ϊ-1������ЩԪ��ȫ�Ǹ��ڵ� 
	}
	return 1;
}

int FindMFSet(MFSet S, int i)
{
	if(i<1 || i>S.n)
		return 0;
	int root;
	for(root=i; S.node[root].parent>0; root=S.node[root].parent)//�ҵ�parent��-1�ĵ���Ǹ��ڵ� 
		;
	return root;
}

int FixMFSet(MFSet* S, int i)
{
	if(i<1 || i>S->n)
		return 0;
	int root;
	for(root=i; S->node[root].parent>0; root=S->node[root].parent)//�ҵ����ڵ� 
		;
	int parent;
	for(int p=i; p!=root; p=parent)//p�Ǳ����ڵ㣬Ϊ�˲�Ӱ��i����ģ���iһֱ������root 
	{
		parent = S->node[p].parent;//parentʼ��Ϊ��ǰ�ڵ�ĸ��ڵ� 
		S->node[p].parent = root;//��һ·�ϱ������Ľڵ㶼���root�ĺ��ӽڵ㣬Ҳ���ǰ�����ѹ��Ϊ2 
	}
	return root;
}

int MergeMFSet(MFSet* S, int i, int j)
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return 0;
	if(i!=j)
		S->node[i].parent = j;//���i��j����ȣ����i����j�Ķ���
	return 1; 
}

int MixMFSet(MFSet* S, int i, int j)//parent���¼�Ӽ�������Ԫ����Ŀ�ĸ�ֵ 
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return 0;
	if(S->node[i].parent > S->node[j].parent)//i�Ĵ�˵������Ԫ���٣�����j��ȥ 
	{
		S->node[j].parent += S->node[i].parent;//�޸�j����ĿΪ������ֵ
		S->node[i].parent = j;//�ϲ����� 
	}
	else
	{
		S->node[i].parent += S->node[j].parent;
		S->node[j].parent = i;
	}
	return 1;
}

int BuildRelationMFSet(FILE* fp, Relation* R)
{
	Scanf(fp, "%d", &(R->n));//��ȡ��ϵ�ڵ����
	if(R->n < 0)
		return 0;
	
	for(int k=1; k<=R->n; k++)
		 Scanf(fp, "%d%d", &(R->nodes[k-1].i), &(R->nodes[k-1].j));//��ȡ��ϵ�ڵ㸳��i��j 
 	return 1;
}

int EquivalenceClassMFSet(MFSet* S, Relation R)
{
	for(int k=1; k<=R.n; k++)
	{
		int x = FindMFSet(*S, R.nodes[k-1].i);//��S��Ѱ�Ҹ�����ϵ��ֵ���ڼ��ϵĸ��ڵ� 
		int y = FindMFSet(*S, R.nodes[k-1].j);
		MergeMFSet(S, x, y);//�ϲ����ڵ㣬Ҳ�ͺϲ����������� 
	}
	return 1;
}

int SubsetCountMFSet(MFSet S)
{
	int i=1;
	int count=0;
	while(i<=S.n)
	{
		if(S.node[i].parent<0)
			count++;
		i++;
	}
	return count;
}

int ShowSetMFSet(MFSet S)
{
	int i,j,k,count;
	int a[100][100] = {};
	int tmp[100] = {};
	
	for(i=1; i<=S.n; i++)
	{
		j = FindMFSet(S, i);//�жϵ�i��Ԫ�������ĸ����ϣ�������i�ĸ��ڵ�
		if(j>0)
		{
			tmp[j]++;
			a[j][tmp[j]] = S.node[i].data;
		} 
	}
	
	k = SubsetCountMFSet(S);//�Ӽ����� 
	
	printf("{");
	count = 0;
	
	for(i=1; i<=S.n; i++)
	{
		for(j=1; j<=S.n; j++)
		{
			if(a[i][j])
			{
				if(j==1)//ĳ�����ϵĵ�һ��Ԫ�� 
					printf("{%d", a[i][j]);
				else
					printf(",%d", a[i][j]);
				
				if(j==tmp[i])//ĳ���ϵ����һ��Ԫ��
				{
					count++;
					printf("}");
					if(count!=k)//�Ӽ�֮��Ҫ���� 
						printf(", ");
				} 
			}
		}
	}
	printf("}\n");
}
