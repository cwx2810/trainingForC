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
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//��ȡ������������������Ϣ 
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з� 
	
	//��ȡ���㣬��ʼ��ͷ���
	ArcNode* note[21];//���ʱ�ǣ�������֮������Ӷ�λ�� 
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
		note[i] = NULL;
	}
	Scanf(fp, "%c", &tmp);//�������з�
	
	// ��ȡ�ߣ������ڽӱ�
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AL(*G, start);//�õ��ߵ������������� 
		order2 = LocateVertex_AL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//��ʼ����	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		p->order = order2;
		p->nextArc = NULL;
		if((*G).arcInfo==1)
			Input_AL(fp, &(p->info));
		
		//���ӱ� 
		if(note[order1]==NULL)//����ǵ�һ��������ӵ�ͷ������ 
			(*G).vertex[order1].firstArc = p;
		else			//������ǵ�һ�������ӵ���ǵĻ����� 
			note[order1]->nextArc = p;	
		note[order1] = p;//�ƶ���ǣ�����µĻ� 
	} 
	return 1;
}

int CreateUnDirectGraph_AL(FILE* fp, ALGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).arcInfo));//��ȡ������������������Ϣ 
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з� 
	
	//��ȡ���㣬��ʼ��ͷ���
	ArcNode* note[21];//���ʱ�ǣ�������֮������Ӷ�λ�� 
	for(int i=1; i<=(*G).vexNum; i++) 
	{
		Scanf(fp, "%c", &((*G).vertex[i].data));
		(*G).vertex[i].firstArc = NULL;
		note[i] = NULL;
	}
	Scanf(fp, "%c", &tmp);//�������з�
	
	// ��ȡ�ߣ������ڽӱ�
	char start, end;
	int order1, order2;
	for(int i=1; i<=(*G).arcNum; i++) 
	{
		Scanf(fp, "%c%c", &start, &end);
		order1 = LocateVertex_AL(*G, start);//�õ��ߵ������������� 
		order2 = LocateVertex_AL(*G, end);
		if(!order1 || !order2)
			return 0;
			
		//��ʼ����	
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!p)
			return 0;
		p->order = order2;
		p->nextArc = NULL;
		if((*G).arcInfo==1)
			Input_AL(fp, &(p->info));
		
		//���ӱ� 
		if(note[order1]==NULL)//����ǵ�һ��������ӵ�ͷ������ 
			(*G).vertex[order1].firstArc = p;
		else			//������ǵ�һ�������ӵ���ǵĻ����� 
			note[order1]->nextArc = p;	
		note[order1] = p;//�ƶ���ǣ�����µĻ� 
		
		//��ʼ���ߣ���Ϊ������ͼ�����Է��������ӵı�Ҳ��	
		ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode)); 
		if(!q)
			return 0;
		q->order = order1;
		q->nextArc = NULL;
		if((*G).arcInfo==1)
			q->info = p->info;
		
		//���ӱ� 
		if(note[order2]==NULL)//����ǵ�һ��������ӵ�ͷ������ 
			(*G).vertex[order2].firstArc = q;
		else			//������ǵ�һ�������ӵ���ǵĻ����� 
			note[order2]->nextArc = q;	
		note[order2] = q;//�ƶ���ǣ�����µĻ�
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
			printf("%c->", G.vertex[i].data);//��ӡ����� 
			ArcNode* p = G.vertex[i].firstArc;//������ӡ�߱� 
			while(p)
			{
				printf(" %c", G.vertex[p->order].data);
				p = p->nextArc;
			}
			printf("\n");//���� 
		} 
	}
	return 1;
}

int Input_AL(FILE* fp, ArcInfo* info)
{
	//���ĵ��޻���Ϣ
	return 1; 
}
