%{
    #include<stdio.h>

%}
%%
[a-zA-Z_.0-9]+@[a-zA-Z0-9_.]+".com"|".in" {
    printf("Email Vaidated Successfully");
}
.* {printf("Invalid Email");}
%%

int yywrap()
{
    return 1;
}
int main()
{
    yyin = fopen("input.txt","r");
    yylex();
    fclose(yyin);
}