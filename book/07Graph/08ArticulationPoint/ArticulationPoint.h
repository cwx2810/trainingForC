#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../02AdjListGraph/AdjListGraph.c"

//ȫ�ֱ���
int count;
int low[21];//�Ե�ǰ�ڵ�Ϊ����������׷�ݵ��������ȣ�����Խ��ԽС������low[3]=1��ʾ3�Žڵ�Ϊ����������׷�ݵ�����������1�Žڵ� 
int node[21];//��Źؽڵ㣬0�Ŵ�Źؽڵ����

int FindArticulation(ALGraph G);//�ҳ����йؽڵ� 
int DFSArticulation(ALGraph G, int order);//�ӵ�order�����������ȱ���G���ҳ����йؽڵ� 

int SavePoint(int order);//�洢���Ϊorder�Ĺؽڵ㵽node�� 
 
int OutputPoint(ALGraph G);
