#include "HuffmanTree.h"

int InitTree_HT(HTNode **T)
{
	*T = NULL;
}

int CreateHuffmanTree_HT(FILE* fp, HTNode **T)
{
	
	/*录入txt中的节点权重到数组中*/
	int n;
	Scanf(fp, "%d", &n);//录入哈夫曼树节点数 
	int w[100];
	for(int i=1; i<=n; i++)
		Scanf(fp, "%d", &w[i]);//录入各个节点权值到数组中，0号单元弃用 
		
	int m = 2*n-1;//哈夫曼树建树后的节点个数 
	
	
	/*把数组中的节点录入到哈夫曼树节点中*/
	*T = (HTNode*)malloc((m+1)*sizeof(HTNode));//多分配一个0号单元的空间，用于存放哈夫曼树叶子节点个数 
	if(!(*T))
		return 0;
	(*T)[0].weight = n;//0号存放叶子个数 
	
	for(int i=1; i<=m; i++)//初始化哈夫曼树节点 
	{
		if(i<=n)
			(*T)[i].weight = w[i];//1~n，存放叶子节点权重 
		else
			(*T)[i].weight = 0; //n+1~2*n-1，存放爸爸权重，初始创建时先设为0，后面的循环再设置 
		
		(*T)[i].parent = 0;//各个节点的其他域都初始化为0 
		(*T)[i].lchild = 0;
		(*T)[i].rchild = 0; 
	}
	for(int i=n+1; i<=m; i++)//处理爸爸权重  
	{
		int order_1,order_2;//保存两个最小权重的标号 
		SelectMini_HT(*T, i-1, &order_1, &order_2);//寻找n+1开始到i-1结束的权重最小的两个节点，i-1是因为2n-1-n=n-1,即组合的爸爸一共n-1个，在这里也就是i-1个 
		(*T)[order_1].parent = (*T)[order_2].parent = i;//设置最小两个节点的父亲域
		(*T)[i].lchild = order_1;//设置父亲的域 
		(*T)[i].rchild = order_2;
		(*T)[i].weight = (*T)[order_1].weight + (*T)[order_2].weight; 
	}
	return 1;
}

int SelectMini_HT(HTNode* T, int end, int* order_1, int* order_2)
{
	if(end<2)//end只有1或者更少，凑不出两个节点 
		return 0;
		
	int i=1; 
	int m,n;//记录下数到的2个未输入节点的编号 
	int count = 1;
	while(i<=end)
	{
		if(T[i].parent==0)//未输入 
		{
			if(count==1)//数到1个 
				m=i;
			if(count==2)//数到2个 
				n=i;
			count++;
		}
		if(count>2)//数够了，跳出循环 
			break;
		i++;
	}
	
	if(T[m].weight > T[n].weight)//保证m的权重小于n的权重 
	{
		int tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m>n?m:n) + 1;//从第i个继续寻找更小的，i是前面找过的元素的后一个
	while(i<=end)
	{
		if(T[i].parent==0)
		{
			if(T[i].weight < T[m].weight)//i比m还小 
			{
				n = m;
				m = i;
			}
			else if(T[i].weight >= T[m].weight && T[i].weight < T[n].weight)//i在m和n之间 
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
	int n = T[0].weight;//叶子节点个数，也是编码长度 
	*Code = (char**)malloc((n+1)*sizeof(char*));//分配总编码空间，多分配一个弃置空间，和初始化时对应 
	if(!(*Code))
		return 0;
	char* code = (char*)malloc(n*sizeof(char));//分配字符串空间，从字符串向Code赋值 
	if(!code)
		return 0;
	code[n-1] = '\0';//字符串结尾 
	for(int i=1; i<=n; i++)//遍历叶子节点，每个叶子对应一个编码 
	{
		int start = n-1;//给临时字符串code赋值的起始下标，从字符串最后赋值，因为最先赋值的是哈夫曼的叶子，是编码的最后一位 
		int current=i;
		int front=T[i].parent;
		while(front!=0)//哈夫曼树根节点parent为0 
		{
			if(T[front].lchild==current)//左孩子编码为0 
			{
				start--;
				code[start] = '0';
			}
			else if(T[front].rchild==current)//右孩子编码为1 
			{
				start--;
				code[start] = '1';
			}
			
			current = front;//移动当前和前面游标 
			front = T[front].parent;
		}
		
		(*Code)[i] = (char*)malloc((n-start)*sizeof(char));//分配每个叶节点哈夫曼编码的空间
		strcpy((*Code)[i], &code[start]);//从start开始复制 
	} 
	free(code);//code是中转空间
	return 1; 
}

int HuffmanCode_Pre(HTNode* T, char*** Code)
{
	int n = T[0].weight;//叶子节点个数 
	int m = 2*n-1;//建树后的总节点个数
	*Code = (char**)malloc((n+1)*sizeof(char*));//分配总编码空间 
	if(!(*Code))
		return 0;
	char* code = (char*)malloc(n*sizeof(char));//分配临时字符串空间，从字符串向Code赋值 
	if(!code)
		return 0;
	for(int i=1; i<=n; i++)//初始化临时字符串 
		code[i]='\0';
	int mark[100];
	for(int i=1; i<=m; i++)//初始化访问标记，0、1、2分别代表访问了几次 
		mark[i]=0; 
	int p = m;//游标，初始化为最后一个节点 
	int codelen = 0;//编码数组下标，初始从第一个位子开始赋值给临时数组code，对比上面逆序计算是从最后一个开始赋值 
	while(p)//从最后一个节点开始访问，数组中从前往后是叶子节点和父节点，因此访问的是根节点 
	{
		if(mark[p]==0)//第一次访问到此节点，因为mark为0 
		{
			mark[p] = 1;//代表已经访问过一次了 
			if(T[p].lchild!=0)
			{
				p = T[p].lchild;//向左访问
				code[codelen] = '0'; //有左孩子，则编码为0
				codelen++; 
			}
			else if(T[p].rchild==0)//此节点左孩子为空，右孩子也为空，则为叶子，可以求编码了 
			{
				(*Code)[p] = (char*)malloc((codelen+1)*sizeof(char));
				strcpy((*Code)[p], code);
			}
		}
		else if(mark[p]==1)//第二次访问此节点，已经确定不是叶子了，是主干，向右访问 
		{
			mark[p] = 2;
			if(T[p].rchild!=0) 
			{
				p = T[p].rchild;
				code[codelen] = '1';
				codelen++;
			}
		}
		else 			//第三次访问此节点，叶子处理过了，主干也不是，则回溯往下走 
		{
			p = T[p].parent;
			codelen--;//第二次访问时多加了1，要减回来才能设置结尾 
			code[codelen] = '\0';
		}
	}
	free(code);
 	return 1;
}

int ShowHuffmanTree(HTNode* T)
{
			printf("*order | weight | parent | lchild | rchild\n");
	for(int i=0; i<=2*T[0].weight-1; i++)//遍历所有哈夫曼节点
	{
		if(i==0)//0号存放的是叶子节点数
			printf("  %2d  |%4d叶子 |    x   |    x   |    x  \n", i, T[0].weight);
		else
			printf("  %2d  |   %4d  |   %2d   |   %2d   |   %2d \n", i, T[i].weight, T[i].parent, T[i].lchild, T[i].rchild); 
	} 
	return 1;
}

int ShowHuffmanCode(HTNode* T, char** Code)
{
		printf("*order | weight | 哈夫曼编码\n");
	for(int i=1; i<=T[0].weight; i++)
		printf(" %2d   |  %4d   | %-14s\n", i, T[i].weight, Code[i]);
	return 1;
}
