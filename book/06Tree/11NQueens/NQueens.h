#include <stdio.h>
#include "../../01intro/Status.h"

#define N 8

int order;//ȫ�ֱ�������¼��order�ֽⷨ



int InitChassBoard_CB(int c[N][N]);//��ʼ������ 

int Trial_CB(int i, int c[N][N]);//��8�ʺ�������⣬�ӵ�i�п�ʼ 

int Layout_CB(int x, int y, int c[N][N]);//�ж�������x��y���������Ƿ����xy���Ƕ�ά�����±꣬�Ǳ����1���к��� 

int Output_CB(int c[N][N]);//������� 
