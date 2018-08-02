#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"

#define NULLKEY -2
#define DUPILICATE -1
#define Equal(a,b) ((a)==(b))

//ȫ�ֱ�������ϣ������������һ�����ʵ���������
int hashsize[] = {7,13,17,101,211,307,401,503,601,701,809,907,997};


typedef struct
{
	int* elem;
	int length;//��ǰ��ϣ������Ĺؼ��ָ��� 
	int sizeindex;//hashsize[sizeindex]Ϊ��ǰ���� 
}HashTable;

int InitHash(HashTable* H);

int CreateHash(HashTable* H, Table T);

int SearchHash(HashTable H, int key, int* p, int* count);//pָ����ҳɹ����Ԫ��λ�ã�count��¼��ͻ���� 

int InsertHash(HashTable* H, int key);

int RecreateHash(HashTable* H);//�ؽ���ϣ�� 

int Hash(HashTable H, int key);//��ϣ����

int collision(int* p, int count);//��ͻ�������Ŷ�ַ��Ѱ����һ��̽��λ��

int PrintHash(HashTable H); 
