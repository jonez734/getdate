%{

#include "getdate.tab.h"
#include <stdio.h>

%}

DIGIT [0-9]

%option 8bit bison-bridge 
%option warn
%option yylineno

%%

1st		|
2nd		|
3rd		|
4th 		{
                  printf("ordinal: %s\n", yytext);
                }
mon		|
tue		|
wed		|
thu		|
fri		|
sat		|
sun		{
                  printf("day name: %s\n", yytext);
                }

jan|january		|
feb|february		|
mar|march		|
apr|april		|
may			|
jun|june		|
jul|july		|
aug|august		|
sep|september		|
oct|october		|
nov|november		|
dec|december		{
                  printf("month name: %s\n", yytext);
                }

[0-9]{4}	{
                  printf("year: %d\n", atoi(yytext));
                }
%%

int main(int argc, char **argv)
{
  ++argv, --argc;  /* skip over program name */
  if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
  else
    yyin = stdin;
  
  yylex();
  return 0;
  
}

