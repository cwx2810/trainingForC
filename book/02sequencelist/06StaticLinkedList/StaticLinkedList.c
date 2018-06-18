#include "StaticLinkedList.h"

void InitSpace()
{
	for(int i=0; i<99; i++)//�ռ�С���Ŵ�0~99��ָ���Ŵ�1~100��0��ʾ100 
		SPACE[i].cur = i+1;
	SPACE[99].cur = 0;
}

int MallocSpace()
{
	int cur = SPACE[0].cur;//��ʼ����Ҫ����Ľڵ��ָ��Ϊ�ռ�ĵ�ǰ����ָ�룬��һ���ǵ�һ��ָ�� 
	if(cur!=0)//�������Ŀռ�ָ��û��100��Ҳ��������ռ�û������ 
	{
		SPACE[0].cur = SPACE[cur].cur;//����ɹ�������ָ��������ƶ�������Ϊ�ı�ָ���ֵ
		return cur;//�������뵽��ָ��ֵ 
	} 
	else
		return 0;//����ʧ�� 
}

void FreeSpace(int k)
{
	SPACE[k].cur = SPACE[0].cur;//��k���ڵ��ָ���Ϊ����ָ�룬��ӣ��´������������� 
	SPACE[0].cur = k;//֮ǰ�Ŀ���ָ����k 
}

int InitList_SL(int *L)//����ͷ���ָ�� 
{
	*L = MallocSpace();//*LΪȡ��ͷ��㣬Ϊͷ������ռ䣬ʵ���Ͼ��ǵõ�һ���α�ֵ
	if((*L)==0)		  //�ռ�����
		return 0;
	SPACE[*L].cur = 0;//����Ұָ�룬ͷ����ÿ� 
	return 1; 
}




