#include "AMLGraph.h"

int CreateUnDirectGraph_AML(FILE* fp, AMLGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//��ȡ������������������Ϣ 
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з� 
	
	//��ȡ���㣬��ʼ��ͷ���
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
	}
	Scanf(fp, "%c", &tmp);//�������з�
	
	// ��ȡ�ߣ�����ʮ������
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AML(*G, start);//�õ��ߵ������������� 
		order2 = LocateVertex_AML(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//����߿ռ�	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		
		p->mark = UnVisit;	//p���Ϊδ���� 
		p->headVex = order1;//��p�Ķ�����Ÿ�ֵ 
		p->tailVex = order2;//��p�Ķ�����Ÿ�ֵ
		 
		p->headLink = (*G).vertex[order1].firstArc;//��p��ͷ����ֵ��ָ��ͷ������ڽӱ� 
		(*G).vertex[order1].firstArc = p;//��p�����Ϊͷ������ڽӱ� 
		
		p->tailLink = (*G).vertex[order2].firstArc;//��p��β����ֵ��ָ��β������ڽӱ� 
		(*G).vertex[order2].firstArc = p;//��p�����Ϊβ������ڽӱ� 
		
		if((*G).arcInfo==1)
			Input_AML(fp, &(p->info)); 
			
		arcPtr[i] = p;//��ָ�������¼��ǰ������ 
	} 
	return 1;
}
//�о������ڽӶ�������Ĺ��� 

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
		ClearMark(G);
		
		printf("���㣺");
		for(int i=1; i<=G.vexNum; i++)
			printf("%c ", G.vertex[i].data);
		printf("\n");
		
		printf("�ߣ�");
		for(int i=1; i<=G.vexNum; i++)
		{
			if(G.vertex[i].firstArc)//�����ǰ�����г��� 
			{
				ArcNode* p = G.vertex[i].firstArc;
				while(p)
				{
					if(p->mark==UnVisit)
					{
						printf("<%c,%C> ", G.vertex[p->headVex].data, G.vertex[p->tailVex].data);
						p->mark = Visit;
					}
					
					if(p->headVex==i)//����ܶ���ͷ������ͷ������ 
						p = p->headLink;
					else
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
	//����Ϣ
	return 1; 
}
