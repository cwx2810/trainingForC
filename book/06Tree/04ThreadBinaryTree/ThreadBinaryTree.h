#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum
{
	Link,Thread
}PointerTag;

typedef struct TriBiNode
{
	char data;
	struct TriBiNode* lchild;
	struct TriBiNode* rchild;
	PointerTag LTag;
	PointerTag RTag;
	
	struct TriBiNode* parent;//双亲节点指针，一般不同，仅非递归后序遍历后继线索二叉树中用，后继线索二叉树就是只有后继线索 
}TriBiNode;

TriBiNode* pre;//全局变量，指向当前小节点的上一个节点


//工具函数 
int CreateBiTree_Tri(FILE* fp, TriBiNode **T);//先序构造二叉树，无线索 
//void CreateParentPtr(TriBiNode* T);//层序二叉树，建立小结构中的parent指针指向爸爸
//TriBiNode* PostNextPtr(TriBiNode* T, TriBiNode* p);//在T中寻找节点p的后继 
 

//算法函数 
void InThreading_Tri(TriBiNode* p);//中序全线索化，利用游标p，是下一个函数的工具函数      极度烧脑，基本靠画图看懂 

int InOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//中序遍历二叉树P，顺便同时将其全线索化为T 

int InOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//非递归中序遍历 全线索二叉树 


//void PreThreading_Tri(TriBiNode* T);//先序后继线索化，就是按照先序的顺序只设置节点的后继线索

//int PreOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//先序遍历二叉树P，顺便将其后继线索化

//int PreOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//非递归先序遍历 后继线索二叉树 


//void PostThreading_Tri(TriBiNode* T);//后续后继线索化

//int PostOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//后续遍历二叉树P，并后继线索化

//int PostOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//非递归后续遍历 后继线索二叉树

 
