#include "MGraph.h"

int CreateGraph_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d", &((*G).kind));//��ȡͼ�����ͣ����������жϵ�����һ���������� 
	
	switch((*G).kind)
	{
		case DirectGraph:
			return CreateDirectGraph_M(fp, G);
		case DirectNet:
			return CreateDirectNet_M(fp, G);
		case UnDirectGraph:
			return CreateUnDirectGraph_M(fp, G);
		case UnDirectNet:
			return CreateUnDirectNet_M(fp, G);
		default:
			return 0;
	}
}

int CreateDirectGraph_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//��ȡ����������������Ϣ����ͼ�ṹ��

	char tmp;
	Scanf(fp, "%c", &tmp);//�������з�����Ϊ\nҲ��char��ʽ������tmp����ס������ַ���ʱ���һ�������\n 
	for(int i=1; i<=(*G).vexNum; i++)//��ȡ���� 
	{
		Scanf(fp, "%c", &((*G).vertex[i]));
	}
	Scanf(fp, "%c", &tmp);	//�������з� 
	
		
	for(int i=1; i<=(*G).vexNum; i++)//��ʼ���ڽӾ��� 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = 0;
	}
	
	char e1, e2;//<e1, e2>��e1��e2�ֱ��ʾ����x�����y���� 
	for(int k=1; k<=(*G).arcNum; k++)//��ȡ�� 
	{
		Scanf(fp, "%c%c", &e1, &e2);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = 1;//�����ӵĻ���ֵ1
		
		if((*G).info == 1)				//����л�����Ϣ��¼�� 
			Input_M(fp, &((*G).matrix[x][y].info)); 
	}
	return 1;
}

int CreateDirectNet_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//��ȡ����������������Ϣ����ͼ�ṹ��
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з�����Ϊ\nҲ��char��ʽ������tmp����ס������ַ���ʱ���һ�������\n  
	for(int i=1; i<=(*G).vexNum; i++)//��ȡ���� 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//�������з�
		
	for(int i=1; i<=(*G).vexNum; i++)//��ʼ���ڽӾ��� 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = INT_MAX;
	}
	
	char e1, e2;//<e1, e2>��e1��e2�ֱ��ʾ����x�����y����
	int vr; //���߱�ʾȨֵ��ͼ����01��ʾ�Ƿ����� 
	for(int k=1; k<=(*G).arcNum; k++)//��ȡ�� 
	{
		Scanf(fp, "%c%c%d", &e1, &e2, &vr);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = vr;//�����ӵĻ���Ȩֵ 
		
		if((*G).info == 1)				//����л�����Ϣ��¼�� 
			Input_M(fp, &((*G).matrix[x][y].info)); 
	}
	return 1;
}

int CreateUnDirectGraph_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//��ȡ����������������Ϣ����ͼ�ṹ��
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з�����Ϊ\nҲ��char��ʽ������tmp����ס������ַ���ʱ���һ�������\n  
	for(int i=1; i<=(*G).vexNum; i++)//��ȡ���� 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//�������з�
		
	for(int i=1; i<=(*G).vexNum; i++)//��ʼ���ڽӾ��� 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = 0;
	}
	
	char e1, e2;//<e1, e2>��e1��e2�ֱ��ʾ����x�����y���� 
	for(int k=1; k<=(*G).arcNum; k++)//��ȡ�� 
	{
		Scanf(fp, "%c%c", &e1, &e2);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = 1;//�����ӵĻ���ֵ1
		
		if((*G).info == 1)				//����л�����Ϣ��¼�� 
			Input_M(fp, &((*G).matrix[x][y].info)); 
			
		(*G).matrix[y][x] = (*G).matrix[x][y];//���ԳƵ� 
	}
	return 1;
}

int CreateUnDirectNet_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//��ȡ����������������Ϣ����ͼ�ṹ��
	char tmp;
	Scanf(fp, "%c", &tmp);//�������з�����Ϊ\nҲ��char��ʽ������tmp����ס������ַ���ʱ���һ�������\n  
	for(int i=1; i<=(*G).vexNum; i++)//��ȡ���� 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//�������з�
		
	for(int i=1; i<=(*G).vexNum; i++)//��ʼ���ڽӾ��� 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = INT_MAX;
	}
	
	char e1, e2;//<e1, e2>��e1��e2�ֱ��ʾ����x�����y����
	int vr; //���߱�ʾȨֵ��ͼ����01��ʾ�Ƿ����� 
	for(int k=1; k<=(*G).arcNum; k++)//��ȡ�� 
	{
		Scanf(fp, "%c%c%d", &e1, &e2, &vr);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = vr;//�����ӵĻ���Ȩֵ 
		
		if((*G).info == 1)				//����л�����Ϣ��¼�� 
			Input_M(fp, &((*G).matrix[x][y].info)); 
			
		(*G).matrix[y][x] = (*G).matrix[x][y];//���ԳƵ�
	}
	return 1;
}

