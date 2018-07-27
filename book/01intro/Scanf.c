/*�Զ�������¼�뺯������txt�ж�ȡ����������ֻ��Ӣ��*/

#ifndef SCANF_C
#define SCANF_C

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

int Scanf(FILE *fp, char *format, ...)//����ÿ�ζ������ַ����� 
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
		while((tmp=getc(fp))!=EOF)//�������з�Ӣ�� 
		{
			if((tmp>=0 && tmp<=127))//0-127����ascii���������Ӣ���ַ������ȣ���������ĵ����žͻᳬ����Χ��������ַ�ungetc���ص����У��Ͷ����� 
			{
				ungetc(tmp, fp);
				break;
			}
		}
		
		if(tmp==EOF)//����������ַ���end of fileҲ����\n 
			break;
		
		if(format[k-1]=='c')//��ȡ�ַ� 
		{
			ch = va_arg(ap, char*);//�����Ĳ�����һ��char�͵�ָ��������������ն������ַ� 
			
			if(tmp!=EOF)
				count += fscanf(fp, "%c", ch);//����ȡ���ַ���ֵ��ch�����Ҹ���+1 
		}
		
		if(format[k-1]=='d')//��ȡ���� 
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
		
		if(format[k-1]=='f')//��ȡ������ 
		{
			f = va_arg(ap, float*);
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0'&&tmp<='9')||tmp=='-'||tmp=='+'||tmp=='.')
				{
					ungetc(tmp, fp);
					break;
				}
			}
			if(tmp!=EOF)
				count += fscanf(fp, "%f", f);
		}
		
		if(format[k-1]=='s')//��ȡ�ַ���
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

