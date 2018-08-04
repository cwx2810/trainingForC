#include "LoserTree.h"

int K_Merge(FILE* fp_out, int ls[5], ExNode exNode[6])
{
	FILE* fp_in[5] = {};//5个输入归并段
	for(int i=0; i<5; i++)
		 input(fp_in, &(exNode[i].key), i);//从文件fpin中读取关键字到外部待归并记录
		 
	CreateLoserTree(ls, exNode);//用待归并记录创建败者树，得到最小关键字ls0 
	
	while(exNode[ls[0]].key != INT_MAX)
	{
		int p = ls[0];//指向最小关键字 
		output(fp_out, exNode[p].key);//将最小关键字写到输出归并段 
		input(fp_in, &(exNode[p].key), p);//读入下一个关键字 
		Adjust(ls, exNode, p);//调整败者树，重新选择最小关键字 
	} 
	
	output(fp_out, exNode[ls[0]].key);//如果是IntMax，也输出 
	fclose(fp_out);
	return 1;
}

int Adjust(int ls[5], ExNode exNode[6], int p)
{
	int father = (p+5)/2;//ls-father是exNode-p的双亲节点
	while(father>0)//从最底下叶子节点到根节点沿路调整败者树 
	{
		if(exNode[p].key > exNode[ls[father]].key)//p指向小的节点，这里是败者树上的节点小 
		{
			int tmp = p;
			p = ls[father];
			ls[father] = tmp;
		}
		father = father/2;
	} 
	ls[0] = p;//根节点为最小值
	return 1; 
}

int CreateLoserTree(int ls[5], ExNode exNode[6])
{
	//初始化败者树 
	exNode[5].key = INT_MIN;
	for(int i=0; i<5; i++)
		ls[i] = 5;
		
	//调整败者树 
	for(int p=4; p>=0; p--)
		Adjust(ls, exNode, p);
		
	return 1;
}


