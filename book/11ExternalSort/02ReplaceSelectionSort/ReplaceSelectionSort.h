#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct
{
	int key;
}RecordType;//��¼���� 

typedef struct
{
	RecordType rec;//��¼ 
	int key;//�Ӽ�¼�г�ȡ�Ĺؼ��� 
	int num;//�����鲢�εĶκ� 
}RecordNode;//�ڴ湤���� 

int originalpart;//�θ��� 
int maxNumber;//wa���������κ� 
int currentNumber;//��ǰ�κ� 

int Replace_Selection(FILE* fp_in, int ls[6], RecordNode wa[6]);
//�ڰ�����ls���ڴ湤����wa�����û�ѡ���������ʼ�鲢��

int get_run(FILE* fp_in, FILE* fp_out, int ls[6], RecordNode wa[6]);
//���һ����ʼ�鲢��

int Select_MiniMax(int ls[6], RecordNode wa[6], int p);
//��wa[p]��ʼ���������ĸ��Ƚ�ѡ���¼����pָ����

int Construct_Loser(FILE* fp_in, int ls[6], RecordNode wa[6]);
//�����¼���ڴ湤����wa������������ls��ѡ����С��¼����pָʾ����wa�е�λ�� 
