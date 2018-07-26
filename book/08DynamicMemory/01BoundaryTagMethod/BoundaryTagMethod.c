#include "BoundaryTagMethod.h"

int InitSpace(SpaceNode memory[1002])
{
	SpaceNode* pstart = &memory[0];//��ʼ���ռ����ʼ��ַ 
	
	memory[0].Ptr.llink = pstart;
	memory[0].tag = 0;
	memory[0].size = 1000;
	memory[0].rlink = pstart;
	
	memory[999].Ptr.uplink = pstart;
	memory[999].tag = 0;
	
	start = pstart;
	return 1;
}

SpaceNode* AllocBoundTag(SpaceNode **pstart, int n)
{
	SpaceNode* p;//�������Ŀ��п� 
	//�������п飬����б�n��ģ�����ѭ����Ҳ����Ҫ����n���֣���Ҫ�ҵ���n��Ŀ��п� 
	for(p=*pstart; p && p->size<n && p->rlink!=*pstart; p=p->rlink)
		;
	if(!p || p->size<n)//Ѱ��ʧ�� 
		return 0;
	else
	{
		SpaceNode* foot;
		foot = FootLocate(p);//footָ����п�ĵײ� 
		*pstart = p->rlink;//pstartָ��p�ĺ�̿��п� 
		if(p->size-n < 10)//�ҵ��Ŀռ��С������Ŀռ��С��������10���� 
		{
			if(*pstart==p)//���p�ĺ��ָ��p��˵��ֻ��һ�����п飬�ÿ�û�õ�ָ�� 
				*pstart = 0;
			else
			{
				(*pstart)->Ptr.llink = p->Ptr.llink;//�ѷ�����ռ�Ŀ��п��������ȥ��
				p->Ptr.llink->rlink = *pstart; 
			}
		}
		else			//������10������ֳ����� 
		{
			foot->tag = 1;
			
			p->size -= n;//����p��ǰ��Ϊ�ռ�����С�����ѵõ��Ŀ��п�ֳ��������п飬ǰ���Ǵ��������Ǹպ�n���� 
			foot = FootLocate(p);
			foot->tag = 0;
			foot->Ptr.uplink = p;
			
			p = foot+1;//pָ������ǿ�պ�n���ֵĿ��ͷ�� 
			p->tag = 1;
			p->size = n; 
		}
		return p;
	}
}

int Reclaim(SpaceNode **pstart, SpaceNode **p)
{
	//δ����� 
	return 1;
}

int PrintLayout(SpaceNode* start, SpaceNode* pstart)
{
	SpaceNode* r;//�ƶ��α�βָ��
	r = pstart;
	printf("���п���ֹ��Χ��|");
	printf("%4d--%4d | ", r-pstart+1, r+r->size-pstart);
	//printf("%d", r->rlink);
	//printf("%d", pstart);
	while(r->rlink!=pstart)
	{
		r = r->rlink;
		printf("%4d--%4d | ", r-pstart+1, r+r->size-pstart);
	} 
	printf("\n");
}
