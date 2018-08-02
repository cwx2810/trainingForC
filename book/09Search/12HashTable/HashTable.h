#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"

#define NULLKEY -2
#define DUPILICATE -1
#define Equal(a,b) ((a)==(b))

//全局变量，哈希表容量递增表，一个合适的素数序列
int hashsize[] = {7,13,17,101,211,307,401,503,601,701,809,907,997};


typedef struct
{
	int* elem;
	int length;//当前哈希表包含的关键字个数 
	int sizeindex;//hashsize[sizeindex]为当前容量 
}HashTable;

int InitHash(HashTable* H);

int CreateHash(HashTable* H, Table T);

int SearchHash(HashTable H, int key, int* p, int* count);//p指向查找成功后的元素位置，count记录冲突次数 

int InsertHash(HashTable* H, int key);

int RecreateHash(HashTable* H);//重建哈希表 

int Hash(HashTable H, int key);//哈希函数

int collision(int* p, int count);//冲突处理，开放定址法寻找下一个探查位置

int PrintHash(HashTable H); 
