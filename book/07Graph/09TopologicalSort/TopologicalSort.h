#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/01SequenceStack/SequenceStack.c"
#include "../02AdjListGraph/AdjListGraph.c"

int TopologicalSort(ALGraph G, int topo[]);//求有向五环图的拓扑排序，用数组topo保存之 

int FindInDegree(ALGraph G, int indegree[21]);//对有向图各顶点求入度 

