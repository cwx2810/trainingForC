/*线性表测试文件*/

#include <stdio.h>
#include "SequenceList.c"

int main(int argc, char **argv)
{
	SqList L;
	int i;
	LElemType_Sq e;
	
	printf("InitList测试...\n");
	{
		printf("初始化顺序表\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
