#include "HuffmanTree.h"

int InitTree_HT(HTNode **T)
{
	*T = NULL;
}

int CreateHuffmanTree_HT(FILE* fp, HTNode **T)
{
	
	/*¼��txt�еĽڵ�Ȩ�ص�������*/
	int n;
	Scanf(fp, "%d", &n);//¼����������ڵ��� 
	int w[100];
	for(int i=1; i<=n; i++)
		Scanf(fp, "%d", &w[i]);//¼������ڵ�Ȩֵ�������У�0�ŵ�Ԫ���� 
		
	int m = 2*n-1;//��������������Ľڵ���� 
	
	
	/*�������еĽڵ�¼�뵽���������ڵ���*/
	*T = (HTNode*)malloc((m+1)*sizeof(HTNode));//�����һ��0�ŵ�Ԫ�Ŀռ䣬���ڴ�Ź�������Ҷ�ӽڵ���� 
	if(!(*T))
		return 0;
	(*T)[0].weight = n;//0�Ŵ��Ҷ�Ӹ��� 
	
	for(int i=1; i<=m; i++)//��ʼ�����������ڵ� 
	{
		if(i<=n)
			(*T)[i].weight = w[i];//1~n�����Ҷ�ӽڵ�Ȩ�� 
		else
			(*T)[i].weight = 0; //n+1~2*n-1����Űְ�Ȩ�أ���ʼ����ʱ����Ϊ0�������ѭ�������� 
		
		(*T)[i].parent = 0;//�����ڵ�������򶼳�ʼ��Ϊ0 
		(*T)[i].lchild = 0;
		(*T)[i].rchild = 0; 
	}
	for(int i=n+1; i<=m; i++)//����ְ�Ȩ��  
	{
		int order_1,order_2;//����������СȨ�صı�� 
		SelectMini_HT(*T, i-1, &order_1, &order_2);//Ѱ��n+1��ʼ��i-1������Ȩ����С�������ڵ㣬i-1����Ϊ2n-1-n=n-1,����ϵİְ�һ��n-1����������Ҳ����i-1�� 
		(*T)[order_1].parent = (*T)[order_2].parent = i;//������С�����ڵ�ĸ�����
		(*T)[i].lchild = order_1;//���ø��׵��� 
		(*T)[i].rchild = order_2;
		(*T)[i].weight = (*T)[order_1].weight + (*T)[order_2].weight; 
	}
	return 1;
}

int SelectMini_HT(HTNode* T, int end, int* order_1, int* order_2)
{
	if(end<2)//endֻ��1���߸��٣��ղ��������ڵ� 
		return 0;
		
	int i=1; 
	int m,n;//��¼��������2��δ����ڵ�ı�� 
	int count = 1;
	while(i<=end)
	{
		if(T[i].parent==0)//δ���� 
		{
			if(count==1)//����1�� 
				m=i;
			if(count==2)//����2�� 
				n=i;
			count++;
		}
		if(count>2)//�����ˣ�����ѭ�� 
			break;
		i++;
	}
	
	if(T[m].weight > T[n].weight)//��֤m��Ȩ��С��n��Ȩ�� 
	{
		int tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m>n?m:n) + 1;//�ӵ�i������Ѱ�Ҹ�С�ģ�i��ǰ���ҹ���Ԫ�صĺ�һ��
	while(i<=end)
	{
		if(T[i].parent==0)
		{
			if(T[i].weight < T[m].weight)//i��m��С 
			{
				n = m;
				m = i;
			}
			else if(T[i].weight >= T[m].weight && T[i].weight < T[n].weight)//i��m��n֮�� 
				n = i;
		}
		i++;
	} 
	
	*order_1 = m;
	*order_2 = n;
	return 1;
}

