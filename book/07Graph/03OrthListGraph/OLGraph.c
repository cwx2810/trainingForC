#include "OLGraph.h"

int CreateDirectGraph_OL(FILE* fp, OLGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//��ȡ������������������Ϣ 
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з� 
	
	//��ȡ���㣬��ʼ��ͷ���
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstin = NULL;
		(*G).vertex[i].firstout = NULL;
	}
	Scanf(fp, "%c", &tmp);//�������з�
	
	// ��ȡ�ߣ�����ʮ������
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_OL(*G, start);//�õ��ߵ������������� 
		order2 = LocateVertex_OL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//����߿ռ�	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
			
		p->tailVex = order1;//��p�Ķ�����Ÿ�ֵ 
		p->headVex = order2;//��p�Ķ�����Ÿ�ֵ
		 
		p->headLink = (*G).vertex[order2].firstin;//��p������ֵ
		(*G).vertex[order2].firstin = p;//��p���뻡���м䣬��p����β�ڵ��inָ�� 
		
		p->tailLink = (*G).vertex[order1].firstout;//��p������ֵ 
		(*G).vertex[order1].firstout = p;//��p���뻡���м䣬��p����ͷ����outָ�� 
		
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
			printf("%c->", G.vertex[i].data);//��ӡ����� 
			ArcNode* p = G.vertex[i].firstout;//������ӡ�߱� 
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
			printf("\n");//���� 
		} 
	}
	return 1;
}

int Input_OL(FILE* fp, ArcInfo* info)
{
	//���ĵ��޻���Ϣ 
	return 1;
}
