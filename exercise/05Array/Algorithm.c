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

 
 
 
//ͷβ������չ��������������ǣ�ͷβ���е�һ����ƽ�����ӵģ���չ����������ͨ��next�������ӵ� 
//��������ȷ���2��ͷβ���洢��
int GListDepth_HT_2(GLNode* L)
{
	if(!L)
		return 1;//�ձ����Ϊ1
	if(L->type == Atom)
		return 0;//ԭ�����Ϊ0
	int head = GListDepth_HT_2(L->Union.ptr.hp) + 1;
	int tail = GListDepth_HT_2(L->Union.ptr.tp);
	return head > tail ? head : tail;
}
//��������ȷ���2����չ��������洢��
int GListDepth_E_2(GLNode* L)
{
	if(!L)
		return 1;//�ձ����Ϊ1
	if(L->type == Atom)
		return 0;//ԭ�����Ϊ0
	int head = GListDepth_E_2(L->Union.hp) + 1;
	int tail = GListDepth_E_2(L->tp);
	return head > tail ? head : tail;
}
//�жϹ�����Ƿ���ȣ�ͷβ���洢�� 
int GListEqual_HT(GLNode* A, GLNode* B)
{
	if(!A && !B)//�ձ���� 
		return 1;
	if(A && B)//���������Ϊ�� 
	{
		if(A->type == B->type)//Ԫ��������ͬ 
		{
			if(A->type == Atom)//ԭ�ӽڵ� 
			{
				if(A->Union.atom == B->Union.atom)
					return 1;
			}
			else				//��ڵ� 
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
//�жϹ�����Ƿ���ȣ���չ��������洢�� 
int GListEqual_E(GLNode* A, GLNode* B)
{
	if(!A && !B)//�ձ���� 
		return 1;
	if(A && B)//���������Ϊ�� 
	{
		if(A->type == B->type)//Ԫ��������ͬ 
		{
			if(A->type == Atom)//ԭ�ӽڵ� 
			{
				if(A->Union.atom == B->Union.atom)
				{
					if(GListEqual_E(A->tp, B->tp))
						return 1;
				}
			}
			else				//��ڵ� 
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
//������������ԭ��������ڲ�Σ�ͷβ���洢�� 
int GListAtomLayer_HT(GLNode* L, int depth)
{
	int i=depth;//��ʼΪ0 
	if(L)
	{
		if(L->type == Atom)
			printf("%c�ڵ�%d��\n", L->Union.atom, i);
		if(L->type == List)//�����ͷָ��ָ��������+1 
		{
			GListAtomLayer_HT(L->Union.ptr.hp, i+1);
			GListAtomLayer_HT(L->Union.ptr.tp, i);
		}
	}
}
//������������ԭ��������ڲ�Σ���չ��������洢�� 
int GListAtomLayer_E(GLNode* L, int depth)
{
	int i=depth;//��ʼΪ0 
	if(L)
	{
		if(L->type == Atom)
			printf("%c�ڵ�%d��\n", L->Union.atom, i);
		if(L->type == List)
			GListAtomLayer_E(L->Union.hp, i+1);
		GListAtomLayer_E(L->tp, i);
	}
}
//���ù����ͷβ���洢��
void ReverseGList_HT(GLNode* *L)
{
	GLNode* head, tail;
	if(*L)
	{
		head = *L;
		tail = (*L)->Union.ptr.tp;
		//�Ա�ͷ�������� 
		if(head->Union.ptr.hp && head->Union.ptr.hp->type==List)
			ReverseGList_HT(&(head->Union.ptr.hp));
		//�Ա�β�������� 
		if(tail)
		{
			ReverseGList_HT(&((*L)->Union.ptr.tp));
			//ͷβ����
			*L = (*L)->Union.ptr.tp;
			tail->Union.ptr.tp = head;
			head->Union.ptr.tp = NULL; 
		}
	}
} 
//���ù������չ��������洢�� 
void ReverseGList_E(GLNode* *L)
{
	GLNode* head, tail;
	if(*L)
	{
		head = *L;
		tail = (*L)->tp;
		//�Ա�ͷ�������� 
		if(head->Union.hp && head->type==List)
			ReverseGList_E(&(head->Union.hp));
		//�Ա�β�������� 
		if(tail)
		{
			ReverseGList_E(&((*L)->tp));
			//ͷβ����
			*L = (*L)->tp;
			tail->tp = head;
			head->tp = NULL; 
		}
	}
}
//ɾ���������ֵΪx��ԭ���ͷβ���洢�� 
void GListDeleteX_HT(GLNode* *L, int x)
{
	GLNode* head, p;
	if(*L && (*L)->type==List)//��������������Ǳ�����ɾ�� 
	{
		head = (*L)->Union.ptr.hp;
		if(head)			//�����ͷ���ڣ��ݹ�ɾ����ͷ 
		{
			if(head->type==List)//�Ǳ��ݹ�ɾ�� 
			{
				GListDeleteX_HT(&((*L)->Union,ptr.hp), x);
				GListDeleteX_HT(&((*L)->Union,ptr.tp), x);
			}
			else				 
			{
				if(head->Union.atom==x)//��Ԫ��==x���ݹ鵽������Ծ���ɾ����
				{
					p = *L;//pָ������L������Lָ��L�ı�β���ٰ�p�ı�βȥ������p��ʣ����ԭ��L�ı�ͷ 
					*L = (*L)->Union.ptr.tp;
					p->Union.ptr.tp = NULL;
					ClearGList_HT(&p);//����ɾ����p����ɾ����ͷ 
					GListDeleteX_HT(L, x);
				}
				else					//��Ԫ�ز������x��������ݹ�ɾ�� 
					GListDeleteX_HT(&((*L)->Union.ptr.tp), x);
			}
		}
		else if((*L)->Union.ptr.tp)				//û�б�ͷ����ɾ����β 
				GListDeleteX_HT(&((*L)->Union.ptr.tp), x);
	}
}
//ɾ���������ֵΪx��ԭ�����չ���Ա�洢��
void GListDeleteX_E(GLNode* *L, int x)
{
	GLNode* p;
	if(*L)
	{
		if((*L)->type == List)//�Ǳ��ݹ�ɾ�� 
		{
			GListDeleteX_E(&((*L)->Union.hp), x);
			GListDeleteX_E(&((*L)->tp), x);
		}
		else
		{
			if((*L)->Union.atom==x)//�ݹ鵽����㣬ԭ�ӵ���x������ɾ������ 
			{
				p = *L;
				*L = (*L)->tp;
				free(p);
				p = NULL;
				
				GListDeleteX_E(L, x);
			}
			else				//�����ԭ�Ӳ�����x�������ݹ� 
				GListDeleteX_E(&((*L)->tp), x);
		}
	}
}
//���������level���ԭ���ͷβ���洢�� 
void LevelOutput_HT(GLNode* L, int depth, int level)
{
	int i=depth;
	if(L && level>=i)
	{
		if(L->type==Atom)
		{
			if(level==i)			//�������� 
				printf("%c ", L->Union.atom);
		}
		else					//����ԭ�ӣ��Ǳ���ͷָ��ָ���Ļ���������1 
		{
			LevelOutput_HT(L->Union.ptr.hp, i+1, level);
			LevelOutput_HT(L->Union.ptr.tp, i, level);
		}
	}
}
//���������level���ԭ�����չ���Ա�洢��
void LevelOutput_E(GLNode* L, int depth, int level)
{
	int i=depth;
	if(L && level>=i)
	{
		if(L->type==Atom)
		{
			if(level==i)			//�������� 
				printf("%c ", L->Union.atom);
		}
		else					//����ԭ�ӣ��Ǳ���ͷָ��ָ���Ļ���������1 
			LevelOutput_E(L->Union.hp, i+1, level);
		LevelOutput_E(L->tp, i, level);
	}
}
 