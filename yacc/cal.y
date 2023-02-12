%{
	#include<stdio.h>
	int flag = 0;
	
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression : E{
	printf("Result is %d\n",$$);
	return 0;
}
E:E'+'E {$$ = $1+$3;}
 |E'-'E {$$ = $1-$3;}
 |E'*'E {$$ = $1*$3;}
 |E'%'E {$$ = $1%$3;}
 |E'/'E {$$ = $1/$3;}
 |'('E')' {$$ = $2;}
 |NUMBER {$$ = $1;}
;
%%

void main()
{
	yyparse();
	if(flag ==0)
	{
		printf("\nExpression evaluated successfully\n");
	}
}
int yyerror(char *x)
{
	printf("\nNot successful\n");
	flag = 1;
}
