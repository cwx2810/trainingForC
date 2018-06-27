#include "KMP.h"


int Index_KMP(SString S, SString T, int pos, int next[])
{
	if(pos<1)
		return 0;
	int i = pos;
	int j = 1;
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j] || j==0)//ƥ���ϻ���j next����0 
		{
			i++;
			j++;
		}
		else
			j = next[j];//ûƥ���ϣ�����һ��j 
	}
	if(j>T[0])//j�������ˣ�ƥ��ɹ�������S��ƥ�䵽���Ӵ��Ŀ�ͷԪ�� 
		return i-T[0];
	else
		return 0;
}

void get_next(SString T, int next[])//��һ���յ�next��ȥ���õ�һ������next���鹩KMP�㷨ʹ�� 
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	
	while(i<T[0])
	{
		if(T[i]==T[j] || j==0)// ����ƥ���ϻ�j next����0(û��ƥ��ģ�kmp��������ʧЧ)���������һ��next 
		{					//��Ȼ�Ѿ�ƥ���ϣ����next���Ǵ���һ��j��ʼƥ���ˣ��պ���j++ 
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];//ƥ��ʧ�ܣ�����next��������ĵݹ飬���Ի���j����һ��ƥ�� 
	}
}

void get_nextval(SString T, int nextval[])
{
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	
	while(i<T[0])
	{
		if(T[i]==T[j] || j==0)
		{
			j++;
			i++;
			if(T[i]!=T[j])//�����ʱ�ӳ�����ij����ȣ�����ͨ���� 
				nextval[i] = j;
			else
				nextval[i] = nextval[j];//�������ˣ���໬��һ�Σ�����ֻ��� 
		}
		else
			j = nextval[j];
	}
}
