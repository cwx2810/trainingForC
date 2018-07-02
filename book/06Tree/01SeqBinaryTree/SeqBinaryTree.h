#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef char SqBiTree[100];//定义二叉树 

typedef struct
{
	int level;//节点所在层数 
	int order;//节点所在本层序号，按完全二叉树计算 
}Position;		//节点位置信息结构体 

int InitBiTree_Sq(SqBiTree T);

int ClearBiTree_Sq(SqBiTree T);

int DestroyBiTree_Sq(SqBiTree T);

int BiTreeEmpty_Sq(SqBiTree T);

int CreateBiTree_Level(FILE *fp, SqBiTree T);//层序序列构造二叉树 

int CreateBiTree_Pre(FILE *fp, SqBiTree T, int i);//先序序列构造二叉树 

int BiTreeLength_Sq(SqBiTree T);//完全二叉树长度，就是非空节点数 

int BiTreeDepth_Sq(SqBiTree T);

int Root_Sq(SqBiTree T, char *e);//找到根节点用e接收 

char Value_Sq(SqBiTree T, Position s);//找到位置s的节点的值 

int Assign_Sq(SqBiTree T, Position s, char value);//给位置s的节点赋值value 

char Parent_Sq(SqBiTree T, char e);//找到e的爸爸 

char LeftChild_Sq(SqBiTree T, char e);

char RightChild_Sq(SqBiTree T, char e);

char LeftBrother_Sq(SqBiTree T, char e);

char RightBrother_Sq(SqBiTree T, char e);

int LevelOrderTraverse_Sq(SqBiTree T, void(Visit)(char));//层序遍历 

int PreOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int InOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int PostOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int Print_Sq(SqBiTree T);
