#include "MST.h"

int MiniSpanTree_Prim(MGraph G, char e)
{
	EdgeNode closedge[G.vexNum+1];//0�ŵ�Ԫ���ã������������鱣��ߵ�Ȩֵ 
	int order = LocateVertex_M(G, e);//�õ���������ʼ��������
	 
	//��ʼ���������飬����������㵽���ඥ���Ȩֵ
	for(int j=1; j<=G.vexNum; j++) 
	{
		//if(j!=order)//�Լ����Լ�û���� 
		//{
			//closedge[j].vertex = e;//������ĸ����Ҫ 
			closedge[j].lowcost = G.matrix[order][j].vertexRelation;//���浱ǰ�ڵ㵽�����Ȩֵ 
		//}
	} 
	closedge[order].lowcost = 0;//�趨������������ʼ���㵽��ʼ�����ȨֵΪ0���Ա�������ı����к��� 
	
	printf("Start:%c\n", e);//��ӡ��ʼ�ڵ㣬���Ϳ���ͨ�������������δ�ӡ������ߵ���СȨֵ����СȨֵ�ߵ�β�ڵ��� 
	
	//���¸������飬̽��ս�������������ӳ���ͼ���������ڵ����СȨֵ 
	for(int i=1; i<=G.vexNum-1; i++)//�ܹ���ҪvexNum-1��Ѱ����С�ߣ���Ϊ���������ܹ��ɻ�·�������ҲҪ�Ƚڵ���1 
	{
		order = Minimum(closedge, G.vexNum);//Ѱ�Ҹ���������Ȩֵ��С�ıߵ���ţ�����0Ȩ�� 
		printf("--%2d--%c\n", closedge[order].lowcost, G.vertex[order]);//��ӡ��С�ߵ�Ȩֵ����С�߶�Ӧ��β�ڵ�
		
		closedge[order].lowcost = 0;//��С��Ȩֵ��0��������Ѱ����һ����С��ʱ�ͻ���������� 
		for(int j=1; j<=G.vexNum; j++)//�ҵ��Ѿ����̽������СȨֵͼ�У��������ඥ�����СȨֵ�����µ�����������
		{
			if(G.matrix[order][j].vertexRelation < closedge[j].lowcost)//��ô�ң�����̽�����Ķ��㵽���ඥ���Ȩֵ�����ԭ������������ͬ��λ�ӵ�ҪС������� 
			{
				//closedge[j].vertex = G.vertex[order];
				closedge[j].lowcost = G.matrix[order][j].vertexRelation;//��������СȨֵ���µ�����������ͬ����λ�� 
			} 
		} 
	}
	return 1;
}

int Minimum(EdgeNode closedge[], int n)
{
	int min = INT_MAX;
	int order=0;
	for(int i=1; i<=n; i++)
	{
		if(closedge[i].lowcost)//��Ȩֵ��Ϊ0�ı���ѡȨֵ��С�ı�
		{
			if(closedge[i].lowcost<=min) 
			{
				min = closedge[i].lowcost;
				order = i;
			}
		} 
	}
	return order;
}
