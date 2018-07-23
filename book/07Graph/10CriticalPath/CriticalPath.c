#include "CriticalPath.h"

int TopologicalOrder(ALGraph G, SqStack *T)
{
	int indegree[21];
	FindInDegree(G, indegree);
	
	SqStack S;
	InitStack_Sq(&S);//0��ȶ���ջ
	InitStack_Sq(T);//���˶���ջ 
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
		Push_Sq(T, i);//0��ȶ���������ջ 
		count++;
		
		for(ArcNode* p=G.vertex[i].firstArc; p; p=p->nextArc)//�������˶���ĺ������� 
		{
			int order = p->order;
			indegree[order]--;//��ΪҪ�����˶���ɾ�������Ժ����������-1
			if(indegree[order]==0)//������������ʱ�������ˣ���Ҫ���
				Push_Sq(&S, order);
				
			if(ve[i]+p->info.info > ve[order])//��ǰ��ve��ɸ�����·�� 
				ve[order] = ve[i]+p->info.info;
		}
	}
	
	if(G.vexNum > count)//Ҫ����Ķ������������˵��û�����꣬�Ҳ����������� 
		return 0;
	else
		return 1;
}

int CriticalPath(ALGraph G)
{
	if(!TopologicalOrder(G, &T))
		return 0;
	for(int i=1; i<=G.vexNum; i++)
		vl[i] = ve[G.vexNum];//��ʼ��ÿ�������¼�����ٷ���ʱ��Ϊ���һ����������緢��ʱ��
	
	int i;
	ArcNode* p;	
	int order;
	int w;
	while(!StackEmpty_Sq(T))//������������������vl��ٷ���ʱ�� 
	{
		for(Pop_Sq(&T, &i), p=G.vertex[i].firstArc; p; p=p->nextArc)
		{
			order = p->order;
			w = p->info.info;//Ȩֵ����Ϊ�ڽӱ�Ķ���û��Ȩֵ������д����info�� 
			
			if(vl[order]-w < vl[i])
				vl[i] = vl[order]-w;
		}
	} 
	
	int count;
	int ee,el;
	int tag;
	for(i=1,count=1; i<=G.vexNum; i++)//��ee��el�͹ؼ�� 
	{
		for(p=G.vertex[i].firstArc; p; p=p->nextArc)
		{
			order = p->order;
			w = p->info.info;
			ee = ve[i];
			el = vl[order]-w;
			tag = (ee==el)?'*':' ';//��*��ǹؼ��
			
			printf("%c-%c  a%-2d=%2d  (%2d, %2d)  %c\n", G.vertex[i].data, G.vertex[order].data, count++, w, ee, el, tag); 
		}
	}
	
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
