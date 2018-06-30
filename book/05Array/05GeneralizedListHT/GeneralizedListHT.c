#include "GeneralizedListHT.h"

int InitGList_HT(GLNode **L)
{
	*L = NULL;
}

int sever_GL(SString hstr, SString str)
{
	int len = StrLength_Sq(str);//Ҫ�ָ���ַ������� 
	int i = 0;//�������� 
	int layer = 0;//��ʾ��ǰ�������Ų��� 
	SString ch;//��¼ÿ��������char 
	do
	{
		i++;
		SubString_Sq(ch, str, i, 1);
		if(ch[1]=='(')
			layer++;
		if(ch[1]==')')
			layer--;
	}while(i<len && (ch[1]!=',' || layer!=0));//ֻҪû�б����꣬û���������Ż��������˶��ŵ������ڽڵ��еĶ��ţ���һֱ���� 
				//�����������ѭ���������˶��ţ�λ�þ���i 
	if(i<len)
	{
		SubString_Sq(hstr, str, 1, i-1);
		SubString_Sq(str, str, i+1, len-i);
	}
	else		//������������������˵��û�ҵ����ţ���ô�����ַ�������ǰ׺����׺û�� 
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
	if(StrCompare_Sq(S, emp)==0)//����ַ���Ϊ��(��ȷ���0)���ʹ����չ���� 
		*L = NULL;
	else
	{
		(*L) = (GLNode*)malloc(sizeof(GLNode));
		if(!(*L))
			return 0;
		
		if(StrLength_Sq(S)==1)//��ԭ�ӹ����
		{
			(*L)->type = Atom;//��Ȼ*L��ȡ������������ǹ�����Ǹ���ָ�룬������-> 
			(*L)->Union.atom = S[1];//��������ص��ַ�����ֵ����������ԭ����
			(*L)->mark = 0; //���Ժ���õ� 
		}
		else				//�ǵ�ԭ�ӹ���� 
		{
			(*L)->type = List;
			(*L)->mark = 0; //
			GLNode* p = *L; //�������ʼ��LΪp���Ա�ı���L���Ǻ��滹����ԭ����L 
			SString sub;
			SubString_Sq(sub, S, 2, StrLength_Sq(S)-2);//ȥ��L���������ţ��õ�û�����ŵĹ����sub��L�����sub 
			SString hsub;
			GLNode* q;
			do
			{
				sever_GL(hsub, sub);//�����sub�ı�ͷ��sub�����sub�ı�β��Ҳ����L�Ѿ������sub�ı�β 
				CreateGList_HT(&(p->Union.ptr.hp), hsub);//�ڱ�ͷ�ظ������ӹ����
				q = p;//������������ͷû�б�β��״̬Ϊq��Ҳ����q������ѭ�������յı�ͷ 
				if(!StrEmpty_Sq(sub))//�����β 
				{
					p = (GLNode*)malloc(sizeof(GLNode));
					if(!p)
						return 0;
					
					p->type = List;
					p->mark = 0;
					q->Union.ptr.tp = p;//���ӱ�β��Ȼ����ѭ��������β�ı�ͷ 
				} 
			}while(!StrEmpty_Sq(sub));
			q->Union.ptr.tp = NULL;//����βû�ˣ��ÿ� 
		} 
	}
	return 1;
}

int ClearGList_HT(GLNode **L)
{
	if(!(*L))
		return 0;
	else			//�����漰�ݹ鶼Ҫ��else����Ȼ�����˳�������ߣ����� 
	{
		if((*L)->type==Atom)//ɾ��ԭ�ӽڵ� 
		{
			free(*L);
			(*L) = NULL;
		}
		else				//ɾ����ڵ� 
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
		*L = (GLNode*)malloc(sizeof(GLNode));//T����˵�����Ը��ƣ�����L�Ŀռ� 
		if(!(*L))
			return 0;
			
		(*L)->type = T->type;//copy���� 
		if(T->type==Atom)//�����ԭ�ӣ���copyԭ�� 
			(*L)->Union.atom = T->Union.atom;
		else			//����Ǳ���copy�� 
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
		return 1;//�ձ����Ϊ1
	if(L->type == Atom)
		return 0;//ԭ�����Ϊ0
	int max = 0;
	int deep;
	GLNode* p = L;
	while(p)
	{
		deep = GListDepth_HT(p->Union.ptr.hp);//ͷ������
		if(deep>max)
			max = deep; 
		p = p->Union.ptr.tp;
	} 
	return max + 1;//�������Ҫ��������һ������ 
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
	p->Union.ptr.hp = e;//��e��L��װ��p���ֱ���ͷ��β������ڰ�p����L 
	p->Union.ptr.tp = *L;
	*L = p;
	return 1;
}

int DeleteFirst_HT(GLNode **L, GLNode **e)
{
	if(!(*L))
		return 0;
		
	GLNode* p = *L;
	*L = (*L)->Union.ptr.tp;//��L�ı�β����L
	CopyGList_HT(e, p->Union.ptr.hp);//p��ʱ��������L��ȡ����ͷԪ��
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
	if(!L)//�����գ���������������һ��ָ���ڱ�ͷ����ͷ�ǣ�����һ��ָ���ڱ�β����ʱ���ǰ������� 
	{
		if(mark==Head)
			printf("()");
		else
			printf(")");
	}
	else	//������գ�������� 
	{
		if(L->type==Atom)
			printf("%c", L->Union.atom);
		else
		{
			if(mark==Head)//�����ԭ�ӵı������֮ǰ�������ͷ�ķ��� 
				printf("(");
			else
				printf(",");
			
			Output_HT(L->Union.ptr.hp, Head);
			Output_HT(L->Union.ptr.tp, Tail);
		}
	}
	return 1;
}
