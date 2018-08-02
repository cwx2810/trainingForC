#include "TrieTree.h"

int CreateTrieTree(FILE* fp, TrieNode* *TT)
{
	Record tmp;
	*TT = NULL;
	while(Scanf(fp, "%s", &(tmp.key))==1)
		InsertTrieTree(TT, tmp);
	return 1; 
}

Record* SearchTrieTree(TrieNode* TT, KeyType key)
{
	TrieNode* p;
	int i;
	for(p=TT, i=0; p&&p->kind==Branch&&i<=key.length; p=p->Ptr.branch.ptr[ord(key.ch[i])], i++)
		;
	if(p&&p->kind==Leaf&&cmp(p->Ptr.leaf.key, key))
		return p->Ptr.leaf.childptr;//查找成功 
	else
		return NULL;
}

int ord(char ch)
{
	if(isalpha(ch))//是英文字母 
		return ch-'A'+1;//得到是从A开始的第几个 
	else			//不是英文字母 
		return 0;
}

int cmp(KeyType A, KeyType B)
{
	if(A.length != B.length)//长度不等绝对不一样 
		return 0;
	else
	{
		for(int i=0 i<A.length; i++)//长度相等了，遍历一下，有元素不等也不一样 
		{
			if(A.ch[i] != B.ch[i])
				return 0;
		}
	}
	return 1;
}
