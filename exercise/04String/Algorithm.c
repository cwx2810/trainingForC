#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/04String/01SequenceString/SequenceString.h"

//逆置串 
void ReverseString(SString T, SString S)
{
	for(int i=T[0]; i>=1; i--)//逆置串 
		S[T[0]-i+1] = T[i];
	S[0] = T[0];//复制串长度 
}

//R = S - S ∩T 
//求所有包含在S中而不包含在T中的字符，不能重复，构成R，a保存R中每个字符第一次在S中出现的位置 
void Algo_411(SString R, SString S, SString T, int a[])
{
	a[0] = 0;
	for(int i=1; i<=S[0]; i++)
	{
		int p = Index_Sq(T, S[i], 1);//求出S在T中第一次出现的位置，判断S是否在T中，在则不能进R 
		if(!p)
			p = Index_Sq(R, S[i], 1);//判断是否重复，重复则不能进R
			
		if(!p)//进R 
		{
			a[0]++;
			a[a[0]] = i;
			StrInsert_Sq(R, a[0], S[i]);
		} 
	}
}
