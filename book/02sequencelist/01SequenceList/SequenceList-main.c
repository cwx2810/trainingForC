/*���Ա�����ļ�*/

#include <stdio.h>
#include "SequenceList.c"

int main(int argc, char **argv)
{
	SqList L;
	int i;
	LElemType_Sq e;
	
	printf("InitList����...\n");
	{
		printf("��ʼ��˳���\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
