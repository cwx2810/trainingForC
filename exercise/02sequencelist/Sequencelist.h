typedef struct
{
	int* elem;
	int  length;//�Ѿ��õ���Ч���ݵĳ��� 
	int  listsize;//����������������������û�ж��������� 
}SqList;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;
