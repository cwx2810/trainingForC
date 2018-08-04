#include "ReplaceSelectionSort.h"

int Replace_Selection(FILE* fp_in, int ls[6], RecordNode wa[6])
{
	FILE* fp_out;
	char str1[100], str2[100], str3[100] = ".txt";
	
	Construct_Loser(fp_in, ls, wa);
	
	maxNumber = currentNumber = 1;//初始化 最大段号和当前初始段号为1 
	
	system("md tmpfile");
	
	while(currentNumber<=maxNumber)
	{
		strcpy(str1, "tmpfile/");//拼出tmpfile/
		itoa(originalpart, str2, 10);//将归并段个数转换成字符串xxxx
		strcat(str1, strcat(str2, str3)); //拼出tmpfile/xxxx.txt 
		
		fp_out = fopen(str1, "w+");//存储到fpout 
		
		get_run(fp_in, fp_out, ls, wa);//求得一个初始归并段
		fprintf(fp_out, "%d", INT_MAX);//表示写入段结束标志
		fclose(fp_out);
		originalpart++;
		currentNumber = wa[ls[0]].num;//设置下一段的段号 
	}
	
	return 1;
}

int get_run(FILE* fp_in, FILE* fp_out, int ls[6], RecordNode wa[6])
{
	while(wa[ls[0]].num == currentNumber)//当工作区段号==初始段号
	{
		int p = ls[0];//p指示位置 
		int minimax = wa[p].key;
		fprintf(fp_out, "%d, ", wa[p].rec.key);//将选出的minimax写入fpout
		
		//读入下一记录
		if(Scanf(fp_in, "%d", &(wa[p].rec.key)) != 1)//读取失败 
		{
			wa[p].num = maxNumber + 1;
			wa[p].key = INT_MAX;
		} 
		else
		{
			wa[p].key = wa[p].rec.key;
			
			if(wa[p].key < minimax)//新读入的记录属于下一段 
			{
				maxNumber = currentNumber + 1;
				wa[p].num = maxNumber;
			}
			else
				wa[p].num = currentNumber;//新读入的记录属于当前段 
		}
		Select_MiniMax(ls, wa, p);//选择新的minimax 
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
			p = ls[father];//p指向新的胜利者 
			ls[father] = tmp;
		}
	}
	ls[0] = p;
	return 1;
}

int Construct_Loser(FILE* fp_in, int ls[6], RecordNode wa[6])
{
	//工作区初始化 
	for(int i=0; i<6; i++)
		wa[i].num = wa[i].key = ls[i] = 0;
		
	for(int i=5; i>=0; i--)
	{
		Scanf(fp_in, "%d", &(wa[i].rec.key));//输入一个记录
		wa[i].key = wa[i].rec.key;//提取关键字
		wa[i].num = 1;//设置段号 
		Select_MiniMax(ls, wa, i);//调整败者 
	}
	return 1;
}
