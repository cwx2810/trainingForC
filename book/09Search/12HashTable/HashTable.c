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
	while(i<=T.length)//��T�еĹؼ������β��뵽��ϣ���� 
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
	while(H.elem[*p].key!=NULLKEY && !Equal(key, H.elem[*p].key)) //��λ�����м�¼���ҹؼ��ֲ����
	{
		collision(p, ++(*count));//�����һ��̽���ַp 
	} 
	if(Equal(key, H.elem[*p].key))//�����������ؼ�����ȣ����ҳɹ� 
		return 1;
	else
		return 0;
}

int InsertHash(HashTable* H, int key)
{
	int count = 0;
	int* p;
	if(SearchHash(H, key, p, count))
		return DUPILICATE;//�ظ��ˣ������Ѿ���key��
	else if(count < hashsize[H.sizeindex]/2)//��ͻ����δ�ﵽ���ޣ������key 
	{
		H.elem[*p].key = key;
		++H.length;
		return 1;
	} 
	else								//�ﵽ���ޣ��ؽ�hash�� 
	{
		RecreateHash(H);
		return 0;
	}
}


