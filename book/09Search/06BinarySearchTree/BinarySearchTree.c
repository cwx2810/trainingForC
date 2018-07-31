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
	if(!BST || Equal(key, BST->data.key))//如果二叉排序树不存在或者找到了key，就返回指针 
		return BST;
	else if(Left(key, BST->data.key))//key比根小，就去左子树找 
		return SearchBST_Ptr(BST->lchild, key);
	else
		return SearchBST_Ptr(BST->rchild, key);//key比根大，就去右子树找 
}

int SearchBST_ForInsert(BSTNode* BST, int key, BSTNode* father, BSTNode* *p)
{
	if(!BST)
	{
		*p = father;//father初始为空
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
	if(SearchBST_ForInsert(*BST, e.key, NULL, &p))//如果找到了相同的，不能插入，因为BST要求所有元素不同 
		return 0;
	else
	{
		bstInsertNode = (BSTNode*)malloc(sizeof(BSTNode));//初始化二叉搜索树节点 
		if(!bstInsertNode)
			return 0;
		bstInsertNode->data = e;//初始化的是指针类型，用-> 
		bstInsertNode->lchild = bstInsertNode->rchild = NULL;
		
		if(!p)
			*BST = bstInsertNode;//原树为空，直接插入单节点
		else if(Left(e.key, p->data.key))//节点比原树节点小，插在左子树 
			p->lchild = bstInsertNode;
		else
			p->rchild = bstInsertNode;//节点比原树节点打，插在右子树 
		
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
	BSTNode* q;//临时指针 
	BSTNode* priorOfP;//p的直接前驱 
	if(!(*p)->rchild)//p只有左子树，直接删 
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if(!(*p)->lchild)//p只有右子树，直接删 
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	} 
	else				//p既有左子树，又有右子树，把p的直接前驱的数值交给p，然后释放该前驱 
	{
		q = *p;
		priorOfP = (*p)->lchild;
		while(priorOfP->rchild)//寻找p的直接前驱 
		{
			q = priorOfP;
			priorOfP = priorOfP->rchild;
		}
		(*p)->data = priorOfP->data;//把p直接前驱的数值交给p，这样p就变成了前驱，就可以删除原来的前驱
		
		if(q!=*p)
			q->rchild = priorOfP->lchild;//直接前驱走到了p的左子树的右子树的尽头
		else
			q->lchild = priorOfP->lchild; //直接前驱就是初始化的值，也就是p的左子树
		free(priorOfP); 
	}
	return 1;
}

int PrintBST(BSTNode* T)
{
	BSTNode a[100][100] = {};//用一个足够大的矩阵存储树 
	
	if(!T)
		return 0;
	else
	{
		int row = BSTDepth(T);//总行数 
		int col = pow(2, row) - 1;//总列数，其实就是一共有几个节点2^h-1
		for(int i=1; i<=row-1; i++)
		{
			for(int j=1; j<=pow(2, i-1); j++)
			{
				int m = (2*j-1)*pow(2, row-i);//当前行节点的相对位序 
				int l = (4*j-3)*pow(2, row-i-1);//下一行节点的相对位序 
				int r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)
					a[i][m] = *T;//初始化 
				
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
					printf(" ");
			}
			printf("\n");
		}
		
		return 1;
	}
}

int BSTDepth(BSTNode* T)
{
	if(!T)
		return 0;
	else
	{
		int LeftDepth = BSTDepth(T->lchild);
		int RightDepth = BSTDepth(T->rchild);
		
		return (LeftDepth > RightDepth ? LeftDepth : RightDepth) + 1;
	}
}

