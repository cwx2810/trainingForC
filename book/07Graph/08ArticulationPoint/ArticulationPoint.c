#include "ArticulationPoint.h"

int FindArticulation(ALGraph G)
{
	//count=1��ʾ���ڵ��ǵ�һ�����ʵĽڵ� 
	Visited[1] = count = 1;//��1�Žڵ�Ϊ�������ĸ���0�ŵ�Ԫ���ã�visit�б���count������ÿ���ڵ�ڼ������ʣ�ԽСԽ���� 
	for(int i=2; i<=G.vexNum; i++)//����ڵ㶼��ʼ��Ϊδ���� 
		Visited[i] = 0;
	ArcNode* p = G.vertex[1].firstArc;//�õ�������һ���� 
	int order = p->order;//�õ��û���β�ڵ����
	
	//������������� 
	DFSArticulation(G, order);//���������������ҵ��ؽڵ�洢���� 
	
	//������͸����������������� 
	if(G.vexNum > count)//����������2����������Ϊ����DFS����count�����������ڵ���Ŀ�������ʱ�ڵ��������������ڵ�࣬˵������������ 
	{
		SavePoint(1);//������ڵ� 
		while(p->nextArc)//������������ 
		{
			p = p->nextArc;
			order = p->order;
			if(Visited[order]==0)
				DFSArticulation(G, order);
		}
	}	
	 
	return 1;
}

int DFSArticulation(ALGraph G, int order)
{
	int min;//�ݴ��������� 
	Visited[order] = min = ++count;//order�ǵ�count�����ʵĽڵ�
	
	for(ArcNode* p=G.vertex[order].firstArc; p; p=p->nextArc)
	{
		int w = p->order;//wΪorder���ڽӵ����� 
		if(Visited[w]==0)//wδ���ʣ�����order�ĺ��ӣ���DFS�ھ� 
		{
			DFSArticulation(G, w);
			if(low[w]<min)//�ڵ�����ȱ��Ѿ���¼�Ķ�Ҫ�磬������������� 
				min = low[w];
			if(low[w]>=Visited[order])//�����еĽڵ�DFS׷�ݵ�����������ű��Լ���˵��׷�������Լ���������ȣ���order�Ϸ����ǹؽڵ� 
				SavePoint(order);
		} 
		else			//w�Ѿ����ʹ��ˣ���order������ 
		{
			if(Visited[w]<min)//������ȱ��Ѿ���¼�Ķ�Ҫ�磬����� 
				min = Visited[w];
		}
		low[order] = min;//order�������������
	} 
	
	return 1;
}

int SavePoint(int order)
{
	for(int i=1; i<=node[0]; i++)
	{
		if(node[i]==order)//�ùؽڵ��Ѿ��洢�� 
			return 0;
	}
	node[0]++;//���Ϸ�����������1 
	node[node[0]] = order;//��order�Źؽڵ�洢����� 
	return 1;
}

int OutputPoint(ALGraph G)
{
	for(int i=1; i<=node[0]; i++)
		printf("��%2d���ҵ��Ĺؽڵ�%c��������Ϊ%2d\n", i, G.vertex[node[i]].data, node[i]);
}
