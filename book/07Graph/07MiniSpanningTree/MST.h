#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../06Tree/08MFSet/MFSet.c"
#include "../01MatrixGraph/MGraph.c"

typedef struct
{
	//char vertex;//边的尾节点 
	int lowcost;//边的权值 
}EdgeNode;//辅助数组 


int MiniSpanTree_Prim(MGraph G, char e);//Prim算法(只在已经探索过的顶点中找下一条最小边)构造从顶点e出发的最小生成树，输出树的各条边
int Minimum(EdgeNode closedge[], int n);//返回辅助数组中权值最小边的序号(也是真实图中边的尾节点序号)，n为顶点数，遍历用的 
 




