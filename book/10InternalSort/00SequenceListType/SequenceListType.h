#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

#define Left(a,b) ((a)<(b))
#define LeftEqual(a,b) ((a)<=(b))

typedef struct
{
	int key;
}RecordType;

typedef struct
{
	RecordType record[21];//record[0]���û������ڱ���Ԫ
	int length; 
}SqSortList;


int CreateSortList(FILE* fp, SqSortList* L);

int TraverseList(SqSortList L, void(Visit)(int));



