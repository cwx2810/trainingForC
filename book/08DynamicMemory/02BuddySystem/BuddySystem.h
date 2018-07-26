#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct SpaceNode
{
	struct SpaceNode* llink;//ָ��ǰ���ռ� 
	int tag;//��־��0���У�1ռ�� 
	int size;
	struct SpaceNode* rlink;//ָ���̿ռ� 
}SpaceNode;//�ڴ������ 

typedef struct HeadNode
{
	int size;
	SpaceNode* first;//ָ���ڴ�� 
}FreeList[4];//�ڴ���ͷ������ͣ�Ҳ�������������ڴ�� 

//ȫ�ֱ���
SpaceNode *start,*end;//�ڴ�������յ� 


int InitSpace_b(FreeList available);

SpaceNode* AllocBuddy(FreeList available, int n);//nΪ��������� 

int PrintLayout_b(FreeList available); 
