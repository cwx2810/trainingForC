#include "TopologicalSort.h"

int TopologicalSort(ALGraph G, int topo[])
{
	int indegree[21];
	FindInDegree(G, indegree);
	
	SqStack S;
	InitStack_Sq(&S);
	for(int i=1; i<=G.vexNum; i++)
	{
		if(indegree[i]==0)
			Push_Sq(&S, i);//���Ϊ0�Ķ��������ջ 
	}
	
	int count = 0;//����Ķ����м��� 
	while(!StackEmpty_Sq(S))
	{
		int i;
		Pop_Sq(&S, &i);
		count++;
		topo[count] = i;//��Ҫ��������˶�������ݴ��������� 
		
		for(ArcNode* p=G.vertex[i].firstArc; p; p=p->nextArc)//�������˶���ĺ������� 
		{
			int order = p->order;
			indegree[order]--;//��ΪҪ�����˶���ɾ�������Ժ����������-1
			if(indegree[order]==0)//������������ʱ�������ˣ���Ҫ���
				Push_Sq(&S, order);
		}
	}
	
	if(G.vexNum > count)//Ҫ����Ķ������������˵��û�����꣬�Ҳ����������� 
		return 0;
	else
		return 1;
}

int FindInDegree(ALGraph G, int indegree[21])
{
	for(int i=1; i<=G.vexNum; i++)//��ʼ��������� 
		indegree[i] = 0;
	for(int i=1; i<=G.vexNum; i++)
	{
		ArcNode* p = G.vertex[i].firstArc;//��ʼ��p��Ϊͷ������ĵ�һ���� 
		while(p)
		{
			indegree[p->order]++;//p�����ڣ���p����β�ڵ�����++ 
			p = p->nextArc;
		}
	}
	return 1;
}
