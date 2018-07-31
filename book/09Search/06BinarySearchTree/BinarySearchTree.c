#include "BinarySearchTree.h"

int CreateBSTree(BSTNode** BST, Table T)
{
	*BST = NULL;
	if(T.length==0)
		return 0;
	else
	{
		for(int i=1; i<=T.length; i++)
			InsertBSTree(BST, T.elem[i]);
		return 1;
	}
}

BSTNode* SearchBST_Ptr(BSTNode* BST, int key)
{
	if(!BST || Equal(key, BST->data.key))//������������������ڻ����ҵ���key���ͷ���ָ�� 
		return BST;
	else if(Left(key, BST->data.key))//key�ȸ�С����ȥ�������� 
		return SearchBST_Ptr(BST->lchild, key);
	else
		return SearchBST_Ptr(BST->rchild, key);//key�ȸ��󣬾�ȥ�������� 
}

int SearchBST_ForInsert(BSTNode* BST, int key, BSTNode* father, BSTNode* *p)
{
	if(!BST)
	{
		*p = father;//father��ʼΪ��
		return 0; 
	}
	else if(Equal(key, BST->data.key))
	{
		*p = BST;
		return 1;
	}
	else if(Left(key, BST->data.key))
		return SearchBST_ForInsert(BST->lchild, key, BST, p);
	else
		return SearchBST_ForInsert(BST->rchild, key, BST, p);
}

int InsertBSTree(BSTNode** BST, ElemType e)
{
	BSTNode* p;
	BSTNode* bstInsertNode;
	if(SearchBST_ForInsert(*BST, e.key, NULL, &p))//����ҵ�����ͬ�ģ����ܲ��룬��ΪBSTҪ������Ԫ�ز�ͬ 
		return 0;
	else
	{
		bstInsertNode = (BSTNode*)malloc(sizeof(BSTNode));//��ʼ�������������ڵ� 
		if(!bstInsertNode)
			return 0;
		bstInsertNode->data = e;//��ʼ������ָ�����ͣ���-> 
		bstInsertNode->lchild = bstInsertNode->rchild = NULL;
		
		if(!p)
			*BST = bstInsertNode;//ԭ��Ϊ�գ�ֱ�Ӳ��뵥�ڵ�
		else if(Left(e.key, p->data.key))//�ڵ��ԭ���ڵ�С������������ 
			p->lchild = bstInsertNode;
		else
			p->rchild = bstInsertNode;//�ڵ��ԭ���ڵ�򣬲��������� 
		
		return 1; 
	}
}

int InOrderTraverse_BST(BSTNode* BST, void(Visit)(ElemType))
{
	if(!BST)
		return 0;
	else
	{
		InOrderTraverse_BST(BST->lchild, Visit);
		Visit(BST->data);
		InOrderTraverse_BST(BST->rchild, Visit);
		return 1;
	}
}

int DeleteBST_Key(BSTNode** BST, int key)
{
	if(!(*BST))
		return 0;
	else
	{
		if(Equal(key, (*BST)->data.key))
			return DeleteBST_Ptr(BST);
		else if(Left(key, (*BST)->data.key))
			return DeleteBST_Key(&((*BST)->lchild), key);
		else
			return DeleteBST_Key(&((*BST)->rchild), key);
		return 1;
	}
}

int DeleteBST_Ptr(BSTNode** p)
{
	BSTNode* q;//��ʱָ�� 
	BSTNode* priorOfP;//p��ֱ��ǰ�� 
	if(!(*p)->rchild)//pֻ����������ֱ��ɾ 
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if(!(*p)->lchild)//pֻ����������ֱ��ɾ 
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	} 
	else				//p��������������������������p��ֱ��ǰ������ֵ����p��Ȼ���ͷŸ�ǰ�� 
	{
		q = *p;
		priorOfP = (*p)->lchild;
		while(priorOfP->rchild)//Ѱ��p��ֱ��ǰ�� 
		{
			q = priorOfP;
			priorOfP = priorOfP->rchild;
		}
		(*p)->data = priorOfP->data;//��pֱ��ǰ������ֵ����p������p�ͱ����ǰ�����Ϳ���ɾ��ԭ����ǰ��
		
		if(q!=*p)
			q->rchild = priorOfP->lchild;//ֱ��ǰ���ߵ���p�����������������ľ�ͷ
		else
			q->lchild = priorOfP->lchild; //ֱ��ǰ�����ǳ�ʼ����ֵ��Ҳ����p��������
		free(priorOfP); 
	}
	return 1;
}

