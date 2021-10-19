%{

#include <stdio.h>

%}


%%

#.* {printf("\n%s is a preprocesor directive",yytext);}

int {printf("\n%s is a keyword",yytext);}


[0-9]+  {printf("\n%s is a number",yytext);}

.* {printf("Invalid Input");}

%%

int main()

{
    yylex();

}
