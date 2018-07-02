#include "SeqBinaryTree.h"
#include <math.h>

int InitBiTree_Sq(SqBiTree T)
{
	for(int i=1; i<=100; i++)
		T[i-1] = '\0';//�սڵ���\0��� 
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
	//�������޷����٣���Ϊ��char[100]�Ľṹ�����������Լ������Ľṹ�� 
}

int BiTreeEmpty_Sq(SqBiTree T)
{
	return T[0]=='\0' ? 1 : 0;//���ڵ㶼���ˣ���Ȼ���������ǿյ� 
}

int CreateBiTree_Level(FILE *fp, SqBiTree T)
{
	char ch;
	int i = 1;
	while(Scanf(fp, "%c", &ch)==1 && ch!='\n')//�������char���ڲ���char���ǻ��з�
	{
		if(ch=='^')//��TestData�еĶ������սڵ���^��ʾ 
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
		T[i-1] = '\0';//�����ʵ��ֱ���ߵ���ײ㴴���սڵ� 
	else
	{
		T[i-1] = ch;//�������ڵ� 
		CreateBiTree_Pre(fp, T, 2*i);//�������Һ��� 
		CreateBiTree_Pre(fp, T, 2*i+1);
	}
	return 1;
}

int BiTreeLength_Sq(SqBiTree T)
{
	int len;
	for(len=100; len>=1; len--)//Ѱ�����һ���ڵ� 
	{
		if(T[len-1]!='\0')
			break;
	}
	return len;
}

int BiTreeDepth_Sq(SqBiTree T)
{
	int depth = 0;
	while((int)pow(2, depth)-1<BiTreeLength_Sq(T))//2^h - 1 = ���������ڵ��� 
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
	//���λ��s�ǵڶ������ڼ����ڵ� 
	int i = (int)pow(2, s.level-1) + s.order-1;//2^(h-1)����������ÿ��ڵ�����Ҳ�ǵ�h���һ���ڵ�����
	return T[i-1]; 
}

int Assign_Sq(SqBiTree T, Position s, char value)
{
	int i = (int)pow(2, s.level-1) + s.order-1;
	if(value=='\0' && (T[2*i-1]!='\0' || T[2*i]!='\0'))//�ѿ���Ϣ���������м�(���Ӳ�Ϊ0)��Ȼ���� 
		return 0;
	else if(value!='0' && T[i/2-1]=='\0')//�ѷǿ���Ϣ�������ĺ��治��ߵĽڵ�(��ĸ��0)��Ȼ����
		return 0;
	else 
		T[i-1] = value;
	return 1; 
}

char Parent_Sq(SqBiTree T, char e)
{
	if(T[0]=='\0')//���� 
		return '\0';
	for(int i=1; i<=100; i++)//�ҵ�e 
	{
		if(T[i-1]==e)
			return T[i/2-1];
	}
	return '\0';	//û�ҵ�e 
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
	int len = BiTreeLength_Sq(T);//����len���ҵ������һ���ڵ��ǵڼ��� 
	for(int i=1; i<=len; i++)
	{
		if(T[i-1]!='\0')//���Բ������ֻ�����ǰ���ŷ��ʶ�����ÿ���ڵ���� 
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

int Print_Sq(SqBiTree T)//�˺�����û��ע�ͣ��޷�����!!!!!!!!!! 
{
	char tmp[100][100] = {};
	int level = BiTreeDepth_Sq(T);
	for(int i=1; i<=level; i++)//����ÿ���ÿ��Ԫ�� 
	{
		for(int j=1; j<=(int)pow(2, i-1); j++)
			tmp[i-1][(int)pow(2, level-i) + (j-1)*(int)pow(2, level-i+1) - 1] = T[(int)pow(2, i-1)-1+j-1];
	}
	
	for(int i=0; i<level; i++)//����ÿ�� 
	{
		for(int j=0; j<2*(int)pow(2, level-1) - 1; j++)//����ÿ���ÿ��Ԫ�� 
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
