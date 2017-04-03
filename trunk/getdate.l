%{

#include <stdio.h>
#include "getdate.h"
#include "getdate.tab.h"

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
                  return tORDINAL;
                }
mon|monday	|
tue|tuesday	|
wed|wednesday	|
thu|thursday	|
fri|friday	|
sat|saturday	|
sun|sunday	{
                  printf("day name: %s\n", yytext);
                  return tDAY;
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
                  return tMONTH;
                }

[0-9]{4}	{
                  ECHO; /* printf("year: %d\n", atoi(yytext)); */
                  return tUNUMBER;
                }
%%

int main(int argc, char **argv)
{
  printf("foo!\n");
  ++argv, --argc;  // skip over program name 
  if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
  else
    yyin = stdin;
  
  yylex();
  return 0;
  
}
