%{
#include<stdio.h>
int c=0;
%}

number [0-9]+
valid {number}[.]?{number}*
invalid {number}[.]({number}*)([.]{number}*)+

%%
\n {c++;}

{valid} {printf("Valid numerical constant, at line : %d \n",c+1);}
{invalid} {printf("INValid numerical constant, at line : %d \n",c+1);}
.|\n ;
%%

void main()
{
yyin=fopen("text5.c","r");
yylex();
fclose(yyin);
}

int yywrap(){return (1);};