int HuffmanCode_Invert(HTNode* T, char*** Code)
{
	int n = T[0].weight;//Ҷ�ӽڵ������Ҳ�Ǳ��볤�� 
	*Code = (char**)malloc((n+1)*sizeof(char*));//�����ܱ���ռ䣬�����һ�����ÿռ䣬�ͳ�ʼ��ʱ��Ӧ 
	if(!(*Code))
		return 0;
	char* code = (char*)malloc(n*sizeof(char));//�����ַ����ռ䣬���ַ�����Code��ֵ 
	if(!code)
		return 0;
	code[n-1] = '\0';//�ַ�����β 
	for(int i=1; i<=n; i++)//����Ҷ�ӽڵ㣬ÿ��Ҷ�Ӷ�Ӧһ������ 
	{
		int start = n-1;//����ʱ�ַ���code��ֵ����ʼ�±꣬���ַ������ֵ����Ϊ���ȸ�ֵ���ǹ�������Ҷ�ӣ��Ǳ�������һλ 
		int current=i;
		int front=T[i].parent;
		while(front!=0)//�����������ڵ�parentΪ0 
		{
			if(T[front].lchild==current)//���ӱ���Ϊ0 
			{
				start--;
				code[start] = '0';
			}
			else if(T[front].rchild==current)//�Һ��ӱ���Ϊ1 
			{
				start--;
				code[start] = '1';
			}
			
			current = front;//�ƶ���ǰ��ǰ���α� 
			front = T[front].parent;
		}
		
		(*Code)[i] = (char*)malloc((n-start)*sizeof(char));//����ÿ��Ҷ�ڵ����������Ŀռ�
		strcpy((*Code)[i], &code[start]);//��start��ʼ���� 
	} 
	free(code);//code����ת�ռ�
	return 1; 
}

int HuffmanCode_Pre(HTNode* T, char*** Code)
{
	int n = T[0].weight;//Ҷ�ӽڵ���� 
	int m = 2*n-1;//��������ܽڵ����
	*Code = (char**)malloc((n+1)*sizeof(char*));//�����ܱ���ռ� 
	if(!(*Code))
		return 0;
	char* code = (char*)malloc(n*sizeof(char));//������ʱ�ַ����ռ䣬���ַ�����Code��ֵ 
	if(!code)
		return 0;
	for(int i=1; i<=n; i++)//��ʼ����ʱ�ַ��� 
		code[i]='\0';
	int mark[100];
	for(int i=1; i<=m; i++)//��ʼ�����ʱ�ǣ�0��1��2�ֱ��������˼��� 
		mark[i]=0; 
	int p = m;//�α꣬��ʼ��Ϊ���һ���ڵ� 
	int codelen = 0;//���������±꣬��ʼ�ӵ�һ��λ�ӿ�ʼ��ֵ����ʱ����code���Ա�������������Ǵ����һ����ʼ��ֵ 
	while(p)//�����һ���ڵ㿪ʼ���ʣ������д�ǰ������Ҷ�ӽڵ�͸��ڵ㣬��˷��ʵ��Ǹ��ڵ� 
	{
		if(mark[p]==0)//��һ�η��ʵ��˽ڵ㣬��ΪmarkΪ0 
		{
			mark[p] = 1;//�����Ѿ����ʹ�һ���� 
			if(T[p].lchild!=0)
			{
				p = T[p].lchild;//�������
				code[codelen] = '0'; //�����ӣ������Ϊ0
				codelen++; 
			}
			else if(T[p].rchild==0)//�˽ڵ�����Ϊ�գ��Һ���ҲΪ�գ���ΪҶ�ӣ������������ 
			{
				(*Code)[p] = (char*)malloc((codelen+1)*sizeof(char));
				strcpy((*Code)[p], code);
			}
		}
		else if(mark[p]==1)//�ڶ��η��ʴ˽ڵ㣬�Ѿ�ȷ������Ҷ���ˣ������ɣ����ҷ��� 
		{
			mark[p] = 2;
			if(T[p].rchild!=0) 
			{
				p = T[p].rchild;
				code[codelen] = '1';
				codelen++;
			}
		}
		else 			//�����η��ʴ˽ڵ㣬Ҷ�Ӵ�����ˣ�����Ҳ���ǣ������������ 
		{
			p = T[p].parent;
			codelen--;//�ڶ��η���ʱ�����1��Ҫ�������������ý�β 
			code[codelen] = '\0';
		}
	}
	free(code);
 	return 1;
}

int ShowHuffmanTree(HTNode* T)
{
			printf("*order | weight | parent | lchild | rchild\n");
	for(int i=0; i<=2*T[0].weight-1; i++)//�������й������ڵ�
	{
		if(i==0)//0�Ŵ�ŵ���Ҷ�ӽڵ���
			printf("  %2d  |%4dҶ�� |    x   |    x   |    x  \n", i, T[0].weight);
		else
			printf("  %2d  |   %4d  |   %2d   |   %2d   |   %2d \n", i, T[i].weight, T[i].parent, T[i].lchild, T[i].rchild); 
	} 
	return 1;
}

int ShowHuffmanCode(HTNode* T, char** Code)
{
		printf("*order | weight | ����������\n");
	for(int i=1; i<=T[0].weight; i++)
		printf(" %2d   |  %4d   | %-14s\n", i, T[i].weight, Code[i]);
	return 1;
}
