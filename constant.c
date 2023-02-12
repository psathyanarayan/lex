#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void input();
void output();
void constant();
void change();

int n;

struct expr
{
    char op[2],op1[5],op2[2],res[5];
    int flag;
}arr[10];

void input()
{
    int i;
    char res1[10];
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i].op);
        scanf("%s",arr[i].op1);
        scanf("%s",arr[i].op2);
        scanf("%s",arr[i].res);
        arr[i].flag = 0;
    }

}

void constant()
{
    int i,op1,op2,res;
    char op,res1[10];
    for(i=0;i<n;i++)
    {
        if(isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op,"=")==0)
        {
            printf("is  %s",arr[i].op1);
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];
            switch(op){
                case '+' :  res = op1+op2;
                            break;
                case '-' :  res = op1-op2;
                            break;
                case '*' :  res = op1*op2;
                            break;
                case '/' :  res = op1/op2;
                            break;
                case '=' :  res = op1;
                            break;
                

            }
            sprintf(res1,"%d",res);
            arr[i].flag = 1;
            change(i,res1);

        }
    }
}

void change( int p, char *res)
{
    int i;
    for(i=p+1;i<n;i++)
    {
        if(strcmp(arr[p].res,arr[i].op1)==0)
        {
            strcpy(arr[i].op1,res);
        }
        else if(strcmp(arr[p].res,arr[i].op2)==0)
        {
            strcpy(arr[i].op2,res);
        }
    }
}

void output()
{
    int i =0;
    for (i=0;i<n;i++)
    {
        if(!arr[i].flag)
        {
            printf("\n%s %s %s %s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res); 
        }
    }
}

void main()
{
    input();
    constant();
    output();
}
