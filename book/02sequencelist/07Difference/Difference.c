#include "Difference.h"

void Difference(int *L, int A[], int len_A, int B[], int len_B)
{
	InitSpace();
	*L = MallocSpace();//����ͷ��㣬��¼��AB��ͬ��Ԫ�� 
	int r = *L;//βָ��
	SPACE[r].pnext = 0;//����βָ���Ұָ�� 
	
	for(int i=0; i<len_A; i++)//¼��A������Ԫ�ص���̬���� 
	{
		int p = MallocSpace();
		SPACE[p].data = A[i];//����ռ䲢¼��A��ֵ 
		SPACE[r].pnext = p;//�ѿռ���뵽βָ�����
		r = p;//�ƶ�βָ�� 
	} 
	SPACE[r].pnext = 0;//���±���Ұָ��
	
	for(int i=0; i<len_B; i++)
	{
		int p = *L;//p��pnext�ֱ���ͷ���͵�һ���ڵ㣬�������ƶ��α� 
		int pnext = SPACE[*L].pnext;
		while(pnext && SPACE[pnext].data!=B[i])//����ǰ��¼���A�е�Ԫ����B 
		{
			p = pnext;
			pnext = SPACE[pnext].pnext;
		}
		if(!pnext)//�Ҳ���B������� 
		{
			int q = MallocSpace();
			SPACE[q].data = B[i];
			SPACE[r].pnext = q;
			r = q;
		}
		else     //�ҵ�B����ʱpΪ�ҵ������Ԫ�ص�ǰһ����pnextΪ�ҵ������Ԫ�أ�ɾ�� 
		{
			SPACE[p].pnext = SPACE[pnext].pnext;
			FreeSpace(pnext);
			
		}
	} 
	SPACE[r].pnext = 0;//���±���Ұָ��
	
}