int ClearGraph_M(MGraph *G)
{
	(*G).vexNum = 0;
	(*G).arcNum = 0;
	(*G).info = 0;
}

int LocateVertex_M(MGraph G, char e)
{
	for(int i=1; i<=G.vexNum; i++)
	{
		if(G.vertex[i]==e)
			return i;
	}
	return 0;
}

char GetVertex_M(MGraph G, int order)
{
	if(order<1 || order>G.vexNum)
		return '\0';
	else
		return G.vertex[order];
}

int PutVertex_M(MGraph *G, char e, char value)
{
	int order = LocateVertex_M(*G, e);
	if(!order)
		return 0;
	
	(*G).vertex[order] = value;
	return 1;
}

int FirstAdjVertex_M(MGraph G, char e)
{
	int order = LocateVertex_M(G, e);//�õ�e����� 
	if(!order)
		return 0;
	
	int nulltype;
	if(G.kind%2 != 0)//�������������������ӵĻ� 
 		nulltype = INT_MAX;
 	else			//������ͼ�����������ӵĻ� 
 		nulltype = 0;
 		
	for(int j=1; j<=G.vexNum; j++)
	{
		if(G.matrix[order][j].vertexRelation!=nulltype)//��������ӣ��򷵻�<order��j>��j��Ҳ�����ڽӵ����� 
			return j;
	}
	return 0;
}

int NextAdjVertex_M(MGraph G, char e, char w)
{
	int order1 = LocateVertex_M(G, e);//�õ�e��w����� 
	int order2 = LocateVertex_M(G, w);
	
	if(!order1 || !order2)
		return 0;
		
	int nulltype;
	if(G.kind%2 != 0)//�������������������ӵĻ� 
 		nulltype = INT_MAX;
 	else			//������ͼ�����������ӵĻ� 
 		nulltype = 0;
	for(int j=order2+1; j<=G.vexNum; j++)//��Ϊ�������w����һ���������ţ����Դ�w����һ����ſ�ʼ���� 
	{
		if(G.matrix[order1][j].vertexRelation!=nulltype)
			return j;
	}
	return 0;
}

int InsertVertex_M(MGraph *G, char e)
{
	if((*G).vexNum==20)
		return 0;
		
	int nulltype;
	if((*G).kind%2 != 0)//�������������������ӵĻ� 
 		nulltype = INT_MAX;
 	else			//������ͼ�����������ӵĻ� 
 		nulltype = 0;
	int order = (*G).vexNum+1;//�����λ�����
	(*G).vertex[order] = e;//�������
	
	for(int i=1; i<=order; i++)//�����ڽӾ�����Ϊֻ�ǲ��룬û�����ӻ��������ڽӾ���ĵ㶼�������� 
	{
		(*G).matrix[i][order].vertexRelation = nulltype;
		(*G).matrix[order][i].vertexRelation = nulltype;
	} 
	(*G).vexNum++;
	return 1;
}

int DeleteVertex_M(MGraph *G, char e)
{
	int order = LocateVertex_M(*G, e);
	if(!order)
		return 0;
	
	int nulltype;
	if((*G).kind%2 != 0)//�������������������ӵĻ� 
 		nulltype = INT_MAX;
 	else			//������ͼ�����������ӵĻ� 
 		nulltype = 0;
	
	for(int i=1; i<=order; i++)//���������� 
	{
		if((*G).matrix[order][i].vertexRelation!=nulltype)//����õ�������������ӣ�����Ҫ���� 
			(*G).arcNum--;
		if((*G).kind==DirectGraph || (*G).kind==DirectNet)//���������ģ����ܻ�Ҫ�ظ�����һ�鷴�� 
		{
			if((*G).matrix[i][order].vertexRelation!=nulltype)
				(*G).arcNum--;
		}
	}
	
	//�ƶ�order֮�������Ԫ�أ�����ά�ȶ�Ҫ�ƶ� 
	for(int i=1; i<=(*G).vexNum; i++)
	{
		for(int j=order+1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j-1] = (*G).matrix[i][j];
	}
	for(int i=order+1; i<=(*G).vexNum; i++)
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i-1][j] = (*G).matrix[i][j];
	}
	(*G).vexNum--;
	return 1;
}

