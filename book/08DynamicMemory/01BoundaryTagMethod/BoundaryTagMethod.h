#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

#define FootLocate(p) p+(p)->size-1//ָ��p��ָ�ڵ�ĵײ� 

typedef struct SpaceNode
{
	union
	{
		struct SpaceNode* llink;//��ָ�룬ָ��ǰ�� 
		struct SpaceNode* uplink;//�ײ�ָ�룬ָ�򱾽ڵ�ͷ�� 
	}Ptr;
	int tag;//��־��0���У�1ռ�� 
	int size;
	struct SpaceNode* rlink;
}SpaceNode;

//ȫ�ֱ��� 
SpaceNode* start;//����space����ʼ��ַ



int InitSpace(SpaceNode memory[1002]);

SpaceNode* AllocBoundTag(SpaceNode* *pstart, int n);//�����㷨���״���Ϸ����������п��п����ʼ��ַ���������n���֣����ط���Ŀ��п� 

int Reclaim(SpaceNode* *pstart, SpaceNode* *p);//�����㷨

int PrintLayout(SpaceNode* start, SpaceNode* pstart);//�����ǰ�ڴ�����ֹ��ַ 
