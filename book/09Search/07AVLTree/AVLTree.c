#include "AVLTree.h"

int CreateAVLTree(AVLTNode **AVLT, Table T)
{
	*AVLT = NULL;
	int taller = 0;
	if(T.length==0)
		return 0;
	else
	{
		for(int i=1; i<=T.length; i++)
			InsertAVL(AVLT, T.elem[i], &taller);
		return 1;
	}
}

AVLTNode* SearchAVLTree(AVLTNode* AVLT, int key)
{
	if(!AVLT || Equal(key, AVLT->data.key))
		return AVLT;
	else if(Left(key, AVLT->data.key))
		return SearchAVLTree(AVLT->lchild, key);
	else
		return SearchAVLTree(AVLT->rchild, key);
}

int InsertAVL(AVLTNode** AVLT, ElemType e, int* taller)
{
	if(!(*AVLT))//�����򴴽��ڵ� 
	{
		*AVLT = (AVLTNode*)malloc(sizeof(AVLTNode));
		if(!(*AVLT))
			return 0;
		(*AVLT)->data = e;
		(*AVLT)->lchild = (*AVLT)->rchild = NULL;
		(*AVLT)->balanceFactor = 0;//ƽ������Ϊ0��ȸ�
		*taller = 1;//������AVLT�������� 
	}
	else		//����������жϣ��ܷ���롢�����ı� 
	{
		if(Equal(e.key, (*AVLT)->data.key))//���ܲ�����ͬ��Ԫ�� 
		{
			*taller = 0;
			return 0;
		}
		else if(Left(e.key, (*AVLT)->data.key))//����Ľڵ�С������뵽������ 
		{
			if(!InsertAVL(&((*AVLT)->lchild), e, taller))//����ʧ�ܣ���ʵҲ���������������ҵ�����ͬԪ�� 
				return 0;
			if(*taller==1)//�ɹ����뵽�����������Ѿ������� 
			{
				switch((*AVLT)->balanceFactor)
				{
					case 1:							//����ǰ�������ߣ��ٲ���͸����ˣ�������ƽ�⣬���ٳ��� 
						LeftBalance(AVLT);
						*taller = 0;
						break;
					case 0:							//����ǰ�ȸߣ�ֱ�ӽ����������ߣ��᳤�� 
						(*AVLT)->balanceFactor = 1;
						*taller = 1;
						break;
					case -1:						//����ǰ�������ߣ�������߾�ƽ���ˣ����᳤�� 
						(*AVLT)->balanceFactor = 0;
						*taller = 0;
						break;
				}
			}
		}
		else				//����Ľڵ�󣬲嵽������ 
		{
			if(!InsertAVL(&((*AVLT)->rchild), e, taller))//����ʧ�ܣ���ʵҲ���������������ҵ�����ͬԪ�� 
				return 0;
			if(*taller==1)//�ɹ����뵽�����������Ѿ������� 
			{
				switch((*AVLT)->balanceFactor)
				{
					case 1:							//����ǰ�������ߣ������ұ߾�ƽ���ˣ����᳤��  
						(*AVLT)->balanceFactor = 0;
						*taller = 0;
						break;
					case 0:							//����ǰ�ȸߣ�ֱ�ӽ����������ߣ��᳤�� 
						(*AVLT)->balanceFactor = -1;
						*taller = 1;
						break;
					case -1:						//����ǰ�������ߣ��ٲ���͸����ˣ�������ƽ�⣬���ٳ��� 
						RightBalance(AVLT);
						*taller = 0;
						break;
				}
			}
		}
	}
	return 1;
}

int DeleteAVL(AVLTNode **AVLT, ElemType e, AVLTNode* father, AVLTNode* p, int* taller, int mark)
{
	return 0;
}

