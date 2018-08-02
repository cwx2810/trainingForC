#include "BuddySystem.h"

int InitSpace_b(FreeList available)
{
	for(int i=0; i<=3; i++)
	{
		available[i].size = (int)pow(2, i);//����2��i�η� 
		available[i].first = 0;
	}
	
	SpaceNode* r = (SpaceNode*)malloc((int)pow(2,3)*sizeof(SpaceNode));
	if(!r)
		return 0;
	r->llink = r->rlink = r;
	r->tag = 0;
	r->size = 3;
	
	available[3].first = r;//�������ָ�����Ŀռ�r 
	
	start = r;
	end = r + available[3].size - 1;
	
	return 1;
}

SpaceNode* AllocBuddy(FreeList available, int n)
{
	int i;
	SpaceNode* pstart;
	for(i=0; i<=3 && (available[i].size<n || !available[i].first); i++)//�ҵ���������ռ�Ŀɷ���������С������ռ���߸ñ�δ����SpaceNode����������� 
		;
	if(i>3)
		return 0;
	else							//���з��� 
	{
		pstart = available[i].first;//ָ��ɷ����ӱ��ĵ�һ��spaceNode 
		SpaceNode* pre = pstart->llink;//����ǰ���ͺ�� 
		SpaceNode* next = pstart->rlink;
		
		//�������ifelse����û���õ����������������л��õ� 
		if(pstart==next)//����ɷ����ӱ��ĵ�һ���ڵ�û�к�̣�����һ�ξͲ��ܷ����ˣ��������õ�һ���ڵ�Ϊ�ÿ� 
			available[i].first = 0;
		else			//����к�̣���ȥ���������Ѿ�����Ŀռ䣬�������õ�һ���ڵ�Ϊ��ԭ���ĺ�� 
		{
			pre->rlink = next;
			next->llink = pre;
			available[i].first = next;
		}
		
		int j;
		for(j=1; i-j>=0 && available[i-j].size>=n; j++)//�״Σ����ҵ����ӱ��Ŀռ��ٴν��л��֣��ָ�û�з�����ռ���ӱ�������һ��ʼ��8�������ռ䣬����1����ʣ7�ָ�0��1��2���ӱ�1��2��4�Ŀռ䣬������size 
		{												//����Ҫ����Ŀռ䶼�պã��������õ���������㷨 
			SpaceNode* p = pstart + (int)pow(2, i-j);
			p->rlink = p;
			p->llink = p;
			p->tag = 0;
			p->size = i-j;
			available[i-j].first = p;
		}
		
		pstart->tag = 1;//�ռ���ռ�� 
		j--;
		pstart->size = i-j;//�Ѿ�ռ�õĿռ�Ĵ�С 
	}
	return pstart;
}

int PrintLayout_b(FreeList available)
{
	int mark=0;
	for(int i=0; i<=3; i++)//�ж��ڴ��Ƿ�ռ�� 
	{
		if(available[i].first)
		{
			mark = 1;
			break;
		}
	}
	
	if(mark==0)
		printf("�ڴ�����");
	else
	{
		printf("���п���ֹ��Χ��");
		for(int i=0; i<=3; i++)//���ÿ���ӱ��Ŀ��п���ֹ��Χ 
		{
			SpaceNode* r = available[i].first;
			if(r)
			{
				printf("|%d--%d", r-start+1, r+(int)pow(2, r->size)-start);//ֻ�õ������� 
				//printf("%d", r->rlink);
				//printf("%d", available[i].first);
				while(r->rlink!=available[i].first) 
				{
					r = r->rlink;
					printf("|%d--%d", r-start+1, r+(int)pow(2, r->size)-start);
				}
			}
		}
	}
	printf("\n");
	return 1;
}