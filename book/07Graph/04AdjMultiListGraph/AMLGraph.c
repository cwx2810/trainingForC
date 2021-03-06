#include "AMLGraph.h"

int CreateUnDirectGraph_AML(FILE* fp, AMLGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//读取顶点数，弧数，弧信息 
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符 
	
	//读取顶点，初始化头结点
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
	}
	Scanf(fp, "%c", &tmp);//跳过换行符
	
	// 读取边，制作邻接多重链表 
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AML(*G, start);//得到边的两个顶点的序号 
		order2 = LocateVertex_AML(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//分配边空间	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		
		p->mark = UnVisit;	//p标记为未访问 
		p->headVex = order1;//对p的顶点序号赋值 
		p->tailVex = order2;//对p的顶点序号赋值
		 
		p->headLink = (*G).vertex[order1].firstArc;//对p的头链域赋值，让其和头顶点的出边指针融合 
		(*G).vertex[order1].firstArc = p;//把p接入变为头顶点的出边 
		
		p->tailLink = (*G).vertex[order2].firstArc;//对p的尾链域赋值，让其和尾顶点的出边指针融合 
		(*G).vertex[order2].firstArc = p;//把p接入变为尾顶点的出边 
		
		if((*G).arcInfo==1)
			Input_AML(fp, &(p->info)); 
			
		arcPtr[i] = p;//弧指针数组保存当前插入的弧 
	} 
	return 1;
}

int LocateVertex_AML(AMLGraph G, char e)
{
	for(int i=1; i<=G.vexNum; i++)
	{
		if(G.vertex[i].data==e)
			return i;
	}
	return 0;
}

int Output_AML(AMLGraph G)
{
	if(!G.vexNum && !G.arcNum)
		return 0;
	else
	{
		ClearMark(G);//防止之前的函数用过，先重新设置为未访问 
		
		printf("顶点：");
		for(int i=1; i<=G.vexNum; i++)
			printf("%c ", G.vertex[i].data);
		printf("\n");
		
		printf("边：");
		for(int i=1; i<=G.vexNum; i++)
		{
			if(G.vertex[i].firstArc)//如果当前顶点有出边 
			{
				ArcNode* p = G.vertex[i].firstArc;
				while(p)
				{
					if(p->mark==UnVisit)
					{
						printf("<%c,%C> ", G.vertex[p->headVex].data, G.vertex[p->tailVex].data);
						p->mark = Visit;
					}
					
					if(p->headVex==i)//如果该边头顶点还有其他邻接边，则遍历之 
						p = p->headLink;
					else			//否则遍历该边尾顶点的其他边 
						p = p->tailLink;
				}
			}
		}
		printf("\n"); 
	}
	return 1;
}

int ClearMark(AMLGraph G)
{
	for(int i=1; i<=G.arcNum; i++)
		arcPtr[i]->mark = UnVisit;
}

int Input_AML(FILE* fp, ArcInfo* info)
{
	//无信息
	return 1; 
}
