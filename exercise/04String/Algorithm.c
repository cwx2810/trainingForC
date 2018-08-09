#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/04String/01SequenceString/SequenceString.h"

//���ô� 
void ReverseString(SString T, SString S)
{
	for(int i=T[0]; i>=1; i--)//���ô� 
		S[T[0]-i+1] = T[i];
	S[0] = T[0];//���ƴ����� 
}

//R = S - S ��T 
//�����а�����S�ж���������T�е��ַ��������ظ�������R��a����R��ÿ���ַ���һ����S�г��ֵ�λ�� 
void Algo_411(SString R, SString S, SString T, int a[])
{
	a[0] = 0;
	for(int i=1; i<=S[0]; i++)
	{
		int p = Index_Sq(T, S[i], 1);//���S��T�е�һ�γ��ֵ�λ�ã��ж�S�Ƿ���T�У������ܽ�R 
		if(!p)
			p = Index_Sq(R, S[i], 1);//�ж��Ƿ��ظ����ظ����ܽ�R
			
		if(!p)//��R 
		{
			a[0]++;
			a[a[0]] = i;
			StrInsert_Sq(R, a[0], S[i]);
		} 
	}
}
