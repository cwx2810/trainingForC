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
		return p->Ptr.leaf.childptr;//���ҳɹ� 
	else
		return NULL;
}

int ord(char ch)
{
	if(isalpha(ch))//��Ӣ����ĸ 
		return ch-'A'+1;//�õ��Ǵ�A��ʼ�ĵڼ��� 
	else			//����Ӣ����ĸ 
		return 0;
}

int cmp(KeyType A, KeyType B)
{
	if(A.length != B.length)//���Ȳ��Ⱦ��Բ�һ�� 
		return 0;
	else
	{
		for(int i=0 i<A.length; i++)//��������ˣ�����һ�£���Ԫ�ز���Ҳ��һ�� 
		{
			if(A.ch[i] != B.ch[i])
				return 0;
		}
	}
	return 1;
}
