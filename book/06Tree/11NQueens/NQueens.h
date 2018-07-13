#include <stdio.h>
#include "../../01intro/Status.h"

#define N 8

int order;//全局变量，记录第order种解法



int InitChassBoard_CB(int c[N][N]);//初始化棋盘 

int Trial_CB(int i, int c[N][N]);//求8皇后问题各解，从第i行开始 

int Layout_CB(int x, int y, int c[N][N]);//判断在坐标x，y放入棋子是否合理，xy不是二维数组下标，是比其大1的行和列 

int Output_CB(int c[N][N]);//输出棋盘 
