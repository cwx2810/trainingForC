#include "GarbageCollection.h"

int MakeList(GLNode* G)
{
	int finished;//������ɱ��
	if(G && G->mark==0)
	{
		GLNode* t = NULL;
		GLNode* p = G;
		GLNode* q;
		finished = FALSE; 
		
		while(!finished)
		{
			while(p->mark==0)//��Ǳ�ͷ 
			{
				p->mark=1;
				q = p->Union.ptr.hp;//qָ��p�ı�ͷ
				
				if(q && q->mark==0)
				{
					if(q->type==Atom)//��ͷΪԭ�ӽڵ� 
						q->mark=1;
					else			//����������ͷ���ӱ� 
					{
						p->Union.ptr.hp = t;
						p->type = Atom;
						t = p;//tΪp��ĸ��ÿ�δ�tmp�в���p 
						p = q; 
					}
				} 
			}
			
			q = p->Union.ptr.tp;//��Ǳ�β 
			if(q && q->mark==0)
			{
				p->Union.ptr.tp = t;
				t = p;
				p = q;
			}
			else
			{
				while(t && t->type==List)//�ӱ�β���ݣ���ʵ���Ǵﵽջ��Ч�� 
				{
					q = t;
					t = q->Union.ptr.tp;
					q->Union.ptr.tp = p;
					p = q;
				}
				
				if(!t)
					finished = TRUE;	//��ɻ��� 
				else					//�ӱ�ͷ���� 
				{
					q = t;
					t = q->Union.ptr.hp;
					q->Union.ptr.hp = p;
					p = q;
					p->type = List;
				}						//�����ص���ͷ������β 
			}
		}
		return 1;
	}
	return 0;
}
