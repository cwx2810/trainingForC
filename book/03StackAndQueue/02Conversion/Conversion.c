#include "Conversion.h"

void Conversion(int i)
{
	SqStack S;
	int e;
	
	InitStack_Sq(&S);
	
	printf("ʮ������ %d ת��Ϊ�˽�����Ϊ 0", i);
	
	while(i)//ջ�б������� 
	{
		Push_Sq(&S, i%8);
		i = i/8;
	}
	
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);
		printf("%d", e);
	}
	
}

