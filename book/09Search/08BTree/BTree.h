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
	int keyNum;//每个节点中关键字个数
	struct BTNode* parent;//指向双亲节点
	
	int key[4];//关键字向量，0号单元弃用
	struct BTNode* ptr[4];//子树指针向量 
}BTNode;

typedef struct
{
	BTNode* p;//指向找到的节点
	int order;//关键字在节点中的序号，1~n
	int tag;//1代表查找成功，0代表查找失败 
}Result;

int CreateBTree(BTNode* *BT, Table T);

Result SearchBTree(BTNode* BT, int key);

int SearchOrderOfKey(BTNode* p, int key);//查找关键字key在节点p中的次序 

int InsertKey(BTNode* *BT, int key);//将关键字key插入B树

int InsertKeyAccurate(BTNode* *BT, int key, BTNode* p, int i);//在节点p的第i个关键字和第i+1个关键字之间插入key

int Insert(BTNode* p, int i, int x, BTNode* ap);//将x和ap分别插入到关键字向量和指针向量

int split(BTNode* p, int splitPoint, BTNode* *ap);//以s为边界，把p指向的节点分成p和ap两部分

int NewRoot(BTNode* *BT, BTNode* p, int x, BTNode* ap);//生成含信息(BT, x, ap)的新的根节点，原BT和ap为子树指针，p初始为空 
