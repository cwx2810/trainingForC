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
//������С�ṹ���͵�ָ��*L��������*L�͵ȼ���ȡ��С�ṹ���ָ�뱾�壬ʹ�ó�Ա��-> 
//�Ա�SqList *L��������SqList���͵�ָ�룬������*L�ȼ���ȡ��SqList���壬ʹ�ó�Ա��.  

int ClearList_L(LNode* L);//����˫������Ϊ��պ�ͷ��㻹�ڣ����ı�С�ṹ 

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


