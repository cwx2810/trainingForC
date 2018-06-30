#include "ExtenGeneralizedList.h"

int InitGList_E(GLNode **L)
{
	*L = (GLNode*)malloc(sizeof(GLNode));
	if(!(*L))
		return 0;
	(*L)->type = List;
	(*L)->Union.hp = NULL;
	(*L)->tp = NULL;
	return 1;
}

int sever_E(SString hstr, SString str)
{
	int len = StrLength_Sq(str);
	int i = 0;
	SString ch;
	int layer = 0;
	do
	{
		i++;
		SubString_Sq(ch, str, i, 1);
		if(ch[1]=='(')
			layer++;
		if(ch[1]==')')
			layer--;
	}while(i<len && (ch[1]!=',' || layer!=0));
	if(i<len)
	{
		SubString_Sq(hstr, str, 1, i-1);
		SubString_Sq(str, str, i+1, len-i);
	}
	else
	{
		StrCopy_Sq(hstr, str);
		ClearString_Sq(str);
	}
	return 1;
}

int CreateGList_E(GLNode **L, SString S)
{
	SString emp;
	StrAssign_Sq(emp, "()");//设置空字符串条件 
	
	SString sub;
	StrCopy_Sq(sub, S);
	SString hsub;
	sever_E(hsub, sub);//不改变字符串S，重新设定hsub和sub代表头结点和尾表 
	
	*L = (GLNode*)malloc(sizeof(GLNode));//分配空间 
	if(!(*L))
		return 0;
		
	/*头结点处理*/
	if(!StrCompare_Sq(hsub, emp))//空头结点处理 
	{
		(*L)->type = List;
		(*L)->Union.hp = NULL;
	}
	else
	{
		if(StrLength_Sq(hsub)==1)//单元素头结点 
		{
			(*L)->type = Atom;
			(*L)->Union.atom = hsub[1];
		}
		else					//表节点 
		{
			(*L)->type = List;
			SString tmp;
			SubString_Sq(tmp, hsub, 2, StrLength_Sq(hsub)-2);//去括号
			CreateGList_E(&((*L)->Union.hp), tmp);//递归创建头结点 
		}
	}
	/*尾表处理*/
	if(StrEmpty_Sq(sub))
		(*L)->tp = NULL;
	else
		CreateGList_E(&((*L)->tp), sub);
	return 1;
}

int DestroyGList_E(GLNode **L)
{
	if(!(*L))
		return 0;
	else
	{
		if((*L)->type == Atom)
		{
			GLNode* p = (*L)->tp;//保存尾指针，原子只有表尾递归 
			free(*L);
			(*L) = NULL;
			if(p)
				DestroyGList_E(&p);
		}
		else
		{
			GLNode* h = (*L)->Union.hp;//保存头尾指针，表有表头表尾，都要递归 
			GLNode* t = (*L)->tp;
			free(*L);
			(*L) = NULL;
			if(h)
				DestroyGList_E(&h);
			if(t)
				DestroyGList_E(&t);
		}
		return 1;
	}
}

int CopyGList_E(GLNode **L, GLNode* T)
{
	if(!T)
		return 0;
	else
	{
		*L = (GLNode*)malloc(sizeof(GLNode));
		if(!(*L))
			return 0;
		if(T->type==Atom)//如过是原子就复制原子 
		{
			(*L)->type = Atom;
			(*L)->Union.atom = T->Union.atom;
		}
		else			//如果是表就复制表 
		{
			(*L)->type = List;
			if(T->Union.hp)//表要非空才好递归，否则直接置空，不然会造成传入NULL的参数 
				CopyGList_E(&((*L)->Union.hp), T->Union.hp);
			else
				(*L)->Union.hp = NULL;
		}
		
		if(T->tp)//处理表尾，有就递归，没有就置空 
			CopyGList_E(&((*L)->tp), T->tp);
		else
			(*L)->tp = NULL;
		return 1;
	}	
}

int GListLength_E(GLNode* L)
{
	if(!L)
		return 0;
	int count = 0;
	GLNode* p = L->Union.hp;
	while(p)
	{
		count++;
		p = p->tp;
	}
	return count;
}

int GListDepth_E(GLNode* L)
{
	if(!L)
		return 0;
	
	if(L->type==List && L->Union.hp==NULL)//空表深度为1，注意！L不是空表，是不存在 
		return 1;
	else if(L->type==Atom)//原子节点深度为0 
		return 0;
	else
	{
		int max = 0;
		int deep;
		GLNode* p = L->Union.hp;
		while(p)
		{
			deep = GListDepth_E(p);//找到最深的深度 
			if(deep>max)
				max = deep;
			p = p->tp;//遍历 
		}
		return max + 1;
	}
	
}

int GListEmpty_E(GLNode* L)
{
	if(!L)
		return 0;
	
	if(L->type==List && L->Union.hp==NULL && L->tp==NULL)
		return 1;
	else
		return 0;
}

GLNode* GetHead_E(GLNode* L)
{
	if(!L || L->Union.hp==NULL)//L不存在或者是空表 
		return 0;
		
	GLNode* t = L->Union.hp->tp;//t临时存放除头结点以外的表尾 
	L->Union.hp->tp = NULL;//从头结点后面截断 
	GLNode* h;
	CopyGList_E(&h, L->Union.hp);//单独将表头赋给h
	L->Union.hp->tp = t;//恢复表尾 
	return h; //返回表头 
}

GLNode* GetTail_E(GLNode* L)
{
	if(!L || L->Union.hp==NULL)
		return 0;
	
	GLNode* t;
	InitGList_E(&t);//建立广义表保存表尾 
	GLNode* p = L->Union.hp;//p指向L的头部 
	do
	{
		p = p->tp;
	}while(p && p->tp);//遍历到p指向L的尾部 
	t->Union.hp = p;//保存表尾 
	return t;
}

int InsertFirst_E(GLNode **L, GLNode *e)
{
	if(!(*L))
		return 0;
	
	GLNode* p;
	CopyGList_E(&p, e);//将e安装进广义表节点
	p->tp = (*L)->Union.hp;
	(*L)->Union.hp = p;
	return 1; 
}

int DeleteFirst_E(GLNode **L, GLNode **e)
{
	if(!(*L) || (*L)->Union.hp==NULL)
		return 0;
	
	GLNode* p = (*L)->Union.hp;//保存原来的头指针 
	(*L)->Union.hp = p->tp;//原来的头指针指向下一个节点 
	p->tp = NULL;//原来的头指针next域置空
	*e = p;
	return 1; 
}

int TraverseGList_E(GLNode* L, void(Visit)(char))
{
	if(!L)
		return 0;
	else
	{
		if(L->type==List)//遍历表头的list类型
			TraverseGList_E(L->Union.hp, Visit);
		else			//遍历表头的atom类型 
			Visit(L->Union.atom); 
		TraverseGList_E(L->tp, Visit);//遍历表尾
		return 1; 
	}
}

int Output_E(GLNode* L)
{
	if(!L)
		return 0;
	else
	{
		if(L->type==List)		//处理表节点 
		{
			printf("(");	
			
			if(L->Union.hp)	
			{
				Output_E(L->Union.hp);
			}
			if(L->tp)		
			{
				printf("),");
				Output_E(L->tp);
			}
			else
				printf(")");
		}
		else					//处理原子节点 
		{
			printf("%c", L->Union.atom);
			if(L->tp)
			{
				printf(",");
				Output_E(L->tp);
			}
		}
		return 1;
	}
}

