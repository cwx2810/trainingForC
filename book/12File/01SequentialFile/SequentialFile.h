#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

//主文件 
typedef struct
{
	int key;//账号 
	int balance;//余额 
}MainFile;

//事物文件
typedef struct
{
	char code;//操作 
	int key;//账号 
	int money;//金额变动 
}AffairFile;




