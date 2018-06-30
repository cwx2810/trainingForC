#include "GeneralizedListHT.h"

int InitGList_HT(GLNode **L)
{
	*L = NULL;
}

int sever_GL(SString hstr, SString str)
{
	int len = StrLength_Sq(str);//要分割的字符串长度 
	int i = 0;//遍历变量 
	int layer = 0;//表示当前所在括号层数 
	SString ch;//记录每个遇到的char 
	do
	{
		i++;
		SubString_Sq(ch, str, i, 1);
		if(ch[1]=='(')
			layer++;
		if(ch[1]==')')
			layer--;
	}while(i<len && (ch[1]!=',' || layer!=0));//只要没有遍历完，没有遇到逗号或者遇到了逗号但是是在节点中的逗号，就一直遍历 
				//正常情况打破循环是遇到了逗号，位置就在i 
	if(i<len)
	{
		SubString_Sq(hstr, str, 1, i-1);
		SubString_Sq(str, str, i+1, len-i);
	}
	else		//如果发生了其他情况，说明没找到逗号，那么整个字符串都是前缀，后缀没了 
	{
		StrCopy_Sq(hstr, str);
		ClearString_Sq(str);
	}
	return 1;
}

int CreateGList_HT(GLNode **L, SString S)
{
	SString emp;
	StrAssign_Sq(emp, "()");
	if(StrCompare_Sq(S, emp)==0)//如果字符串为空(相等返回0)，就创建空广义表 
		*L = NULL;
	else
	{
		(*L) = (GLNode*)malloc(sizeof(GLNode));
		if(!(*L))
			return 0;
		
		if(StrLength_Sq(S)==1)//单原子广义表
		{
			(*L)->type = Atom;//虽然*L是取到广义表本身，但是广义表是个大指针，所以用-> 
			(*L)->Union.atom = S[1];//把数组承载的字符串的值赋给广义表的原子域
			(*L)->mark = 0; //在以后会用到 
		}
		else				//非单原子广义表 
		{
			(*L)->type = List;
			(*L)->mark = 0; //
			GLNode* p = *L; //保存最初始的L为p，以便改变了L但是后面还能用原来的L 
			SString sub;
			SubString_Sq(sub, S, 2, StrLength_Sq(S)-2);//去掉L最外层的括号，得到没有括号的广义表sub，L变成了sub 
			SString hsub;
			GLNode* q;
			do
			{
				sever_GL(hsub, sub);//分离出sub的表头，sub变成了sub的表尾，也就是L已经变成了sub的表尾 
				CreateGList_HT(&(p->Union.ptr.hp), hsub);//在表头重复创建子广义表
				q = p;//保存有完整表头没有表尾的状态为q，也就是q代表本轮循环的最终的表头 
				if(!StrEmpty_Sq(sub))//处理表尾 
				{
					p = (GLNode*)malloc(sizeof(GLNode));
					if(!p)
						return 0;
					
					p->type = List;
					p->mark = 0;
					q->Union.ptr.tp = p;//连接表尾，然后再循环创建表尾的表头 
				} 
			}while(!StrEmpty_Sq(sub));
			q->Union.ptr.tp = NULL;//最后表尾没了，置空 
		} 
	}
	return 1;
}

int ClearGList_HT(GLNode **L)
{
	if(!(*L))
		return 0;
	else			//凡是涉及递归都要用else，不然程序会顺序往下走，出错 
	{
		if((*L)->type==Atom)//删除原子节点 
		{
			free(*L);
			(*L) = NULL;
		}
		else				//删除表节点 
		{
			GLNode* h = (*L)->Union.ptr.hp;
			GLNode* t = (*L)->Union.ptr.tp;
			free(*L);
			(*L) = NULL;
			ClearGList_HT(&h);
			ClearGList_HT(&t);
		}
	}

	return 1;
}

int CopyGList_HT(GLNode **L, GLNode* T)
{
	if(!T)
		*L = NULL;
	else
	{
		*L = (GLNode*)malloc(sizeof(GLNode));//T不空说明可以复制，创建L的空间 
		if(!(*L))
			return 0;
			
		(*L)->type = T->type;//copy类型 
		if(T->type==Atom)//如果是原子，则copy原子 
			(*L)->Union.atom = T->Union.atom;
		else			//如果是表，则copy表 
		{
			CopyGList_HT(&((*L)->Union.ptr.hp), T->Union.ptr.hp);
			CopyGList_HT(&((*L)->Union.ptr.tp), T->Union.ptr.tp);
		}
	}
	return 1;
}

int GListLength_HT(GLNode* L)
{
	int count = 0;
	GLNode* p = L;
	while(p)
	{
		count++;
		p = p->Union.ptr.tp;
	}
	return count;
}

int GListDepth_HT(GLNode* L)
{
	if(!L)
		return 1;//空表深度为1
	if(L->type == Atom)
		return 0;//原子深度为0
	int max = 0;
	int deep;
	GLNode* p = L;
	while(p)
	{
		deep = GListDepth_HT(p->Union.ptr.hp);//头结点深度
		if(deep>max)
			max = deep; 
		p = p->Union.ptr.tp;
	} 
	return max + 1;//最终深度要加上最外一层括号 
}

int GListEmpty_HT(GLNode* L)
{
	return !L ? 1 : 0;
}

GLNode* GetHead_HT(GLNode* L)
{
	if(!L)
		return 0;
	GLNode* p;
	CopyGList_HT(&p, L->Union.ptr.hp);
	return p;
}

GLNode* GetTail_HT(GLNode* L)
{
	if(!L)
		return 0;
	GLNode* p;
	CopyGList_HT(&p, L->Union.ptr.tp);
	return p;
}

int InsertFirst_HT(GLNode **L, GLNode* e)
{
	GLNode* p = (GLNode*)malloc(sizeof(GLNode));
	if(!p)
		return 0;
	
	p->type = List;
	p->Union.ptr.hp = e;//把e和L组装进p，分别当做头和尾，最后在把p赋给L 
	p->Union.ptr.tp = *L;
	*L = p;
	return 1;
}

int DeleteFirst_HT(GLNode **L, GLNode **e)
{
	if(!(*L))
		return 0;
		
	GLNode* p = *L;
	*L = (*L)->Union.ptr.tp;//用L的表尾赋给L
	CopyGList_HT(e, p->Union.ptr.hp);//p此时是完整的L，取到表头元素
	free(p);
	p = NULL;
	return 1; 
}

int Traverse_HT(GLNode* L, void(Visit)(char))
{
	if(!L)
		return 0;
	else
	{
		if(L->type==Atom)
		Visit(L->Union.atom);
		else
		{
			Traverse_HT(L->Union.ptr.hp, Visit);
			Traverse_HT(L->Union.ptr.tp, Visit);
		}
	}

	return 1;
}

int Output_HT(GLNode* L, Mark mark)
{
	if(!L)//广义表空，表空有两种情况，一种指针在表头，表头是（），一种指针在表尾，此时配合前面输出） 
	{
		if(mark==Head)
			printf("()");
		else
			printf(")");
	}
	else	//广义表不空，正常输出 
	{
		if(L->type==Atom)
			printf("%c", L->Union.atom);
		else
		{
			if(mark==Head)//输出非原子的表，在输出之前先输出打头的符号 
				printf("(");
			else
				printf(",");
			
			Output_HT(L->Union.ptr.hp, Head);
			Output_HT(L->Union.ptr.tp, Tail);
		}
	}
	return 1;
}
