#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../06Tree/08MFSet/MFSet.c"
#include "../01MatrixGraph/MGraph.c"

typedef struct
{
	//char vertex;//�ߵ�β�ڵ� 
	int lowcost;//�ߵ�Ȩֵ 
}EdgeNode;//�������� 


int MiniSpanTree_Prim(MGraph G, char e);//Prim�㷨(ֻ���Ѿ�̽�����Ķ���������һ����С��)����Ӷ���e��������С��������������ĸ�����
int Minimum(EdgeNode closedge[], int n);//���ظ���������Ȩֵ��С�ߵ����(Ҳ����ʵͼ�бߵ�β�ڵ����)��nΪ�������������õ� 
 




