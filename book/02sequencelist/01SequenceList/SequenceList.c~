#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

Status InitList_Sq(SqList *L)
{
	(*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW);
	
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	
	return OK;
}



#endif
