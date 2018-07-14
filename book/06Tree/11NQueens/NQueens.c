#include "NQueens.h"

int InitChassBoard_CB(int c[N][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			c[i][j] = 0;//0代表没有棋子，默认是空棋盘 
	}
	return 1;
}

int Trial_CB(int i, int c[N][N])
{
	if(N<=3)//3皇后及以下，凑不出不在同一行同一列同一斜线的棋盘 
		return 0;
	
	if(i>N)//行递归结束，输出 
	{
		printf("%d皇后的第%d种解法\n", N, ++order);
		Output_CB(c);
		printf("\n");
		//PressEnter;//单步输出棋盘 
	}
	else
	{
		for(int j=1; j<=N; j++)
		{
			c[i-1][j-1] = 1;//在某一行遍历放置棋子 
			if(Layout_CB(i, j, c))//判断放置的是否合规 
				Trial_CB(i+1, c);//递归放置每列棋子 
			c[i-1][j-1] = 0;//移除，准备放这一行的下一个，这里不能用else，否则递归跳出来没法用这个删除 
		}
	}
}

int Layout_CB(int x, int y, int c[N][N])
{
	int k,count;//检查行列重复用 
	int m,n;//检查斜对角重复用 
	
	count = 0;
	for(k=1; k<=N; k++)//检查x这一行有没有重复的 
	{
		if(c[x-1][k-1]==1)
			count++;
		if(count>1)
			return 0;
	}
	
	count = 0;
	for(k=1; k<=N; k++)//检查y这一列有没有重复的 
	{
		if(c[k-1][y-1]==1)
			count++;
		if(count>1)
			return 0;
	}
	
	m = x-1;//m、n还是行和列，只不过x、y这个坐标已经有棋子是1了，所以从下一个开始遍历 
	n = y-1;
	while(m>=1 && n>=1)//检查左下对角 
	{
		if(c[m-1][n-1])
			return 0;
		m--;
		n--;
	}
	
	m = x+1;
	n = y+1;
	while(m<=N && n<=N)//检查右上 
	{
		if(c[m-1][n-1])
			return 0;
		m++;
		n++;
	}
	
	m = x+1;
	n = y-1;
	while(m<=N && n>=1)//检查右下 
	{
		if(c[m-1][n-1])
			return 0;
		m++;
		n--;
	}
	
	m = x-1;
	n = y+1;
	while(m>=1 && n<=N)//检查左上 
	{
		if(c[m-1][n-1])
			return 0;
		m--;
		n++;
	}
	return 1;
}

int Output_CB(int c[N][N])
{
	printf("┏");//画第一行边框 
	for(int i=1; i<=N-1; i++)
		printf("━┳");
	printf("━┓\n");
	
	for(int i=1; i<=N; i++)
	{
		printf("┃");//画每行的棋子 
		for(int j=1; j<=N; j++)
		{
			if(c[i-1][j-1]==1)
				printf("●┃");
			else
				printf("  ┃");
		}
		printf("\n");
		
		if(i<N)//画内部的边框 
		{
			printf("┣");
			for(int j=1; j<=N-1; j++)
				printf("━╋");
			printf("━┫\n");
		}
	}
	
	printf("┗");//画底部边框 
	for(int i=1; i<=N-1; i++)
		printf("━┻");
	printf("━┛\n");
	
	return 1;
}
