#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum { Leaf, Branch }NodeKind;//节点种类，0叶子，1分支
typedef struct
{
	char ch[17];//关键字，共17位 
	int length;//关键字长度 
}KeyType;//关键字类型

typedef struct DLTNode
{
	NodeKind kind;
	char symbol;//存储关键字的一个字符 
	struct DLTNode* next;//指向兄弟节点 
	union
	{
		char* childptr;//叶子节点的记录指针 
		struct DLTNode* first;//分支节点的孩子链指针 
	}Ptr;
}DLTNode;

int CreateDLTree(FILE* fp, DLTNode* *DLT);

char* SearchDLTree(DLTNode* DLT, KeyType key);

int InsertDLTree(DLTNode* *DLT, KeyType key);

int Printkey(DLTNode* DLT);
