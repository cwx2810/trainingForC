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
		int RTag;//������־������ϰ�������� 
	};
}BSTNode;

int CreateBSTree(BSTNode* *BST, Table T);

BSTNode* SearchBST_Ptr(BSTNode* BST, int key);//���ҷ���ָ��key��ָ��

int SearchBST_ForInsert(BSTNode* BST, int key, BSTNode* father, BSTNode* *p);
//����key�Ƿ���ڣ�fatherָ��BST��˫�ף�pΪ�ҵ��Ľڵ��ָ�룬�����Ҳ���ʱָ�򸸽ڵ��Ա���� 

int InsertBSTree(BSTNode* *BST, ElemType e);//�������Ĳ��ң����key����������� 

int InOrderTraverse_BST(BSTNode* BST, void(Visit)(ElemType));

int DeleteBST_Key(BSTNode* *BST, int key);//ɾ��key 
int DeleteBST_Ptr(BSTNode* *p);//ɾ���ĺ��ĺ�����ɾ��pָ��Ľڵ� 

int PrintBST(BSTNode* T);
int BSTDepth(BSTNode* T);
