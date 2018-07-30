#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"
#include "../00Base/Base.c"
#include "../../06Tree/02BinaryTree/BinaryTree.c"

char ch[] = "\0ABCDEFGHI";

int FindAllWeight(float w[], Table T);//建立累计权值数组，每个位子存储之前的所有权值之和 

int MinBetweenWeight(float w[], int low, int high);
//借助累计权值数组，找出权值中某个权值对应的序号，这个位子左边所有权值之和和右边所有权值之和相差最小 

int NearlyOptimal(BiTNode* *BT, ElemType R[], float w[], int low, int high);//次优查找树构造函数的核心递归函数 
int CreateNearlyOptimal(BiTNode* *BT, Table T);//用有序表T构造次优查找树

int SearchKey(BiTNode* BT, int key);//判断关键字key是否在次优查找树中 

