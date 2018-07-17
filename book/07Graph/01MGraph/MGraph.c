#include "MGraph.h"

int CreateGraph_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d", &((*G).kind));//读取图的类型，根据类型判断调用哪一个创建函数 
	
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
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//读取顶点数，弧数，信息赋给图结构体

	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符，因为\n也是char格式，不用tmp保存住下面读字符的时候第一个会读成\n 
	for(int i=1; i<=(*G).vexNum; i++)//读取顶点 
	{
		Scanf(fp, "%c", &((*G).vertex[i]));
	}
	Scanf(fp, "%c", &tmp);	//跳过换行符 
	
		
	for(int i=1; i<=(*G).vexNum; i++)//初始化邻接矩阵 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = 0;
	}
	
	char e1, e2;//<e1, e2>，e1和e2分别表示弧的x坐标和y坐标 
	for(int k=1; k<=(*G).arcNum; k++)//读取弧 
	{
		Scanf(fp, "%c%c", &e1, &e2);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = 1;//有连接的弧赋值1
		
		if((*G).info == 1)				//如果有弧的信息则录入 
			Input_M(fp, &((*G).matrix[x][y].info)); 
	}
	return 1;
}

int CreateDirectNet_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//读取顶点数，弧数，信息赋给图结构体
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符，因为\n也是char格式，不用tmp保存住下面读字符的时候第一个会读成\n  
	for(int i=1; i<=(*G).vexNum; i++)//读取顶点 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//跳过换行符
		
	for(int i=1; i<=(*G).vexNum; i++)//初始化邻接矩阵 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = INT_MAX;
	}
	
	char e1, e2;//<e1, e2>，e1和e2分别表示弧的x坐标和y坐标
	int vr; //网边表示权值，图中用01表示是否相邻 
	for(int k=1; k<=(*G).arcNum; k++)//读取弧 
	{
		Scanf(fp, "%c%c%d", &e1, &e2, &vr);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = vr;//有连接的弧赋权值 
		
		if((*G).info == 1)				//如果有弧的信息则录入 
			Input_M(fp, &((*G).matrix[x][y].info)); 
	}
	return 1;
}

int CreateUnDirectGraph_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//读取顶点数，弧数，信息赋给图结构体
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符，因为\n也是char格式，不用tmp保存住下面读字符的时候第一个会读成\n  
	for(int i=1; i<=(*G).vexNum; i++)//读取顶点 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//跳过换行符
		
	for(int i=1; i<=(*G).vexNum; i++)//初始化邻接矩阵 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = 0;
	}
	
	char e1, e2;//<e1, e2>，e1和e2分别表示弧的x坐标和y坐标 
	for(int k=1; k<=(*G).arcNum; k++)//读取弧 
	{
		Scanf(fp, "%c%c", &e1, &e2);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = 1;//有连接的弧赋值1
		
		if((*G).info == 1)				//如果有弧的信息则录入 
			Input_M(fp, &((*G).matrix[x][y].info)); 
			
		(*G).matrix[y][x] = (*G).matrix[x][y];//填充对称点 
	}
	return 1;
}

