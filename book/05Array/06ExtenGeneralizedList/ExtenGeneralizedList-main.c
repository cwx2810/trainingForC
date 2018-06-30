#include "ExtenGeneralizedList.c"

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
		InitGList_E(&G);
		printf("��ʼ���ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("GListEmpty����...\n");
	{
		int emp = GListEmpty_E(G);
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
		
		CreateGList_E(&G1, S1);
		CreateGList_E(&G2, S2);
		CreateGList_E(&G3, S3);
		printf("�����G1��G2��G3�����ɹ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("InsertFirst����...\n");
	{
		InsertFirst_E(&G, G3);
		InsertFirst_E(&G, G2);
		InsertFirst_E(&G, G1);
		printf("�Ѿ���G3��G2��G1���β��뵽G��ǰ��\n");
		printf("\n");
	}
	PressEnter;
	
	printf("TraverseGList����...\n");
	{
		printf("G = ");
		TraverseGList_E(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("Output����...\n");
	{
		printf("��������������G = ");
		Output_E(G);
		printf("\n");
	}
	PressEnter;
	
	printf("CopyGList����...\n");
	{
		CopyGList_E(&Tmp, G);
		printf("��ֵ�����G��Tmp = ");
		Output_E(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteFirst����...\n");
	{
		GLNode* h;
		DeleteFirst_E(&Tmp, &h);
		printf("ɾ�������Tmp�ı�ͷ��");
		Output_E(h);
		printf("\n");
		printf("��ʣTmp = ");
		Output_E(Tmp);
		printf("\n");
		
	}
	PressEnter;
	
	printf("GListLength����...\n");
	{
		printf("�����G�ĳ���Ϊ��%d\n", GListLength_E(G));
		printf("\n");
		
	}
	PressEnter;
	
	printf("GListDepth����...\n");
	{
		printf("�����G�����Ϊ��%d\n", GListDepth_E(G));
		printf("\n");
		
	}
	PressEnter;
	
	printf("GetHead����...\n");
	{
		
		GLNode* H;
		H = GetHead_E(G);
		printf("�����G�ı�ͷ H = ");
		Output_E(H);
		printf("\n");
	}
	PressEnter;
	
	printf("GetTail����...\n");
	{
		GLNode* T;
		
		T = GetTail_E(G);
		printf("�����G�ı�β T = ");
		Output_E(T);
		printf("\n");
	}
	PressEnter;
	
	printf("ClearGList����...\n");
	{
		DestroyGList_E(&G);
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
