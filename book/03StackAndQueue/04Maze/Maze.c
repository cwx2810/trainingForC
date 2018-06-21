#include "Maze.h"

int InitStack_Sq(SqStack *S)
{
	(*S).base = (MazeInfo*)malloc(100*sizeof(MazeInfo));
	if(!(*S).base)
		return 0;
	(*S).top = (*S).base;
	(*S).stacksize = 100;
	
	return 1;
}

int StackEmpty_Sq(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

int Push_Sq(SqStack *S, MazeInfo e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base = (MazeInfo*)realloc((*S).base, ((*S).stacksize+10)*sizeof(MazeInfo));
		if(!(*S).base)
			return 0;
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += 10;
	}
	
	*((*S).top) = e;//为什么进栈先赋值，想图，top是在最后一个元素的尾部，也就是下个元素的头部 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, MazeInfo *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//为什么先递减指针，想图，如果先赋值了，那top此时就没有意义了，是空的尾部 
	*e = *((*S).top);
	return 1;
}


int MazePath(int maze[][15], MazePos start, MazePos end)
{
	SqStack S;
	MazeInfo info;
	MazePos curPos;
	int curOrder;
	
	InitStack_Sq(&S);
	curPos = start;//设置当前迷宫块坐标为入口 
	curOrder = 1;//设置当前迷宫块编号为1 
	
	do
	{
		if(CanPass(maze, curPos))//当前坐标未访问过，全是初始化操作 
		{
			FootPrint(maze, curPos);//初始化留下方向足迹 
			ShowMaze(maze);
			SetMazeInfo(&info, curOrder, curPos, Right);//初始化设置迷宫块信息 
			Push_Sq(&S, info);			//信息压栈，以便回溯
			
			if(EqualMazePos(curPos, end))//到达终点 
			{
				printf("\n寻路成功！！\n");
				return 1;
			}
			else
			{
				curPos = NextPos(info.pos, info.direction);//没到终点，探索下一步 
				curOrder++;
			}
			
			
		}
		else					//当前坐标访问过，回溯换方向 
		{
			if(!StackEmpty_Sq(S))//栈里有迷宫块，可以回溯 
			{
				Pop_Sq(&S, &info);//回溯一块 
				
				while(info.direction==Up && !StackEmpty_Sq(S))//上一块四面都访问过了，就再回到上一块，默认顺时针访问 
				{
					MarkPrint(maze, info.pos);//设置此路不通 
					ShowMaze(maze);
					
					Pop_Sq(&S, &info);//再返回上一块 
				} 
				
				if(info.direction<Up)//上一块有没有访问过的方向 
				{ 
					maze[info.pos.x][info.pos.y] = ++info.direction;//改变一次方向足迹 
					ShowMaze(maze);
					
					Push_Sq(&S, info); //信息压栈，以便回溯 
					curPos = NextPos(info.pos, info.direction);//探索下一步，这里不用判断终点，因为终点一定往右 
				}
			}
		}
	}while(!StackEmpty_Sq(S));
	
	printf("\n寻路失败！！\n");
	return 0;
}

void InitMaze(int maze[][15], MazePos *start, MazePos *end)
{
	srand((unsigned)time(NULL));    //生成随机数种子
	
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			if(i==0 || j==0 || i==14 || j==14)
				maze[i][j] = Wall;		//外墙设置
			else
			{
				int random = rand()%3;     //生成随机数填充迷宫
				if(!random) 
					maze[i][j] = Obstacle;//1/3的概率生成障碍 
				else
					maze[i][j] = Way;
			} 
		}
	} 
	
	(*start).x = 1;//设置入口坐标 
	(*start).y = 0;
	(*end).x = 13;//设置出口坐标 
	(*end).y = 14;
	
	maze[1][0] = maze[13][14] = Way;//开放出入口坐标
	maze[1][1] = maze[13][13] = Way;//开放出入口之前一个迷宫格的坐标，增加迷宫产生通路的几率 
	
}

void PaintMaze(int maze[][15])
{
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			if(maze[i][j]==Wall)
				printf("█");
			else if(maze[i][j]==Obstacle)
				printf("▓");
			else if(maze[i][j]==Right)
				printf("→");
			else if(maze[i][j]==Down)
				printf("↓");
			else if(maze[i][j]==Left)
				printf("←");
			else if(maze[i][j]==Up)
				printf("↑");
			else if(maze[i][j]==DeadLock)
		 		printf("★");
 			else
 				printf("  ");//未访问过 
 				
			if(j%14==0 && j!=0)//换行 
				printf("\n");
				
		}
	}
}

void ShowMaze(int maze[][15])
{
	Wait(2);//等待2秒钟 
	system("cls");//清除屏幕现有内容 
	PaintMaze(maze);//画出迷宫格 
}

int EqualMazePos(MazePos pos1, MazePos pos2)
{
	if(pos1.x==pos2.x && pos1.y==pos2.y)
		return 1;
	else
		return 0;
}

int CanPass(int maze[][15], MazePos pos)
{
	if(maze[pos.x][pos.y]==Way && !IsCross(pos))//节点是通路并且没有出界则未被访问，能通过 
		return 1;
	else
		return 0;
}

void FootPrint(int maze[][15], MazePos pos)//设置足迹就是设置当前迷宫块下次访问的方向箭头 
{
	maze[pos.x][pos.y] = Right;
}

void SetMazeInfo(MazeInfo *info, int order, MazePos pos, int direction)
{
	(*info).order = order;
	(*info).pos = pos;
	(*info).direction = direction;
}

MazePos NextPos(MazePos pos, int direction)
{
	MazePos tmp = pos;//不破坏当前坐标
	
	switch(direction)
	{
		case Right: tmp.y++;//列坐标+1，向右
			break;
		case Down: tmp.x++;//行坐标+1，向下
			break;
		case Left: tmp.y--;
			break;
		case Up: tmp.x--;
	} 
	return tmp;
}

int IsCross(MazePos pos)
{
	if(pos.x<0 || pos.x>14 || pos.y<0 || pos.y>14)
		return 1;
	else
		return 0;
}

void MarkPrint(int maze[][15], MazePos pos)
{
	maze[pos.x][pos.y] = DeadLock;
}


