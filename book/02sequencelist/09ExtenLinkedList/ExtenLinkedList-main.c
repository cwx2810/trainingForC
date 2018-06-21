#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct ENode
{
	int data;
	ENode* next;
	ENode* head,tail;
	int length;
}Enode;

int MallocNodeE(ENode* p, int e);

int FreeNode(ENode* p);

int InitList_EL(ENode **L);

int ClearList_EL(ENode* L);

int DestroyList_EL(ENode **L);

int ListEmpty(ENode* L);


