#include "GarbageCollection.c"

int Traverse(GLNode* L, void(Visit)(GLNode*));

void print(GLNode* L);


int main(int argc, char** argv)
{
	GLNode* G;
	
	printf("创建并输出广义表\n");
	{
		SString S;
		char* s = "((),(e),(a,(b,c,d)))";
		
		StrAssign_Sq(S, s);
		InitGList_HT(&G);
		CreateGList_HT(&G, S);
		Output_HT(G, Head);
		printf("\n");
	}
	PressEnter;
	
	printf("函数MakeList测试\n");
	{
		printf("访问前的标志状态：\n");
		Traverse(G, print);
		printf("\n");
		
		PressEnter;
		
		MakeList(G);
		printf("访问后的标志状态：\n");
		Traverse(G, print);
		printf("\n");
	}
	PressEnter;
	
	
	return 0;
}

int Traverse(GLNode* L, void(Visit)(GLNode*))
{
	if(L)
	{
		Visit(L);
		if(L->type==List)
		{
			Traverse(L->Union.ptr.hp, Visit);
			Traverse(L->Union.ptr.tp, Visit);
		}
	}
	return 1;
}

void print(GLNode* L)
{
	if(L->type==Atom)
		printf("mark = %d 原子节点：%c\n", L->mark, L->Union.atom);
	else
		printf("mark = %d 表节点\n", L->mark);
}

