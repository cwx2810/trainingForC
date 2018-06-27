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
	
	printf("主串：");
	StrPrint_Sq(S);
	printf("\n");
	
	printf("模式串：");
	StrPrint_Sq(T);
	printf("\n");
	
	printf("next数组：");
	for(int i=1; i<=Tlength; i++)
		printf("%d", next[i]);
	printf("\n");
	
	printf("从第%d个字符起第一次匹配成功的位置为i1 = %d\n", pos, i1);
	
	printf("改进的next数组：");
	for(int i=1; i<=Tlength; i++)
		printf("%d", nextval[i]);
	printf("\n");
	
	printf("从第%d个字符起第一次匹配成功的位置为i2 = %d\n", pos, i2);
	
	return 0;
}
