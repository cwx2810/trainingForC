#include "KMP.h"


int Index_KMP(SString S, SString T, int pos, int next[])
{
	if(pos<1)
		return 0;
	int i = pos;
	int j = 1;
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j] || j==0)//匹配上或者j next出了0 
		{
			i++;
			j++;
		}
		else
			j = next[j];//没匹配上，找下一个j 
	}
	if(j>T[0])//j消耗完了，匹配成功，返回S中匹配到的子串的开头元素 
		return i-T[0];
	else
		return 0;
}

void get_next(SString T, int next[])//传一个空的next进去，得到一个满的next数组供KMP算法使用 
{
	int i = 1;//主串游标，从主串第一个字符开始匹配 
	int j = 0;//子串游标 
	next[1] = 0;//默认值 
	
	while(i<T[0])
	{
		if(T[i]==T[j] || j==0)// 自身匹配上或j next出了0(没有匹配的，kmp滑动窗口失效)，都能求出一个next 
		{					 
			j++;
			i++;
			next[i] = j;//既然已经匹配上，这个next就从子串下一个j开始匹配了，刚好是j++
		}
		else
			j = next[j];//匹配失败，利用next数组自身的递归，可以回溯j到上一步匹配 
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
			if(T[i]!=T[j])//如果临时加出来的ij不相等，则普通滑动 
				nextval[i] = j;
			else
				nextval[i] = nextval[j];//如果相等了，则多滑动一次，做充分滑动，也就是失配时直接跳到第一个next，不用像普通next一样跳到前一个next再跳到再前一个next 
		}
		else
			j = nextval[j];
	}
}
