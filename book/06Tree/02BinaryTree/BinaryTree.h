#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct BiTNode//����������ڵ� 
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode;

typedef struct{      //�������ڵ����õĻ���ջ 
	BiTNode **base;
	BiTNode **top;
	int stacksize;
}SqStack;

typedef struct		//����ڵ���Ϣ����������������� 
{
	BiTNode* left;//�ڵ�ָ�� 
	BiTNode* right;
	int order;//�ڵ���� 
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

//int Root(BiTNode* T, char* e);//��e���ո��ڵ� 

//char Value(BiTNode* p);//���ؽڵ��ֵ��pΪ�ýڵ�ָ�� 

//int Assign(BiTNode* p, char value);//���ڵ�p����value 

char Parent(BiTNode* T, char e);

//char LeftChild(BiTNode* T, char e);

//char RightChild(BiTNode* T, char e);

//char LeftBrother(BiTNode* T, char e);

//char RightBrother(BiTNode* T, char e);

BiTNode* LocateBiTree(BiTNode* T, char e);//��ȡָ��ڵ�e��ָ��

//int InsertBiTree(BiTNode* T, char e, BiTNode* T0, int LR);//��T0���뵽T�е�e���档LR��ʾT0�����ӣ�ֻ�ܲ����ұ�

//int DeleteBiTree(BiTNode* T, char e, int LR);//ɾ��T��e��������LR��ʾɾ��������

int LevelOrderTraverse(BiTNode* T, void(Visit)(char));

int PreOrderTraverse(BiTNode* T, void(Visit)(char));

int InOrderTraverse(BiTNode* T, void(Visit)(char)); 

int InOrderTraverseNonRecursive1(BiTNode* T, int(Visit)(char));
int InOrderTraverseNonRecursive2(BiTNode* T, int(Visit)(char));

int PostOrderTraverse(BiTNode* T, void(Visit)(char));

//int PrintTree(BiTNode* T);

