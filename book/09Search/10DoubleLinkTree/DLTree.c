#include "DLTree.h"

int CreateDLTree(FILE* fp, DLTNode** DLT)
{
	*DLT = (DLTNode*)malloc(sizeof(DLTNode));
	if(!(*DLT))
		return 0;
	(*DLT)->kind = Branch;
	(*DLT)->symbol = '\0';
	(*DLT)->next = NULL;
	(*DLT)->Ptr->first = NULL;
	
	KeyType tmp;
	while(Scanf(fp, "%s", &(tmp.ch))==1)
	{
		tmp.length = strlen(tmp.ch);
		InsertDLTree(DLT, tmp);
	}
	return 1;
}

char* SearchDLTree(DLTNode* DLT, KeyType key)
{
	DLTNode* p = DLT->Ptr.first;//��ʼ��pΪ��һ������ 
	int i=0;
	while(p && i<key.length)
	{
		while(p && p->symbol < key.ch[i])
			p = p->next;//���ҹؼ��ֵĵ�iλ 
		
		if(p && p->symbol == key.ch[i])
		{
			p = p->Ptr.first;//����������һλ 
			i++;
		}
		else			//����ʧ�ܣ�����ѭ�� 
			p = NULL;
	}
	
	if(p && p->kind == Leaf)//���ҵ���Ҷ�ӣ�˵�����ҳɹ� 
		return p->Ptr.childptr;
	else					//����ʧ�� 
		return NULL;
}

