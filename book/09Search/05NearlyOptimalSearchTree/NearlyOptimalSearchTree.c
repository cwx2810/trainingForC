#include "NearlyOptimalSearchTree.h"

int FindAllWeight(float w[], Table T)//������sw�����T���ۼ�Ȩֵ 
{
	w[0] = 0.0;//��ʼ���ۼ�Ȩֵ�����0��λ���������Ҫ�õ� 
	for(int i=1; i<=T.length; i++)
		w[i] = w[i-1] + T.elem[i].weight; 
	return 1;
}

int MinBetweenWeight(float w[], int low, int high)
{
	float weightBound = w[high] + w[low-1];//����һ�����߽߱�Ȩֵ֮�� 
	float min = fabs(w[high] - w[low]);//��ʼ����С�� 
	int order = low;
	for(int i=low; i<=high; i++)
	{
		float tmp = fabs(weightBound - w[i] - w[i-1]);//���μ�ȥÿ�����ڵ��ۼ�Ȩֵ����С�ľ͸պ���Ҫ�ҵ����(���ø���Ϊʲô������㷨������ѧ��ʽ��û����) 
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
	int i = MinBetweenWeight(w, low, high);//�ҵ��ۼ�Ȩֵ����С�ķֽ�� 
	*BT = (BiTNode*)malloc(sizeof(BiTNode));//����������ռ� 
	if(!(*BT))
		return 0;
	(*BT)->data = ch[R[i].key];//�÷ֽ���Ӧ��keyѰ�Ҷ�Ӧ��ȫ�ֱ��������õ����ڵ�
	
	if(i==low)
		(*BT)->lchild = NULL;
	else
		NearlyOptimal(&((*BT)->lchild), R, w, low, i-1); //��i����ߵݹ�
	
	if(i==high)
		(*BT)->rchild = NULL;
	else
		NearlyOptimal(&((*BT)->rchild), R, w, i+1, high);//��i���ұߵݹ� 
	return 1; 
}

int CreateNearlyOptimal(BiTNode **BT, Table T)
{
	float w[T.length+1];//��ʼ���ۼ�Ȩֵ��������� 
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
