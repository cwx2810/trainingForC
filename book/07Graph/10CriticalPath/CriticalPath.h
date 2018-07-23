#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/01SequenceStack/SequenceStack.c"
#include "../02AdjListGraph/AdjListGraph.c"

//全局变量
SqStack T;//拓扑序列顶点栈
int ve[21];//各事件（顶点）的最早发生时间
int vl[21];//各事件（顶点）的最迟发生时间

int TopologicalOrder(ALGraph G, SqStack *T);//求有向网拓扑排序，并求各事件的最早发生时间

int CriticalPath(ALGraph G);//求有向网关键活动

int FindInDegree(ALGraph G, int indegree[21]);//对有向图各顶点求入度  
