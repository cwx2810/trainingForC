#include <stdio.h>
#include <string.h>
#include "../../01intro/Status.h"

typedef unsigned char SString[256];//˳�򴮶��壬��������أ�0�Ŵ�Ŵ��� 

int StrAssign_Sq(SString S, const char* chars);//��chars���䵽��T�У�Ҳ���ǳ�ʼ�����ɴ�T 

int StrCopy_Sq(SString S, SString T);//��T���Ƶ�S��

int StrEmpty_Sq(SString S);

int StrCompare_Sq(SString S, SString T);//���S�󣬷���ֵ����0�����SС������ֵС��0�������ȣ�����ֵ����0 

int StrLength_Sq(SString S);

int ClearString_Sq(SString S);

int Concat_Sq(SString S, SString T1, SString T2);//��T1��T2ƴ�ӵ�S 

int SubString_Sq(SString Sub, SString S, int pos, int len);//��Sub�н�S�е�pos���ַ���ʼlen���ȵ��Ӵ� 

int Index_Sq(SString S, SString T, int pos);//����T��S�е�pos���ַ����һ�γ��ֵ�λ�� 

int Index_Match(SString S, SString T, int pos);//����ģʽƥ�䣬������������������ƥ���㷨 

int Replace_Sq(SString S, SString T, SString V);//��V�滻S�����еĲ��ص���T

int StrInsert_Sq(SString S, int pos, SString T);//��S�еĵ�pos���ַ�ǰ����T

int StrDelete_Sq(SString S, int pos, int len);//�ӵ�pos���ַ���ʼɾ��len���ȵ��Ӵ� 

int DestroyString_Sq(SString S);

int StrPrint_Sq(SString S);

