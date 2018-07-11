#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"



/*���鼯�Ķ���*/
typedef struct PTNode//����˫�ױ�ʾ���Ľڵ� 
{
	int data;//������ 
	int parent;//˫��λ���� 
}PTNode;
typedef struct 
{
	PTNode node[100];
	int n;
}PTree;//˫�ױ�ʾ�������ṹ�壬����100����0��ʼ�Ľڵ�ռ䣬������n���ڵ�
typedef PTree MFSet;



/*���Ϲ�ϵ����*/
typedef struct
{
	int i;
	int j;
}Node;//��Ԫ��ϵ
typedef struct
{
	Node nodes[100];
	int n;
}Relation; //�ȼ۹�ϵ




int InitMFSet(FILE* fp, MFSet* S);//��ʼ��n����Ԫ���Ӽ���ÿ���Ӽ���һ���ڵ㣬����� 

int FindMFSet(MFSet S, int i);//���Ҽ���S��i�����Ӽ��ĸ��ڵ㣬Ҳ����i�������ĸ��ڵ� 

int FixMFSet(MFSet* S, int i);//�ҵ�i�������ĸ��ڵ㣬���Ѵ���ѹ������Ϊ2 

int MergeMFSet(MFSet* S, int i, int j);//���ཻ��Si��Sj�Ĳ���

int MixMFSet(MFSet* S, int i, int j);//�����㷨�ĸĽ�

int BuildRelationMFSet(FILE* fp, Relation* R);//������Ԫ�ȼ۹�ϵ 

int EquivalenceClassMFSet(MFSet* S, Relation R);//��ȼ۹�ϵR�µļ���S�ĵȼ���

int SubsetCountMFSet(MFSet S);//���ؼ���S�еķǿ��Ӽ���Ŀ

int ShowSetMFSet(MFSet S); 
 
 
