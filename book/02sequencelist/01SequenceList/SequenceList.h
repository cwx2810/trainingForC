/*顺序表相关操作*/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"

/*宏定义*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

/*顺序表类型定义*/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;//顺序表存储空间基址
	int length;
	int listsize; 
}SqList;

/*函数列表*/
Status InitList_Sq(SqList *L);//初始化空顺序表

void ClearList_Sq(SqList *L);//清空顺序表

void DestroyList_Sq(SqList *L);//销毁顺序表

Status ListEmpty_Sq(SqList L);//判断顺序表是否为空

int ListLength_Sq(SqList L);//返回顺序表元素个数

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);//获得顺序表第i个元素，用基址e接收 

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));//返回顺序表中与e满足某种比较关系(compare方法定义这种关系)的元素的位子

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);//获得cur_e的前驱，用pre_e接收

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);//获得后继

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);//在第i个位子插入元素e

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);//删除第i个元素，并保存在基址e，返回之

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));//用visit方法访问顺序表 

#endif
