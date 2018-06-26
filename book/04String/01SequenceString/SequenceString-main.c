#include "SequenceString.c"

int main(int argc, char **argv)
{
	char* chars = "abcdefg";
	char* t = "***";
	char* v = "^^^";
	SString S, Tmp, T, V, Sub;
	int i;
	
	printf("StrAssign����...\n");
	{
		printf("��ʼ����Tmp\n");
		StrAssign_Sq(Tmp, chars);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrEmpty����...\n");
	{
		StrEmpty_Sq(Tmp) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrLength����...\n");
	{
		i = StrLength_Sq(Tmp);
		printf("Tmp�ĳ���Ϊ��%d", i);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrPrint����...\n");
	{
		printf("Tmp�е�Ԫ��Ϊ��");
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrCopy����...\n");
	{
		StrCopy_Sq(S, Tmp);
		printf("����Tmp��Ԫ�ص�S��S�е�Ԫ��Ϊ��");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrCompare����...\n");
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
	
	printf("StrInsert����...\n");
	{
		printf("��***��ֵ��T\n");
		StrAssign_Sq(T, t);
		printf("��S�ĵ�5��Ԫ��ǰ����T\n");
		StrInsert_Sq(S, 5, T);
		printf("S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("Index_Sq����...\n");
	{
		i = Index_Sq(S, T, 1);
		printf("�ַ���***��S�дӵ�1���ַ������һ�γ��ֵ�λ���� %d", i);
		printf("\n\n");
	}
	PressEnter;
	
	printf("SubString����...\n");
	{
		SubString_Sq(Sub, S, 5, 3);
		printf("����S�е�5���ַ����3���ַ� Sub = ");
		StrPrint_Sq(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("Replace & Index_Match����...\n");
	{
		printf("��^^^��ֵ��V\n");
		StrAssign_Sq(V, v);
		printf("��^^^�滻S�е�***\n");
		Replace_Sq(S, T, V);
		printf("S�е�Ԫ�ر�Ϊ S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StrDelete����...\n");
	{
		StrDelete_Sq(S, 5, 4);
		printf("ɾ��S�е�5���ַ����4���ַ���S��ʣ S = ");
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearString����...\n");
	{
		ClearString_Sq(S);
		StrEmpty_Sq(S) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("Concat����...\n");
	{
		Concat_Sq(Tmp, T, V);
		printf("����T��V�γ�Tmp��Tmp = ");
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	
	
	return 0;
}

