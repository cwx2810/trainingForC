#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"

#define Equal(a,b) ((a)==(b))
#define Left(a,b) ((a)<(b))

typedef struct BSTNode
{
	ElemType data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
	
	union
	{
		int RTag;//线索标志，在练习题中有用 
	};
}BSTNode;

int CreateBSTree(BSTNode* *BST, Table T);

BSTNode* SearchBST_Ptr(BSTNode* BST, int key);//查找返回指向key的指针

int SearchBST_ForInsert(BSTNode* BST, int key, BSTNode* father, BSTNode* *p);
//查找key是否存在，father指向BST的双亲，p为找到的节点的指针，或者找不到时指向父节点以便插入 

int InsertBSTree(BSTNode* *BST, ElemType e);//结合上面的查找，如果key不存在则插入 

int InOrderTraverse_BST(BSTNode* BST, void(Visit)(ElemType));

int DeleteBST_Key(BSTNode* *BST, int key);//删除key 
int DeleteBST_Ptr(BSTNode* *p);//删除的核心函数，删除p指向的节点 

int PrintBST(BSTNode* T);
int BSTDepth(BSTNode* T);
