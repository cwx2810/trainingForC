#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

#define ord(ch) ((ch)-'0')
#define succ(x) ((x)+1)

typedef struct
{
	char keys[8];//�ؼ������8λ
	int next; 
}SLKey;

typedef struct
{
	SLKey space[1000];//�����1000���ؼ��ֲ���������� 
	int keyNum;//ÿ���ؼ���λ�� 
	int length;//������ �����ؼ��ָ��� 
}SLList;

int CreateSLList(FILE* fp, SLList* L);

int TraverseSLList(SLList L);

int RadixSort(SLList* L);

int Distribute(SLKey space[], int i, int f[10], int e[10]);

int Collect(SLKey space[], int i, int f[10], int e[10]);
