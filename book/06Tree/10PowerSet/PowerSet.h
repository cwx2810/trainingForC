#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../02SequenceList/04SinglyLinkedList/SinglyLinkedList.c"

int CreatePowerSet_PS(FILE* fp, LNode** A);//创建集合A，用链表存储 

int GetPowerSet_PS(int i, LNode* A, LNode* B);//求A的幂集，也就是所有子集，集合B暂存得到的子集并输出 

int Output_PS(LNode* A);//打印子集 
