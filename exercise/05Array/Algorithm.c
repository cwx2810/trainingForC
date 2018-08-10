#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/04String/01SequenceString/SequenceString.h"
#include "../../book/05Array/05GeneralizedListHT/GeneralizedListHT.h"
#include "../../book/05Array/06ExtenGeneralizedList/ExtenGeneralizedList.h"

//将数组a[n]中的元素循环右移move个位置，只用1个元素的多余空间，移动或交换次数不超过O(n) 
void ArrayRightMove(int a[], int n, int move)
{
	int realMove = move%n;//实际循环右移的位数，因为是循环，所以超过n的倍数没用，只会移动余数个位置
	
	//右移个数不为0的情况下，递归移动，直接想不好想，自己画一个1到10的数组，移动一下就懂了 
	if(realMove)
	{
		Reversal(a, n, 1, n);
		Reversal(a, n, 1, realMove);
		Reversal(a, n, realMove+1, n);
	} 
}
//逆置数组a[n]中第start到第end之间的元素 
int Reversal(int a[], int n, int start, int end)
{
	int e;//只用1个元素空间
	if(start<1 || end>n || start>end)
		return 0;
	else
	{
		for(int i=0; i<=(end-start+1)/2; i++)//寻找中点，然后前后交换逆置 
		{
			e = a[end=i-1];
			a[end-i-1] = a[start+i-1];
			a[start+i-1] = e;
		}
	}
	return 1; 
}









//寻找二维数组中的所有马鞍点，马鞍点就是每一行中的最小元素，同时这个元素是它那一列的最大元素
typedef struct
{
	int x;
	int y;
	int value;
}Node;

