#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../../02SequenceList/04SinglyLinkedList/SinglyLinkedList.c"

int CreatePowerSet_PS(FILE* fp, LNode** A);//��������A��������洢 

int GetPowerSet_PS(int i, LNode* A, LNode* B);//��A���ݼ���Ҳ���������Ӽ�������B�ݴ�õ����Ӽ������ 

int Output_PS(LNode* A);//��ӡ�Ӽ� 
