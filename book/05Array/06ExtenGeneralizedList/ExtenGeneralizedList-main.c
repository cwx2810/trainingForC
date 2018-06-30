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
	
	printf("InitGList测试...\n");
	{
		InitGList_E(&G);
		printf("初始化成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("GListEmpty测试...\n");
	{
		int emp = GListEmpty_E(G);
		emp ? printf("G为空\n") : printf("G不为空\n");
		printf("\n");
	}
	PressEnter;
	
	printf("sever,CreateGList测试...\n");
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
		printf("广义表G1、G2、G3创建成功\n");
		printf("\n");
	}
	PressEnter;
	
	printf("InsertFirst测试...\n");
	{
		InsertFirst_E(&G, G3);
		InsertFirst_E(&G, G2);
		InsertFirst_E(&G, G1);
		printf("已经将G3、G2、G1依次插入到G的前面\n");
		printf("\n");
	}
	PressEnter;
	
	printf("TraverseGList测试...\n");
	{
		printf("G = ");
		TraverseGList_E(G, PrintElem);
		printf("\n");
	}
	PressEnter;
	
	printf("Output测试...\n");
	{
		printf("带符号输出广义表G = ");
		Output_E(G);
		printf("\n");
	}
	PressEnter;
	
	printf("CopyGList测试...\n");
	{
		CopyGList_E(&Tmp, G);
		printf("赋值广义表G到Tmp = ");
		Output_E(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("DeleteFirst测试...\n");
	{
		GLNode* h;
		DeleteFirst_E(&Tmp, &h);
		printf("删除广义表Tmp的表头：");
		Output_E(h);
		printf("\n");
		printf("还剩Tmp = ");
		Output_E(Tmp);
		printf("\n");
		
	}
	PressEnter;
	
	printf("GListLength测试...\n");
	{
		printf("广义表G的长度为：%d\n", GListLength_E(G));
		printf("\n");
		
	}
	PressEnter;
	
	printf("GListDepth测试...\n");
	{
		printf("广义表G的深度为：%d\n", GListDepth_E(G));
		printf("\n");
		
	}
	PressEnter;
	
	printf("GetHead测试...\n");
	{
		
		GLNode* H;
		H = GetHead_E(G);
		printf("广义表G的表头 H = ");
		Output_E(H);
		printf("\n");
	}
	PressEnter;
	
	printf("GetTail测试...\n");
	{
		GLNode* T;
		
		T = GetTail_E(G);
		printf("广义表G的表尾 T = ");
		Output_E(T);
		printf("\n");
	}
	PressEnter;
	
	printf("ClearGList测试...\n");
	{
		DestroyGList_E(&G);
		G ? printf("G存在") : printf("G不存在");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(char e)
{
	printf("%d ", e);
}
