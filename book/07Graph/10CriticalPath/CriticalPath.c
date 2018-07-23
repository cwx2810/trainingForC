#include "CriticalPath.h"

int TopologicalOrder(ALGraph G, SqStack *T)
{
	int indegree[21];
	FindInDegree(G, indegree);
	
	SqStack S;
	InitStack_Sq(&S);//0入度顶点栈
	InitStack_Sq(T);//拓扑顶底栈 
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
		Push_Sq(T, i);//0入度顶点入拓扑栈 
		count++;
		
		for(ArcNode* p=G.vertex[i].firstArc; p; p=p->nextArc)//遍历拓扑顶点的后续顶点 
		{
			int order = p->order;
			indegree[order]--;//因为要把拓扑顶点删除，所以后续顶点入度-1
			if(indegree[order]==0)//如果后续顶点此时变拓扑了，还要入队
				Push_Sq(&S, order);
				
			if(ve[i]+p->info.info > ve[order])//当前的ve变成更长的路径 
				ve[order] = ve[i]+p->info.info;
		}
	}
	
	if(G.vexNum > count)//要输出的顶点个数不够，说明没有走完，找不到拓扑排序 
		return 0;
	else
		return 1;
}

int CriticalPath(ALGraph G)
{
	if(!TopologicalOrder(G, &T))
		return 0;
	for(int i=1; i<=G.vexNum; i++)
		vl[i] = ve[G.vexNum];//初始化每个顶点事件的最迟发生时间为最后一个顶点的最早发生时间
	
	int i;
	ArcNode* p;	
	int order;
	int w;
	while(!StackEmpty_Sq(T))//按拓扑逆序求各顶点的vl最迟发生时间 
	{
		for(Pop_Sq(&T, &i), p=G.vertex[i].firstArc; p; p=p->nextArc)
		{
			order = p->order;
			w = p->info.info;//权值，因为邻接表的定义没有权值，所以写在了info中 
			
			if(vl[order]-w < vl[i])
				vl[i] = vl[order]-w;
		}
	} 
	
	int count;
	int ee,el;
	int tag;
	for(i=1,count=1; i<=G.vexNum; i++)//求ee，el和关键活动 
	{
		for(p=G.vertex[i].firstArc; p; p=p->nextArc)
		{
			order = p->order;
			w = p->info.info;
			ee = ve[i];
			el = vl[order]-w;
			tag = (ee==el)?'*':' ';//用*标记关键活动
			
			printf("%c-%c  a%-2d=%2d  (%2d, %2d)  %c\n", G.vertex[i].data, G.vertex[order].data, count++, w, ee, el, tag); 
		}
	}
	
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
