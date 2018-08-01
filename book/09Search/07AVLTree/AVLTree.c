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
	if(!(*AVLT))//空树则创建节点 
	{
		*AVLT = (AVLTNode*)malloc(sizeof(AVLTNode));
		if(!(*AVLT))
			return 0;
		(*AVLT)->data = e;
		(*AVLT)->lchild = (*AVLT)->rchild = NULL;
		(*AVLT)->balanceFactor = 0;//平衡因子为0则等高
		*taller = 1;//创建了AVLT，长高了 
	}
	else		//不空则进行判断，能否插入、插入哪边 
	{
		if(Equal(e.key, (*AVLT)->data.key))//不能插入相同的元素 
		{
			*taller = 0;
			return 0;
		}
		else if(Left(e.key, (*AVLT)->data.key))//插入的节点小，则插入到左子树 
		{
			if(!InsertAVL(&((*AVLT)->lchild), e, taller))//插入失败，其实也就是又在左子树找到了相同元素 
				return 0;
			if(*taller==1)//成功插入到左子树，树已经长高了 
			{
				switch((*AVLT)->balanceFactor)
				{
					case 1:							//插入前左子树高，再插入就更高了，需做左平衡，不再长高 
						LeftBalance(AVLT);
						*taller = 0;
						break;
					case 0:							//插入前等高，直接将左子树增高，会长高 
						(*AVLT)->balanceFactor = 1;
						*taller = 1;
						break;
					case -1:						//插入前右子树高，插入左边就平衡了，不会长高 
						(*AVLT)->balanceFactor = 0;
						*taller = 0;
						break;
				}
			}
		}
		else				//插入的节点大，插到右子树 
		{
			if(!InsertAVL(&((*AVLT)->rchild), e, taller))//插入失败，其实也就是又在右子树找到了相同元素 
				return 0;
			if(*taller==1)//成功插入到右子树，树已经长高了 
			{
				switch((*AVLT)->balanceFactor)
				{
					case 1:							//插入前左子树高，插入右边就平衡了，不会长高  
						(*AVLT)->balanceFactor = 0;
						*taller = 0;
						break;
					case 0:							//插入前等高，直接将右子树增高，会长高 
						(*AVLT)->balanceFactor = -1;
						*taller = 1;
						break;
					case -1:						//插入前右子树高，再插入就更高了，需做右平衡，不再长高 
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
		case -1:						//插入到右孩子的右子树，直接左旋平衡 
			(*AVLT)->balanceFactor = rchild->balanceFactor = 0;
			LeftRotate(AVLT);
			break;
		case 1:							//插入到右孩子的左子树上，先右旋再左旋 
			rlchild = rchild->lchild;
			switch(rlchild->balanceFactor)
			{
				case 1://右孩子的左子树左边高 
					(*AVLT)->balanceFactor = 0;
					rchild->balanceFactor = -1; 
					break;
				case 0://右孩子的左子树等高 
					(*AVLT)->balanceFactor = rchild->balanceFactor = 0;//旋转完等高
					break;
				case -1://右孩子的左子树右边高 
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
		case 1:						//插入到左孩子的左子树，直接左旋平衡 
			(*AVLT)->balanceFactor = lchild->balanceFactor = 0;
			RightRotate(AVLT);
			break;
		case -1:							//插入到左孩子的右子树上，先左旋再右旋 
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
	//右边下沉 
	(*p)->lchild = lchild->rchild;
	lchild->rchild = *p;
	//左孩子上来了变成了根 
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
	AVLTNode a[100][100] = {};//用一个足够大的矩阵存储树 
	
	if(!AVLT)
		return 0;
	else
	{
		int row = AVLDepth(AVLT);//总行数 
		int col = pow(2, row) - 1;//总列数，其实就是一共有几个节点2^h-1
		for(int i=1; i<=row-1; i++)
		{
			for(int j=1; j<=pow(2, i-1); j++)
			{
				int m = (2*j-1)*pow(2, row-i);//当前行节点的相对位序 
				int l = (4*j-3)*pow(2, row-i-1);//下一行节点的相对位序 
				int r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)
					a[i][m] = *AVLT;//初始化 
				
				if(a[i][m].lchild)
					a[i+1][l] = *(a[i][m].lchild);//下一行 
				
				if(a[i][m].rchild)
					a[i+1][r] = *(a[i][m].rchild);//下一行 
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
