%{
#include <stdio.h>
#include <stdlib.h>
int op = 0;
float a, b;
int i;  // Move 'i' here for scope
void digi();
%}

%%
[0-9]+(\.[0-9]+)?  { digi(); }       /* Digits with optional decimal point */
"+"               { op = 1; }        /* Addition */
"-"               { op = 2; }        /* Subtraction */
"*"               { op = 3; }        /* Multiplication */
"/"               { op = 4; }        /* Division */
"^"               { op = 5; }        /* Power */
\n                { printf("\nThe Answer: %f\n\n", a); }  /* Print result */
%%

void digi() {
    if (op == 0) {
        a = atof(yytext);  // Convert input to float and store in 'a'
    } else {
        b = atof(yytext);  // Convert input to float and store in 'b'

        // Perform the operation based on 'op'
        switch(op) {
            case 1: a = a + b; break;
            case 2: a = a - b; break;
            case 3: a = a * b; break;
            case 4: a = a / b; break;
            case 5:  // Power function
                for (i = a; b > 1; b--) {
                    a = a * i;
                }
                break;
        }
        op = 0;  // Reset the operation
    }
}

int main(int argc, char *argv[]) {
    yylex();  // Start lexing input
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}
