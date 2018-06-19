#include "Difference.h"

void Difference(int *L, int A[], int len_A, int B[], int len_B)
{
	InitSpace();
	*L = MallocSpace();//建立头结点，供录入AB不同的元素 
	int r = *L;//尾指针
	SPACE[r].pnext = 0;//避免尾指针的野指针 
	
	for(int i=0; i<len_A; i++)//录入A的所有元素到静态链表 
	{
		int p = MallocSpace();
		SPACE[p].data = A[i];//申请空间并录入A的值 
		SPACE[r].pnext = p;//把空间插入到尾指针后面
		r = p;//移动尾指针 
	} 
	SPACE[r].pnext = 0;//重新避免野指针
	
	for(int i=0; i<len_B; i++)
	{
		int p = *L;//p和pnext分别是头结点和第一个节点，他们是移动游标 
		int pnext = SPACE[*L].pnext;
		while(pnext && SPACE[pnext].data!=B[i])//遍历前面录入的A中的元素找B 
		{
			p = pnext;
			pnext = SPACE[pnext].pnext;
		}
		if(!pnext)//找不到B，则插入 
		{
			int q = MallocSpace();
			SPACE[q].data = B[i];
			SPACE[r].pnext = q;
			r = q;
		}
		else     //找到B，此时p为找到的相等元素的前一个，pnext为找到的相等元素，删除 
		{
			SPACE[p].pnext = SPACE[pnext].pnext;
			FreeSpace(pnext);
			
		}
	} 
	SPACE[r].pnext = 0;//重新避免野指针
	
}

