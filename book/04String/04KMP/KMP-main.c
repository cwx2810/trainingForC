#include "KMP.c"

int main(int argc, char **argv)
{
	SString S,T;
	char* s = "abaaabcaabaabcacabaabcaabaabcac";
	char* t = "abaabcac";
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	
	int Tlength = StrLength_Sq(T);
	int next[Tlength+1];
	int nextval[Tlength+1];
	get_next(T, next);
	get_nextval(T, nextval);
	
	int pos = 1;
	int i1 = Index_KMP(S, T, pos, next);
	int i2 = Index_KMP(S, T, pos, nextval);
	
	printf("������");
	StrPrint_Sq(S);
	printf("\n");
	
	printf("ģʽ����");
	StrPrint_Sq(T);
	printf("\n");
	
	printf("next���飺");
	for(int i=1; i<=Tlength; i++)
		printf("%d", next[i]);
	printf("\n");
	
	printf("�ӵ�%d���ַ����һ��ƥ��ɹ���λ��Ϊi1 = %d\n", pos, i1);
	
	printf("�Ľ���next���飺");
	for(int i=1; i<=Tlength; i++)
		printf("%d", nextval[i]);
	printf("\n");
	
	printf("�ӵ�%d���ַ����һ��ƥ��ɹ���λ��Ϊi2 = %d\n", pos, i2);
	
	return 0;
}
