#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int n,i,j,m,val;
char a[30][30],f[50],ch;

void first(char ch);
void follow(char ch);

void first(char ch)
{
	int i;	
	if(!isupper(ch))
   	 {	
        	f[m++] = ch;
    	}	
	for(i=0;i<n;i++)
	{
			if(ch == a[i][0])
			{

				if(isupper(a[i][2]))
				{
					first(a[i][2]);
				}
				else if(islower(a[i][2]))
				{
					f[m++] = a[i][2];
				}
				else if(a[i][2] == '$')
				{
					follow(a[i][0]);
				}
			}
		
	}
}

void follow(char ch)
{
	int k,j;
	if(a[0][0] == ch)
	{
		f[m++] = '$';
	}
	for(k=0;k<n;k++)
	{
		for(j=2;j<strlen(a[k]);j++)
		{
			if(ch == a[k][j])
			{
				if(a[k][j+1] != '\0')
					       first(a[k][j+1]);
				else if(a[k][j+1] == '\0' && a[k][0]!= ch)
						follow(a[k][0]);
			}
		}
	}
}	


int main()
{
	printf("Enter the number of productions\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	do
	{
		m =0;
		printf("Enter the element whose first need to be calculated\n");
		scanf(" %c",&ch);
		first(ch);
		printf("first(%c) -> %s\n",ch,f);
		strcpy(f," ");
		m =0;
		follow(ch);
		printf("follow(%c) -> %s\n",ch,f);
		printf("Enter 1 to continue or 0 to stop\n");
		scanf("%d",&val);
	}while(val == 1);
}
