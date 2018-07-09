#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef enum
{
	Link,Thread
}PointerTag;

typedef struct TriBiNode
{
	char data;
	struct TriBiNode* lchild;
	struct TriBiNode* rchild;
	PointerTag LTag;
	PointerTag RTag;
	
	struct TriBiNode* parent;//˫�׽ڵ�ָ�룬һ�㲻ͬ�����ǵݹ�����������������������ã������������������ֻ�к������ 
}TriBiNode;

TriBiNode* pre;//ȫ�ֱ�����ָ��ǰС�ڵ����һ���ڵ�


//���ߺ��� 
int CreateBiTree_Tri(FILE* fp, TriBiNode **T);//������������������� 
//void CreateParentPtr(TriBiNode* T);//���������������С�ṹ�е�parentָ��ָ��ְ�
//TriBiNode* PostNextPtr(TriBiNode* T, TriBiNode* p);//��T��Ѱ�ҽڵ�p�ĺ�� 
 

//�㷨���� 
void InThreading_Tri(TriBiNode* p);//����ȫ�������������α�p������һ�������Ĺ��ߺ���      �������ԣ���������ͼ���� 

int InOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//�������������P��˳��ͬʱ����ȫ������ΪT 

int InOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//�ǵݹ�������� ȫ���������� 


//void PreThreading_Tri(TriBiNode* T);//�����������������ǰ��������˳��ֻ���ýڵ�ĺ������

//int PreOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//�������������P��˳�㽫����������

//int PreOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//�ǵݹ�������� ������������� 


//void PostThreading_Tri(TriBiNode* T);//�������������

//int PostOrderThreading_Tri(TriBiNode **T, TriBiNode* P);//��������������P�������������

//int PostOrderTraverse_Tri(TriBiNode* T, void(Visit)(char));//�ǵݹ�������� �������������

 
