#include "BinaryTree.h"

int InitStack_Sq(SqStack *S)
{
	(*S).base = (BiTNode**)malloc(100*sizeof(BiTNode));
	if(!(*S).base)
		return 0;
	(*S).top = (*S).base;
	(*S).stacksize = 100;
	
	return 1;
}

int StackEmpty_Sq(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

int GetTop_Sq(SqStack S, BiTNode **e)
{
	if(S.base==S.top)
		return 0;
	*e = *(S.top-1);
	return 1;
}

int Push_Sq(SqStack *S, BiTNode* e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base = (BiTNode**)realloc((*S).base, ((*S).stacksize+10)*sizeof(BiTNode));
		if(!(*S).base)
			return 0;
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += 10;
	}
	
	*((*S).top) = e;//为什么进栈先赋值，想图，top是在最后一个元素的尾部，也就是下个元素的头部 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, BiTNode **e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//为什么先递减指针，想图，如果先赋值了，那top此时就没有意义了，是空的尾部 
	*e = *((*S).top);
	return 1;
}

int InitBiTree(BiTNode **T)
{
	*T = NULL;//体内是取到二叉树小结构本体 
}

int ClearBiTree(BiTNode **T)
{
	if(!(*T))
		return 0;
	else
	{
		if((*T)->lchild)
			ClearBiTree(&((*T)->lchild));
		if((*T)->rchild)
			ClearBiTree(&((*T)->rchild));
		free(*T);
		*T = NULL;
		return 1;
	}
}

int DestroyBiTree(BiTNode **T)
{
	//二叉树无法销毁，上面的清空就是大众意义的销毁，大众的清空是把二叉树都所有节点都free却不置空 
}

int BiTreeEmpty(BiTNode* T)
{
	return T==NULL? 1 : 0;
}

int CreateBiTree(FILE *fp, BiTNode **T)
{
	char ch;
	Scanf(fp, "%c", &ch);
	if(ch=='^')
		*T = NULL;
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		if(!(*T))
			return 0;
		(*T)->data = ch;
		CreateBiTree(fp, &(*T)->lchild);
		CreateBiTree(fp, &(*T)->rchild);
	}
	return 1;
}

int BiTreeDepth(BiTNode* T)
{
	if(!T)
		return 0;
	else
	{
		int LeftDepth = BiTreeDepth(T->lchild);
		int RightDepth = BiTreeDepth(T->rchild);
		
		return (LeftDepth >= RightDepth ? LeftDepth : RightDepth) + 1;
	}
}

char Parent(BiTNode* T, char e)
{
	if(!T || (T && T->data==e))//T不存在或者T存在但是根节点，则不存在父节点 
		return '\0';
		
	BiTNode node[100];//初始化100个二叉树节点
	int i = 0;
	node[i] = *T;//初始化第一个二叉树节点为根节点
	while(i>=0)
	{
		while(node[i].lchild)//向左孩子不断遍历寻找 
		{
			if(node[i].lchild->data==e)//找到了 
				return node[i].data;
			node[i+1] = *(node[i].lchild);//向左孩子探寻战争迷雾
			node[i].lchild = NULL;//表示此路已经走过，下次不用再走
			i++; 
		}
		if(node[i].rchild)//向右孩子寻找 
		{
			if(node[i].rchild->data==e)
				return node[i].data;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		if(node[i].lchild==NULL && node[i].rchild==NULL)//当走到最底下，回溯 
			i--;
	} 
	if(i<0)//回溯发现找不到e 
		return '\0';
}

BiTNode* LocateBiTree(BiTNode* T, char e)
{
	BiTNode* p = NULL;
	if(T)
	{
		if(T->data==e)
			p = T;
		else
		{
			if(p=LocateBiTree(T->lchild, e))
				return p;
			if(p=LocateBiTree(T->rchild, e))
				return p;
		}
	}
	return p;
}

int LevelOrderTraverse(BiTNode* T, void(Visit)(char))
{
	if(!T)
		return 0;
	int i=0;//i作为访问下标，每次自增时跳到队列中下一次访问的下标 
	int j=0;//j作为填入下标，每次自增时跳到下一次填入的下标
	BiTNode* p[100];//用数组模拟队列，放入每次要访问的二叉树节点
	if(T)//根节点存在，则初始化队列0号位为根节点 
	{
		p[j] = T;
		j++;
	}
	while(i<j)//游标i始终是小于j的 
	{
		Visit(p[i]->data);
		if(p[i]->lchild)//如果访问过的i的孩子存在，就让孩子入队 
		{
			p[j] = p[i]->lchild;
			j++;
		}
		if(p[i]->rchild)
		{
			p[j] = p[i]->rchild;
			j++;
		}
		i++; //准备访问队列中下一个元素 
	} 
	return 1;
}

int PreOrderTraverse(BiTNode* T, void(Visit)(char))
{
	if(!T)
		return 0;
	else
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
		return 1;
	}
}

int InOrderTraverse(BiTNode* T, void(Visit)(char))
{
	if(!T)
		return 0;
	else
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
		return 1;
	}
}

int InOrderTraverseNonRecursive1(BiTNode* T, int(Visit)(char))
{
	if(!T)
		return 0;
	SqStack S;
	InitStack_Sq(&S);
	Push_Sq(&S, T);//二叉树根节点入栈 
	BiTNode* p;//临时保存栈顶元素  
	while(!StackEmpty_Sq(S))
	{
		while(GetTop_Sq(S, &p) && p)
			Push_Sq(&S, p->lchild);//只要没有走到空，就一直向左依次入栈走到头，反过来访问的就是左和中
		Pop_Sq(&S, &p);//最后一次push的左孩子是空，要弹出
		if(!StackEmpty_Sq(S))
		{
			Pop_Sq(&S, &p);//弹出栈顶 
			if(!Visit(p->data))//进入visit函数判断，读到了就输出，读不到就返回0 
				return 0;
			Push_Sq(&S, p->rchild);//向右一步，之后再向左 
		} 
	}
	return 1;
}

int InOrderTraverseNonRecursive2(BiTNode* T, int(Visit)(char))
{
	if(!T)
		return 0;
	SqStack S;
	InitStack_Sq(&S);
	BiTNode* p = T;//p指向二叉树根节点 
	while(p || !StackEmpty_Sq(S))
	{
		if(p)//一直向左走，入栈 
		{
			Push_Sq(&S, p);
			p = p->lchild;
		}
		else
		{
			Pop_Sq(&S, &p);//弹出访问 
			if(!Visit(p->data))
				return 0;
			p = p->rchild;//向右一步 
		}
	}
	return 1;
}

int PostOrderTraverse(BiTNode* T, void(Visit)(char))
{
	if(!T)
		return 0;
	else
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
		return 1;
	}
}


