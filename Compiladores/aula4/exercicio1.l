DIGITO      [0-9]
LETRA       [a-zA-Z]
UNDERLINE   "_"
PONTO       "."

ZERO        [0]
BIN         "b"
BINUM       [01]
HEX         "x"
HEXUM       [0-9a-fA-F]

%%

({ZERO})?+{BIN}({BINUM}+)                     { printf("número binário: %s\n", yytext); }
({ZERO})?+{HEX}({HEXUM}+)                     { printf("número hexadecimal: %s\n", yytext); }
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