int RightBalance(AVLTNode** AVLT)
{
	AVLTNode* rchild = (*AVLT)->rchild;
	AVLTNode* rlchild;
	switch(rchild->balanceFactor)
	{
		case -1:						//���뵽�Һ��ӵ���������ֱ������ƽ�� 
			(*AVLT)->balanceFactor = rchild->balanceFactor = 0;
			LeftRotate(AVLT);
			break;
		case 1:							//���뵽�Һ��ӵ��������ϣ������������� 
			rlchild = rchild->lchild;
			switch(rlchild->balanceFactor)
			{
				case 1://�Һ��ӵ���������߸� 
					(*AVLT)->balanceFactor = 0;
					rchild->balanceFactor = -1; 
					break;
				case 0://�Һ��ӵ��������ȸ� 
					(*AVLT)->balanceFactor = rchild->balanceFactor = 0;//��ת��ȸ�
					break;
				case -1://�Һ��ӵ��������ұ߸� 
					(*AVLT)->balanceFactor = 1;
					rchild->balanceFactor = 0; 
					break;
			}
			rlchild->balanceFactor = 0;
			RightRotate(&((*AVLT)->rchild));
			LeftRotate(AVLT);
			break;
	}
	return 1;
}

int LeftBalance(AVLTNode** AVLT)
{
	AVLTNode* lchild = (*AVLT)->lchild;
	AVLTNode* lrchild;
	switch(lchild->balanceFactor)
	{
		case 1:						//���뵽���ӵ���������ֱ������ƽ�� 
			(*AVLT)->balanceFactor = lchild->balanceFactor = 0;
			RightRotate(AVLT);
			break;
		case -1:							//���뵽���ӵ��������ϣ������������� 
			lrchild = lchild->rchild;
			switch(lrchild->balanceFactor)
			{
				case 1: 
					(*AVLT)->balanceFactor = -1;
					lchild->balanceFactor = 0; 
					break;
				case 0:
					(*AVLT)->balanceFactor = lchild->balanceFactor = 0;
					break;
				case -1: 
					(*AVLT)->balanceFactor = 0;
					lchild->balanceFactor = 1; 
					break;
			}
			lrchild->balanceFactor = 0;
			LeftRotate(&((*AVLT)->lchild));
			RightRotate(AVLT);
			break;
	}
	return 1;
}

int RightRotate(AVLTNode** p)
{
	AVLTNode* lchild = (*p)->lchild;
	//�ұ��³� 
	(*p)->lchild = lchild->rchild;
	lchild->rchild = *p;
	//���������˱���˸� 
	*p = lchild;
	return 1;
}

int LeftRotate(AVLTNode** p)
{
	AVLTNode* rchild = (*p)->rchild;
	(*p)->rchild = rchild->lchild;
	rchild->lchild = *p;
	*p = rchild;
	return 1;
}

int InOrderTraverse_AVL(AVLTNode* AVLT, void(Visit)(ElemType))
{
	if(!AVLT)
		return 0;
	else
	{
		InOrderTraverse_AVL(AVLT->lchild, Visit);
		Visit(AVLT->data);
		InOrderTraverse_AVL(AVLT->rchild, Visit);
		return 1;
	}
}

int AVLDepth(AVLTNode* AVLT)
{
	if(!AVLT)
		return 0;
	else
	{
		int LeftDepth = AVLDepth(AVLT->lchild);
		int RightDepth = AVLDepth(AVLT->rchild);
		return (LeftDepth > RightDepth ? LeftDepth : RightDepth) + 1;
	}
}

int PrintAVLTree(AVLTNode* AVLT)
{
	AVLTNode a[100][100] = {};//��һ���㹻��ľ���洢�� 
	
	if(!AVLT)
		return 0;
	else
	{
		int row = AVLDepth(AVLT);//������ 
		int col = pow(2, row) - 1;//����������ʵ����һ���м����ڵ�2^h-1
		for(int i=1; i<=row-1; i++)
		{
			for(int j=1; j<=pow(2, i-1); j++)
			{
				int m = (2*j-1)*pow(2, row-i);//��ǰ�нڵ�����λ�� 
				int l = (4*j-3)*pow(2, row-i-1);//��һ�нڵ�����λ�� 
				int r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)
					a[i][m] = *AVLT;//��ʼ�� 
				
				if(a[i][m].lchild)
					a[i+1][l] = *(a[i][m].lchild);//��һ�� 
				
				if(a[i][m].rchild)
					a[i+1][r] = *(a[i][m].rchild);//��һ�� 
			}
		} 
		
		for(int i=1; i<=row; i++)
		{
			for(int j=1; j<=col; j++)
			{
				if(a[i][j].data.key)
					printf("%2d", a[i][j].data.key);
				else
					printf("  ");
			}
			printf("\n");
		}
		
		return 1;
	}
}
