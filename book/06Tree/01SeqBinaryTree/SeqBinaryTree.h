#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef char SqBiTree[100];//��������� 

typedef struct
{
	int level;//�ڵ����ڲ��� 
	int order;//�ڵ����ڱ�����ţ�����ȫ���������� 
}Position;		//�ڵ�λ����Ϣ�ṹ�� 

int InitBiTree_Sq(SqBiTree T);

int ClearBiTree_Sq(SqBiTree T);

int DestroyBiTree_Sq(SqBiTree T);

int BiTreeEmpty_Sq(SqBiTree T);

int CreateBiTree_Level(FILE *fp, SqBiTree T);//�������й�������� 

int CreateBiTree_Pre(FILE *fp, SqBiTree T, int i);//�������й�������� 

int BiTreeLength_Sq(SqBiTree T);//��ȫ���������ȣ����Ƿǿսڵ��� 

int BiTreeDepth_Sq(SqBiTree T);

int Root_Sq(SqBiTree T, char *e);//�ҵ����ڵ���e���� 

char Value_Sq(SqBiTree T, Position s);//�ҵ�λ��s�Ľڵ��ֵ 

int Assign_Sq(SqBiTree T, Position s, char value);//��λ��s�Ľڵ㸳ֵvalue 

char Parent_Sq(SqBiTree T, char e);//�ҵ�e�İְ� 

char LeftChild_Sq(SqBiTree T, char e);

char RightChild_Sq(SqBiTree T, char e);

char LeftBrother_Sq(SqBiTree T, char e);

char RightBrother_Sq(SqBiTree T, char e);

int LevelOrderTraverse_Sq(SqBiTree T, void(Visit)(char));//������� 

int PreOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int InOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int PostOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i);

int Print_Sq(SqBiTree T);
