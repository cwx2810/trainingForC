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
}ExNode;//存放待归并记录

int K_Merge(FILE* fp_out, int ls[5], ExNode exNode[6]);
//利用败者树将输入的k个归并段归并到输出归并段

int Adjust(int ls[5], ExNode exNode[6], int p);
//从eXnode[p]出发调整败者树

int CreateLoserTree(int ls[5], ExNode exNode[6]);
//依次从exNode[k-1 ~ 0]出发调整ls为败者树

int input(FILE* fp[5], int x[], int i);
//从文件fp[i]中读取关键字到x[]

int output(FILE* fp, int x);
//将x输出到有序表fp

int RandomNum(FILE* fp);//生成随机数到fp 

int CutSort(FILE* fp);//将随机数表fp分段排序后分别写入 
 



