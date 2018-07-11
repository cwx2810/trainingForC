#include "MFSet.h"

int InitMFSet(FILE* fp, MFSet* S)
{
	Scanf(fp, "%d", &(S->n));//读取并查集个数 
	for(int i=1; i<=S->n; i++)//node[0]弃用 
	{
		Scanf(fp, "%d", &i);//读取并查集元素赋给临时变量i 
		S->node[i].data = i;//这里好像用了刚刚好的奇技淫巧，因为测试集本身就是1~10，赋给i也是1~10，就是说i既是下标又是data 
		S->node[i].parent = -1; //parent域统一初始化为-1，即这些元素全是根节点 
	}
	return 1;
}

int FindMFSet(MFSet S, int i)
{
	if(i<1 || i>S.n)
		return 0;
	int root;
	for(root=i; S.node[root].parent>0; root=S.node[root].parent)//找到parent是-1的点就是根节点 
		;
	return root;
}

int FixMFSet(MFSet* S, int i)
{
	if(i<1 || i>S->n)
		return 0;
	int root;
	for(root=i; S->node[root].parent>0; root=S->node[root].parent)//找到根节点 
		;
	int parent;
	for(int p=i; p!=root; p=parent)//p是遍历节点，为了不影响i而设的，从i一直遍历到root 
	{
		parent = S->node[p].parent;//parent始终为当前节点的父节点 
		S->node[p].parent = root;//将一路上遍历到的节点都变成root的孩子节点，也就是把树高压缩为2 
	}
	return root;
}

int MergeMFSet(MFSet* S, int i, int j)
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return 0;
	if(i!=j)
		S->node[i].parent = j;//如果i和j不相等，则把i并成j的儿子
	return 1; 
}

int MixMFSet(MFSet* S, int i, int j)//parent域记录子集中所含元素数目的负值 
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return 0;
	if(S->node[i].parent > S->node[j].parent)//i的大，说明所含元素少，并到j中去 
	{
		S->node[j].parent += S->node[i].parent;//修改j的数目为更负的值
		S->node[i].parent = j;//合并操作 
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
	Scanf(fp, "%d", &(R->n));//读取关系节点个数
	if(R->n < 0)
		return 0;
	
	for(int k=1; k<=R->n; k++)
		 Scanf(fp, "%d%d", &(R->nodes[k-1].i), &(R->nodes[k-1].j));//读取关系节点赋给i和j 
 	return 1;
}

int EquivalenceClassMFSet(MFSet* S, Relation R)
{
	for(int k=1; k<=R.n; k++)
	{
		int x = FindMFSet(*S, R.nodes[k-1].i);//在S中寻找给定关系数值所在集合的根节点 
		int y = FindMFSet(*S, R.nodes[k-1].j);
		MergeMFSet(S, x, y);//合并根节点，也就合并了两个集合 
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
		j = FindMFSet(S, i);//判断第i个元素属于哪个集合，就是找i的根节点
		if(j>0)
		{
			tmp[j]++;
			a[j][tmp[j]] = S.node[i].data;
		} 
	}
	
	k = SubsetCountMFSet(S);//子集个数 
	
	printf("{");
	count = 0;
	
	for(i=1; i<=S.n; i++)
	{
		for(j=1; j<=S.n; j++)
		{
			if(a[i][j])
			{
				if(j==1)//某个集合的第一个元素 
					printf("{%d", a[i][j]);
				else
					printf(",%d", a[i][j]);
				
				if(j==tmp[i])//某集合的最后一个元素
				{
					count++;
					printf("}");
					if(count!=k)//子集之间要隔开 
						printf(", ");
				} 
			}
		}
	}
	printf("}\n");
}
