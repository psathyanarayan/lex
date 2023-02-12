#include <stdio.h>
#include <string.h>
int i, j, l ,nonTerminal = 90;
char str[100], left[15], right[15]; 
struct exp
{
    int pos; 
    char op;
} K[10];
char operators[] = {'=', '/', '*', '+', '-'};

void explore();
void fleft(int);
void fright(int); 
int check(int x);

 

void main() 
{

    printf("\t\tINTERMEDIATE CODE GENERATION\n\n"); 
    printf("Enter the Expression : ");
    scanf("%s", str);
    printf("\n Intermediate code \n"); 

    for (l = 0; l < 5; l++) // l is for the op array
        for (i = 0; str[i] != '\0'; i++) //Checking till the end of the string
            if (str[i] == operators[l]) // Checking the character is an operator
            {
                K[j].pos = i;
                K[j++].op = operators[l]; 
            }
    explore(); 
}
void explore() 
{
    i = 1;
    while (K[i].op != '\0') 
    {
        fleft(K[i].pos); 
        fright(K[i].pos);
        str[K[i].pos] = nonTerminal--;
        printf("\t%c = %s%c%s\n", str[K[i].pos], left, K[i].op, right); 
        i++;
    }
    fright(-1); 
    fleft(strlen(str));
    printf("\t%s = %s", right, left); 
}
void fleft(int x) 
{
    int w = 0, flag = 0;
    x--;
    while (check(x)) 
    {
        if (str[x] != '$' && flag == 0)                                
        { 
            left[w++] = str[x];
            left[w] = '\0'; 
            str[x] = '$'; 
            flag = 1;
        } 
    x--;
    } 
}
void fright(int x) 
{
    int w = 0, flag = 0; 
    x++;
    while (check(x))                    
    {
        if (str[x] != '$' && flag == 0)                                
        { 
            right[w++] = str[x];
            right[w] = '\0'; 
            str[x] = '$'; 
            flag = 1;
        } 
        x++;
    } 
}
int check(int x) 
{
    int flag = 1; 
    switch (str[x]) 
    {
        case '+':
        case '=':
        case '-':
        case '/':
        case '\0':
        case '*':
        flag = 0; 
    }
    if (x == 1) 
        flag = 0;
    return flag; 
}
