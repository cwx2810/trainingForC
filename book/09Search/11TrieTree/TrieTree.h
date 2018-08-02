#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum { Leaf, Branch }NodeKind;//�ڵ����࣬0Ҷ�ӣ�1��֧
typedef struct
{
	char ch[27];//�ؼ��֣���27λ 
	int length;//�ؼ��ֳ��� 
}KeyType;//�ؼ�������

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
			struct TrieNode* ptr[27];//�洢26��Ӣ����ĸ��һ���ո� 
			int count;//��ǰ��֧�ڵ��Ѿ�ռ�õ���ĸ���� 
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
int ord(char ch);//�����ַ�ch��Trie���ڵ��е����
int cmp(KeyType A, KeyType B);//�жϽṹA��B�Ƿ���� 
