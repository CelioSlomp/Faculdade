DIGITO      [0-9]
LETRA       [a-zA-Z]
UNDERLINE   "_"
PONTO       "."
MENORQUE    "<"
MAIORQUE    ">"
ANO         "2020"|"2021"

%%

{MENORQUE}(({DIGITO})*({LETRA})*){MAIORQUE}   { printf("%s", yytext); }  
{DIGITO}+                                     { printf("número inteiro:  %s\n", yytext); }
({DIGITO})?+{PONTO}({DIGITO}+)                { printf("número real:  %s\n", yytext); }
{LETRA}+({UNDERLINE}*{DIGITO}*{LETRA}*)*      { printf("variável: %s\n", yytext); }

%%

int yywrap();

int main(void) {
  yylex();
}

int yywrap() {
 return 1;
}
