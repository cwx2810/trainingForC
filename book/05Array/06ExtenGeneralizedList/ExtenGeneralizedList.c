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
	StrAssign_Sq(emp, "()");//���ÿ��ַ������� 
	
	SString sub;
	StrCopy_Sq(sub, S);
	SString hsub;
	sever_E(hsub, sub);//���ı��ַ���S�������趨hsub��sub����ͷ����β�� 
	
	*L = (GLNode*)malloc(sizeof(GLNode));//����ռ� 
	if(!(*L))
		return 0;
		
	/*ͷ��㴦��*/
	if(!StrCompare_Sq(hsub, emp))//��ͷ��㴦�� 
	{
		(*L)->type = List;
		(*L)->Union.hp = NULL;
	}
	else
	{
		if(StrLength_Sq(hsub)==1)//��Ԫ��ͷ��� 
		{
			(*L)->type = Atom;
			(*L)->Union.atom = hsub[1];
		}
		else					//��ڵ� 
		{
			(*L)->type = List;
			SString tmp;
			SubString_Sq(tmp, hsub, 2, StrLength_Sq(hsub)-2);//ȥ����
			CreateGList_E(&((*L)->Union.hp), tmp);//�ݹ鴴��ͷ��� 
		}
	}
	/*β����*/
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
			GLNode* p = (*L)->tp;//����βָ�룬ԭ��ֻ�б�β�ݹ� 
			free(*L);
			(*L) = NULL;
			if(p)
				DestroyGList_E(&p);
		}
		else
		{
			GLNode* h = (*L)->Union.hp;//����ͷβָ�룬���б�ͷ��β����Ҫ�ݹ� 
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
		if(T->type==Atom)//�����ԭ�Ӿ͸���ԭ�� 
		{
			(*L)->type = Atom;
			(*L)->Union.atom = T->Union.atom;
		}
		else			//����Ǳ�͸��Ʊ� 
		{
			(*L)->type = List;
			if(T->Union.hp)//��Ҫ�ǿղźõݹ飬����ֱ���ÿգ���Ȼ����ɴ���NULL�Ĳ��� 
				CopyGList_E(&((*L)->Union.hp), T->Union.hp);
			else
				(*L)->Union.hp = NULL;
		}
		
		if(T->tp)//�����β���о͵ݹ飬û�о��ÿ� 
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
	
	if(L->type==List && L->Union.hp==NULL)//�ձ����Ϊ1��ע�⣡L���ǿձ��ǲ����� 
		return 1;
	else if(L->type==Atom)//ԭ�ӽڵ����Ϊ0 
		return 0;
	else
	{
		int max = 0;
		int deep;
		GLNode* p = L->Union.hp;
		while(p)
		{
			deep = GListDepth_E(p);//�ҵ��������� 
			if(deep>max)
				max = deep;
			p = p->tp;//���� 
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
	if(!L || L->Union.hp==NULL)//L�����ڻ����ǿձ� 
		return 0;
		
	GLNode* t = L->Union.hp->tp;//t��ʱ��ų�ͷ�������ı�β 
	L->Union.hp->tp = NULL;//��ͷ������ض� 
	GLNode* h;
	CopyGList_E(&h, L->Union.hp);//��������ͷ����h
	L->Union.hp->tp = t;//�ָ���β 
	return h; //���ر�ͷ 
}

GLNode* GetTail_E(GLNode* L)
{
	if(!L || L->Union.hp==NULL)
		return 0;
	
	GLNode* t;
	InitGList_E(&t);//������������β 
	GLNode* p = L->Union.hp;//pָ��L��ͷ�� 
	do
	{
		p = p->tp;
	}while(p && p->tp);//������pָ��L��β�� 
	t->Union.hp = p;//�����β 
	return t;
}

int InsertFirst_E(GLNode **L, GLNode *e)
{
	if(!(*L))
		return 0;
	
	GLNode* p;
	CopyGList_E(&p, e);//��e��װ�������ڵ�
	p->tp = (*L)->Union.hp;
	(*L)->Union.hp = p;
	return 1; 
}

int DeleteFirst_E(GLNode **L, GLNode **e)
{
	if(!(*L) || (*L)->Union.hp==NULL)
		return 0;
	
	GLNode* p = (*L)->Union.hp;//����ԭ����ͷָ�� 
	(*L)->Union.hp = p->tp;//ԭ����ͷָ��ָ����һ���ڵ� 
	p->tp = NULL;//ԭ����ͷָ��next���ÿ�
	*e = p;
	return 1; 
}

int TraverseGList_E(GLNode* L, void(Visit)(char))
{
	if(!L)
		return 0;
	else
	{
		if(L->type==List)//������ͷ��list����
			TraverseGList_E(L->Union.hp, Visit);
		else			//������ͷ��atom���� 
			Visit(L->Union.atom); 
		TraverseGList_E(L->tp, Visit);//������β
		return 1; 
	}
}

int Output_E(GLNode* L)
{
	if(!L)
		return 0;
	else
	{
		if(L->type==List)		//�����ڵ� 
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
		else					//����ԭ�ӽڵ� 
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

