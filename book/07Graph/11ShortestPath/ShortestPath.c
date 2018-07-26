#include "ShortestPath.h"

int ShortestPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[])
{
	int added[21];//��ǵ�ǰ�ڵ��Ƿ��Ѿ��������·��path��0�ŵ�Ԫ����
	//��ʼ�� 
	for(int v=1; v<=G.vexNum; v++)
	{
		//��ʼ�����Ϊ���нڵ㶼û����
		added[v] = FALSE;
		//��ʼ��dist����v0�������Ȩֵ����dist����ֱ����ϵ���Ѿ������·����  
		dist[v] = G.matrix[v0][v].vertexRelation;
		//��ʼ�����·���ڵ�
		for(int w=1; w<=G.vexNum; w++) 
			path[v][w] = 0;	
		if(dist[v] < INT_MAX)//��������ģ�ֱ�Ӻ�v0��ͨ�ĵ� 
		{
			path[v][v0] = 1;//��v�д洢v0��vv�����·�������Ľڵ㣬��Ϊֻ��v0��vֱ����ͨ������ֻ��v0��vv�������ǹؼ�·�� 
			path[v][v] = 1;
		}
	} 
	
	dist[v0] = 0;//��ʼ��v0 
	added[v0] = TRUE;
	for(int i=2; i<=G.vexNum; i++)//��������ڵ㣬�õ�v0��ĳ��v�����·������������ 
	{
		int min = INT_MAX;//��ǰ�ڵ���v0�����·�� 
		int v;
		for(int w=1; w<=G.vexNum; w++)
		{
			if(added[w]==FALSE)//��û����ӹ��Ľڵ㣬��������v0����������min��ʱ����֮ 
			{
				if(dist[w]<min)
				{
					v=w;//����������Ľڵ�Ϊv��v0��vΪ���·�� 
					min=dist[w];
				}
			}
		}
		added[v] = TRUE;//���������·�� 
		for(int w=1; w<=G.vexNum; w++)
		{	//min + v֮��ľ���dist�ȳ�ʼ���ľ���dist�̵ģ����¾���dist 
			if(added[w]==FALSE && min<INT_MAX && G.matrix[v][w].vertexRelation<INT_MAX && (min+G.matrix[v][w].vertexRelation<dist[w]))
			{
				dist[w] = min + G.matrix[v][w].vertexRelation;
				for(int j=1; j<=G.vexNum; j++)//��w�д洢v0��vw���·�������Ľڵ� 
					path[w][j] = path[v][j];//v0~vwҲ�����·����������v��һ������ 
				path[w][w] = 1;//w����϶������·���ڵ� 
			}
		}
	}
	return 1;
}

int OutputPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[])
{
	int count[21];//ͳ��ÿ���ؼ�·���еĹؼ��ڵ���� 
	int order[21];//��¼���нڵ���� 
	//��ʼ��count��order 
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
			if(count[j]<count[i])//���·���ڵ���Ŀ�ٵ���ǰ�� 
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
		if(order[i]!=v0)//��������Լ����Լ������·�� 
		{
			printf("%c��%c�����·��Ϊ��", G.vertex[v0], G.vertex[order[i]]);
			if(count[i]==0)//û�����·���ڵ��� 
				printf("��");
			else
			{
				for(int j=1; j<=G.vexNum; j++)
				{
					if(path[order[i]][j]==1)
						printf("%c ", G.vertex[order[j]]);
				}
			}
			
			printf("��ȨֵΪ��");
			if(dist[order[i]] < INT_MAX)
				printf("%2d\n", dist[order[i]]);
			else
				printf("��\n");
		}
	}
	return 1;
}

int ShortestPath_Floyd(MGraph G, int path[][21][21], int dist[][21])
{
	//��ʼ������֮��ĳ�ʼ���뼰·�� 
	for(int v=1; v<=G.vexNum; v++)
	{
		for(int w=1; w<=G.vexNum; w++)
		{
			dist[v][w] = G.matrix[v][w].vertexRelation;//��ʼ������
			for(int u=1; u<=G.vexNum; u++)
				path[v][w][u] = 0;
			if(dist[v][w] < INT_MAX)//��v��w��ֱ��·�� 
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
				//��v��u��w��·������ 
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
				printf("%c��%c�����·��Ϊ��", G.vertex[i], G.vertex[j]);
				
				if(count[i][j]==0)
					printf("��");
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
				
				printf("��ȨֵΪ��");
				if(dist[i][j]<INT_MAX)
					printf("%2d\n", dist[i][j]);
				else
					printf("��\n");
			}
		}
	}
	return 1;
}
