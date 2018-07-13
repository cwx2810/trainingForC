#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode;

int InitTree_HT(HTNode* *T);//声明结构体指针类型的 指向结构体的指针，在函数内是取到结构体本体 

int CreateHuffmanTree_HT(FILE* fp, HTNode** T);

int SelectMini_HT(HTNode* T, int end, int* order_1, int* order_2);//在节点1~end(代表下标)中找出权值最小的两个节点的序号

int HuffmanCode_Invert(HTNode* T, char*** Code);//逆序计算哈夫曼编码 
//char*是编码的node，char**是char指针类型的 指向char的指针，因为要改变node，所以有char***是声明指向（char的指针）的指针，在函数内是取到char指针本体，char指针本体是编码node 

int HuffmanCode_Pre(HTNode* T, char*** Code); //先序遍历计算哈夫曼编码

int ShowHuffmanTree(HTNode* T);

int ShowHuffmanCode(HTNode* T, char** Code); 
