#include<stdio.h>
#include<string.h>

char str[100],*ip;

int S();
int L();
int LP();

int S()
{
	if(*ip == '(')
	{
		printf("%s\t\tS->(L)\n",ip);
		ip++;
		if(L())
		{
			if(*ip == ')')
			{
				ip++;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	else if (*ip == 'a')
	{
		ip++;
		printf("%s\t\tS->a\n",ip);
		return 1;
	}
}

int L()
{
	printf("%s\t\tL->SL'\n",ip);
	if(S())
	{
		if(LP())
		{
			return 1;		
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int LP()
{
	if(*ip == ','){
		printf("%s\t\tL'->,,SL'",ip);
		ip++;
		if(S())
		{
			if(LP())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		printf("%s\t\tL->e",ip);
		return 1;
	}
}


int main()
{
	printf("\nS->(L)\nS->a\nL->SL'\nL'->SL'\nL'->e\n");
	printf("Enter the input string");
	scanf("%s",str);
	ip = str;
	if(S())
	{
		printf("Expression validated successfully\n");
	}
	else{
		printf("Expression not evaluated successfully\n");
	}
}
