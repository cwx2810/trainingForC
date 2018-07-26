#include "ShortestPath.h"

int ShortestPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[])
{
	int added[21];//标记当前节点是否已经加入最短路径path，0号单元弃用
	//初始化 
	for(int v=1; v<=G.vexNum; v++)
	{
		//初始化标记为所有节点都没加入
		added[v] = FALSE;
		//初始化dist，将v0到各点的权值加入dist，有直接联系的已经是最短路径了  
		dist[v] = G.matrix[v0][v].vertexRelation;
		//初始化最短路径节点
		for(int w=1; w<=G.vexNum; w++) 
			path[v][w] = 0;	
		if(dist[v] < INT_MAX)//不是无穷的，直接和v0连通的点 
		{
			path[v][v0] = 1;//第v行存储v0到vv的最短路径经过的节点，因为只有v0和v直接连通，所以只有v0和vv这两点是关键路径 
			path[v][v] = 1;
		}
	} 
	
	dist[v0] = 0;//初始化v0 
	added[v0] = TRUE;
	for(int i=2; i<=G.vexNum; i++)//遍历其余节点，得到v0到某个v的最短路径，加入数组 
	{
		int min = INT_MAX;//当前节点离v0的最短路径 
		int v;
		for(int w=1; w<=G.vexNum; w++)
		{
			if(added[w]==FALSE)//有没有添加过的节点，并且其离v0更近，更新min临时保存之 
			{
				if(dist[w]<min)
				{
					v=w;//令这个更近的节点为v，v0到v为最短路径 
					min=dist[w];
				}
			}
		}
		added[v] = TRUE;//添加这个最短路径 
		for(int w=1; w<=G.vexNum; w++)
		{	//min + v之后的距离dist比初始化的距离dist短的，更新距离dist 
			if(added[w]==FALSE && min<INT_MAX && G.matrix[v][w].vertexRelation<INT_MAX && (min+G.matrix[v][w].vertexRelation<dist[w]))
			{
				dist[w] = min + G.matrix[v][w].vertexRelation;
				for(int j=1; j<=G.vexNum; j++)//第w行存储v0到vw最短路径经过的节点 
					path[w][j] = path[v][j];//v0~vw也是最短路径，紧跟着v，一样即可 
				path[w][w] = 1;//w本身肯定是最短路径节点 
			}
		}
	}
	return 1;
}

int OutputPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[])
{
	int count[21];//统计每条关键路径中的关键节点个数 
	int order[21];//记录所有节点序号 
	//初始化count和order 
	for(int i=1; i<=G.vexNum; i++)
	{
		order[i]=i;
		count[i]=0;
		for(int j=1; j<=G.vexNum; j++)
		{
			if(path[i][j]==1)
				count[i]++;
		}
	}
	
	for(int i=1; i<=G.vexNum; i++)
	{
		for(int j=i+1; j<=G.vexNum; j++)
		{
			if(count[j]<count[i])//最短路径节点数目少的排前面 
			{
				int tmp = count[i];
				count[i] = count[j];
				count[j] = tmp;
				
				for(int k=1; k<=G.vexNum; k++)
				{
					tmp = path[k][i];
					path[k][i] = path[k][j];
					path[k][j] = tmp;
				}
				
				tmp = order[i];
				order[i] = order[j];
				order[j] = tmp;
			}
		}
	}
	
	for(int i=1; i<=G.vexNum; i++)
	{
		if(order[i]!=v0)//不能输出自己到自己的最短路径 
		{
			printf("%c到%c的最短路径为：", G.vertex[v0], G.vertex[order[i]]);
			if(count[i]==0)//没有最短路径节点打× 
				printf("×");
			else
			{
				for(int j=1; j<=G.vexNum; j++)
				{
					if(path[order[i]][j]==1)
						printf("%c ", G.vertex[order[j]]);
				}
			}
			
			printf("，权值为：");
			if(dist[order[i]] < INT_MAX)
				printf("%2d\n", dist[order[i]]);
			else
				printf("∞\n");
		}
	}
	return 1;
}

int ShortestPath_Floyd(MGraph G, int path[][21][21], int dist[][21])
{
	//初始化各点之间的初始距离及路径 
	for(int v=1; v<=G.vexNum; v++)
	{
		for(int w=1; w<=G.vexNum; w++)
		{
			dist[v][w] = G.matrix[v][w].vertexRelation;//初始化距离
			for(int u=1; u<=G.vexNum; u++)
				path[v][w][u] = 0;
			if(dist[v][w] < INT_MAX)//从v到w有直接路径 
			{
				path[v][w][v] = 1;
				path[v][w][w] = 1;
			} 
		}
	}
	
	for(int u=1; u<=G.vexNum; u++)
	{
		for(int v=1; v<=G.vexNum; v++)
		{
			for(int w=1; w<=G.vexNum; w++)
			{
				//从v经u到w的路径更短 
				if(v!=w && dist[v][u]<INT_MAX && dist[u][w]<INT_MAX && dist[v][u]+dist[u][w]<dist[v][w])
				{
					dist[v][w] = dist[v][u] + dist[u][w];
					
					for(int i=1; i<=G.vexNum; i++)
						path[v][w][i] = path[v][u][i] || path[u][w][i];
				}
			}
		}
	}
	return 1;
}

int OutputPath_Floyd(MGraph G, int path[][21][21], int dist[][21])
{
	int count[21][21];
	int tmp[21];
	
	for(int i=1; i<=G.vexNum; i++)
	{
		for(int j=1; j<=G.vexNum; j++)
		{
			count[i][j] = 0;
			for(int k=1; k<=G.vexNum; k++)
			{
				if(path[i][j][k]==1)
					count[i][j]++;
			}
		}
	}
	
	for(int i=1; i<=G.vexNum; i++)
	{
		for(int j=1; j<=G.vexNum; j++)
		{
			if(i!=j)
			{
				printf("%c到%c的最短路径为：", G.vertex[i], G.vertex[j]);
				
				if(count[i][j]==0)
					printf("×");
				else
				{
					tmp[0] = 0;
					for(int k=1; k<=G.vexNum; k++)
					{
						if(k!=i && k!=j && path[i][j][k]==1)
						{
							int m = tmp[0];
							while(m>0 && count[i][tmp[m]]>count[i][k])
							{
								tmp[m+1] = tmp[m];
								m--;
							}
							tmp[m+1] = k;
							tmp[0]++;
						}
					}
					
					printf("%c ", G.vertex[i]);
					for(int t=1; t<=tmp[0]; t++)
						printf("%c ", G.vertex[tmp[t]]);
					printf("%c ", G.vertex[j]);
				}
				
				printf("，权值为：");
				if(dist[i][j]<INT_MAX)
					printf("%2d\n", dist[i][j]);
				else
					printf("∞\n");
			}
		}
	}
	return 1;
}
