#include "../00SequenceListType/SequenceListType.c"

int Merge(RecordType SR[], RecordType TR[], int start, int mid, int end);
//将有序的两个SR：start~mid和mid+1~end 归并到TR

int MSort(RecordType SR[], RecordType TR[], int start, int end);
//将SR Start~end归并排序为TR start~end

int MergeSort(SqSortList* L); 
