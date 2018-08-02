#include "../00SequenceListType/SequenceListType.c"

int Partition(SqSortList* L, int low, int high);//巧妙借助哨兵的分治，还有一种不借助的，会多设一个变量 

int QuickSort(SqSortList* L);
int QSort(SqSortList* L, int low, int high);//快排核心算法 