//从矩阵a中找出马鞍点存储到node中 
int SaddlePoint(int a[256][256], int row, int col, Node node[256])
{
	Node minRow[256];
	node[0].value = 0;
	for(int i=0; i<row; i++)
	{
		MinRow(a, col, i, minRow);//找出每行最小元素 
		for(int j=1; j<=minRow[0].value; j++)//遍历最小元素，判断该元素是不是它那一列的最大元素 
		{
			if(IsMaxCol(a, row, minRow[j]))
			{
				node[0].value++;
				node[node[0].value] = minRow[j];
			}
		}
	}
	
	if(node[0].value)//有马鞍点 
		return 1;
	else
		return 0;
}
//找出矩阵a中的第i行的最小元素 
void MinRow(int a[256][256], int col, int i, Node minRow[256])
{
	minRow[0].value = 0;//0号元素存放最小元素个数
	for(int j=0; j<col; j++)
	{
		if(!j || a[i][j]==minRow[j-1].value)//第一个元素或者是相等的最小元素，最小元素数量增加 
			minRow[0].value++;
		else
		{
			if(a[i][j] < minRow[j-1].value)//找到了更小的，则最小元素数量重新归1 
				minRow[0].value = 1;
			else							//找到了大元素，没有影响，继续循环 
				continue;
		}
		//将最小元素保存进数组 
		minRow[minRow[0].value].x = i;
		minRow[minRow[0].value].y = j;
		minRow[minRow[0].value].value = a[i][j];
	} 
}
int IsMaxCol(int a[256][256], int row, Node minRow)
{
	for(int i=; i<=row; i++)
	{
		if(a[i][minRow.y] > minRow.value)//每行最小元素不是那一列的最大元素，则不是马鞍点 
			return 0;
	}
	return 1;
}

 
 
 
//头尾链和扩展线性链表的区别是：头尾链中第一层是平行连接的，扩展线性链表是通过next阶梯连接的 
//求广义表深度方法2（头尾链存储）
int GListDepth_HT_2(GLNode* L)
{
	if(!L)
		return 1;//空表深度为1
	if(L->type == Atom)
		return 0;//原子深度为0
	int head = GListDepth_HT_2(L->Union.ptr.hp) + 1;
	int tail = GListDepth_HT_2(L->Union.ptr.tp);
	return head > tail ? head : tail;
}
//求广义表深度方法2（扩展线性链表存储）
int GListDepth_E_2(GLNode* L)
{
	if(!L)
		return 1;//空表深度为1
	if(L->type == Atom)
		return 0;//原子深度为0
	int head = GListDepth_E_2(L->Union.hp) + 1;
	int tail = GListDepth_E_2(L->tp);
	return head > tail ? head : tail;
}
//判断广义表是否相等（头尾链存储） 
int GListEqual_HT(GLNode* A, GLNode* B)
{
	if(!A && !B)//空表相等 
		return 1;
	if(A && B)//两个表均不为空 
	{
		if(A->type == B->type)//元素类型相同 
		{
			if(A->type == Atom)//原子节点 
			{
				if(A->Union.atom == B->Union.atom)
					return 1;
			}
			else				//表节点 
			{
				if(GListEqual_HT(A->Union.ptr.hp, B->Union.ptr.hp))
				{
					if(GListEqual_HT(A->Union.ptr.tp, B->Union.ptr.tp))
						return 1;
				}
			}
		}
	}
	return 0;
}
//判断广义表是否相等（扩展线性链表存储） 
int GListEqual_E(GLNode* A, GLNode* B)
{
	if(!A && !B)//空表相等 
		return 1;
	if(A && B)//两个表均不为空 
	{
		if(A->type == B->type)//元素类型相同 
		{
			if(A->type == Atom)//原子节点 
			{
				if(A->Union.atom == B->Union.atom)
				{
					if(GListEqual_E(A->tp, B->tp))
						return 1;
				}
			}
			else				//表节点 
			{
				if(GListEqual_E(A->Union.hp, B->Union.hp))
				{
					if(GListEqual_E(A->tp, B->tp))
						return 1;
				}
			}
		}
	}
	return 0;
}
//输出广义表所有原子项及其所在层次（头尾链存储） 
int GListAtomLayer_HT(GLNode* L, int depth)
{
	int i=depth;//初始为0 
	if(L)
	{
		if(L->type == Atom)
			printf("%c在第%d层\n", L->Union.atom, i);
		if(L->type == List)//如果表头指针指向表，则层数+1 
		{
			GListAtomLayer_HT(L->Union.ptr.hp, i+1);
			GListAtomLayer_HT(L->Union.ptr.tp, i);
		}
	}
}
//输出广义表所有原子项及其所在层次（扩展线性链表存储） 
int GListAtomLayer_E(GLNode* L, int depth)
{
	int i=depth;//初始为0 
	if(L)
	{
		if(L->type == Atom)
			printf("%c在第%d层\n", L->Union.atom, i);
		if(L->type == List)
			GListAtomLayer_E(L->Union.hp, i+1);
		GListAtomLayer_E(L->tp, i);
	}
}
//逆置广义表（头尾链存储）
void ReverseGList_HT(GLNode* *L)
{
	GLNode* head, tail;
	if(*L)
	{
		head = *L;
		tail = (*L)->Union.ptr.tp;
		//对表头进行逆置 
		if(head->Union.ptr.hp && head->Union.ptr.hp->type==List)
			ReverseGList_HT(&(head->Union.ptr.hp));
		//对表尾进行逆置 
		if(tail)
		{
			ReverseGList_HT(&((*L)->Union.ptr.tp));
			//头尾交换
			*L = (*L)->Union.ptr.tp;
			tail->Union.ptr.tp = head;
			head->Union.ptr.tp = NULL; 
		}
	}
} 
//逆置广义表（扩展线性链表存储） 
void ReverseGList_E(GLNode* *L)
{
	GLNode* head, tail;
	if(*L)
	{
		head = *L;
		tail = (*L)->tp;
		//对表头进行逆置 
		if(head->Union.hp && head->type==List)
			ReverseGList_E(&(head->Union.hp));
		//对表尾进行逆置 
		if(tail)
		{
			ReverseGList_E(&((*L)->tp));
			//头尾交换
			*L = (*L)->tp;
			tail->tp = head;
			head->tp = NULL; 
		}
	}
}
//删除广义表中值为x的原子项（头尾链存储） 
void GListDeleteX_HT(GLNode* *L, int x)
{
	GLNode* head, p;
	if(*L && (*L)->type==List)//广义表必须存在且是表，才能删除 
	{
		head = (*L)->Union.ptr.hp;
		if(head)			//如果表头存在，递归删除表头 
		{
			if(head->type==List)//是表，递归删除 
			{
				GListDeleteX_HT(&((*L)->Union,ptr.hp), x);
				GListDeleteX_HT(&((*L)->Union,ptr.tp), x);
			}
			else				 
			{
				if(head->Union.atom==x)//单元素==x，递归到这里可以具体删除了
				{
					p = *L;//p指向整个L，再让L指向L的表尾，再把p的表尾去除，则p就剩下了原来L的表头 
					*L = (*L)->Union.ptr.tp;
					p->Union.ptr.tp = NULL;
					ClearGList_HT(&p);//所以删除了p就是删除表头 
					GListDeleteX_HT(L, x);
				}
				else					//单元素不相等于x，则继续递归删除 
					GListDeleteX_HT(&((*L)->Union.ptr.tp), x);
			}
		}
		else if((*L)->Union.ptr.tp)				//没有表头，则删除表尾 
				GListDeleteX_HT(&((*L)->Union.ptr.tp), x);
	}
}
//删除广义表中值为x的原子项（扩展线性表存储）
void GListDeleteX_E(GLNode* *L, int x)
{
	GLNode* p;
	if(*L)
	{
		if((*L)->type == List)//是表，递归删除 
		{
			GListDeleteX_E(&((*L)->Union.hp), x);
			GListDeleteX_E(&((*L)->tp), x);
		}
		else
		{
			if((*L)->Union.atom==x)//递归到最里层，原子等于x，具体删除操作 
			{
				p = *L;
				*L = (*L)->tp;
				free(p);
				p = NULL;
				
				GListDeleteX_E(L, x);
			}
			else				//最里层原子不等于x，继续递归 
				GListDeleteX_E(&((*L)->tp), x);
		}
	}
}
//输出广义表第level层的原子项（头尾链存储） 
void LevelOutput_HT(GLNode* L, int depth, int level)
{
	int i=depth;
	if(L && level>=i)
	{
		if(L->type==Atom)
		{
			if(level==i)			//层数符合 
				printf("%c ", L->Union.atom);
		}
		else					//不是原子，是表，且头指针指向表的话，层数增1 
		{
			LevelOutput_HT(L->Union.ptr.hp, i+1, level);
			LevelOutput_HT(L->Union.ptr.tp, i, level);
		}
	}
}
//输出广义表第level层的原子项（扩展线性表存储）
void LevelOutput_E(GLNode* L, int depth, int level)
{
	int i=depth;
	if(L && level>=i)
	{
		if(L->type==Atom)
		{
			if(level==i)			//层数符合 
				printf("%c ", L->Union.atom);
		}
		else					//不是原子，是表，且头指针指向表的话，层数增1 
			LevelOutput_E(L->Union.hp, i+1, level);
		LevelOutput_E(L->tp, i, level);
	}
}
 