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
	
	*((*S).top) = e;//为什么进栈先赋值，想图，top是在最后一个元素的尾部，也就是下个元素的头部 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, CSNode* *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//为什么先递减指针，想图，如果先赋值了，那top此时就没有意义了，是空的尾部 
	*e = *((*S).top);
	return 1;
}

int Print_CS(CSNode* T)
{
	typedef struct
	{
		char e;//字母 
		int x, y;//坐标 
	}Node;//画出的孩子兄弟树矩阵的节点结构体 
	
	if(T)
	{
		SqStack S;
		InitStack_Sq(&S);
		
		Push_Sq(&S, T);
		//初始化坐标信息 
		int row=0;
		int col=0;
		int row_max=0;
		
		CSNode* tmp;
		Node node[100];
		int k=0;
		while(!StackEmpty_Sq(S))
		{
			GetTop_Sq(S, &tmp);
			//给画图坐标赋值 
			node[k].e = tmp->data;
			node[k].x = col;
			node[k].y = row;
			k++;
			
			while(tmp->firstchild)//给画图坐标赋值孩子兄弟树的孩子，并压栈 
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
			
			Pop_Sq(&S, &tmp);//弹出最后一个孩子 
			
			if(tmp->nextsibling)//如果其有兄弟，压栈兄弟，继续完善坐标信息 
			{
				Push_Sq(&S, tmp->nextsibling);
				col++;
			}
			else
			{
				while(!StackEmpty_Sq(S))//没有兄弟就继续弹栈直到找到某个孩子有兄弟，继续压栈 
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
		for(int i=0; i<k; i++)//此时小结构数组已经接受到了所有的坐标信息，将这些信息输出到二维数组中 
			a[node[i].x][3*node[i].y] = node[i].e;
		
		for(int i=0; i<=col; i++)//打印出二维数组，同一行中的字母都是父节点和孩子，同一列的是兄弟 
		{
			for(int j=0; j<=3*row_max; j++)
			{
				if(a[i][j])
					printf("%c", a[i][j]);
				else
					printf(".");//.相邻的字母是孩子 
			}
			printf("\n");//换行相邻的字母是兄弟 
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
	for(int i=1; i<=G.vexNum; i++)//初始化无向图各节点为未访问 
		Visited[i] = 0;
	for(int i=1; i<=G.vexNum; i++)
	{
		if(Visited[i]==0)
		{
			//分配根节点 
			p = (CSNode*)malloc(sizeof(CSNode));
			if(!p)
				return 0;
			p->data = GetVertex_M(G, i);//获取图当前节点的值赋给树节点
			p->firstchild = p->nextsibling = NULL;
			
			if(!(*T))//如果此时树刚被初始化，只有空树根，则直接把p赋进去，p是第一棵生成树的根 
				*T = p; 
			else	//p是前一棵生成树的兄弟，是新的生成树的根	
				q->nextsibling = p;//把p赋给前一棵生成树的兄弟	
			
			q = p; //q指向当前生成树，也就是下一棵生成树的前一棵树 
			DFSTree(G, i, &p);//递归生成孩子节点	
		}
	}
	return 1;
}

int DFSTree(MGraph G, int order, CSNode **T)
{
	Visited[order] = 1;
	int first = 1;//访问状态，是否是首次访问 
	CSNode* p;
	CSNode* q; 
	for(int w=FirstAdjVertex_M(G, G.vertex[order]); w; w=NextAdjVertex_M(G, G.vertex[order], G.vertex[w]))
	{
		if(Visited[w]==0)
		{
			//分配孩子节点 
			p = (CSNode*)malloc(sizeof(CSNode));
			if(!p)
				return 0;
			p->data = GetVertex_M(G, w);
			p->firstchild = p->nextsibling = NULL;
			
			if(first==1)//如果首次访问该图节点，p就是当前树节点的孩子 
			{
				(*T)->firstchild = p;
				first = 0;
			}	
			else		//如果已经访问过了，p就是兄弟 
				q->nextsibling = p;
				
			q = p;
			DFSTree(G, w, &q);
		}
	}
	return 1;
}
