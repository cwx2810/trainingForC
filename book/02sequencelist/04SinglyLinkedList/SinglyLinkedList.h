#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
//#include "../../01intro/Scanf.c"

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

int InitList_L(LNode **L);
//声明了小结构类型的指针*L，函数内*L就等价于取到小结构这个指针本体，使用成员用-> 
//对比SqList *L是声明了SqList类型的指针，函数内*L等价于取到SqList本体，使用成员用.  

int ClearList_L(LNode* L);//不用双星是因为清空后头结点还在，不改变小结构 

int DestroyList_L(LNode **L);

int ListEmpty_L(LNode* L);

int ListLength_L(LNode* L);

int GetElem_L(LNode* L, int i, int *e);

int LocateElem_L(LNode* L, int e, int(Compare)(int, int));

int PriorElem_L(LNode* L, int cur_e, int *pre_e);

int NextElem_L(LNode* L, int cur_e, int *next_e);

int ListInsert_L(LNode* L, int i, int e);

int ListDelete_L(LNode* L, int i, int *e);

int ListTraverse_L(LNode* L, void(Visit)(int));


