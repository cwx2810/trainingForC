#include "SpanningTree.h"

int InitCSTree(CSNode **T)
{
	*T = NULL;
	return 1;
}

int InitStack_Sq(SqStack *S)
{
	(*S).base = (CSNode**)malloc(100*sizeof(CSNode*));
	if(!(*S).base)
		return 0;
	(*S).top = (*S).base;
	(*S).stacksize = 100;
	
	return 1;
}

int StackEmpty_Sq(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

int GetTop_Sq(SqStack S, CSNode* *e)
{
	if(S.base==S.top)
		return 0;
	*e = *(S.top-1);
	return 1;
}

int Push_Sq(SqStack *S, CSNode* e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base = (CSNode**)realloc((*S).base, ((*S).stacksize+10)*sizeof(CSNode*));
		if(!(*S).base)
			return 0;
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += 10;
	}
	
	*((*S).top) = e;//Ϊʲô��ջ�ȸ�ֵ����ͼ��top�������һ��Ԫ�ص�β����Ҳ�����¸�Ԫ�ص�ͷ�� 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, CSNode* *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//Ϊʲô�ȵݼ�ָ�룬��ͼ������ȸ�ֵ�ˣ���top��ʱ��û�������ˣ��ǿյ�β�� 
	*e = *((*S).top);
	return 1;
}

int Print_CS(CSNode* T)
{
	typedef struct
	{
		char e;//��ĸ 
		int x, y;//���� 
	}Node;//�����ĺ����ֵ�������Ľڵ�ṹ�� 
	
	if(T)
	{
		SqStack S;
		InitStack_Sq(&S);
		
		Push_Sq(&S, T);
		//��ʼ��������Ϣ 
		int row=0;
		int col=0;
		int row_max=0;
		
		CSNode* tmp;
		Node node[100];
		int k=0;
		while(!StackEmpty_Sq(S))
		{
			GetTop_Sq(S, &tmp);
			//����ͼ���긳ֵ 
			node[k].e = tmp->data;
			node[k].x = col;
			node[k].y = row;
			k++;
			
			while(tmp->firstchild)//����ͼ���긳ֵ�����ֵ����ĺ��ӣ���ѹջ 
			{
				Push_Sq(&S, tmp->firstchild);
				row++;
				if(row_max<row)
					row_max = row;
				GetTop_Sq(S, &tmp);
				
				node[k].e = tmp->data;
				node[k].x = col;
				node[k].y = row;
				k++;
			}
			
			Pop_Sq(&S, &tmp);//�������һ������ 
			
			if(tmp->nextsibling)//��������ֵܣ�ѹջ�ֵܣ���������������Ϣ 
			{
				Push_Sq(&S, tmp->nextsibling);
				col++;
			}
			else
			{
				while(!StackEmpty_Sq(S))//û���ֵܾͼ�����ջֱ���ҵ�ĳ���������ֵܣ�����ѹջ 
				{
					Pop_Sq(&S, &tmp);
					row--;
					
					if(tmp->nextsibling)
					{
						Push_Sq(&S, tmp->nextsibling);
						col++;
						break;
					}
				}
			}
		}
		
		char a[100][100] = {};
		for(int i=0; i<k; i++)//��ʱС�ṹ�����Ѿ����ܵ������е�������Ϣ������Щ��Ϣ�������ά������ 
			a[node[i].x][3*node[i].y] = node[i].e;
		
		for(int i=0; i<=col; i++)//��ӡ����ά���飬ͬһ���е���ĸ���Ǹ��ڵ�ͺ��ӣ�ͬһ�е����ֵ� 
		{
			for(int j=0; j<=3*row_max; j++)
			{
				if(a[i][j])
					printf("%c", a[i][j]);
				else
					printf(".");//.���ڵ���ĸ�Ǻ��� 
			}
			printf("\n");//�������ڵ���ĸ���ֵ� 
		}
	}
	else
		return 0;
}

int DFSForest(MGraph G, CSNode **T)
{
	InitCSTree(T);
	CSNode* p; 
	CSNode* q;
	for(int i=1; i<=G.vexNum; i++)//��ʼ������ͼ���ڵ�Ϊδ���� 
		Visited[i] = 0;
	for(int i=1; i<=G.vexNum; i++)
	{
		if(Visited[i]==0)
		{
			//������ڵ� 
			p = (CSNode*)malloc(sizeof(CSNode));
			if(!p)
				return 0;
			p->data = GetVertex_M(G, i);//��ȡͼ��ǰ�ڵ��ֵ�������ڵ�
			p->firstchild = p->nextsibling = NULL;
			
			if(!(*T))//�����ʱ���ձ���ʼ����ֻ�п���������ֱ�Ӱ�p����ȥ��p�ǵ�һ���������ĸ� 
				*T = p; 
			else	//p��ǰһ�����������ֵܣ����µ��������ĸ�	
				q->nextsibling = p;//��p����ǰһ�����������ֵ�	
			
			q = p; //qָ��ǰ��������Ҳ������һ����������ǰһ���� 
			DFSTree(G, i, &p);//�ݹ����ɺ��ӽڵ�	
		}
	}
	return 1;
}

int DFSTree(MGraph G, int order, CSNode **T)
{
	Visited[order] = 1;
	int first = 1;//����״̬���Ƿ����״η��� 
	CSNode* p;
	CSNode* q; 
	for(int w=FirstAdjVertex_M(G, G.vertex[order]); w; w=NextAdjVertex_M(G, G.vertex[order], G.vertex[w]))
	{
		if(Visited[w]==0)
		{
			//���亢�ӽڵ� 
			p = (CSNode*)malloc(sizeof(CSNode));
			if(!p)
				return 0;
			p->data = GetVertex_M(G, w);
			p->firstchild = p->nextsibling = NULL;
			
			if(first==1)//����״η��ʸ�ͼ�ڵ㣬p���ǵ�ǰ���ڵ�ĺ��� 
			{
				(*T)->firstchild = p;
				first = 0;
			}	
			else		//����Ѿ����ʹ��ˣ�p�����ֵ� 
				q->nextsibling = p;
				
			q = p;
			DFSTree(G, w, &q);
		}
	}
	return 1;
}
