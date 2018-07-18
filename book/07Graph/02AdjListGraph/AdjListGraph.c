#include "AdjListGraph.h"

int CreateGraph_AL(FILE* fp, ALGraph *G)
{
	Scanf(fp, "%d", &((*G).kind));
	switch((*G).kind)
	{
		case DirectGraph:
			return CreateDirectGraph_AL(fp, G);
		case UnDirectGraph:
			return CreateUnDirectGraph_AL(fp, G);
		default:
			return 0;
	}
}

int CreateDirectGraph_AL(FILE* fp, ALGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//读取顶点数，弧数，弧信息 
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符 
	
	//读取顶点，初始化头结点
	ArcNode* note[21];//访问标记，用于链之间的连接定位等 
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
		note[i] = NULL;
	}
	Scanf(fp, "%c", &tmp);//跳过换行符
	
	// 读取边，制作邻接表
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AL(*G, start);//得到边的两个顶点的序号 
		order2 = LocateVertex_AL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//初始化边	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		p->order = order2;
		p->nextArc = NULL;
		if((*G).arcInfo==1)
			Input_AL(fp, &(p->info));
		
		//连接边 
		if(note[order1]==NULL)//如果是第一个弧，则接到头结点后面 
			(*G).vertex[order1].firstArc = p;
		else			//如果不是第一个弧，接到标记的弧后面 
			note[order1]->nextArc = p;	
		note[order1] = p;//移动标记，标记新的弧 
	} 
	return 1;
}

int CreateUnDirectGraph_AL(FILE* fp, ALGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//读取顶点数，弧数，弧信息 
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符 
	
	//读取顶点，初始化头结点
	ArcNode* note[21];//访问标记，用于链之间的连接定位等 
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
		note[i] = NULL;
	}
	Scanf(fp, "%c", &tmp);//跳过换行符
	
	// 读取边，制作邻接表
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AL(*G, start);//得到边的两个顶点的序号 
		order2 = LocateVertex_AL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//初始化边	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		p->order = order2;
		p->nextArc = NULL;
		if((*G).arcInfo==1)
			Input_AL(fp, &(p->info));
		
		//连接边 
		if(note[order1]==NULL)//如果是第一个弧，则接到头结点后面 
			(*G).vertex[order1].firstArc = p;
		else			//如果不是第一个弧，接到标记的弧后面 
			note[order1]->nextArc = p;	
		note[order1] = p;//移动标记，标记新的弧 
		
		//初始化边，因为是无向图，所以反过来连接的边也算	
		ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!q)
			return 0;
		q->order = order1;
		q->nextArc = NULL;
		if((*G).arcInfo==1)
			q->info = p->info;
		
		//连接边 
		if(note[order2]==NULL)//如果是第一个弧，则接到头结点后面 
			(*G).vertex[order2].firstArc = q;
		else			//如果不是第一个弧，接到标记的弧后面 
			note[order2]->nextArc = q;	
		note[order2] = q;//移动标记，标记新的弧
	} 
	return 1;
}

int LocateVertex_AL(ALGraph G, char e)
{
	for(int i=1; i<=G.vexNum; i++)
	{
		if(G.vertex[i].data==e)
			return i;
	}
	return 0;
}

int Output_AL(ALGraph G)
{
	if(!G.vexNum && !G.arcNum)
		return 0;
	else
	{
		for(int i=1; i<=G.vexNum; i++)
		{
			printf("%c->", G.vertex[i].data);//打印顶点表 
			ArcNode* p = G.vertex[i].firstArc;//遍历打印边表 
			while(p)
			{
				printf(" %c", G.vertex[p->order].data);
				p = p->nextArc;
			}
			printf("\n");//换行 
		} 
	}
	return 1;
}

int Input_AL(FILE* fp, ArcInfo* info)
{
	//本文档无弧信息
	return 1; 
}
