#include "SequenceString.c"

int main(int argc, char **argv)
{
	char* chars = "abcdefg";
	char* t = "***";
	char* v = "^^^";
	SString S, Tmp, T, V, Sub;
	int i;
	
	printf("StrAssign测试...\n");
	{
		printf("初始化串Tmp\n");
		StrAssign_Sq(Tmp, chars);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrEmpty测试...\n");
	{
		StrEmpty_Sq(Tmp) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrLength测试...\n");
	{
		i = StrLength_Sq(Tmp);
		printf("Tmp的长度为：%d", i);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrPrint测试...\n");
	{
		printf("Tmp中的元素为：");
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrCopy测试...\n");
	{
		StrCopy_Sq(S, Tmp);
		printf("复制Tmp的元素到S，S中的元素为：");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrCompare测试...\n");
	{
		i = StrCompare_Sq(S, Tmp);
		if(i==0)
			printf("S = Tmp");
		else if(i>0)
			printf("S > Tmp");
		else
			printf("S < Tmp");
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrInsert测试...\n");
	{
		printf("将***赋值给T\n");
		StrAssign_Sq(T, t);
		printf("在S的第5个元素前插入T\n");
		StrInsert_Sq(S, 5, T);
		printf("S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("Index_Sq测试...\n");
	{
		i = Index_Sq(S, T, 1);
		printf("字符串***在S中从第1个字符起算第一次出现的位置是 %d", i);
		printf("\n\n");
	}
	PressEnter;
	
	printf("SubString测试...\n");
	{
		SubString_Sq(Sub, S, 5, 3);
		printf("返回S中第5个字符起的3个字符 Sub = ");
		StrPrint_Sq(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("Replace & Index_Match测试...\n");
	{
		printf("将^^^赋值给V\n");
		StrAssign_Sq(V, v);
		printf("用^^^替换S中的***\n");
		Replace_Sq(S, T, V);
		printf("S中的元素变为 S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrDelete测试...\n");
	{
		StrDelete_Sq(S, 5, 4);
		printf("删除S中第5个字符起的4个字符，S还剩 S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearString测试...\n");
	{
		ClearString_Sq(S);
		StrEmpty_Sq(S) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("Concat测试...\n");
	{
		Concat_Sq(Tmp, T, V);
		printf("连接T和V形成Tmp，Tmp = ");
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	
	
	return 0;
}

