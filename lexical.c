#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    FILE *input,*output;
    int i,j,l=0,t=0,flag;
    char keyword[30][30] = {"int","char","float","double","if","else","for","do","while","return","void","main","printf"};
    char ch,str[30];
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");
    fprintf(output,"Line Number\t\tToken Number\t\tName\n");
    while(!feof(input))
    {
        i=0;
        flag = 0;
        ch = fgetc(input);
        if(ch == '/' && fgetc(input) == '/')
        {
            while(fgetc(input) != '\n')
            {}
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '-' || ch == '/')
        {
            fprintf(output,"%d\t\t%d\t\tOperator %c\n",l,t,ch);
            t++;
        }
        else if (ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '@' || ch == '#' || ch == '&' || ch == '|' || ch == '!' || ch == '[' || ch == ']' )
        {
            fprintf(output,"%d\t\t%d\t\tSpecial Symbol %c\n",l,t,ch);
            t++;
        }
        else if (isdigit(ch))
        {
            fprintf(output,"%d\t\t%d\t\tDigit %c\n",l,t,ch);
            t++;
        }
        else if(isalpha(ch))
        {
            str[i] = ch;
            i++;
            ch = fgetc(input);
            while(isalnum(ch) && ch != ' ')
            {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }
            str[i] = '\0';
            for(j=0;j<=30;j++)
            {
                if(strcmp(keyword[j],str)==0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                fprintf(output,"%d\t\t%d\t\tKeyword %s\n",l,t,str);
                t++;
            }
            else{
                fprintf(output,"%d\t\t%d\t\tIdentifier %s\n",l,t,str);
                t++;

            }
        }
        else if(ch == '\n'){
            l++;
        }
    }
}
