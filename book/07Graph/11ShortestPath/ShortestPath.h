#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../01MatrixGraph/MGraph.c"

//��Dijkstra�㷨��ͼG��v0���㵽���ඥ������·��path
//path��һ�д洢v0��v1��path�����Ľڵ㣬�ڶ��д洢v0��v2��path�����Ľڵ�... 
//����̴�Ȩ����dist��dist[10]�洢v0��v10�����·������ 
int ShortestPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[]);

int OutputPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[]);

int ShortestPath_Floyd(MGraph G, int path[][21][21], int dist[][21]);

int OutputPath_Floyd(MGraph G, int path[][21][21], int dist[][21]);


