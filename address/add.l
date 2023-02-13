%{
    #include<stdio.h>
%}

%%
[a-zA-Z]+[ ]:[ ][a-zA-Z]+ {
    printf("Valid\n");
}
[a-zA-Z]+[ ]:[ ][0-9]+ {
    printf("Valid\n");
}
[a-zA-Z]+[ ]:[ ][0-9]+-[0-9]+ {
    printf("Valid\n");
}
.* {printf("na");}
%%

int main()
{
    yyin = fopen("input.txt","r");
    yylex();
    /*
    Name : name
    Place : place
    Pin : 999999
    Phone : 9999-9999999
    */
}

int yywrap()
{
    return 1;
}
