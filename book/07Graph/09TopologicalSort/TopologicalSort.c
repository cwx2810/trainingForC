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
			Push_Sq(&S, i);//入度为0的顶点序号入栈 
	}
	
	int count = 0;//输出的顶点有几个 
	while(!StackEmpty_Sq(S))
	{
		int i;
		Pop_Sq(&S, &i);
		count++;
		topo[count] = i;//将要输出的拓扑顶点序号暂存于数组中 
		
		for(ArcNode* p=G.vertex[i].firstArc; p; p=p->nextArc)//遍历拓扑顶点的后续顶点 
		{
			int order = p->order;
			indegree[order]--;//因为要把拓扑顶点删除，所以后续顶点入度-1
			if(indegree[order]==0)//如果后续顶点此时变拓扑了，还要入队
				Push_Sq(&S, order);
		}
	}
	
	if(G.vexNum > count)//要输出的顶点个数不够，说明没有走完，找不到拓扑排序 
		return 0;
	else
		return 1;
}

int FindInDegree(ALGraph G, int indegree[21])
{
	for(int i=1; i<=G.vexNum; i++)//初始化入度数组 
		indegree[i] = 0;
	for(int i=1; i<=G.vexNum; i++)
	{
		ArcNode* p = G.vertex[i].firstArc;//初始化p弧为头结点后面的第一个弧 
		while(p)
		{
			indegree[p->order]++;//p弧存在，则p弧的尾节点的入度++ 
			p = p->nextArc;
		}
	}
	return 1;
}
