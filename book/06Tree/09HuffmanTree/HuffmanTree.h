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

int InitTree_HT(HTNode* *T);//�����ṹ��ָ�����͵� ָ��ṹ���ָ�룬�ں�������ȡ���ṹ�屾�� 

int CreateHuffmanTree_HT(FILE* fp, HTNode** T);

int SelectMini_HT(HTNode* T, int end, int* order_1, int* order_2);//�ڽڵ�1~end(�����±�)���ҳ�Ȩֵ��С�������ڵ�����

int HuffmanCode_Invert(HTNode* T, char*** Code);//���������������� 
//char*�Ǳ����node��char**��charָ�����͵� ָ��char��ָ�룬��ΪҪ�ı�node��������char***������ָ��char��ָ�룩��ָ�룬�ں�������ȡ��charָ�뱾�壬charָ�뱾���Ǳ���node 

int HuffmanCode_Pre(HTNode* T, char*** Code); //��������������������

int ShowHuffmanTree(HTNode* T);

int ShowHuffmanCode(HTNode* T, char** Code); 
