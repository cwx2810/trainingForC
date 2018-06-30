#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../01intro/Status.h"
#include "../../04String/01SequenceString/SequenceString.c"

typedef enum
{
	Atom,List
}NodeType;

typedef struct GLNode
{
	NodeType type;
	union
	{
		char atom;
		struct GLNode *hp;
	}Union;
	struct GLNode *tp;//Ïàµ±ÓÚnext 
}GLNode;

int InitGList_E(GLNode **L);

int sever_E(SString hstr, SString str);

int CreateGList_E(GLNode **L, SString S);

int DestroyGList_E(GLNode **L);

int CopyGList_E(GLNode **L, GLNode* T);

int GListLength_E(GLNode* L);

int GListDepth_E(GLNode* L);

int GListEmpty_E(GLNode* L);

GLNode* GetHead_E(GLNode* L);

GLNode* GetTail_E(GLNode* L);

int InsertFirst_E(GLNode **L, GLNode* e);

int DeleteFirst_E(GLNode **L, GLNode **e);

int TraverseGList_E(GLNode* L, void(Visit)(char));

int Output_E(GLNode* L);
