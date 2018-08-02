#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"

#define Equal(a,b) ((a)==(b))
#define Left(a,b) ((a)<(b))
#define Right(a,b) (((a)>(b)))

typedef struct BTNode
{
	int keyNum;//ÿ���ڵ��йؼ��ָ���
	struct BTNode* parent;//ָ��˫�׽ڵ�
	
	int key[4];//�ؼ���������0�ŵ�Ԫ����
	struct BTNode* ptr[4];//����ָ������ 
}BTNode;

typedef struct
{
	BTNode* p;//ָ���ҵ��Ľڵ�
	int order;//�ؼ����ڽڵ��е���ţ�1~n
	int tag;//1������ҳɹ���0�������ʧ�� 
}Result;

int CreateBTree(BTNode* *BT, Table T);

Result SearchBTree(BTNode* BT, int key);

int SearchOrderOfKey(BTNode* p, int key);//���ҹؼ���key�ڽڵ�p�еĴ��� 

int InsertKey(BTNode* *BT, int key);//���ؼ���key����B��

int InsertKeyAccurate(BTNode* *BT, int key, BTNode* p, int i);//�ڽڵ�p�ĵ�i���ؼ��ֺ͵�i+1���ؼ���֮�����key

int Insert(BTNode* p, int i, int x, BTNode* ap);//��x��ap�ֱ���뵽�ؼ���������ָ������

int split(BTNode* p, int splitPoint, BTNode* *ap);//��sΪ�߽磬��pָ��Ľڵ�ֳ�p��ap������

int NewRoot(BTNode* *BT, BTNode* p, int x, BTNode* ap);//���ɺ���Ϣ(BT, x, ap)���µĸ��ڵ㣬ԭBT��apΪ����ָ�룬p��ʼΪ�� 
