typedef struct
{
	int* elem;
	int  length;//已经用的有效数据的长度 
	int  listsize;//分配总容量，不管里面有没有东西都不变 
}SqList;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;
