#include "BTree.h"

int CreateBTree(BTNode** BT, Table T)
{
	*BT = NULL;
	int i;
	if(T.length!=0)
	{
		for(i=0; i<=T.length; i++)
		{
			if(!InsertKey(BT, T.elem[i].key))//����ʧ��������ѭ�� 
				break;
		}
	}
	
	if(i>T.length)//ÿ��Ԫ�ض������˲Ŵ����ɹ� 
		return 1;
	else
		return 0;
}

Result SearchBTree(BTNode* BT, int key)
{
	Result R = {NULL, 0, 0};//��ʼ������� 
	BTNode* p = BT;
	BTNode* q = NULL;
	int found = FALSE;
	int i=0;
	while(p && !found)
	{
		i = SearchOrderOfKey(p, key);//���ҽڵ�key�ڹؼ���p�еĴ��� 
		if(i>0 && p->key[i]==key)//����֮����Ҫ����һ��key==key��if������Ϊ�п����ҵ���iֻ����ӽ��� 
			found = TRUE;//�ҵ��˹ؼ���
		else
		{
			q = p;
			p = p->ptr[i];//û�ҵ�������������Ѱ�� 
		} 
	}
	R.order = i;//���ҵ��Ĵ���ֵ��Result
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
	for(int j=1; j<=p->keyNum; j++)//�����ڵ�p�е����йؼ��� 
	{
		if(p->key[j] <= key)//��С����Ѱ�ң��������ҵ���key��ȵĻ��ߺ�key��ӽ��� 
			i = j;
		else
			break;
	}
	return i;
}

int InsertKey(BTNode** BT, int key)
{
	Result R = SearchBTree(*BT, key);
	if(R.tag == 0)//B���в����ڴ˹ؼ��֣������ 
	{
		InsertKeyAccurate(BT, key, R.p, R.order);
		return 1;
	}
	else
		return 0;
}

int InsertKeyAccurate(BTNode** BT, int key, BTNode* p, int i)
{
	int x = key;//�洢Ҫ�����key 
	BTNode* ap = NULL;//�洢Ҫ�����ָ�� 
	int finished = FALSE;
	
	while(p && !finished)//����ڵ�p������δ���룬��x��ap���뵽��i���ڵ���� 
	{
		Insert(p, i, x, ap);
		if(p->keyNum <3)//������������B��ÿ���ڵ����ؼ��ָ����������ɹ� 
			finished = TRUE;
		else			//����������ؼ��ָ�������ڵ���� 
		{
			int splitPoint = ceil((double)3/2);//�ؼ��ָ������� 
			split(p, splitPoint, &ap);
			x = p->key[splitPoint];//�����趨������ڵ�Ϊ�����ҳ��Ľڵ㣬������뵽˫���� 
			p = p->parent;
			
			if(p)
				i = SearchOrderOfKey(p, x);//��˫���в��Ҳ���λ�� 
		}
	}
	
	if(!finished)//�������˻�û�в���ɹ�����˵���ǿ�����ֱ�ӽ������ڵ� 
		NewRoot(BT, p, x, ap);
	return 1;
}

int Insert(BTNode* p, int i, int x, BTNode* ap)//��key��nextָ����뵽�ڵ�p�е�i���ؼ��ֺ��� 
{
	for(int j=p->keyNum; j>i; j--)//�ƶ�����λ�Ӻ�������йؼ��ֺ�ָ�� 
	{
		p->key[j+1] = p->key[j];
		p->ptr[j+1] = p->ptr[j];
	}
	
	p->key[i+1] = x;//���� 
	p->ptr[i+1] = ap;
	p->keyNum++;
	return 1;
}

int split(BTNode* p, int splitPoint, BTNode** ap)
{
	(*ap) = (BTNode*)malloc(sizeof(BTNode));//��ΪҪ�ֳ�p��ap�����֣���˸��µ�ap����ռ� 
	if(!(*ap))
		return 0;
	(*ap)->ptr[0] = p->ptr[splitPoint];
	
	//����ķָ��㷨��һ��������� 
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
