#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../01MatrixGraph/MGraph.c"

//�����ֵ����ڵ� 
typedef struct CSNode
{
	char data;
	struct CSNode* firstchild;
	struct CSNode* nextsibling;
}CSNode;

//ջ�ṹ������ڵ� 
typedef struct
{
	CSNode* *base;//ջ��ָ�룬�൱��ԭ��˳����elem����ַ 
	CSNode* *top;//ջ��ָ�� 
	int stacksize;//ջ��Ԫ�ظ��� 
}SqStack;

int InitCSTree(CSNode **T);
int InitStack_Sq(SqStack *S);
int StackEmpty_Sq(SqStack S);
int GetTop_Sq(SqStack S, CSNode* *e);
int Push_Sq(SqStack *S, CSNode* e);
int Pop_Sq(SqStack *S, CSNode* *e);
int Print_CS(CSNode* T);



int DFSForest(MGraph G, CSNode **T);//����ȱ�����������ͼ��������ɭ�� 
int DFSTree(MGraph G, int order, CSNode **T);//�������ĺ����㷨�����ɴӽڵ����order��ʼ���� 
