#include "GeneralizedListHT.c"

int main(int arvc, char **argv)
{
	printf("CreateGListœÍœ∏≤‚ ‘...\n");
	{
		char* ch = "(a,(b,c,d))";
		GLNode* G;
		SString S;
		StrAssign_Sq(S, ch);
		CreateGList_HT(&G, S);
		printf("G = ");
		Output_HT(G, Head);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
