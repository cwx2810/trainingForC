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
	int balanceFactor;//节点的平衡因子，0代表等高，1代表左子树高，-1代表右子树高 
	struct AVLTNode* lchild;
	struct AVLTNode* rchild;
	
	union
	{
		int leftsize;//代表左子树的节点数+1 
	};//匿名联合体，只在练习题中用 
}AVLTNode;

int CreateAVLTree(AVLTNode* *AVLT, Table T);

AVLTNode* SearchAVLTree(AVLTNode* AVLT, int key);

int InsertAVL(AVLTNode* *AVLT, ElemType e, int* taller);//插入新节点，树长高，置taller为1，初始为0 

int DeleteAVL(AVLTNode* *AVLT, ElemType e, AVLTNode* father, AVLTNode* p, int* taller, int mark);

int RightBalance(AVLTNode* *AVLT);//右平衡处理 

int LeftBalance(AVLTNode* *AVLT);//左平衡处理

int RightRotate(AVLTNode* *p);//右旋

int LeftRotate(AVLTNode* *p);//左旋

int InOrderTraverse_AVL(AVLTNode* AVLT, void(Visit)(ElemType));

int AVLDepth(AVLTNode* AVLT);

int PrintAVLTree(AVLTNode* AVLT); 