int InsertArc_M(MGraph *G, char e, char w, int vertexRelation, ...)
{
	int order1 = LocateVertex_M(*G, e);//�õ�e��w����� 
	int order2 = LocateVertex_M(*G, w);
	
	if(!order1 || !order2)
		return 0;
		
	(*G).matrix[order1][order2].vertexRelation = vertexRelation;//���뻡�Ĺ�ϵ
	
	va_list ap;//����л���Ϣ����� 
	va_start(ap, vertexRelation);
	(*G).matrix[order1][order2].info = va_arg(ap, ArcInfo);
	va_end(ap); 
	
 	if((*G).kind==UnDirectGraph || (*G).kind==UnDirectNet)//�����������ڽӾ���Ҫ�ٸ���һ�ݶԳƵ� 
 		(*G).matrix[order2][order1] = (*G).matrix[order1][order2];
		
	(*G).arcNum++;
	return 1;
}

int DeleteArc_M(MGraph *G, char e, char w)
{
	int order1 = LocateVertex_M(*G, e);//�õ�e��w����� 
	int order2 = LocateVertex_M(*G, w);
	
	if(!order1 || !order2)
		return 0;
		
	if((*G).kind%2 != 0)//�����������Ѹû����ó������� 
 		(*G).matrix[order1][order2].vertexRelation = INT_MAX;
 	else			//������ͼ���Ѹû����ó������� 
 		(*G).matrix[order1][order2].vertexRelation = 0;
 		
	if((*G).kind==UnDirectGraph || (*G).kind==UnDirectNet)//�����������ڽӾ���Ҫ�ٸ���һ�ݶԳƵ� 
 		(*G).matrix[order2][order1] = (*G).matrix[order1][order2];
		
	(*G).arcNum--;
	return 1;
}

void DFSTraverse_M(MGraph G, void(Visit)(char))
{
	VisitFunc = Visit;
	
	for(int i=1; i<=G.vexNum; i++)//�����ж��㶼��ʼ��Ϊδ���� 
		Visited[i] = 0;
	
	for(int i=1; i<=G.vexNum; i++)
	{
		if(Visited[i]==0)//���δ���ʣ��������ʽڵ� 
			DFS_M(G, i);
	}
}

void DFS_M(MGraph G, int i)
{
	
	Visited[i] = 1;//���ñ��Ϊ�ѷ��� 
	VisitFunc(G.vertex[i]);//����
	
	//w�ǵ�һ�ڽӵ㣬w���ڣ�w����һ�ڽӵ��ƶ� 
	int w;
	for(w=FirstAdjVertex_M(G, G.vertex[i]); w; w=NextAdjVertex_M(G, G.vertex[i], G.vertex[w]))
	{
		if(Visited[w]==0)
			DFS_M(G, w);
	} 
}

int BFSTraverse_M(MGraph G, void(Visit)(char))
{
	for(int i=1; i<=G.vexNum; i++)//���ж����ʼ��Ϊδ���� 
		Visited[i] = 0;
	
	LinkQueue Q;//�ö���ʵ�ֹ�����ȱ���
	InitQueue_L(&Q);
	int e;//��ų��ӵ�Ԫ�� 
	
	for(int i=1; i<=G.vexNum; i++)//�������ж��� 
	{
		if(Visited[i]==0)//���δ���ʣ������ 
		{
			Visited[i] = 1;
			Visit(G.vertex[i]);
			EnQueue_L(&Q, i);//�����������
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);//��������б�ţ��ͳ��ӣ�����֮����ڽӶ��� 
				for(int w=FirstAdjVertex_M(G, G.vertex[e]); w; w=NextAdjVertex_M(G, G.vertex[e], G.vertex[w]))
				{
					if(Visited[w]==0)//���֮���δ���ʣ������ 
					{
						Visited[w] = 1;
						Visit(G.vertex[w]);
						EnQueue_L(&Q, w);//������ӳ��ӷ��� 
					} 
				}
			} 
		}
	} 
	return 1;
}
//֮��д���Ժ���ʱ�ֶ�ģ��һ��BFS����DFS��visit������дһ������

int Output_M(MGraph G)
{
	if(!G.vexNum && !G.arcNum)
		return 0;
	else
	{
		//��ӡ��һ�б�ͷ 
		printf("  "); 
		for(int i=1; i<=G.vexNum; i++)
			printf("%2c ", G.vertex[i]);
		printf("\n");
		
		//��ӡ������
		for(int i=1; i<=G.vexNum; i++)
		{
			printf("%c ", G.vertex[i]);//��ӡ��һ�б�ͷ
			for(int j=1; j<=G.vexNum; j++)//��ӡ�������� 
			{
				if(G.matrix[i][j].vertexRelation==INT_MAX)
					printf("�� ");
				else
					printf("%2d ", G.matrix[i][j]); 
			} 
			printf("\n");//���� 
		} 
	}
	return 1;
} 

int Input_M(FILE* fp, ArcInfo* info)
{
	return 1;//Ĭ������Ϣ 
}
