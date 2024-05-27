DIGITO      [0-9]
LETRA       [a-zA-Z]
UNDERLINE   "_"
PONTO       "."

LETRAMAI    [A-Z]
ESPACO      " "

%%

({LETRAMAI}{3,3})({ESPACO})?+({DIGITO}{4,4})          { printf("placa: %s\n", yytext); }
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
