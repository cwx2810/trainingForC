#include "LoserTree.h"

int K_Merge(FILE* fp_out, int ls[5], ExNode exNode[6])
{
	FILE* fp_in[5] = {};//5������鲢��
	for(int i=0; i<5; i++)
		 input(fp_in, &(exNode[i].key), i);//���ļ�fpin�ж�ȡ�ؼ��ֵ��ⲿ���鲢��¼
		 
	CreateLoserTree(ls, exNode);//�ô��鲢��¼�������������õ���С�ؼ���ls0 
	
	while(exNode[ls[0]].key != INT_MAX)
	{
		int p = ls[0];//ָ����С�ؼ��� 
		output(fp_out, exNode[p].key);//����С�ؼ���д������鲢�� 
		input(fp_in, &(exNode[p].key), p);//������һ���ؼ��� 
		Adjust(ls, exNode, p);//����������������ѡ����С�ؼ��� 
	} 
	
	output(fp_out, exNode[ls[0]].key);//�����IntMax��Ҳ��� 
	fclose(fp_out);
	return 1;
}

int Adjust(int ls[5], ExNode exNode[6], int p)
{
	int father = (p+5)/2;//ls-father��exNode-p��˫�׽ڵ�
	while(father>0)//�������Ҷ�ӽڵ㵽���ڵ���·���������� 
	{
		if(exNode[p].key > exNode[ls[father]].key)//pָ��С�Ľڵ㣬�����ǰ������ϵĽڵ�С 
		{
			int tmp = p;
			p = ls[father];
			ls[father] = tmp;
		}
		father = father/2;
	} 
	ls[0] = p;//���ڵ�Ϊ��Сֵ
	return 1; 
}

int CreateLoserTree(int ls[5], ExNode exNode[6])
{
	//��ʼ�������� 
	exNode[5].key = INT_MIN;
	for(int i=0; i<5; i++)
		ls[i] = 5;
		
	//���������� 
	for(int p=4; p>=0; p--)
		Adjust(ls, exNode, p);
		
	return 1;
}


