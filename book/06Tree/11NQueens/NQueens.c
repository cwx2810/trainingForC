#include "NQueens.h"

int InitChassBoard_CB(int c[N][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			c[i][j] = 0;//0����û�����ӣ�Ĭ���ǿ����� 
	}
	return 1;
}

int Trial_CB(int i, int c[N][N])
{
	if(N<=3)//3�ʺ����£��ղ�������ͬһ��ͬһ��ͬһб�ߵ����� 
		return 0;
	
	if(i>N)//�еݹ��������� 
	{
		printf("%d�ʺ�ĵ�%d�ֽⷨ\n", N, ++order);
		Output_CB(c);
		printf("\n");
	}
	else
	{
		for(int j=1; j<=N; j++)
		{
			c[i-1][j-1] = 1;//��ĳһ�б����������� 
			if(Layout_CB(i, j, c))//�жϷ��õ��Ƿ�Ϲ� 
				Trial_CB(i+1, c);//�ݹ����ÿ������ 
			else
				c[i-1][j-1] = 0;//���Ϲ����Ƴ���׼������һ�е���һ�� 
		}
	}
	return 1;
}

int Layout_CB(int x, int y, int c[N][N])
{
	int k,count;//��������ظ��� 
	int m,n;//���б�Խ��ظ��� 
	
	count = 0;
	for(k=1; k<=N; k++)//���x��һ����û���ظ��� 
	{
		if(c[x-1][k-1]==1)
			count++;
		if(count>1)
			return 0;
	}
	
	count = 0;
	for(k=1; k<=N; k++)//���y��һ����û���ظ��� 
	{
		if(c[k-1][y-1]==1)
			count++;
		if(count>1)
			return 0;
	}
	
	m = x-1;//m��n�����к��У�ֻ����x��y��������Ѿ���������1�ˣ����Դ���һ����ʼ���� 
	n = y-1;
	while(m>=1 && n>=1)//������¶Խ� 
	{
		if(c[m-1][n-1])
			return 0;
		m--;
		n--;
	}
	
	m = x+1;
	n = x+1;
	while(m<=N && n<=N)//������� 
	{
		if(c[m-1][n-1])
			return 0;
		m++;
		n++;
	}
	
	m = x+1;
	n = y-1;
	while(m<=n && n>=1)//������� 
	{
		
	}
}
