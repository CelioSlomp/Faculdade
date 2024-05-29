DIGITO        [0-9]
LETRA         [a-zA-Z]
UNDERLINE     "_"
PONTO         "."
ATRIB         "="
IGUALDADE     "=="
ESPACO        " "
NOVALINHA     "\n"
TAB           "\t"
RETORNOLINHA  "\r"

%%

([-+]?)({DIGITO}?+{PONTO}({DIGITO}+)|({DIGITO}+({PONTO}{DIGITO}*([eE][-+]?{DIGITO}+)?|[eE][-+]?{DIGITO}+))|({PONTO}{DIGITO}*([eE][-+]?{DIGITO}+)?|[eE][-+]?{DIGITO}+))       { printf("Lexema encontrado: %s. É um numero real.\n", yytext); }
[-+]?{DIGITO}+                                       { printf("Lexema encontrado: %s. É um numero inteiro.\n", yytext); }
{LETRA}+[a-zA-Z0-9_]*                                { printf("Lexema encontrado: %s. É uma variável.\n", yytext); }
{ATRIB}                                              { printf("Lexema encontrado: %s. É uma atribuição.\n", yytext); }
{IGUALDADE}                                          { printf("Lexema encontrado: %s. É um operador de igualdade.\n", yytext); }
.

%%

int yywrap();

int main(void) {
  yylex();
}

int yywrap() {
 return 1;
}
