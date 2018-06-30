#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../04String/01SequenceString/SequenceString.c"

typedef enum
{
	Head, Tail//������ͷβö�� 
}Mark;
typedef enum
{
	Atom, List//�����Ľڵ�����ö�٣�Atom=0��ԭ�ӽڵ㣬List=1�Ǳ�ڵ� 
}NodeType;

typedef struct GLNode
{
	union
	{
		int mark;//�������ϣ��ڵڰ��±����������ʹ�� 
	};
	
	NodeType type;//���ֽڵ�����
	
	union
	{
		char atom;//ԭ�ӽڵ��ֵ��
		struct
		{
			struct GLNode* hp;//�����ڵ�ͷָ�룬ָ��ͷ��� 
			struct GLNode* tp;//βָ�룬ָ���ڵ� 
		}ptr; //ָ���� 
	}Union; 			//������������������С����Ľڵ� 
	
}GLNode;				//����ṹ������������������� 

int InitGList_HT(GLNode **L);

int sever_GL(SString hstr, SString str);//���ַ����ָ�������֣���־�Ƕ��ţ�����ǰ�ǵ�һ���֣���ʵ���Ƿָ�ͷ�ͱ� 

int CreateGList_HT(GLNode **L, SString S);//���ַ������������

int ClearGList_HT(GLNode **L);//ֻ����գ��������� 

int CopyGList_HT(GLNode **L, GLNode* T);

int GListLength_HT(GLNode* L);

int GListDepth_HT(GLNode* L);

int GListEmpty_HT(GLNode* L);

GLNode* GetHead_HT(GLNode* L);

GLNode* GetTail_HT(GLNode* L);

int InsertFirst_HT(GLNode **L, GLNode* e);

int DeleteFirst_HT(GLNode **L, GLNode **e);

int Traverse_HT(GLNode* L, void(Visit)(char));

int Output_HT(GLNode* L, Mark mark); 
