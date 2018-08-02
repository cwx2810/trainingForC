#include "HashTable.h"

int InitHash(HashTable* H)
{
	H->length = 0;
	H->sizeindex = -1;
	H->elem = NULL;
}

int CreateHash(HashTable* H, Table T)
{
	InitHash(H);
	RecreateHash(H);
	
	int i;
	while(i<=T.length)//将T中的关键字依次插入到哈希表中 
	{
		int tag = InsertHash(H, T.elem[i].key);
		if(tag==SUCCESS)
			i++;
		else
			i=1;
	}
	return 1;
}

int SearchHash(HashTable H, int key, int* p, int* count)
{ 
	*p = Hash(H, key);
	while(H.elem[*p].key!=NULLKEY && !Equal(key, H.elem[*p].key)) //该位置填有记录并且关键字不相等
	{
		collision(p, ++(*count));//求得下一个探查地址p 
	} 
	if(Equal(key, H.elem[*p].key))//遍历结束，关键字相等，查找成功 
		return 1;
	else
		return 0;
}

int InsertHash(HashTable* H, int key)
{
	int count = 0;
	int* p;
	if(SearchHash(H, key, p, count))
		return DUPILICATE;//重复了，表中已经有key了
	else if(count < hashsize[H.sizeindex]/2)//冲突次数未达到上限，则插入key 
	{
		H.elem[*p].key = key;
		++H.length;
		return 1;
	} 
	else								//达到上限，重建hash表 
	{
		RecreateHash(H);
		return 0;
	}
}


