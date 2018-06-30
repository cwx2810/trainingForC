#include "GeneralizedListHT.c"
void PrintElem(char e);

int main(int argc, char **argv)
{
	GLNode* G;
	GLNode* Tmp;
	GLNode* G1;
	GLNode* G2;
	GLNode* G3;
	SString S1, S2, S3;
	
	printf("InitGList����...\n");
	{
		InitGList_HT(&G);
		printf("��ʼ���ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("GListEmpty����...\n");
	{
		int emp = GListEmpty_HT(G);
		emp ? printf("GΪ��\n") : printf("G��Ϊ��\n");
		printf("\n");
	}
	PressEnter;
	
	printf("sever,CreateGList����...\n");
	{
		char* s1 = "()";
		char* s2 = "(e)";
		char* s3 = "(a,(b,c,d))";
		
		StrAssign_Sq(S1, s1);
		StrAssign_Sq(S2, s2);
		StrAssign_Sq(S3, s3);
		
		CreateGList_HT(&G1, S1);
		CreateGList_HT(&G2, S2);
		CreateGList_HT(&G3, S3);
		
		printf("�����G1��G2��G3�����ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("InsertFirst����...\n");
	{
		InsertFirst_HT(&G, G3);
		InsertFirst_HT(&G, G2);
		InsertFirst_HT(&G, G1);
		printf("�Ѿ���G3��G2��G1���β��뵽G��ǰ��\n");
		printf("\n");
	}
	PressEnter;
	
	printf("TraverseGList����...\n");
	{
		printf("G = ");
		Traverse_HT(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("Output����...\n");
	{
		printf("��������������G = ");
		Output_HT(G, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("CopyGList����...\n");
	{
		CopyGList_HT(&Tmp, G);
		printf("��ֵ�����G��Tmp = ");
		Output_HT(Tmp, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteFirst����...\n");
	{
		GLNode* h;
		DeleteFirst_HT(&Tmp, &h);
		printf("ɾ�������Tmp�ı�ͷ��");
		Output_HT(h, Head);
		printf("\n");
		printf("��ʣTmp = ");
		Output_HT(Tmp, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("GListLength����...\n");
	{
		printf("�����G�ĳ���Ϊ��%d\n", GListLength_HT(G));
		printf("\n");
	}
	PressEnter;
	
	printf("GListDepth����...\n");
	{
		printf("�����G�����Ϊ��%d\n", GListDepth_HT(G));
		printf("\n");
	}
	PressEnter;
	
	printf("GetHead����...\n");
	{
		GLNode* H;
		H = GetHead_HT(G);
		printf("�����G�ı�ͷ H = ");
		Output_HT(H, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("GetTail����...\n");
	{
		GLNode* T;
		T = GetTail_HT(G);
		printf("�����G�ı�β T = ");
		Output_HT(T, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("ClearGList����...\n");
	{
		ClearGList_HT(&G);
		G ? printf("G����") : printf("G������");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char e)
{
	printf("%d ", e);
}
