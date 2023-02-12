#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char keyword[30][30] = {"int","char","float","void","main","printf","return"};
char ch,str[50];
int i,l=0,t=0,flag,j;
int main()
{
	flag = 0;
	FILE *fin,*fout;
	i=0;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");
	fprintf(fout,"Line number\t\t\tToken number\t\t\tName\n");
	while(!feof(fin))
	{
		ch = fgetc(fin);
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			t++;
			fprintf(fout,"%11d\t\t\t%12d\t\t\tOperator\n",l,t);
		}
		else if(ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		{
			t++;
                        fprintf(fout,"%11d\t\t\t%12d\t\t\tSpecial Characters\n",l,t);
		}
		else if(isdigit(ch))
		{
			t++;
                        fprintf(fout,"%11d\t\t\t%12d\t\t\tDigit\n",l,t);
		}
		else if(isalpha(ch))
		{
			str[i] = ch;
			i++;
			ch = fgetc(fin);
			while (isalnum(ch) && ch != ' ')
			{
				str[i] = ch;
				i++;
				ch = fgetc(fin);
			}
			str[i] = '\0';
			for(j=0;j<=30;j++)
			{
				if(strcmp(str,keyword[j])==0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				t++;
                        	fprintf(fout,"%11d\t\t\t%12d\t\t\tKeyword %s\n",l,t,str);
			}
			else
			{
				t++;
                        	fprintf(fout,"%11d\t\t\t%12d\t\t\tIdentifier %s\n",l,t,str);
			}
		}
		else if(ch == '\n')
			l++;
	}
}