int CreateUnDirectNet_M(FILE* fp, MGraph *G)
{
	Scanf(fp, "%d%d%d", &((*G).vexNum), &((*G).arcNum), &((*G).info));//读取顶点数，弧数，信息赋给图结构体
	char tmp;
	Scanf(fp, "%c", &tmp);//跳过换行符，因为\n也是char格式，不用tmp保存住下面读字符的时候第一个会读成\n  
	for(int i=1; i<=(*G).vexNum; i++)//读取顶点 
		Scanf(fp, "%c", &((*G).vertex[i]));
	Scanf(fp, "%c", &tmp);//跳过换行符
		
	for(int i=1; i<=(*G).vexNum; i++)//初始化邻接矩阵 
	{
		for(int j=1; j<=(*G).vexNum; j++)
			(*G).matrix[i][j].vertexRelation = INT_MAX;
	}
	
	char e1, e2;//<e1, e2>，e1和e2分别表示弧的x坐标和y坐标
	int vr; //网边表示权值，图中用01表示是否相邻 
	for(int k=1; k<=(*G).arcNum; k++)//读取弧 
	{
		Scanf(fp, "%c%c%d", &e1, &e2, &vr);
		
		int x = LocateVertex_M(*G, e1);
		int y = LocateVertex_M(*G, e2);
		if(!x || !y)
			return 0;
		
		(*G).matrix[x][y].vertexRelation = vr;//有连接的弧赋权值 
		
		if((*G).info == 1)				//如果有弧的信息则录入 
			Input_M(fp, &((*G).matrix[x][y].info)); 
			
		(*G).matrix[y][x] = (*G).matrix[x][y];//填充对称点
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
	int order = LocateVertex_M(G, e);//得到e的序号 
	if(!order)
		return 0;
	
	int nulltype;
	if(G.kind%2 != 0)//给的是网，设置无连接的弧 
 		nulltype = INT_MAX;
 	else			//给的是图，设置无连接的弧 
 		nulltype = 0;
 		
	for(int j=1; j<=G.vexNum; j++)
	{
		if(G.matrix[order][j].vertexRelation!=nulltype)//如果有连接，则返回<order，j>的j，也就是邻接点的序号 
			return j;
	}
	return 0;
}

int NextAdjVertex_M(MGraph G, char e, char w)
{
	int order1 = LocateVertex_M(G, e);//得到e和w的序号 
	int order2 = LocateVertex_M(G, w);
	
	if(!order1 || !order2)
		return 0;
		
	int nulltype;
	if(G.kind%2 != 0)//给的是网，设置无连接的弧 
 		nulltype = INT_MAX;
 	else			//给的是图，设置无连接的弧 
 		nulltype = 0;
	for(int j=order2+1; j<=G.vexNum; j++)//因为求相对于w的下一个顶点的序号，所以从w的下一个序号开始遍历 
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
	if((*G).kind%2 != 0)//给的是网，设置无连接的弧 
 		nulltype = INT_MAX;
 	else			//给的是图，设置无连接的弧 
 		nulltype = 0;
	int order = (*G).vexNum+1;//插入的位置序号
	(*G).vertex[order] = e;//插入操作
	
	for(int i=1; i<=order; i++)//调整邻接矩阵，因为只是插入，没有连接弧，所以邻接矩阵的点都是无连接 
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
	if((*G).kind%2 != 0)//给的是网，设置无连接的弧 
 		nulltype = INT_MAX;
 	else			//给的是图，设置无连接的弧 
 		nulltype = 0;
	
	for(int i=1; i<=order; i++)//调整弧数量 
	{
		if((*G).matrix[order][i].vertexRelation!=nulltype)//如果该点和其他点有连接，弧数要减少 
			(*G).arcNum--;
		if((*G).kind==DirectGraph || (*G).kind==DirectNet)//如果是有向的，可能还要重复减少一遍反向弧 
		{
			if((*G).matrix[i][order].vertexRelation!=nulltype)
				(*G).arcNum--;
		}
	}
	
	//移动order之后的所有元素，两个维度都要移动 
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
	int order1 = LocateVertex_M(*G, e);//得到e和w的序号 
	int order2 = LocateVertex_M(*G, w);
	
	if(!order1 || !order2)
		return 0;
		
	(*G).matrix[order1][order2].vertexRelation = vertexRelation;//插入弧的关系
	
	va_list ap;//如果有弧信息则插入 
	va_start(ap, vertexRelation);
	(*G).matrix[order1][order2].info = va_arg(ap, ArcInfo);
	va_end(ap); 
	
 	if((*G).kind==UnDirectGraph || (*G).kind==UnDirectNet)//如果是无向的邻接矩阵要再复制一份对称的 
 		(*G).matrix[order2][order1] = (*G).matrix[order1][order2];
		
	(*G).arcNum++;
	return 1;
}

int DeleteArc_M(MGraph *G, char e, char w)
{
	int order1 = LocateVertex_M(*G, e);//得到e和w的序号 
	int order2 = LocateVertex_M(*G, w);
	
	if(!order1 || !order2)
		return 0;
		
	if((*G).kind%2 != 0)//给的是网，把该弧设置成无连接 
 		(*G).matrix[order1][order2].vertexRelation = INT_MAX;
 	else			//给的是图，把该弧设置成无连接 
 		(*G).matrix[order1][order2].vertexRelation = 0;
 		
	if((*G).kind==UnDirectGraph || (*G).kind==UnDirectNet)//如果是无向的邻接矩阵要再复制一份对称的 
 		(*G).matrix[order2][order1] = (*G).matrix[order1][order2];
		
	(*G).arcNum--;
	return 1;
}

void DFSTraverse_M(MGraph G, void(Visit)(char))
{
	VisitFunc = Visit;
	
	for(int i=1; i<=G.vexNum; i++)//把所有顶点都初始化为未访问 
		Visited[i] = 0;
	
	for(int i=1; i<=G.vexNum; i++)
	{
		if(Visited[i]==0)//如果未访问，挨个访问节点 
			DFS_M(G, i);
	}
}

void DFS_M(MGraph G, int i)
{
	
	Visited[i] = 1;//设置标记为已访问 
	VisitFunc(G.vertex[i]);//访问
	
	//w是第一邻接点，w存在，w向下一邻接点移动 
	int w;
	for(w=FirstAdjVertex_M(G, G.vertex[i]); w; w=NextAdjVertex_M(G, G.vertex[i], G.vertex[w]))
	{
		if(Visited[w]==0)
			DFS_M(G, w);
	} 
}

int BFSTraverse_M(MGraph G, void(Visit)(char))
{
	for(int i=1; i<=G.vexNum; i++)//所有顶点初始化为未访问 
		Visited[i] = 0;
	
	LinkQueue Q;//用队列实现广度优先遍历
	InitQueue_L(&Q);
	int e;//存放出队的元素 
	
	for(int i=1; i<=G.vexNum; i++)//遍历所有顶点 
	{
		if(Visited[i]==0)//如果未访问，则访问 
		{
			Visited[i] = 1;
			Visit(G.vertex[i]);
			EnQueue_L(&Q, i);//访问完标号入队
			while(!QueueEmpty_L(Q))
			{
				DeQueue_L(&Q, &e);//如果队列有标号，就出队，遍历之后的邻接顶点 
				for(int w=FirstAdjVertex_M(G, G.vertex[e]); w; w=NextAdjVertex_M(G, G.vertex[e], G.vertex[w]))
				{
					if(Visited[w]==0)//如果之后的未访问，则访问 
					{
						Visited[w] = 1;
						Visit(G.vertex[w]);
						EnQueue_L(&Q, w);//继续入队出队访问 
					} 
				}
			} 
		}
	} 
	return 1;
}
//之后写测试函数时手动模拟一遍BFS，把DFS的visit函数改写一下试试

int Output_M(MGraph G)
{
	if(!G.vexNum && !G.arcNum)
		return 0;
	else
	{
		//打印第一行表头 
		printf("  "); 
		for(int i=1; i<=G.vexNum; i++)
			printf("%2c ", G.vertex[i]);
		printf("\n");
		
		//打印其余行
		for(int i=1; i<=G.vexNum; i++)
		{
			printf("%c ", G.vertex[i]);//打印第一列表头
			for(int j=1; j<=G.vexNum; j++)//打印行中内容 
			{
				if(G.matrix[i][j].vertexRelation==INT_MAX)
					printf("∞ ");
				else
					printf("%2d ", G.matrix[i][j]); 
			} 
			printf("\n");//换行 
		} 
	}
	return 1;
} 

int Input_M(FILE* fp, ArcInfo* info)
{
	return 1;//默认无信息 
}
