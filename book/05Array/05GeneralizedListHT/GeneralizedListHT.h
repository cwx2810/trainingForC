#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../04String/01SequenceString/SequenceString.c"

typedef enum
{
	Head, Tail//广义表的头尾枚举 
}Mark;
typedef enum
{
	Atom, List//广义表的节点类型枚举，Atom=0是原子节点，List=1是表节点 
}NodeType;

typedef struct GLNode
{
	union
	{
		int mark;//匿名联合，在第八章遍历广义表中使用 
	};
	
	NodeType type;//区分节点类型
	
	union
	{
		char atom;//原子节点的值域
		struct
		{
			struct GLNode* hp;//广义表节点头指针，指向头结点 
			struct GLNode* tp;//尾指针，指向表节点 
		}ptr; //指针域 
	}Union; 			//这个联合体代表了三个小方块的节点 
	
}GLNode;				//这个结构体代表了整个广义链表 

int InitGList_HT(GLNode **L);

int sever_GL(SString hstr, SString str);//将字符串分割成两部分，标志是逗号，逗号前是第一部分，其实就是分割头和表 

int CreateGList_HT(GLNode **L, SString S);//由字符串创建广义表

int ClearGList_HT(GLNode **L);//只能清空，不能销毁 

int CopyGList_HT(GLNode **L, GLNode* T);

int GListLength_HT(GLNode* L);

int GListDepth_HT(GLNode* L);

int GListEmpty_HT(GLNode* L);

GLNode* GetHead_HT(GLNode* L);

GLNode* GetTail_HT(GLNode* L);

int InsertFirst_HT(GLNode **L, GLNode* e);

int DeleteFirst_HT(GLNode **L, GLNode **e);

int Traverse_HT(GLNode* L, void(Visit)(char));

int Output_HT(GLNode* L, Mark mark); 
