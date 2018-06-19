#include <stdlib.h>
#include "../../01intro/Status.h"

//�����ĵ������������������Ķ�̬�ռ䣬��ȡ����ģ��malloc��free 
typedef struct
{
	int data;
	int pnext;//�α꣬ģ�ⵥ����Ľṹָ�� 
}Space[1000];//ʵ����SPACE�Ǹ����飬���������ģ��Ķ�̬�ռ� 

Space SPACE;

void InitSpace();//�����ռ� 

int MallocSpace();//ģ��malloc���� 

void FreeSpace(int k);//ģ��free���α�Ϊk�Ľ�� 


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


