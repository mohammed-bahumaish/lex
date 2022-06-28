%{
 #include<stdio.h>
 int c =0;
 FILE *fp;
%}

%%
\n {c++;}
["][a-zA-Z0-9]*["] {
    printf("  vaild String in line number: %d\n",c+1);
}
["][a-zA-Z0-9]* {
    printf("  : Invalid String in line num : %d\n",c+1);
}
%%

void main(){
 yyin = fopen("source.c","r");
 
 yylex();
 
fclose(yyin);

}

int yywrap(){return(1);}
