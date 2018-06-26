#include "SequenceString.h"

int StrAssign_Sq(SString S, const char* chars)
{
	if(strlen(chars)>255)
		return 0;
		
	S[0] = strlen(chars);//0位保存长度 
	for(int i=1; i<=strlen(chars); i++)//其他位保存chars值 
		S[i] = chars[i-1];
	return 1;
}

int StrCopy_Sq(SString S, SString T)
{
	for(int i=0; i<=T[0]; i++)
		S[i] = T[i];
	return 1;
}

int StrEmpty_Sq(SString S)
{
	if(S[0]==0)
		return 1;
	else
		return 0;
}

int StrCompare_Sq(SString S, SString T)
{
	int i = 1;
	while(i<=S[0] && i<=T[0])
	{
		if(S[i]==T[i])
			i++;
		else
			return S[i]-T[i];
	}
	return 0;
}


int StrLength_Sq(SString S)
{
	return S[0];
}

int ClearString_Sq(SString S)
{
	S[0] = 0;
}

int DestroyString_Sq(SString S)
{
	//顺序串不能被销毁，本来也没分配空间 
}

int Concat_Sq(SString S, SString T1, SString T2)
{
	if(T1[0]+T2[0]>255)
		return 0;
	for(int i=1; i<=T1[0]; i++)
		S[i] = T1[i];
	for(int i=1; i<=T2[0]; i++)
		S[T1[0]+i] = T2[i];
	S[0] = T1[0]+T2[0];
	return 1;
}

int SubString_Sq(SString Sub, SString S, int pos, int len)
{
	if(pos<1 || pos>S[0] || len<0 || pos+len-1>S[0])//画图可以理解-1的精髓，只要小于等于S[0]都是合法的 
		return 0;
	for(int i=1; i<=len; i++)
	 	Sub[i] = S[pos+i-1];
	Sub[0] = len;
	
	return 1;
}

int Index_Sq(SString S, SString T, int pos)
{
	if(pos<1 || S[0]==0 || T[0]==0)
		return 0;
	
	SString Sub;	
	while(pos+T[0]-1<=S[0])//在第pos个开始的T要在S的范围内 
	{
		SubString_Sq(Sub, S, pos, T[0]);//找到第pos个开始的和T等长的每个子串，和T比较，相等则找到了 
		if(StrCompare_Sq(Sub, T)==0)
			return pos;
		pos++;
	}
	return 0;
}

int Index_Match(SString S, SString T, int pos)
{	
	if(pos<1 || S[0]==0 || T[0]==0)
		return 0;
		
	int i = pos;  //i负责在原始串S中游动，初始为第pos个元素，题目要求要在第pos个开始嘛 
	int j = 1;    //j负责在匹配串T中游动，初始为第一个元素
		
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j])  //匹配上，就一直移动游标 
		{
			i++;
			j++;
		}
		else		    //没匹配上，就回退重新匹配 
		{
			i = i-(j-1)+1; //i回退j-1个元素，就回到了起点，再+1意思是前进一步，因为当前元素匹配失败 
			j = 1;		   //j不用说，回到开始，重新匹配 
		}
	} 
	if(j>T[0])			//最终j匹配完了所有T的元素，返回在S中的起始位置 
		return i-T[0];
	else
		return 0;
}


int StrInsert_Sq(SString S, int pos, SString T)
{
	if(pos<1 || pos>S[0]+1 || S[0]+T[0]>255)  //pos可以是最后的元素还+1的位置
		return 0;
	for(int i=pos; i<=S[0]; i++)		//S中从pos开始元素整体后移T的长度 
		S[i+T[0]] = S[i];
	for(int i=pos; i<=pos+T[0]-1; i++)	//把T插进去 
		S[i] = T[i-pos+1];				//i-pos+1是没办法，只能这样拼出来T的所有元素遍历 
	S[0] += T[0];
	return 1;
}

int StrDelete_Sq(SString S, int pos, int len)
{
	if(pos<1 || pos>S[0]+1 || pos+len-1>S[0] || len<0)
		return 0;
	for(int i=pos+len; i<=S[0]; i++)//把要删除的部分之后的串整体前移 
		S[i-len] = S[i];
	S[0] -= len;
	return 1;
}

int Replace_Sq(SString S, SString T, SString V)
{
	int i = Index_Match(S, T, 1);
	while(S[0]-T[0]+V[0] && i)//空间足够替换并且能匹配上 
	{
		StrDelete_Sq(S, i, T[0]);//在匹配上的位子删除T 
		StrInsert_Sq(S, i, V);//插入V 
		i = i + V[0];//i切换到下一个位置
		i = Index_Match(S, T, i);//i进行下一次匹配 
	}
	if(i==0)//i已经不能匹配到，说明匹配完了 
		return 1;
	else
		return 0;
}

int StrPrint_Sq(SString S)
{
	if(S[0]==0)
		return 0;
	for(int i=1; i<=S[0]; i++)
		printf("%c", S[i]);
	return 1;
}


