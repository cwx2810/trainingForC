#include "SeqBinaryTree.h"
#include <math.h>

int InitBiTree_Sq(SqBiTree T)
{
	for(int i=1; i<=100; i++)
		T[i-1] = '\0';//空节点用\0填充 
	return 1;
}

int ClearBiTree_Sq(SqBiTree T)
{
	for(int i=1; i<=100; i++)
		T[i-1] = '\0';
	return 1;
}

int DestroyBiTree_Sq(SqBiTree T)
{
	//二叉树无法销毁，因为是char[100]的结构，不是我们自己创建的结构体 
}

int BiTreeEmpty_Sq(SqBiTree T)
{
	return T[0]=='\0' ? 1 : 0;//根节点都空了，自然二叉树就是空的 
}

int CreateBiTree_Level(FILE *fp, SqBiTree T)
{
	char ch;
	int i = 1;
	while(Scanf(fp, "%c", &ch)==1 && ch!='\n')//当读入的char存在并且char不是换行符
	{
		if(ch=='^')//在TestData中的二叉树空节点用^表示 
		{
			T[i-1] = '\0';
			i++;
		}
		else
		{
			T[i-1] = ch;
			i++;
		}	
	} 
	return 1;
}

int CreateBiTree_Pre(FILE *fp, SqBiTree T, int i)
{
	char ch;
	Scanf(fp, "%c", &ch);
	if(ch == '^')
		T[i-1] = '\0';//这个其实是直接走到最底层创建空节点 
	else
	{
		T[i-1] = ch;//创建根节点 
		CreateBiTree_Pre(fp, T, 2*i);//创建左右孩子 
		CreateBiTree_Pre(fp, T, 2*i+1);
	}
	return 1;
}

int BiTreeLength_Sq(SqBiTree T)
{
	int len;
	for(len=100; len>=1; len--)//寻找最后一个节点 
	{
		if(T[len-1]!='\0')
			break;
	}
	return len;
}

int BiTreeDepth_Sq(SqBiTree T)
{
	int depth = 0;
	while((int)pow(2, depth)-1<BiTreeLength_Sq(T))//2^h - 1 = 满二叉树节点数 
		depth++;
	return depth;
}

int Root_Sq(SqBiTree T, char *e)
{
	if(BiTreeEmpty_Sq(T))
		return 0;
	*e = T[0];
	return 1;
}

char Value_Sq(SqBiTree T, Position s)
{
	//求出位置s是第二叉树第几个节点 
	int i = (int)pow(2, s.level-1) + s.order-1;//2^(h-1)是满二叉树每层节点数，也是第h层第一个节点的序号
	return T[i-1]; 
}

int Assign_Sq(SqBiTree T, Position s, char value)
{
	int i = (int)pow(2, s.level-1) + s.order-1;
	if(value=='\0' && (T[2*i-1]!='\0' || T[2*i]!='\0'))//把空信息赋给树的中间(孩子不为0)显然不行 
		return 0;
	else if(value!='0' && T[i/2-1]=='\0')//把非空信息赋给树的后面不搭边的节点(父母是0)显然不行
		return 0;
	else 
		T[i-1] = value;
	return 1; 
}

char Parent_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')//空树 
		return '\0';
	for(int i=1; i<=100; i++)//找到e 
	{
		if(T[i-1]==e)
			return T[i/2-1];
	}
	return '\0';	//没找到e 
}

char LeftChild_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')
		return '\0';
	for(int i=1; i<=100; i++)
	{
		if(T[i-1]==e)
			return T[2*i-1];
	}
	return '\0';
}

char RightChild_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')
		return '\0';
	for(int i=1; i<=100; i++)
	{
		if(T[i-1]==e)
			return T[2*i];
	}
	return '\0';
}

char LeftBrother_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')
		return '\0';
	for(int i=1; i<=100; i++)
	{
		if(T[i-1]==e && i%2!=0)
			return T[i-2];
	}
	return '\0';
}

char RightBrother_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')
		return '\0';
	for(int i=1; i<=100; i++)
	{
		if(T[i-1]==e && i%2==0)
			return T[i];
	}
	return '\0';
}

int LevelOrderTraverse_Sq(SqBiTree T, void(Visit)(char))
{
	int len = BiTreeLength_Sq(T);//这里len是找到的最后一个节点是第几个 
	for(int i=1; i<=len; i++)
	{
		if(T[i-1]!='\0')//所以层序遍历只不过是按序号访问二叉树每个节点而已 
			Visit(T[i-1]);
	} 
	return 1;
}

int PreOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i)
{
	if(T[i]=='\0')
		return 0;
	else
	{
		Visit(T[i]);
		PreOrderTraverse_Sq(T, Visit, 2*i+1);
		PreOrderTraverse_Sq(T, Visit, 2*i+2);
		return 1;
	}
}

int InOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i)
{
	if(T[i]=='\0')
		return 0;
	else
	{
		InOrderTraverse_Sq(T, Visit, 2*i+1);
		Visit(T[i]);
		InOrderTraverse_Sq(T, Visit, 2*i+2);
		return 1;
	}
}

int PostOrderTraverse_Sq(SqBiTree T, void(Visit)(char), int i)
{
	if(T[i]=='\0')
		return 0;
	else
	{
		PostOrderTraverse_Sq(T, Visit, 2*i+1);
		PostOrderTraverse_Sq(T, Visit, 2*i+2);
		Visit(T[i]);
		return 1;
	}
}

int Print_Sq(SqBiTree T)//此函数答案没有注释，无法看懂!!!!!!!!!! 
{
	char tmp[100][100] = {};
	int level = BiTreeDepth_Sq(T);
	for(int i=1; i<=level; i++)//遍历每层的每个元素 
	{
		for(int j=1; j<=(int)pow(2, i-1); j++)
			tmp[i-1][(int)pow(2, level-i) + (j-1)*(int)pow(2, level-i+1) - 1] = T[(int)pow(2, i-1)-1+j-1];
	}
	
	for(int i=0; i<level; i++)//遍历每层 
	{
		for(int j=0; j<2*(int)pow(2, level-1) - 1; j++)//遍历每层的每个元素 
		{
			if(tmp[i][j]!='\0')
				printf("%c", tmp[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 1;
}
