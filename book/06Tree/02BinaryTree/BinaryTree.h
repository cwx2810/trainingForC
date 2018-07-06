#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct BiTNode//定义二叉树节点 
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode;

typedef struct{      //二叉树节点利用的回溯栈 
	BiTNode **base;
	BiTNode **top;
	int stacksize;
}SqStack;

typedef struct		//定义节点信息，用作求二叉树长度 
{
	BiTNode* left;//节点指针 
	BiTNode* right;
	int order;//节点次序 
}NodeInfo;


int InitStack_Sq(SqStack *S);
int StackEmpty_Sq(SqStack S);
int GetTop_Sq(SqStack S, BiTNode **e);
int Push_Sq(SqStack *S, BiTNode* e);
int Pop_Sq(SqStack *S, BiTNode **e);



int InitBiTree(BiTNode **T);

int ClearBiTree(BiTNode **T);

int DestroyBiTree(BiTNode **T);

int BiTreeEmpty(BiTNode* T);

int CreateBiTree(FILE* fp, BiTNode **T);

//int BiTreeLength(BiTNode* T);

int BiTreeDepth(BiTNode* T);

//int Root(BiTNode* T, char* e);//用e接收根节点 

//char Value(BiTNode* p);//返回节点的值，p为该节点指针 

//int Assign(BiTNode* p, char value);//给节点p赋上value 

char Parent(BiTNode* T, char e);

//char LeftChild(BiTNode* T, char e);

//char RightChild(BiTNode* T, char e);

//char LeftBrother(BiTNode* T, char e);

//char RightBrother(BiTNode* T, char e);

BiTNode* LocateBiTree(BiTNode* T, char e);//获取指向节点e的指针

//int InsertBiTree(BiTNode* T, char e, BiTNode* T0, int LR);//把T0插入到T中的e下面。LR表示T0有左孩子，只能插在右边

//int DeleteBiTree(BiTNode* T, char e, int LR);//删除T中e的子树，LR表示删除右子树

int LevelOrderTraverse(BiTNode* T, void(Visit)(char));

int PreOrderTraverse(BiTNode* T, void(Visit)(char));

int InOrderTraverse(BiTNode* T, void(Visit)(char)); 

int InOrderTraverseNonRecursive1(BiTNode* T, int(Visit)(char));
int InOrderTraverseNonRecursive2(BiTNode* T, int(Visit)(char));

int PostOrderTraverse(BiTNode* T, void(Visit)(char));

//int PrintTree(BiTNode* T);

