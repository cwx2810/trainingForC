#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../01MatrixGraph/MGraph.c"

//用Dijkstra算法求图G的v0顶点到其余顶点的最短路径path
//path第一行存储v0到v1的path经过的节点，第二行存储v0到v2的path经过的节点... 
//求最短带权长度dist，dist[10]存储v0到v10的最短路径长度 
int ShortestPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[]);

int OutputPath_Dijkstra(MGraph G, int v0, int path[][21], int dist[]);

int ShortestPath_Floyd(MGraph G, int path[][21][21], int dist[][21]);

int OutputPath_Floyd(MGraph G, int path[][21][21], int dist[][21]);


