#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../02AdjListGraph/AdjListGraph.c"

//全局变量
int count;
int low[21];//以当前节点为根的树可以追溯的最早祖先，祖先越早越小，比如low[3]=1表示3号节点为根的树可以追溯的最早祖先是1号节点 
int node[21];//存放关节点，0号存放关节点个数

int FindArticulation(ALGraph G);//找出所有关节点 
int DFSArticulation(ALGraph G, int order);//从第order个顶点出发深度遍历G，找出所有关节点 

int SavePoint(int order);//存储序号为order的关节点到node中 
 
int OutputPoint(ALGraph G);
