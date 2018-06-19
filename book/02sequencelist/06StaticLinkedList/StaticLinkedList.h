#include <stdlib.h>
#include "../../01intro/Status.h"

//连续的单链表，把它看成连续的动态空间，存取过程模拟malloc和free 
typedef struct
{
	int data;
	int pnext;//游标，模拟单链表的结构指针 
}Space[1000];//实际上SPACE是个数组，用数组承载模拟的动态空间 

Space SPACE;

void InitSpace();//建立空间 

int MallocSpace();//模拟malloc过程 

void FreeSpace(int k);//模拟free掉游标为k的结点 


int InitList_SL(int *L);

int ClearList_SL(int L);

int DestroyList_SL(int *L);

int ListEmpty_SL(int L);

int ListLength_SL(int L);

int GetElem_SL(int L, int i, int *e);

int LocateElem_SL(int L, int e);

int PriorElem_SL(int L, int cur_e, int *pre_e);

int NextElem_SL(int L, int cur_e, int *next_e);

int ListInsert_SL(int L, int i, int e);

int ListDelete_SL(int L, int i, int *e);

int ListTraverse_SL(int L, void(Visit)(int));


