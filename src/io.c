/**
 * @file io.c
 * @brief Funções responsáveis por lidar com o input e ouput do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

/**
 * @brief Esta função está encarregue de adicionar à stack os elementos do input.
 */
int val(STACK* s, char* token) // ! - Falta adicionar os casos DOUBLE e STRING
{
    char val;
    sscanf(token, "%c", &val);
    
    int n = val;

    if (n >= 'a' && n <= 'z') // Caso em que o operando é um caracter
        push_char(s, val);    // Faz push do caracter com a função 'push_char'
    else                      // Caso em que o operando é um inteiro/long
        push_long(s, val-48);

    return 1;
}

/**
 * @brief Nesta função é feita a filtragem dos elementos que vão para a stack e dos elementos que representam as operações.
 */
void handle_token(STACK* s, char* token)
{
    if (strcmp (token, "+") == 0) add(s);
    else if (strcmp (token, "-") == 0) subtract(s);
    else if (strcmp (token, "*") == 0) multiply(s);
    else if (strcmp (token, "/") == 0) divide(s);
    else if (strcmp (token, "&") == 0) bit_and(s);
    else if (strcmp (token, "|") == 0) bit_or(s);
    else if (strcmp (token, "^") == 0) bit_xor(s);
    else if (strcmp (token, "~") == 0) bit_not(s);
    else if (strcmp (token, "(") == 0) decr(s);
    else if (strcmp (token, ")") == 0) incr(s);
    else if (strcmp (token, "%") == 0) mod(s);
    else if (strcmp (token, "#") == 0) expo(s);
    else if (strcmp (token, "i") == 0) conv_int(s);
    else if (strcmp (token, "f") == 0) conv_double(s);
    else val(s, token);
}

void print_stack(STACK *s) // ! - Falta adicionar os casos DOUBLE e STRING
{
    DADOS d;
    for (int i = 1; i <= s->sp; ++i)
    {
        d = s->stack[i];
        if (d.tipo == LONG)           // Caso em que o elemento da stack é um LONG
            printf("%li", *((long*)d.dados));
        else if (d.tipo == CHAR)     // Caso em que o elemento da stack é um CHAR
            printf("%c", *((char*)d.dados));
        else if (d.tipo == DOUBLE)  // Caso em que o elemento da stack é um DOUBLE
            printf("%lf", *((double*)d.dados));
    }
    printf("\n");
}
