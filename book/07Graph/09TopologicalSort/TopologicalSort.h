#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/01SequenceStack/SequenceStack.c"
#include "../02AdjListGraph/AdjListGraph.c"

int TopologicalSort(ALGraph G, int topo[]);//�������廷ͼ����������������topo����֮ 

int FindInDegree(ALGraph G, int indegree[21]);//������ͼ����������� 

