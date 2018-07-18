#include "OLGraph.h"

int CreateDirectGraph_OL(FILE* fp, OLGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//读取顶点数，弧数，弧信息 
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符 
	
	//读取顶点，初始化头结点
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstin = NULL;
		(*G).vertex[i].firstout = NULL;
	}
	Scanf(fp, "%c", &tmp);//跳过换行符
	
	// 读取边，制作十字链表
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_OL(*G, start);//得到边的两个顶点的序号 
		order2 = LocateVertex_OL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//分配边空间	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
			
		p->tailVex = order1;//对p的顶点序号赋值 
		p->headVex = order2;//对p的顶点序号赋值
		 
		p->headLink = (*G).vertex[order2].firstin;//对p的链域赋值
		(*G).vertex[order2].firstin = p;//把p接入弧的中间，让p接入尾节点的in指针 
		
		p->tailLink = (*G).vertex[order1].firstout;//对p的链域赋值 
		(*G).vertex[order1].firstout = p;//把p接入弧的中间，让p接入头结点的out指针 
		
		if((*G).arcInfo==1)
			Input_OL(fp, &(p->info)); 
	} 
	return 1;
}

int LocateVertex_OL(OLGraph G, char e)
{
	for(int i=1; i<=G.vexNum; i++)
	{
		if(G.vertex[i].data==e)
			return i;
	}
	return 0;
}

int Output_OL(OLGraph G)
{
	if(!G.vexNum && !G.arcNum)
		return 0;
	else
	{
		for(int i=1; i<=G.vexNum; i++)
		{
			printf("%c->", G.vertex[i].data);//打印顶点表 
			ArcNode* p = G.vertex[i].firstout;//遍历打印边表 
			int j = 1;
			while(p)
			{
				while(p->headVex!=j)
				{
					printf("      ");
					j++;
				}
				printf("(%-c %c) ", G.vertex[p->tailVex].data, G.vertex[p->headVex].data);
				p = p->tailLink;
				j++;
			}
			printf("\n");//换行 
		} 
	}
	return 1;
}

int Input_OL(FILE* fp, ArcInfo* info)
{
	//本文档无弧信息 
	return 1;
}
