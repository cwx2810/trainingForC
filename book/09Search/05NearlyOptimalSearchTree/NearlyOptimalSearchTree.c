#include "NearlyOptimalSearchTree.h"

int FindAllWeight(float w[], Table T)//用数组sw保存表T的累计权值 
{
	w[0] = 0.0;//初始化累计权值数组的0号位，下面遍历要用到 
	for(int i=1; i<=T.length; i++)
		w[i] = w[i-1] + T.elem[i].weight; 
	return 1;
}

int MinBetweenWeight(float w[], int low, int high)
{
	float weightBound = w[high] + w[low-1];//设置一个两边边界权值之和 
	float min = fabs(w[high] - w[low]);//初始化最小差 
	int order = low;
	for(int i=low; i<=high; i++)
	{
		float tmp = fabs(weightBound - w[i] - w[i-1]);//依次减去每个相邻的累计权值，最小的就刚好是要找的序号(不用搞清为什么，这个算法就像数学公式，没意义) 
		if(tmp<min)
		{
			order = i;
			min = tmp;
		}
	}
	return order;
}

int NearlyOptimal(BiTNode **BT, ElemType R[], float w[], int low, int high)
{
	int i = MinBetweenWeight(w, low, high);//找到累计权值查最小的分界点 
	*BT = (BiTNode*)malloc(sizeof(BiTNode));//分配二叉树空间 
	if(!(*BT))
		return 0;
	(*BT)->data = ch[R[i].key];//用分界点对应的key寻找对应的全局变量中设置的树节点
	
	if(i==low)
		(*BT)->lchild = NULL;
	else
		NearlyOptimal(&((*BT)->lchild), R, w, low, i-1); //在i的左边递归
	
	if(i==high)
		(*BT)->rchild = NULL;
	else
		NearlyOptimal(&((*BT)->rchild), R, w, i+1, high);//在i的右边递归 
	return 1; 
}

int CreateNearlyOptimal(BiTNode **BT, Table T)
{
	float w[T.length+1];//初始化累计权值保存的数组 
	if(T.length==0)
		*BT = NULL;
	else
	{
		FindAllWeight(w, T);
		NearlyOptimal(BT, T.elem, w, 1, T.length);
	}
	return 1;
}

int SearchKey(BiTNode *BT, int key)
{
	if(!BT)
		return 0;
	else
	{
		if(ch[key]==BT->data)
			return 1;
		else if(ch[key]<BT->data)
			return SearchKey(BT->lchild, key);
		else
			return SearchKey(BT->rchild, key);
	}
}
