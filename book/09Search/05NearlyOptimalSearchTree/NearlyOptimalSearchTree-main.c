#include "NearlyOptimalSearchTree.c"

void Print(ElemType e);

int main(int argc, char** argv)
{
	Table T;
	BiTNode* BT;
	
	printf("创建并输出一个查找表\n");
	{
		FILE* fp = fopen("TestDataTable.txt", "r");
		CreateTable(fp, &T, 10);
		TraverseTable(T, Print);
		printf("\n");
	}
	PressEnter;
	
	printf("创建次优查找树\n");
	{
		CreateNearlyOptimal(&BT, T);
		PrintTree(BT);
		printf("\n");
	}
	PressEnter;
	
	printf("SearchKey测试\n");
	{
		printf("关键字%c", ch[3]);
		SearchKey(BT, 3) ? printf("在次优查找树中") : printf("不在次优查找树中");
		printf("\n");
	}
	PressEnter;
	
	
	
	return 0;
}

void Print(ElemType e)
{
	printf("(%c, %.1f) ", ch[e.key], e.weight);
}
