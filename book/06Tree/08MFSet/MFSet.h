#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"



/*并查集的定义*/
typedef struct PTNode//树的双亲表示法的节点 
{
	int data;//数据域 
	int parent;//双亲位置域 
}PTNode;
typedef struct 
{
	PTNode node[100];
	int n;
}PTree;//双亲表示法的树结构体，包括100个从0开始的节点空间，保存了n个节点
typedef PTree MFSet;



/*集合关系定义*/
typedef struct
{
	int i;
	int j;
}Node;//二元关系
typedef struct
{
	Node nodes[100];
	int n;
}Relation; //等价关系




int InitMFSet(FILE* fp, MFSet* S);//初始化n个单元素子集，每个子集是一个节点，组成树 

int FindMFSet(MFSet S, int i);//查找集合S中i所在子集的根节点，也就是i所在树的根节点 

int FixMFSet(MFSet* S, int i);//找到i所在树的根节点，并把此树压缩到高为2 

int MergeMFSet(MFSet* S, int i, int j);//求不相交的Si和Sj的并集

int MixMFSet(MFSet* S, int i, int j);//上面算法的改进

int BuildRelationMFSet(FILE* fp, Relation* R);//建立二元等价关系 

int EquivalenceClassMFSet(MFSet* S, Relation R);//求等价关系R下的集合S的等价类

int SubsetCountMFSet(MFSet S);//返回集合S中的非空子集数目

int ShowSetMFSet(MFSet S); 
 
 
