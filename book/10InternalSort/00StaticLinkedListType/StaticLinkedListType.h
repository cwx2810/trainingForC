#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
	RecordType rc;//记录项 
	int next;//指针项 
}SLNode;

typedef struct
{
	SLNode record[21];//record[0]用作表头结点 
	int length; 
}SLSortList;

int CreateSortList(FILE* fp, SLSortList* L);

int TraverseList(SLSortList L, void(Visit)(int));
