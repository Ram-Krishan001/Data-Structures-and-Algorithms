%{

#include <stdio.h>

%}


%%

#.* {printf("\n%s is a preprocesor directive",yytext);}

int {printf("\n%s is a keyword",yytext);}

float {printf("\n%s is a keyword",yytext);}

double {printf("\n%s is a keyword",yytext);}

char {printf("\n%s is a keyword",yytext);}

if {printf("\n%s is a keyword",yytext);}

else {printf("\n%s is a keyword",yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {printf("\n%s is an Identifier",yytext);}

[0-9]+  {printf("\n%s is a number",yytext);}

.* {printf("Invalid Input");}

%%

int main()

{
    yylex();

}
