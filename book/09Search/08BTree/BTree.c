#include "BTree.h"

int CreateBTree(BTNode** BT, Table T)
{
	*BT = NULL;
	int i;
	if(T.length!=0)
	{
		for(i=0; i<=T.length; i++)
		{
			if(!InsertKey(BT, T.elem[i].key))//插入失败则跳出循环 
				break;
		}
	}
	
	if(i>T.length)//每个元素都插入了才创建成功 
		return 1;
	else
		return 0;
}

Result SearchBTree(BTNode* BT, int key)
{
	Result R = {NULL, 0, 0};//初始化结果集 
	BTNode* p = BT;
	BTNode* q = NULL;
	int found = FALSE;
	int i=0;
	while(p && !found)
	{
		i = SearchOrderOfKey(p, key);//查找节点key在关键字p中的次序 
		if(i>0 && p->key[i]==key)//这里之所以要设置一个key==key的if，是因为有可能找到的i只是最接近的 
			found = TRUE;//找到了关键字
		else
		{
			q = p;
			p = p->ptr[i];//没找到，向子树继续寻找 
		} 
	}
	R.order = i;//把找到的次序赋值给Result
	if(found)
	{
		R.p = p;
		R.tag = 1;
	} 
	else
	{
		R.p = q;
		R.tag = 0;
	}
	return R;
}

int SearchOrderOfKey(BTNode* p, int key)
{
	int i=0;
	for(int j=1; j<=p->keyNum; j++)//遍历节点p中的所有关键字 
	{
		if(p->key[j] <= key)//从小到大寻找，最终能找到和key相等的或者和key最接近的 
			i = j;
		else
			break;
	}
	return i;
}

int InsertKey(BTNode** BT, int key)
{
	Result R = SearchBTree(*BT, key);
	if(R.tag == 0)//B树中不存在此关键字，则插入 
	{
		InsertKeyAccurate(BT, key, R.p, R.order);
		return 1;
	}
	else
		return 0;
}

int InsertKeyAccurate(BTNode** BT, int key, BTNode* p, int i)
{
	int x = key;//存储要插入的key 
	BTNode* ap = NULL;//存储要插入的指针 
	int finished = FALSE;
	
	while(p && !finished)//如果节点p存在且未插入，则将x和ap插入到第i个节点后面 
	{
		Insert(p, i, x, ap);
		if(p->keyNum <3)//如果插入后满足B树每个节点最大关键字个数，则插入成功 
			finished = TRUE;
		else			//如果超过最大关键字个数，则节点分裂 
		{
			int splitPoint = ceil((double)3/2);//关键字个数上限 
			split(p, splitPoint, &ap);
			x = p->key[splitPoint];//重新设定待插入节点为分裂找出的节点，将其插入到双亲中 
			p = p->parent;
			
			if(p)
				i = SearchOrderOfKey(p, x);//在双亲中查找插入位置 
		}
	}
	
	if(!finished)//遍历完了还没有插入成功，则说明是空树，直接建立根节点 
		NewRoot(BT, p, x, ap);
	return 1;
}

int Insert(BTNode* p, int i, int x, BTNode* ap)//将key和next指针插入到节点p中第i个关键字后面 
{
	for(int j=p->keyNum; j>i; j--)//移动插入位子后面的所有关键字和指针 
	{
		p->key[j+1] = p->key[j];
		p->ptr[j+1] = p->ptr[j];
	}
	
	p->key[i+1] = x;//插入 
	p->ptr[i+1] = ap;
	p->keyNum++;
	return 1;
}

int split(BTNode* p, int splitPoint, BTNode** ap)
{
	(*ap) = (BTNode*)malloc(sizeof(BTNode));//因为要分成p和ap两部分，因此给新的ap分配空间 
	if(!(*ap))
		return 0;
	(*ap)->ptr[0] = p->ptr[splitPoint];
	
	//具体的分割算法，一顿数组操作 
	for(int i=splitPoint+1; i<=3; i++)
	{
		(*ap)->key[i-splitPoint] = p->key[i];
		(*ap)->ptr[i-splitPoint] = p->ptr[i];
	}
	(*ap)->keyNum = 3-splitPoint;
	p->keyNum = splitPoint - 1;
	(*ap)->parent = p->parent;
	
	for(int i=0; i<=(*ap)->keyNum; i++)
	{
		if((*ap)->ptr[i])
			(*ap)->ptr[i]->parent = *ap;
	}
	return 1;
}

int NewRoot(BTNode** BT, BTNode* p, int x, BTNode* ap)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if(!root)
		return 0;
	root->keyNum = 1;
	root->parent = NULL;
	root->key[1] = x;
	root->ptr[0] = *BT;
	root->ptr[1] = ap;
	
	if(root->ptr[0])
		root->ptr[0]->parent = root;
	if(root->ptr[1])
		root->ptr[1]->parent = root;
	*BT = root;
	return 1;
}
