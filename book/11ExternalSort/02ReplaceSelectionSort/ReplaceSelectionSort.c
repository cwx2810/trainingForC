#include "ReplaceSelectionSort.h"

int Replace_Selection(FILE* fp_in, int ls[6], RecordNode wa[6])
{
	FILE* fp_out;
	char str1[100], str2[100], str3[100] = ".txt";
	
	Construct_Loser(fp_in, ls, wa);
	
	maxNumber = currentNumber = 1;//��ʼ�� ���κź͵�ǰ��ʼ�κ�Ϊ1 
	
	system("md tmpfile");
	
	while(currentNumber<=maxNumber)
	{
		strcpy(str1, "tmpfile/");//ƴ��tmpfile/
		itoa(originalpart, str2, 10);//���鲢�θ���ת�����ַ���xxxx
		strcat(str1, strcat(str2, str3)); //ƴ��tmpfile/xxxx.txt 
		
		fp_out = fopen(str1, "w+");//�洢��fpout 
		
		get_run(fp_in, fp_out, ls, wa);//���һ����ʼ�鲢��
		fprintf(fp_out, "%d", INT_MAX);//��ʾд��ν�����־
		fclose(fp_out);
		originalpart++;
		currentNumber = wa[ls[0]].num;//������һ�εĶκ� 
	}
	
	return 1;
}

int get_run(FILE* fp_in, FILE* fp_out, int ls[6], RecordNode wa[6])
{
	while(wa[ls[0]].num == currentNumber)//���������κ�==��ʼ�κ�
	{
		int p = ls[0];//pָʾλ�� 
		int minimax = wa[p].key;
		fprintf(fp_out, "%d, ", wa[p].rec.key);//��ѡ����minimaxд��fpout
		
		//������һ��¼
		if(Scanf(fp_in, "%d", &(wa[p].rec.key)) != 1)//��ȡʧ�� 
		{
			wa[p].num = maxNumber + 1;
			wa[p].key = INT_MAX;
		} 
		else
		{
			wa[p].key = wa[p].rec.key;
			
			if(wa[p].key < minimax)//�¶���ļ�¼������һ�� 
			{
				maxNumber = currentNumber + 1;
				wa[p].num = maxNumber;
			}
			else
				wa[p].num = currentNumber;//�¶���ļ�¼���ڵ�ǰ�� 
		}
		Select_MiniMax(ls, wa, p);//ѡ���µ�minimax 
	} 
	return 1;
}

int Select_MiniMax(int ls[6], RecordNode wa[6], int p)
{
	int father, q;
	for(father=(6+p)/2, q=ls[father]; father>0; father=father/2, q=ls[father])
	{
		if(wa[q].num<wa[p].num || wa[q].num==wa[p].num && wa[q].key<wa[p].key)
		{
			int tmp = p;
			p = ls[father];//pָ���µ�ʤ���� 
			ls[father] = tmp;
		}
	}
	ls[0] = p;
	return 1;
}

int Construct_Loser(FILE* fp_in, int ls[6], RecordNode wa[6])
{
	//��������ʼ�� 
	for(int i=0; i<6; i++)
		wa[i].num = wa[i].key = ls[i] = 0;
		
	for(int i=5; i>=0; i--)
	{
		Scanf(fp_in, "%d", &(wa[i].rec.key));//����һ����¼
		wa[i].key = wa[i].rec.key;//��ȡ�ؼ���
		wa[i].num = 1;//���öκ� 
		Select_MiniMax(ls, wa, i);//�������� 
	}
	return 1;
}
