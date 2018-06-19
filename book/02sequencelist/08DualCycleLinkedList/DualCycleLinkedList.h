#include <stdlib.h>
#include "../../01intro/Status.h"

typedef struct DNode
{
	int data;
	struct DNode *prior;
	struct DNode *next;
}DNode;

int InitList_DL(DNode **L);

int ClearList_DL(DNode* L);

int DestroyList_DL(DNode **L);

int ListEmpty_DL(DNode* L);

int ListLength_DL(DNode* L);

int GetElem_DL(DNode* L, int i, int *e);

int LocateElem_DL(DNode* L, int e, int(Compare)(int, int));

int PriorElem_DL(DNode* L, int cur_e, int *pre_e);

int NextElem_DL(DNode* L, int cur_e, int *next_e);

DNode* GetElemPtr_DL(DNode* L, int i);//返回L中指向第i个节点的指针

int ListInsert_DL(DNode* L, int i, int e);

int ListDelete_DL(DNode* L, int i, int *e);

int ListTraverse_DL(DNode* L, void(Visit)(int)); 
