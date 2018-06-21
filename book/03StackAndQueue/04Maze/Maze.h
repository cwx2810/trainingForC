#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../01intro/Status.h"

typedef enum        //�Թ���ö�� 
{
	Wall,
	Obstacle,
	Way,
	DeadLock,
	Right,Down,Left,Up
}MazeEnum;

typedef struct      //�Թ������� 
{
	int x;
	int y;
}MazePos;

typedef struct       //�Թ�����Ϣ 
{
	int order;
	MazePos pos;
	int direction;
}MazeInfo;



typedef struct{      //�Թ����õĻ���ջ 
	MazeInfo *base;
	MazeInfo *top;
	int stacksize;
}SqStack;

int InitStack_Sq(SqStack *S);

int StackEmpty_Sq(SqStack S);

int Push_Sq(SqStack *S, MazeInfo e);

int Pop_Sq(SqStack *S, MazeInfo *e);



int MazePath(int maze[][15], MazePos start, MazePos end);//�Թ�Ѱ·�㷨 

void InitMaze(int maze[][15], MazePos *start, MazePos *end);//��ʼ���Թ� 

void PaintMaze(int maze[][15]);//�����Թ� 

void ShowMaze(int maze[][15]);//��ʾ�Թ� 

int EqualMazePos(MazePos pos1, MazePos pos2);//�Ƚ����꣬�ó��������ǲ���ͬһ���� 

int CanPass(int maze[][15], MazePos pos);//�Թ����Ƿ��ͨ�������ǻ�û���ʹ� 

void FootPrint(int maze[][15], MazePos pos); //���δ���ʹ����������㼣

void SetMazeInfo(MazeInfo *info, int order, MazePos pos, int direction);//�����Թ�����Ϣ 

MazePos NextPos(MazePos pos, int direction);//��ǰ�Թ���ĺ��

int IsCross(MazePos pos);//�ж��Ƿ�Խ�磬���ǳɹ��߳��Թ�

void MarkPrint(int maze[][15], MazePos pos);//��ǵ�ǰ�Թ��鲻�ɷ���

 

