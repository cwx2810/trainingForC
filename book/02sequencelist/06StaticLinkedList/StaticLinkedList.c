#include "StaticLinkedList.h"

void InitSpace()
{
	for(int i=0; i<999; i++)//空间地址编号从0~999，为什么从0开始，因为0号留给空闲指针 
							//指针编号从1~1000，0表示1000，为什么这样设置，因为NULL==0，把最后一个设为0好利用这个机制判断满了，在括号内可以写成L，而不用写成L!=1000 
		SPACE[i].pnext = i+1;
	SPACE[999].pnext = 0;
}

int MallocSpace()
{
	int pnext = SPACE[0].pnext;//得到空闲指针，第一次是第一个指针1 
	if(pnext)//如果申请的空间指针没到1000，也就是如果空间没有用完 
	{
		SPACE[0].pnext = SPACE[pnext].pnext;//申请成功，空闲指针向后面移动，图中体现为改变0号块的cur为2 
		return pnext;//返回申请到的指针值 
	} 
	else
		return 0;//申请失败 
}

void FreeSpace(int k)
{
	SPACE[k].pnext = SPACE[0].pnext;//要删除的节点k的游标存放空闲指针的游标 
	SPACE[0].pnext = k;//空闲指针的游标变为k，下次申请先往这里填
	//这里只有指针的变化，没有data的释放 
}



int InitList_SL(int *L)//声明头结点指针 
{
	*L = MallocSpace();//*L为取到头结点，为头结点分配空间，实际上图中就是得到一个地址值1
	if(!(*L))		  //空间已满
		return 0;
	SPACE[*L].pnext = 0;//避免野指针，头结点的指针置空，实际上图中就是把头结点指针变为了0 
	return 1; 
}

int ClearList_SL(int L)//L声明头结点，但不能对头结点修改，其实就是传入一个地址值，让其为头结点，比如1 
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;//得到头结点游标值，赋值给p，表示p代表头结点的next，也就是p是第一个节点 
	while(p) 
	{
		SPACE[L].pnext = SPACE[p].pnext;//头结点指向下下个节点，也就是第二个节点 
		FreeSpace(p);//释放第一个节点 
		p = SPACE[L].pnext;//p继续表示下下个节点 
	}
	return 1;
}

int DestroyList_SL(int *L)
{
	ClearList_SL(*L);//*L表示取到头结点，实际上在图中就是得到地址值1 
	FreeSpace(*L);
	*L = 0;//这个0在图上表示游标置空，不看图干想根本没有意义 
}

int ListEmpty_SL(int L)
{
	if(L && !SPACE[L].pnext)//L表示不可修改的头结点，就是1，L==1 && SPACE[L].pnext==0，想图，只有头结点的情况 
		return 1;
	else
		return 0;
}

int ListLength_SL(int L)
{
	if(!L)
		return 0;
	int count = 0;
	int p = SPACE[L].pnext;//p表示第一个节点 
	while(p)
	{
		count++;
		p = SPACE[p].pnext;
	}
	return count;
}

int GetElem_SL(int L, int i, int *e)
{
	if(!L || i<1 || i>998)
		return 0;
	int count = 0;
	int p = SPACE[L].pnext;
	while(p)
	{
		count++;
		if(count==i)
		{
			*e = SPACE[p].data;
			return 1;
		}
		p = SPACE[p].pnext;
	}
}

int LocateElem_SL(int L, int e)
{
	if(!L)
		return 0;
	int count = 1;
	int p = SPACE[L].pnext;
	while(p && SPACE[p].data!=e)
	{
		count++;
		p = SPACE[p].pnext;
	}
	if(p)
		return count;
	return 0;
}

int PriorElem_SL(int L, int cur_e, int *pre_e)
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	if(SPACE[p].data!=cur_e)//第一个节点不能是当前节点，因为没有前驱 
	{
		while(SPACE[p].pnext)//第二个节点 
		{
			int q = SPACE[p].pnext;//抽象一下，下面好写 
			if(SPACE[q].data==cur_e)
			{
				*pre_e = SPACE[p].data;
				return 1;
			}
			p = SPACE[p].pnext;//往后遍历寻找 
		}
	}
	return 0;
}

int NextElem_SL(int L, int cur_e, int *next_e)
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	while(SPACE[p].pnext)
	{
		if(SPACE[p].data==cur_e)
		{
			int q = SPACE[p].pnext;
			*next_e = SPACE[q].data;
			return 1;
		}
		p = SPACE[p].pnext;
	}
	return 0;
}

int ListInsert_SL(int L, int i, int e)
{
	int p = L;
	int j = 1;
	while(p && j<i)
	{
		p = SPACE[p].pnext;
		j++;
	}
	if(!p || j>i)//以上是检查合法性，最终找到了p，即插入位置 
		return 0;
		
	int s = MallocSpace();//建立存储结构，保存小e 
	if(!s)
		return 0;
	SPACE[s].data = e;
	SPACE[s].pnext = SPACE[p].pnext;
	SPACE[p].pnext = s;
	return 1;
}

int ListDelete_SL(int L, int i, int *e)
{
	if(!L)
		return 0;
	int pre = L;
	int j = 1;
	while(SPACE[pre].pnext && j<i)
	{
		pre = SPACE[pre].pnext;
		j++;
	}
	if(!SPACE[pre].pnext || j>i)
		return 0;
		
	int p = SPACE[pre].pnext;
	*e = SPACE[p].data;
	int tmp = SPACE[pre].pnext;
	SPACE[pre].pnext = SPACE[tmp].pnext;
	FreeSpace(p);
	return 1;
}

int ListTraverse_SL(int L, void(Visit)(int))
{
	if(!L)
		return 0;
	int p = SPACE[L].pnext;
	while(p)
	{
		Visit(SPACE[p].data);
		p = SPACE[p].pnext;
	}	
	return 1;
}


