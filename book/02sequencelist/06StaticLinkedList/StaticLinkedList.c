#include "StaticLinkedList.h"

void InitSpace()
{
	for(int i=0; i<999; i++)//�ռ��ַ��Ŵ�0~999��Ϊʲô��0��ʼ����Ϊ0����������ָ�� 
							//ָ���Ŵ�1~1000��0��ʾ1000��Ϊʲô�������ã���ΪNULL==0�������һ����Ϊ0��������������ж����ˣ��������ڿ���д��L��������д��L!=1000 
		SPACE[i].pnext = i+1;
	SPACE[999].pnext = 0;
}

int MallocSpace()
{
	int pnext = SPACE[0].pnext;//�õ�����ָ�룬��һ���ǵ�һ��ָ��1 
	if(pnext)//�������Ŀռ�ָ��û��1000��Ҳ��������ռ�û������ 
	{
		SPACE[0].pnext = SPACE[pnext].pnext;//����ɹ�������ָ��������ƶ���ͼ������Ϊ�ı�0�ſ��curΪ2 
		return pnext;//�������뵽��ָ��ֵ 
	} 
	else
		return 0;//����ʧ�� 
}

void FreeSpace(int k)
{
	SPACE[k].pnext = SPACE[0].pnext;//Ҫɾ���Ľڵ�k���α��ſ���ָ����α� 
	SPACE[0].pnext = k;//����ָ����α��Ϊk���´���������������
	//����ֻ��ָ��ı仯��û��data���ͷ� 
}



int InitList_SL(int *L)//����ͷ���ָ�� 
{
	*L = MallocSpace();//*LΪȡ��ͷ��㣬Ϊͷ������ռ䣬ʵ����ͼ�о��ǵõ�һ����ֵַ1
	if(!(*L))		  //�ռ�����
		return 0;
	SPACE[*L].pnext = 0;//����Ұָ�룬ͷ����ָ���ÿգ�ʵ����ͼ�о��ǰ�ͷ���ָ���Ϊ��0 
	return 1; 
}

int ClearList_SL(int L)//L����ͷ��㣬�����ܶ�ͷ����޸ģ���ʵ���Ǵ���һ����ֵַ������Ϊͷ��㣬����1 
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;//�õ�ͷ����α�ֵ����ֵ��p����ʾp����ͷ����next��Ҳ����p�ǵ�һ���ڵ� 
	while(p) 
	{
		SPACE[L].pnext = SPACE[p].pnext;//ͷ���ָ�����¸��ڵ㣬Ҳ���ǵڶ����ڵ� 
		FreeSpace(p);//�ͷŵ�һ���ڵ� 
		p = SPACE[L].pnext;//p������ʾ���¸��ڵ� 
	}
	return 1;
}

int DestroyList_SL(int *L)
{
	ClearList_SL(*L);//*L��ʾȡ��ͷ��㣬ʵ������ͼ�о��ǵõ���ֵַ1 
	FreeSpace(*L);
	*L = 0;//���0��ͼ�ϱ�ʾ�α��ÿգ�����ͼ�������û������ 
}

int ListEmpty_SL(int L)
{
	if(L && !SPACE[L].pnext)//L��ʾ�����޸ĵ�ͷ��㣬����1��L==1 && SPACE[L].pnext==0����ͼ��ֻ��ͷ������� 
		return 1;
	else
		return 0;
}

int ListLength_SL(int L)
{
	if(!L)
		return 0;
	int count = 0;
	int p = SPACE[L].pnext;//p��ʾ��һ���ڵ� 
	while(p)
	{
		count++;
		p = SPACE[p].pnext;
	}
	return count;
}

int GetElem_SL(int L, int i, int *e)
{
	if(!L || i<1 || i>998)
		return 0;
	int count = 0;
	int p = SPACE[L].pnext;
	while(p)
	{
		count++;
		if(count==i)
		{
			*e = SPACE[p].data;
			return 1;
		}
		p = SPACE[p].pnext;
	}
}

int LocateElem_SL(int L, int e)
{
	if(!L)
		return 0;
	int count = 1;
	int p = SPACE[L].pnext;
	while(p && SPACE[p].data!=e)
	{
		count++;
		p = SPACE[p].pnext;
	}
	if(p)
		return count;
	return 0;
}

int PriorElem_SL(int L, int cur_e, int *pre_e)
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	if(SPACE[p].data!=cur_e)//��һ���ڵ㲻���ǵ�ǰ�ڵ㣬��Ϊû��ǰ�� 
	{
		while(SPACE[p].pnext)//�ڶ����ڵ� 
		{
			int q = SPACE[p].pnext;//����һ�£������д 
			if(SPACE[q].data==cur_e)
			{
				*pre_e = SPACE[p].data;
				return 1;
			}
			p = SPACE[p].pnext;//�������Ѱ�� 
		}
	}
	return 0;
}

int NextElem_SL(int L, int cur_e, int *next_e)
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	while(SPACE[p].pnext)
	{
		if(SPACE[p].data==cur_e)
		{
			int q = SPACE[p].pnext;
			*next_e = SPACE[q].data;
			return 1;
		}
		p = SPACE[p].pnext;
	}
	return 0;
}

int ListInsert_SL(int L, int i, int e)
{
	int p = L;
	int j = 1;
	while(p && j<i)
	{
		p = SPACE[p].pnext;
		j++;
	}
	if(!p || j>i)//�����Ǽ��Ϸ��ԣ������ҵ���p��������λ�� 
		return 0;
		
	int s = MallocSpace();//�����洢�ṹ������Сe 
	if(!s)
		return 0;
	SPACE[s].data = e;
	SPACE[s].pnext = SPACE[p].pnext;
	SPACE[p].pnext = s;
	return 1;
}

int ListDelete_SL(int L, int i, int *e)
{
	if(!L)
		return 0;
	int pre = L;
	int j = 1;
	while(SPACE[pre].pnext && j<i)
	{
		pre = SPACE[pre].pnext;
		j++;
	}
	if(!SPACE[pre].pnext || j>i)
		return 0;
		
	int p = SPACE[pre].pnext;
	*e = SPACE[p].data;
	int tmp = SPACE[pre].pnext;
	SPACE[pre].pnext = SPACE[tmp].pnext;
	FreeSpace(p);
	return 1;
}

int ListTraverse_SL(int L, void(Visit)(int))
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	while(p)
	{
		Visit(SPACE[p].data);
		p = SPACE[p].pnext;
	}	
	return 1;
}


