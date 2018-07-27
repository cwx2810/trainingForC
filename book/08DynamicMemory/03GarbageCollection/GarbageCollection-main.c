#include "GarbageCollection.c"

int Traverse(GLNode* L, void(Visit)(GLNode*));

void print(GLNode* L);


int main(int argc, char** argv)
{
	GLNode* G;
	
	printf("��������������\n");
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
	
	printf("����MakeList����\n");
	{
		printf("����ǰ�ı�־״̬��\n");
		Traverse(G, print);
		printf("\n");
		
		PressEnter;
		
		MakeList(G);
		printf("���ʺ�ı�־״̬��\n");
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
		printf("mark = %d ԭ�ӽڵ㣺%c\n", L->mark, L->Union.atom);
	else
		printf("mark = %d ��ڵ�\n", L->mark);
}

