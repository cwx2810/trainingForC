#include "SequenceString.h"

int StrAssign_Sq(SString S, const char* chars)
{
	if(strlen(chars)>255)
		return 0;
		
	S[0] = strlen(chars);//0λ���泤�� 
	for(int i=1; i<=strlen(chars); i++)//����λ����charsֵ 
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
	//˳�򴮲��ܱ����٣�����Ҳû����ռ� 
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
	if(pos<1 || pos>S[0] || len<0 || pos+len-1>S[0])//��ͼ�������-1�ľ��裬ֻҪС�ڵ���S[0]���ǺϷ��� 
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
	while(pos+T[0]-1<=S[0])//�ڵ�pos����ʼ��TҪ��S�ķ�Χ�� 
	{
		SubString_Sq(Sub, S, pos, T[0]);//�ҵ���pos����ʼ�ĺ�T�ȳ���ÿ���Ӵ�����T�Ƚϣ�������ҵ��� 
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
		
	int i = pos;  //i������ԭʼ��S���ζ�����ʼΪ��pos��Ԫ�أ���ĿҪ��Ҫ�ڵ�pos����ʼ�� 
	int j = 1;    //j������ƥ�䴮T���ζ�����ʼΪ��һ��Ԫ��
		
	while(i<=S[0] && j<=T[0])
	{
		if(S[i]==T[j])  //ƥ���ϣ���һֱ�ƶ��α� 
		{
			i++;
			j++;
		}
		else		    //ûƥ���ϣ��ͻ�������ƥ�� 
		{
			i = i-(j-1)+1; //i����j-1��Ԫ�أ��ͻص�����㣬��+1��˼��ǰ��һ������Ϊ��ǰԪ��ƥ��ʧ�� 
			j = 1;		   //j����˵���ص���ʼ������ƥ�� 
		}
	} 
	if(j>T[0])			//����jƥ����������T��Ԫ�أ�������S�е���ʼλ�� 
		return i-T[0];
	else
		return 0;
}


int StrInsert_Sq(SString S, int pos, SString T)
{
	if(pos<1 || pos>S[0]+1 || S[0]+T[0]>255)  //pos����������Ԫ�ػ�+1��λ��
		return 0;
	for(int i=pos; i<=S[0]; i++)		//S�д�pos��ʼԪ���������T�ĳ��� 
		S[i+T[0]] = S[i];
	for(int i=pos; i<=pos+T[0]-1; i++)	//��T���ȥ 
		S[i] = T[i-pos+1];				//i-pos+1��û�취��ֻ������ƴ����T������Ԫ�ر��� 
	S[0] += T[0];
	return 1;
}

int StrDelete_Sq(SString S, int pos, int len)
{
	if(pos<1 || pos>S[0]+1 || pos+len-1>S[0] || len<0)
		return 0;
	for(int i=pos+len; i<=S[0]; i++)//��Ҫɾ���Ĳ���֮��Ĵ�����ǰ�� 
		S[i-len] = S[i];
	S[0] -= len;
	return 1;
}

int Replace_Sq(SString S, SString T, SString V)
{
	int i = Index_Match(S, T, 1);
	while(S[0]-T[0]+V[0] && i)//�ռ��㹻�滻������ƥ���� 
	{
		StrDelete_Sq(S, i, T[0]);//��ƥ���ϵ�λ��ɾ��T 
		StrInsert_Sq(S, i, V);//����V 
		i = i + V[0];//i�л�����һ��λ��
		i = Index_Match(S, T, i);//i������һ��ƥ�� 
	}
	if(i==0)//i�Ѿ�����ƥ�䵽��˵��ƥ������ 
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


