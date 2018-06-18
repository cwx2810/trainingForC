/*自定义数据录入函数，从txt中读取，跳过中文只读英文*/

#ifndef SCANF_C
#define SCANF_C

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

int Scanf(FILE *fp, char *format, ...)
{
	int *i;
	char *ch, *s;
	float *f;
	int count, k, len, n;
	int tmp;
	va_list ap;
	
	len = strlen(format);
	
	va_start(ap, format);
	
	for(count=0,k=2; k<=len; k=k+2)
	{
		while((tmp=getc(fp))!=EOF)//跳过所有非英文 
		{
			if((tmp>=0 && tmp<=127))
			{
				ungetc(tmp, fp);
				break;
			}
		}
		
		if(tmp==EOF)
			break;
		
		if(format[k-1]=='c')//读取字符 
		{
			ch = va_arg(ap, char*);
			
			if(tmp!=EOF)
				count += fscanf(fp, "%c", ch);
		}
		
		if(format[k-1]=='d')//读取整型 
		{
			i = va_arg(ap, int*);
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+')
				{
					ungetc(tmp, fp);
					break;
				}
			}
			
			if(tmp!=EOF)
				count += fscanf(fp, "%d", i);
		}
		
		if(format[k-1]=='s')//读取字符串
		{
			s = va_arg(ap, char*);
			
			while((tmp=getc(fp))!=EOF && (!isprint(tmp) || tmp==' '))
				;
			
			n=0;
			if(!feof(fp))
			{
				ungetc(tmp, fp);
				while((tmp=getc(fp))!=EOF)
				{
					if(isprint(tmp) && tmp!=' ')
						s[n+1] = tmp;
					else
						break;
				}
				ungetc(tmp, fp);
			}
			
			s[n] = '\0';
			
			count++;
		} 
	}
	
	va_end(ap);
	
	return count;
}

#endif

