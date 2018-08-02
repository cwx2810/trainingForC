#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum { Leaf, Branch }NodeKind;//�ڵ����࣬0Ҷ�ӣ�1��֧
typedef struct
{
	char ch[17];//�ؼ��֣���17λ 
	int length;//�ؼ��ֳ��� 
}KeyType;//�ؼ�������

typedef struct DLTNode
{
	NodeKind kind;
	char symbol;//�洢�ؼ��ֵ�һ���ַ� 
	struct DLTNode* next;//ָ���ֵܽڵ� 
	union
	{
		char* childptr;//Ҷ�ӽڵ�ļ�¼ָ�� 
		struct DLTNode* first;//��֧�ڵ�ĺ�����ָ�� 
	}Ptr;
}DLTNode;

int CreateDLTree(FILE* fp, DLTNode* *DLT);

char* SearchDLTree(DLTNode* DLT, KeyType key);

int InsertDLTree(DLTNode* *DLT, KeyType key);

int Printkey(DLTNode* DLT);
