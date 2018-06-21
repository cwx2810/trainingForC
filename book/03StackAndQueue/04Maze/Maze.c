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
	
	*((*S).top) = e;//Ϊʲô��ջ�ȸ�ֵ����ͼ��top�������һ��Ԫ�ص�β����Ҳ�����¸�Ԫ�ص�ͷ�� 
	(*S).top++;
	return 1;
}

int Pop_Sq(SqStack *S, MazeInfo *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;//Ϊʲô�ȵݼ�ָ�룬��ͼ������ȸ�ֵ�ˣ���top��ʱ��û�������ˣ��ǿյ�β�� 
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
	curPos = start;//���õ�ǰ�Թ�������Ϊ��� 
	curOrder = 1;//���õ�ǰ�Թ�����Ϊ1 
	
	do
	{
		if(CanPass(maze, curPos))//��ǰ����δ���ʹ���ȫ�ǳ�ʼ������ 
		{
			FootPrint(maze, curPos);//��ʼ�����·����㼣 
			ShowMaze(maze);
			SetMazeInfo(&info, curOrder, curPos, Right);//��ʼ�������Թ�����Ϣ 
			Push_Sq(&S, info);			//��Ϣѹջ���Ա����
			
			if(EqualMazePos(curPos, end))//�����յ� 
			{
				printf("\nѰ·�ɹ�����\n");
				return 1;
			}
			else
			{
				curPos = NextPos(info.pos, info.direction);//û���յ㣬̽����һ�� 
				curOrder++;
			}
			
			
		}
		else					//��ǰ������ʹ������ݻ����� 
		{
			if(!StackEmpty_Sq(S))//ջ�����Թ��飬���Ի��� 
			{
				Pop_Sq(&S, &info);//����һ�� 
				
				while(info.direction==Up && !StackEmpty_Sq(S))//��һ�����涼���ʹ��ˣ����ٻص���һ�飬Ĭ��˳ʱ����� 
				{
					MarkPrint(maze, info.pos);//���ô�·��ͨ 
					ShowMaze(maze);
					
					Pop_Sq(&S, &info);//�ٷ�����һ�� 
				} 
				
				if(info.direction<Up)//��һ����û�з��ʹ��ķ��� 
				{ 
					maze[info.pos.x][info.pos.y] = ++info.direction;//�ı�һ�η����㼣 
					ShowMaze(maze);
					
					Push_Sq(&S, info); //��Ϣѹջ���Ա���� 
					curPos = NextPos(info.pos, info.direction);//̽����һ�������ﲻ���ж��յ㣬��Ϊ�յ�һ������ 
				}
			}
		}
	}while(!StackEmpty_Sq(S));
	
	printf("\nѰ·ʧ�ܣ���\n");
	return 0;
}

void InitMaze(int maze[][15], MazePos *start, MazePos *end)
{
	srand((unsigned)time(NULL));    //�������������
	
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			if(i==0 || j==0 || i==14 || j==14)
				maze[i][j] = Wall;		//��ǽ����
			else
			{
				int random = rand()%3;     //�������������Թ�
				if(!random) 
					maze[i][j] = Obstacle;//1/3�ĸ��������ϰ� 
				else
					maze[i][j] = Way;
			} 
		}
	} 
	
	(*start).x = 1;//����������� 
	(*start).y = 0;
	(*end).x = 13;//���ó������� 
	(*end).y = 14;
	
	maze[1][0] = maze[13][14] = Way;//���ų��������
	maze[1][1] = maze[13][13] = Way;//���ų����֮ǰһ���Թ�������꣬�����Թ�����ͨ·�ļ��� 
	
}

void PaintMaze(int maze[][15])
{
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			if(maze[i][j]==Wall)
				printf("��");
			else if(maze[i][j]==Obstacle)
				printf("��");
			else if(maze[i][j]==Right)
				printf("��");
			else if(maze[i][j]==Down)
				printf("��");
			else if(maze[i][j]==Left)
				printf("��");
			else if(maze[i][j]==Up)
				printf("��");
			else if(maze[i][j]==DeadLock)
		 		printf("��");
 			else
 				printf("  ");//δ���ʹ� 
 				
			if(j%14==0 && j!=0)//���� 
				printf("\n");
				
		}
	}
}

void ShowMaze(int maze[][15])
{
	Wait(2);//�ȴ�2���� 
	system("cls");//�����Ļ�������� 
	PaintMaze(maze);//�����Թ��� 
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
	if(maze[pos.x][pos.y]==Way && !IsCross(pos))//�ڵ���ͨ·����û�г�����δ�����ʣ���ͨ�� 
		return 1;
	else
		return 0;
}

void FootPrint(int maze[][15], MazePos pos)//�����㼣�������õ�ǰ�Թ����´η��ʵķ����ͷ 
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
	MazePos tmp = pos;//���ƻ���ǰ����
	
	switch(direction)
	{
		case Right: tmp.y++;//������+1������
			break;
		case Down: tmp.x++;//������+1������
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


