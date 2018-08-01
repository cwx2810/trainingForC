#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"

#define Equal(a,b) ((a)==(b))
#define Left(a,b) ((a)<(b))
#define Right(a,b) (((a)>(b)))


typedef struct AVLTNode
{
	ElemType data;
	int balanceFactor;//�ڵ��ƽ�����ӣ�0����ȸߣ�1�����������ߣ�-1������������ 
	struct AVLTNode* lchild;
	struct AVLTNode* rchild;
	
	union
	{
		int leftsize;//�����������Ľڵ���+1 
	};//���������壬ֻ����ϰ������ 
}AVLTNode;

int CreateAVLTree(AVLTNode* *AVLT, Table T);

AVLTNode* SearchAVLTree(AVLTNode* AVLT, int key);

int InsertAVL(AVLTNode* *AVLT, ElemType e, int* taller);//�����½ڵ㣬�����ߣ���tallerΪ1����ʼΪ0 

int DeleteAVL(AVLTNode* *AVLT, ElemType e, AVLTNode* father, AVLTNode* p, int* taller, int mark);

int RightBalance(AVLTNode* *AVLT);//��ƽ�⴦�� 

int LeftBalance(AVLTNode* *AVLT);//��ƽ�⴦��

int RightRotate(AVLTNode* *p);//����

int LeftRotate(AVLTNode* *p);//����

int InOrderTraverse_AVL(AVLTNode* AVLT, void(Visit)(ElemType));

int AVLDepth(AVLTNode* AVLT);

int PrintAVLTree(AVLTNode* AVLT); 
