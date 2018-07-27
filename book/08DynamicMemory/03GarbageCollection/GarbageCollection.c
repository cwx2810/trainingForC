#include "GarbageCollection.h"

int MakeList(GLNode* G)
{
	int finished;//访问完成标记
	if(G && G->mark==0)
	{
		GLNode* t = NULL;
		GLNode* p = G;
		GLNode* q;
		finished = FALSE; 
		
		while(!finished)
		{
			while(p->mark==0)//标记表头 
			{
				p->mark=1;
				q = p->Union.ptr.hp;//q指向p的表头
				
				if(q && q->mark==0)
				{
					if(q->type==Atom)//表头为原子节点 
						q->mark=1;
					else			//继续遍历表头的子表 
					{
						p->Union.ptr.hp = t;
						p->type = Atom;
						t = p;//t为p的母表，每次从tmp中产生p 
						p = q; 
					}
				} 
			}
			
			q = p->Union.ptr.tp;//标记表尾 
			if(q && q->mark==0)
			{
				p->Union.ptr.tp = t;
				t = p;
				p = q;
			}
			else
			{
				while(t && t->type==List)//从表尾回溯，其实就是达到栈的效果 
				{
					q = t;
					t = q->Union.ptr.tp;
					q->Union.ptr.tp = p;
					p = q;
				}
				
				if(!t)
					finished = TRUE;	//完成回溯 
				else					//从表头回溯 
				{
					q = t;
					t = q->Union.ptr.hp;
					q->Union.ptr.hp = p;
					p = q;
					p->type = List;
				}						//继续回到开头遍历表尾 
			}
		}
		return 1;
	}
	return 0;
}
