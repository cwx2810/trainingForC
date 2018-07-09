#include "ThreadBinaryTree.h"

int CreateBiTree_Tri(FILE *fp, TriBiNode **T)
{
	char ch;
	Scanf(fp, "%c", &ch);
	if(ch=='^')
		*T = NULL;
	else
	{
		*T = (TriBiNode*)malloc(sizeof(TriBiNode));
		if(!(*T))
			return 0;
		(*T)->data = ch;
		
		CreateBiTree_Tri(fp, &((*T)->lchild));//�ȵݹ鹹��������
		if((*T)->lchild)//�ݹ鲻��ȥ������·��ص�ÿһ���������ұ�־������������ 
			(*T)->LTag = Link;
		else
			(*T)->LTag = Thread; 
			
		CreateBiTree_Tri(fp, &((*T)->rchild));
		if((*T)->rchild)
			(*T)->RTag = Link;
		else
			(*T)->RTag = Thread;
	}
	return 1;
}

void InThreading_Tri(TriBiNode* p)
{
	if(p)
	{
		InThreading_Tri(p->lchild);//�ݹ���������������ʵ���Ǵ������½ǿ�ʼ������
		
		if(!p->lchild)//Ϊ��ǰ�ڵ㽨��ǰ����������ʱ��p��ǰ��̽����pre�ں�����Ҳ����pָ��֮ǰ�߹�����· 
		{
			p->LTag = Thread;
			p->lchild = pre;
		} 
		
		if(!pre->rchild)//Ϊ��һ���ڵ㽨�������������ʱ���Ѿ�������һ���ˣ�pre��ǰ�棬p�ں�������·��Ҳ����preָ���̵���· 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;//preǰ��һ�� 
		
		InThreading_Tri(p->rchild);//�ݹ������������������ݵ��Ӹ��ڵ���������ĳ����ΪNULL����������ʼ 
	}
}

int InOrderThreading_Tri(TriBiNode **T, TriBiNode* P)//ͷ����̻�ָ������˫������ 
{
	//����ͷ��� 
	*T = (TriBiNode*)malloc(sizeof(TriBiNode));
	if(!(*T))
		return 0;
	(*T)->data = '\0';
	(*T)->LTag = Link;
	(*T)->RTag = Thread;
	(*T)->rchild = *T;
	
	//������ 
	if(!P)
		(*T)->lchild = *T;
	else
	{
		(*T)->lchild = P;
		pre = *T;//��ʼ��preΪ�յ�ͷ��� 
		
		InThreading_Tri(P);//������
		
		pre->rchild = *T;//���һ���ڵ�ָ���ͷ��� 
		pre->RTag = Thread;//����Ϊ���� 
		(*T)->rchild = pre; //ͷ���ָ�����һ���ڵ㣬˫����ϵ 
	}
	return 1;
}

int InOrderTraverse_Tri(TriBiNode* T, void(Visit)(char))
{
	TriBiNode* p = T->lchild;//T�ǿյĸ��ڵ㣬pָ������������ĸ��ڵ�
	while(p!=T)//p==T˵���ǿն����� 
	{
		while(p->LTag==Link)//�ҵ������½ڵ� 
			p = p->lchild;
		
		Visit(p->data);
		
		while(p->RTag==Thread && p->rchild!=T)//��������������������ֱ�ӷ��ʺ�̣���Ȼ�����̲�����ͷ��㣬��Ȼ�͵�ͷ�� 
		{
			p = p->rchild;
			Visit(p->data);
		}
		
		p = p->rchild;//���ƻ�����һ��ֱ���к�̣��߾����ˣ��ƻ������������ߵ��յĸ��ڵ㣬����ѭ�� 
	} 
	return 1;
}
