#include "StaticLinkedList.h"

void InitSpace()
{
	for(int i=0; i<99; i++)//空间小块编号从0~99，指针编号从1~100，0表示100 
		SPACE[i].cur = i+1;
	SPACE[99].cur = 0;
}

int MallocSpace()
{
	int cur = SPACE[0].cur;//初始化想要申请的节点的指针为空间的当前空闲指针，第一次是第一个指针 
	if(cur!=0)//如果申请的空间指针没到100，也就是如果空间没有用完 
	{
		SPACE[0].cur = SPACE[cur].cur;//申请成功，空闲指针向后面移动，体现为改变指针的值
		return cur;//返回申请到的指针值 
	} 
	else
		return 0;//申请失败 
}

void FreeSpace(int k)
{
	SPACE[k].cur = SPACE[0].cur;//第k个节点的指针变为空闲指针，插队，下次先往这里申请 
	SPACE[0].cur = k;//之前的空闲指针变成k 
}

int InitList_SL(int *L)//声明头结点指针 
{
	*L = MallocSpace();//*L为取到头结点，为头结点分配空间，实际上就是得到一个游标值
	if((*L)==0)		  //空间已满
		return 0;
	SPACE[*L].cur = 0;//避免野指针，头结点置空 
	return 1; 
}




