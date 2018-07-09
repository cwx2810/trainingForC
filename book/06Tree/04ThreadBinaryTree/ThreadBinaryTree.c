#include "ThreadBinaryTree.h"

int CreateBiTree_Tri(FILE *fp, TriBiNode **T)
{
	char ch;
	Scanf(fp, "%c", &ch);
	if(ch=='^')
		*T = NULL;
	else
	{
		*T = (TriBiNode*)malloc(sizeof(TriBiNode));
		if(!(*T))
			return 0;
		(*T)->data = ch;
		
		CreateBiTree_Tri(fp, &((*T)->lchild));//先递归构造左子树
		if((*T)->lchild)//递归不下去从最底下返回的每一层设置左右标志，但不线索化 
			(*T)->LTag = Link;
		else
			(*T)->LTag = Thread; 
			
		CreateBiTree_Tri(fp, &((*T)->rchild));
		if((*T)->rchild)
			(*T)->RTag = Link;
		else
			(*T)->RTag = Thread;
	}
	return 1;
}

void InThreading_Tri(TriBiNode* p)
{
	if(p)
	{
		InThreading_Tri(p->lchild);//递归线索化左子树，实际是从最左下角开始线索化
		
		if(!p->lchild)//为当前节点建立前驱线索，此时的p在前锋探索，pre在后卫，也就是p指向之前走过的老路 
		{
			p->LTag = Thread;
			p->lchild = pre;
		} 
		
		if(!pre->rchild)//为上一个节点建立后继线索，此时是已经回溯了一层了，pre在前锋，p在后卫走新路，也就是pre指向后继的新路 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;//pre前进一步 
		
		InThreading_Tri(p->rchild);//递归线索化右子树，回溯到从根节点左子树的某个不为NULL的右子树开始 
	}
}

int InOrderThreading_Tri(TriBiNode **T, TriBiNode* P)//头结点后继回指，建立双向连接 
{
	//处理头结点 
	*T = (TriBiNode*)malloc(sizeof(TriBiNode));
	if(!(*T))
		return 0;
	(*T)->data = '\0';
	(*T)->LTag = Link;
	(*T)->RTag = Thread;
	(*T)->rchild = *T;
	
	//线索化 
	if(!P)
		(*T)->lchild = *T;
	else
	{
		(*T)->lchild = P;
		pre = *T;//初始化pre为空的头结点 
		
		InThreading_Tri(P);//线索化
		
		pre->rchild = *T;//最后一个节点指向空头结点 
		pre->RTag = Thread;//设置为线索 
		(*T)->rchild = pre; //头结点指回最后一个节点，双向联系 
	}
	return 1;
}

int InOrderTraverse_Tri(TriBiNode* T, void(Visit)(char))
{
	TriBiNode* p = T->lchild;//T是空的根节点，p指向二叉树真正的根节点
	while(p!=T)//p==T说明是空二叉树 
	{
		while(p->LTag==Link)//找到最左下节点 
			p = p->lchild;
		
		Visit(p->data);
		
		while(p->RTag==Thread && p->rchild!=T)//利用线索二叉树的优势直接访问后继，当然这个后继不能是头结点，不然就到头了 
		{
			p = p->rchild;
			Visit(p->data);
		}
		
		p = p->rchild;//当破坏条件一，直接有后继，走就行了；破坏条件二，会走到空的根节点，跳出循环 
	} 
	return 1;
}
