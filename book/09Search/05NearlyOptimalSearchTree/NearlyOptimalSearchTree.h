#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"
#include "../../06Tree/02BinaryTree/BinaryTree.c"

char ch[] = "\0ABCDEFGHI";

int FindAllWeight(float w[], Table T);//�����ۼ�Ȩֵ���飬ÿ��λ�Ӵ洢֮ǰ������Ȩֵ֮�� 

int MinBetweenWeight(float w[], int low, int high);
//�����ۼ�Ȩֵ���飬�ҳ�Ȩֵ��ĳ��Ȩֵ��Ӧ����ţ����λ���������Ȩֵ֮�ͺ��ұ�����Ȩֵ֮�������С 

int NearlyOptimal(BiTNode* *BT, ElemType R[], float w[], int low, int high);//���Ų��������캯���ĺ��ĵݹ麯�� 
int CreateNearlyOptimal(BiTNode* *BT, Table T);//�������T������Ų�����

int SearchKey(BiTNode* BT, int key);//�жϹؼ���key�Ƿ��ڴ��Ų������� 

