/*˳�����ز���*/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"

/*�궨��*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

/*˳������Ͷ���*/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;//˳���洢�ռ��ַ
	int length;
	int listsize; 
}SqList;

/*�����б�*/
Status InitList_Sq(SqList *L);//��ʼ����˳���

void ClearList_Sq(SqList *L);//���˳���

void DestroyList_Sq(SqList *L);//����˳���

Status ListEmpty_Sq(SqList L);//�ж�˳����Ƿ�Ϊ��

int ListLength_Sq(SqList L);//����˳���Ԫ�ظ���

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);//���˳����i��Ԫ�أ��û�ַe���� 

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));//����˳�������e����ĳ�ֱȽϹ�ϵ(compare�����������ֹ�ϵ)��Ԫ�ص�λ��

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);//���cur_e��ǰ������pre_e����

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);//��ú��

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);//�ڵ�i��λ�Ӳ���Ԫ��e

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);//ɾ����i��Ԫ�أ��������ڻ�ַe������֮

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));//��visit��������˳��� 

#endif
