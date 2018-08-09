#include <stdio.h>
#include <stdlib.h>
#include "../../book/01intro/Status.h"
#include "../../book/04String/01SequenceString/SequenceString.h"
#include "../../book/05Array/05GeneralizedListHT/GeneralizedListHT.h"
#include "../../book/05Array/06ExtenGeneralizedList/ExtenGeneralizedList.h"

//������a[n]�е�Ԫ��ѭ������move��λ�ã�ֻ��1��Ԫ�صĶ���ռ䣬�ƶ��򽻻�����������O(n) 
void ArrayRightMove(int a[], int n, int move)
{
	int realMove = move%n;//ʵ��ѭ�����Ƶ�λ������Ϊ��ѭ�������Գ���n�ı���û�ã�ֻ���ƶ�������λ��
	
	//���Ƹ�����Ϊ0������£��ݹ��ƶ���ֱ���벻���룬�Լ���һ��1��10�����飬�ƶ�һ�¾Ͷ��� 
	if(realMove)
	{
		Reversal(a, n, 1, n);
		Reversal(a, n, 1, realMove);
		Reversal(a, n, realMove+1, n);
	} 
}
//��������a[n]�е�start����end֮���Ԫ�� 
int Reversal(int a[], int n, int start, int end)
{
	int e;//ֻ��1��Ԫ�ؿռ�
	if(start<1 || end>n || start>end)
		return 0;
	else
	{
		for(int i=0; i<=(end-start+1)/2; i++)//Ѱ���е㣬Ȼ��ǰ�󽻻����� 
		{
			e = a[end=i-1];
			a[end-i-1] = a[start+i-1];
			a[start+i-1] = e;
		}
	}
	return 1; 
}









//Ѱ�Ҷ�ά�����е��������㣬�������ÿһ���е���СԪ�أ�ͬʱ���Ԫ��������һ�е����Ԫ��
typedef struct
{
	int x;
	int y;
	int value;
}Node;

//�Ӿ���a���ҳ�����洢��node�� 
int SaddlePoint(int a[256][256], int row, int col, Node node[256])
{
	Node minRow[256];
	node[0].value = 0;
	for(int i=0; i<row; i++)
	{
		MinRow(a, col, i, minRow);//�ҳ�ÿ����СԪ�� 
		for(int j=1; j<=minRow[0].value; j++)//������СԪ�أ��жϸ�Ԫ���ǲ�������һ�е����Ԫ�� 
		{
			if(IsMaxCol(a, row, minRow[j]))
			{
				node[0].value++;
				node[node[0].value] = minRow[j];
			}
		}
	}
	
	if(node[0].value)//������ 
		return 1;
	else
		return 0;
}
//�ҳ�����a�еĵ�i�е���СԪ�� 
void MinRow(int a[256][256], int col, int i, Node minRow[256])
{
	minRow[0].value = 0;//0��Ԫ�ش����СԪ�ظ���
	for(int j=0; j<col; j++)
	{
		if(!j || a[i][j]==minRow[j-1].value)//��һ��Ԫ�ػ�������ȵ���СԪ�أ���СԪ���������� 
			minRow[0].value++;
		else
		{
			if(a[i][j] < minRow[j-1].value)//�ҵ��˸�С�ģ�����СԪ���������¹�1 
				minRow[0].value = 1;
			else							//�ҵ��˴�Ԫ�أ�û��Ӱ�죬����ѭ�� 
				continue;
		}
		//����СԪ�ر�������� 
		minRow[minRow[0].value].x = i;
		minRow[minRow[0].value].y = j;
		minRow[minRow[0].value].value = a[i][j];
	} 
}
int IsMaxCol(int a[256][256], int row, Node minRow)
{
	for(int i=; i<=row; i++)
	{
		if(a[i][minRow.y] > minRow.value)//ÿ����СԪ�ز�����һ�е����Ԫ�أ��������� 
			return 0;
	}
	return 1;
}

 
 
 
 
//��������ȣ�ͷβ���洢��
//��������ȣ���չ��������洢��
//�жϹ�����Ƿ���ȣ�ͷβ���洢�� 
//�жϹ�����Ƿ���ȣ���չ��������洢�� 
//������������ԭ��������ڲ�Σ�ͷβ���洢�� 
//������������ԭ��������ڲ�Σ���չ��������洢�� 
//���ù����ͷβ���洢�� 
//���ù������չ��������洢�� 
//ɾ���������ֵΪx��ԭ���ͷβ���洢�� 
//ɾ���������ֵΪx��ԭ�����չ���Ա�洢��
//���������level���ԭ���ͷβ���洢�� 
//���������level���ԭ�����չ���Ա�洢��
 