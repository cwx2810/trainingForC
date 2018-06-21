#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../01intro/Status.h"

typedef enum        //迷宫块枚举 
{
	Wall,
	Obstacle,
	Way,
	DeadLock,
	Right,Down,Left,Up
}MazeEnum;

typedef struct      //迷宫块坐标 
{
	int x;
	int y;
}MazePos;

typedef struct       //迷宫块信息 
{
	int order;
	MazePos pos;
	int direction;
}MazeInfo;



typedef struct{      //迷宫利用的回溯栈 
	MazeInfo *base;
	MazeInfo *top;
	int stacksize;
}SqStack;

int InitStack_Sq(SqStack *S);

int StackEmpty_Sq(SqStack S);

int Push_Sq(SqStack *S, MazeInfo e);

int Pop_Sq(SqStack *S, MazeInfo *e);



int MazePath(int maze[][15], MazePos start, MazePos end);//迷宫寻路算法 

void InitMaze(int maze[][15], MazePos *start, MazePos *end);//初始化迷宫 

void PaintMaze(int maze[][15]);//绘制迷宫 

void ShowMaze(int maze[][15]);//显示迷宫 

int EqualMazePos(MazePos pos1, MazePos pos2);//比较坐标，得出两个块是不是同一个块 

int CanPass(int maze[][15], MazePos pos);//迷宫块是否可通过，就是还没访问过 

void FootPrint(int maze[][15], MazePos pos); //如果未访问过，就留下足迹

void SetMazeInfo(MazeInfo *info, int order, MazePos pos, int direction);//更新迷宫块信息 

MazePos NextPos(MazePos pos, int direction);//当前迷宫块的后继

int IsCross(MazePos pos);//判断是否越界，就是成功走出迷宫

void MarkPrint(int maze[][15], MazePos pos);//标记当前迷宫块不可访问

 

