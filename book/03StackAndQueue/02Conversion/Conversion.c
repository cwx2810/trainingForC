#include "Conversion.h"

void Conversion(int i)
{
	SqStack S;
	int e;
	
	InitStack_Sq(&S);
	
	printf("十进制数 %d 转换为八进制数为 0", i);
	
	while(i)//栈中保存余数 
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

