#include "../00SequenceListType/SequenceListType.c"

int t = 3;//增量序列容量，就是要进行t趟希尔排序，每趟的增量不同 
int dlta[] = {5, 3, 1}; 

int ShellInsert(SqSortList* L, int dk);//一趟希尔插入排序 

int ShellSort(SqSortList* L, int dlta[], int t);//按增量序列进行希尔插入排序 
