#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../10InternalSort/10MergingSort/MergingSort.c"

typedef struct
{
	int key;
}ExNode;//��Ŵ��鲢��¼

int K_Merge(FILE* fp_out, int ls[5], ExNode exNode[6]);
//���ð������������k���鲢�ι鲢������鲢��

int Adjust(int ls[5], ExNode exNode[6], int p);
//��eXnode[p]��������������

int CreateLoserTree(int ls[5], ExNode exNode[6]);
//���δ�exNode[k-1 ~ 0]��������lsΪ������

int input(FILE* fp[5], int x[], int i);
//���ļ�fp[i]�ж�ȡ�ؼ��ֵ�x[]

int output(FILE* fp, int x);
//��x����������fp

int RandomNum(FILE* fp);//�����������fp 

int CutSort(FILE* fp);//���������fp�ֶ������ֱ�д�� 
 



