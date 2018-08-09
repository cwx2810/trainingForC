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

 
 
 
 
//求广义表深度（头尾链存储）
//求广义表深度（扩展线性链表存储）
//判断广义表是否相等（头尾链存储） 
//判断广义表是否相等（扩展线性链表存储） 
//输出广义表所有原子项及其所在层次（头尾链存储） 
//输出广义表所有原子项及其所在层次（扩展线性链表存储） 
//逆置广义表（头尾链存储） 
//逆置广义表（扩展线性链表存储） 
//删除广义表中值为x的原子项（头尾链存储） 
//删除广义表中值为x的原子项（扩展线性表存储）
//输出广义表第level层的原子项（头尾链存储） 
//输出广义表第level层的原子项（扩展线性表存储）
 