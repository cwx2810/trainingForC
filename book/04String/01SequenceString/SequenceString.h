#include <stdio.h>
#include <string.h>
#include "../../01intro/Status.h"

typedef unsigned char SString[256];//顺序串定义，用数组承载，0号存放串长 

int StrAssign_Sq(SString S, const char* chars);//将chars分配到串T中，也就是初始化生成串T 

int StrCopy_Sq(SString S, SString T);//把T复制到S中

int StrEmpty_Sq(SString S);

int StrCompare_Sq(SString S, SString T);//如果S大，返回值大于0，如果S小，返回值小于0，如果相等，返回值等于0 

int StrLength_Sq(SString S);

int ClearString_Sq(SString S);

int Concat_Sq(SString S, SString T1, SString T2);//把T1和T2拼接到S 

int SubString_Sq(SString Sub, SString S, int pos, int len);//用Sub承接S中第pos个字符开始len长度的子串 

int Index_Sq(SString S, SString T, int pos);//返回T在S中第pos个字符后第一次出现的位置 

int Index_Match(SString S, SString T, int pos);//串的模式匹配，不依赖其他串操作的匹配算法 

int Replace_Sq(SString S, SString T, SString V);//用V替换S中所有的不重叠的T

int StrInsert_Sq(SString S, int pos, SString T);//在S中的第pos个字符前插入T

int StrDelete_Sq(SString S, int pos, int len);//从第pos个字符开始删除len长度的子串 

int DestroyString_Sq(SString S);

int StrPrint_Sq(SString S);

