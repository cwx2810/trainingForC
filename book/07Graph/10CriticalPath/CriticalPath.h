#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../03StackAndQueue/01SequenceStack/SequenceStack.c"
#include "../02AdjListGraph/AdjListGraph.c"

//ȫ�ֱ���
SqStack T;//�������ж���ջ
int ve[21];//���¼������㣩�����緢��ʱ��
int vl[21];//���¼������㣩����ٷ���ʱ��

int TopologicalOrder(ALGraph G, SqStack *T);//���������������򣬲�����¼������緢��ʱ��

int CriticalPath(ALGraph G);//���������ؼ��

int FindInDegree(ALGraph G, int indegree[21]);//������ͼ�����������  
