#include "../00SequenceListType/SequenceListType.c"

int Merge(RecordType SR[], RecordType TR[], int start, int mid, int end);
//�����������SR��start~mid��mid+1~end �鲢��TR

int MSort(RecordType SR[], RecordType TR[], int start, int end);
//��SR Start~end�鲢����ΪTR start~end

int MergeSort(SqSortList* L); 
