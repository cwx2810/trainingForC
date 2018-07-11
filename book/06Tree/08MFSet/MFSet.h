#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"



/*���鼯�Ķ���
 *��ν���鼯���ǰѼ��ϳ�ʼ��ֳ�n���Ӽ���ÿ���Ӽ�һ��Ԫ�أ�Ԫ�ض���ͬ��ͨ������ĳ�ֹ�ϵһ��һ���ϲ��ɴ��Ӽ� 
 *Ȼ����������˫�׽ڵ��ʾ������ͨ��parent�����˳������ÿ���Ӽ��ĸ��ڵ�  
 *���鼯���Ǵ�����Щ���ཻ�Ӽ��ĺϲ�����ѯ�����ɭ��
*/
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




int InitMFSet(FILE* fp, MFSet* S);//������ʼ������ʼ��n����Ԫ���Ӽ���ÿ���Ӽ���һ���ڵ㣬���������ɭ�� 

int FindMFSet(MFSet S, int i);//���Ҽ���S��i�����Ӽ��ĸ��ڵ㣬Ҳ����i�������ĸ��ڵ㣬�����ҵ�����Ӽ� 
int FixMFSet(MFSet* S, int i);//�����㷨�ĸĽ����ҵ�i�������ĸ��ڵ㣬���Ѵ���ѹ������Ϊ2 

int MergeMFSet(MFSet* S, int i, int j);//���ཻ��Si��Sj�Ĳ���
int MixMFSet(MFSet* S, int i, int j);//�����㷨�ĸĽ����ϲ�����ڵ����ʾ����Ӽ���Ԫ�ظ����ĸ��� 

int BuildRelationMFSet(FILE* fp, Relation* R);//������Ԫ�ȼ۹�ϵ 

int EquivalenceClassMFSet(MFSet* S, Relation R);//��ȼ۹�ϵR�µļ���S�ĵȼ���

int SubsetCountMFSet(MFSet S);//���ؼ���S�еķǿ��Ӽ���Ŀ

int ShowSetMFSet(MFSet S); 
 
 
