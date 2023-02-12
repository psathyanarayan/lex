#include<stdio.h>
#include<string.h>
char str[100],stack[100];
int n,i,j,z;
void check()
{
	for(z=0;z<strlen(stack);z++)
        {
                if(stack[z] == 'i' && stack[z+1] == 'd')
                {
                        stack[z] =  'E';
                        stack[z+1] = '\0';
                        printf("%s\t\t%s\t\tREDUCE id to E\n",str,stack);
                        j++;

                }
        }
	for(z=0;z<strlen(stack);z++)
	{
		if(stack[z] == 'E' && stack[z+1] == '+' && stack[z+2] == 'E')
		{
			stack[z] =  'E';
			stack[z+1] = '\0';
			stack[z+2] = '\0';
			printf("%s\t\t%s\t\tREDUCE E+E to %c\n",str,stack,stack[z]);
			i = i-2;
		}
	}
	for(z=0;z<strlen(stack);z++)
        {
                if(stack[z] == 'E' && stack[z+1] == '*' && stack[z+2] == 'E')
                {
                        stack[z] =  'E';
                        stack[z+1] = '\0';
                        stack[z+2] = '\0';
                        printf("%s\t\t%s\t\tREDUCE E*E to %c\n",str,stack,stack[z]);
			i = i-2;
                }
        }
	for(z=0;z<strlen(stack);z++)
        {
                if(stack[z] == '(' && stack[z+1] == 'E' && stack[z+2] == ')')
                {
                        stack[z] =  'E';
                        stack[z+1] = '\0';
                        stack[z+2] = '\0';
                        printf("%s\t\t%s\t\tREDUCE (E) to %c\n",str,stack,stack[z]);
                        i = i-2;

                }
       }
}
int main()
{
	printf("E->(E+E)\nE->(E*E)\nE->(E)\nE->id\n");
	printf("Enter the input string\n");
	scanf("%s",str);
	for(j = 0,i=0;j<strlen(str);j++,i++)
	{
		if(str[j] == 'i' && str[j+1] == 'd')
		{
			stack[i] = str[j];
			stack[i+1] = str[j+1];
			stack[i+2] = '\0';
			str[j] = ' ';
			str[j+1] = ' ';
			printf("%s\t\t%s\t\tSHIFT id\n",str,stack);
			check();
		}
		else
		{
			stack[i] = str[j];
			str[j] = ' ';
			printf("%s\t\t%s\t\tSHIFT %c\n",str,stack,stack[i]);
			check();
		}
	}
}
