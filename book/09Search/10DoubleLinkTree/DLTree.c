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
	DLTNode* p = DLT->Ptr.first;//初始化p为第一个孩子 
	int i=0;
	while(p && i<key.length)
	{
		while(p && p->symbol < key.ch[i])
			p = p->next;//查找关键字的第i位 
		
		if(p && p->symbol == key.ch[i])
		{
			p = p->Ptr.first;//继续查找下一位 
			i++;
		}
		else			//查找失败，跳出循环 
			p = NULL;
	}
	
	if(p && p->kind == Leaf)//查找到了叶子，说明查找成功 
		return p->Ptr.childptr;
	else					//查找失败 
		return NULL;
}

