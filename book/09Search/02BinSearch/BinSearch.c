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
		else if(Left(key, T.elem[mid].key))//key比中点小，就在左边查找 
			high = mid-1;
		else								//key比中点大，就在右边查找 
			low = mid+1;
	}
	return 0;
}
