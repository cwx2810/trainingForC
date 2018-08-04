#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
}RecordType;//记录类型 

typedef struct
{
	RecordType rec;//记录 
	int key;//从记录中抽取的关键字 
	int num;//所属归并段的段号 
}RecordNode;//内存工作区 

int originalpart;//段个数 
int maxNumber;//wa所属段最大段号 
int currentNumber;//当前段号 

int Replace_Selection(FILE* fp_in, int ls[6], RecordNode wa[6]);
//在败者树ls和内存工作区wa上用置换选择排序求初始归并段

int get_run(FILE* fp_in, FILE* fp_out, int ls[6], RecordNode wa[6]);
//求得一个初始归并段

int Select_MiniMax(int ls[6], RecordNode wa[6], int p);
//从wa[p]开始到败者树的根比较选择记录，由p指向它

int Construct_Loser(FILE* fp_in, int ls[6], RecordNode wa[6]);
//输入记录到内存工作区wa，建立败者树ls，选出最小记录并由p指示其在wa中的位置 
