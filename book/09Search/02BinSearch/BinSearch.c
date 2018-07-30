#include "BinSearch.h"

int Search_Bin(Table T, int key)
{
	int low = 1;
	int high = T.length;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(Equal(key, T.elem[mid].key))
			return mid;
		else if(Left(key, T.elem[mid].key))//key���е�С��������߲��� 
			high = mid-1;
		else								//key���е�󣬾����ұ߲��� 
			low = mid+1;
	}
	return 0;
}
