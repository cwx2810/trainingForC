#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum { Leaf, Branch }NodeKind;//节点种类，0叶子，1分支
typedef struct
{
	char ch[27];//关键字，共27位 
	int length;//关键字长度 
}KeyType;//关键字类型

typedef struct
{
	char key[27];
}Record;

typedef struct TrieNode
{
	NodeKind kind;
	union
	{
		struct
		{
			struct TrieNode* ptr[27];//存储26个英文字母和一个空格 
			int count;//当前分支节点已经占用的字母数量 
		}branch;
		
		struct
		{
			KeyType key;
			Record* childptr;
		}leaf;
	}Ptr;
}TrieNode;

int CreateTrieTree(FILE *fp, TrieNode* *TT);

Record* SearchTrieTree(TrieNode* TT, KeyType key);

int InsertTrieTree(TrieNode* *TT, Record R);
int ord(char ch);//返回字符ch在Trie树节点中的序号
int cmp(KeyType A, KeyType B);//判断结构A和B是否相等 
