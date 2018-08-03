#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

#define ord(ch) ((ch)-'0')
#define succ(x) ((x)+1)

typedef struct
{
	char keys[8];//关键字最多8位
	int next; 
}SLKey;

typedef struct
{
	SLKey space[1000];//最多有1000个关键字参与基数排序 
	int keyNum;//每个关键字位数 
	int length;//链表长度 ，即关键字个数 
}SLList;

int CreateSLList(FILE* fp, SLList* L);

int TraverseSLList(SLList L);

int RadixSort(SLList* L);

int Distribute(SLKey space[], int i, int f[10], int e[10]);

int Collect(SLKey space[], int i, int f[10], int e[10]);
