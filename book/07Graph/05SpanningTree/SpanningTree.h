#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../01MatrixGraph/MGraph.c"

//孩子兄弟树节点 
typedef struct CSNode
{
	char data;
	struct CSNode* firstchild;
	struct CSNode* nextsibling;
}CSNode;

//栈结构存放树节点 
typedef struct
{
	CSNode* *base;//栈底指针，相当于原来顺序表的elem，基址 
	CSNode* *top;//栈顶指针 
	int stacksize;//栈中元素个数 
}SqStack;

int InitCSTree(CSNode **T);
int InitStack_Sq(SqStack *S);
int StackEmpty_Sq(SqStack S);
int GetTop_Sq(SqStack S, CSNode* *e);
int Push_Sq(SqStack *S, CSNode* e);
int Pop_Sq(SqStack *S, CSNode* *e);
int Print_CS(CSNode* T);



int DFSForest(MGraph G, CSNode **T);//用深度遍历创建无向图生成树或森林 
int DFSTree(MGraph G, int order, CSNode **T);//创建树的核心算法，生成从节点序号order开始的树 
