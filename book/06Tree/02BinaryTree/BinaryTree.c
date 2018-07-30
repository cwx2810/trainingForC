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
	
	*((*S).top) = e;//Ϊʲô��ջ�ȸ�ֵ����ͼ��top�������һ��Ԫ�ص�β����Ҳ�����¸�Ԫ�ص�ͷ�� 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, BiTNode **e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//Ϊʲô�ȵݼ�ָ�룬��ͼ������ȸ�ֵ�ˣ���top��ʱ��û�������ˣ��ǿյ�β�� 
	*e = *((*S).top);
	return 1;
}

int InitBiTree(BiTNode **T)
{
	*T = NULL;//������ȡ��������С�ṹ���� 
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
	//�������޷����٣��������վ��Ǵ�����������٣����ڵ�����ǰѶ����������нڵ㶼freeȴ���ÿ� 
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
	if(!T || (T && T->data==e))//T�����ڻ���T���ڵ��Ǹ��ڵ㣬�򲻴��ڸ��ڵ� 
		return '\0';
		
	BiTNode node[100];//��ʼ��100���������ڵ�
	int i = 0;
	node[i] = *T;//��ʼ����һ���������ڵ�Ϊ���ڵ�
	while(i>=0)
	{
		while(node[i].lchild)//�����Ӳ��ϱ���Ѱ�� 
		{
			if(node[i].lchild->data==e)//�ҵ��� 
				return node[i].data;
			node[i+1] = *(node[i].lchild);//������̽Ѱս������
			node[i].lchild = NULL;//��ʾ��·�Ѿ��߹����´β�������
			i++; 
		}
		if(node[i].rchild)//���Һ���Ѱ�� 
		{
			if(node[i].rchild->data==e)
				return node[i].data;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		if(node[i].lchild==NULL && node[i].rchild==NULL)//���ߵ�����£����� 
			i--;
	} 
	if(i<0)//���ݷ����Ҳ���e 
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
	int i=0;//i��Ϊ�����±꣬ÿ������ʱ������������һ�η��ʵ��±� 
	int j=0;//j��Ϊ�����±꣬ÿ������ʱ������һ��������±�
	BiTNode* p[100];//������ģ����У�����ÿ��Ҫ���ʵĶ������ڵ�
	if(T)//���ڵ���ڣ����ʼ������0��λΪ���ڵ� 
	{
		p[j] = T;
		j++;
	}
	while(i<j)//�α�iʼ����С��j�� 
	{
		Visit(p[i]->data);
		if(p[i]->lchild)//������ʹ���i�ĺ��Ӵ��ڣ����ú������ 
		{
			p[j] = p[i]->lchild;
			j++;
		}
		if(p[i]->rchild)
		{
			p[j] = p[i]->rchild;
			j++;
		}
		i++; //׼�����ʶ�������һ��Ԫ�� 
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
	Push_Sq(&S, T);//���������ڵ���ջ 
	BiTNode* p;//��ʱ����ջ��Ԫ��  
	while(!StackEmpty_Sq(S))
	{
		while(GetTop_Sq(S, &p) && p)
			Push_Sq(&S, p->lchild);//ֻҪû���ߵ��գ���һֱ����������ջ�ߵ�ͷ�����������ʵľ��������
		Pop_Sq(&S, &p);//���һ��push�������ǿգ�Ҫ����
		if(!StackEmpty_Sq(S))
		{
			Pop_Sq(&S, &p);//����ջ�� 
			if(!Visit(p->data))//����visit�����жϣ������˾�������������ͷ���0 
				return 0;
			Push_Sq(&S, p->rchild);//����һ����֮�������� 
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
	BiTNode* p = T;//pָ����������ڵ� 
	while(p || !StackEmpty_Sq(S))
	{
		if(p)//һֱ�����ߣ���ջ 
		{
			Push_Sq(&S, p);
			p = p->lchild;
		}
		else
		{
			Pop_Sq(&S, &p);//�������� 
			if(!Visit(p->data))
				return 0;
			p = p->rchild;//����һ�� 
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

int PrintTree(BiTNode* T)
{
	BiTNode a[100][100] = {};//��һ���㹻��ľ���洢�� 
	
	if(!T)
		return 0;
	else
	{
		int row = BiTreeDepth(T);//������ 
		int col = pow(2, row) - 1;//����������ʵ����һ���м����ڵ�2^h-1
		for(int i=1; i<=row-1; i++)
		{
			for(int j=1; j<=pow(2, i-1); j++)
			{
				int m = (2*j-1)*pow(2, row-i);//��ǰ�нڵ�����λ�� 
				int l = (4*j-3)*pow(2, row-i-1);//��һ�нڵ�����λ�� 
				int r = (4*j-1)*pow(2, row-i-1);
				
				if(i==1)
					a[i][m] = *T;//��ʼ�� 
				
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
				if(a[i][j].data)
					printf("%c", a[i][j].data);
				else
					printf(" ");
			}
			printf("\n");
		}
		
		return 1;
	}
}


