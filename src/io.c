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
int val(STACK* s, char* token)
{
    char val;
    sscanf(token, "%c", &val);
    
    int n = val;

    if (n >= 'a' && n <= 'z')
        push_char(s, val);
    else
        push(s, val-48);

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
    else if (strcmp(token, "%") == 0)  mod(s);
    else if (strcmp(token, "#" ) == 0) expo(s);
    else if (strcmp(token, "i" ) == 0) conv_int(s);
    else val(s, token);
}

void printStack(STACK *s)
{
    DADOS d;
    for (int i = 1; i <= s->sp; ++i)
    {
        d = s->stack[i];
        if (d.tipo == LONG)
            printf("%li", *((long*)d.dados));
        if (d.tipo == CHAR)
            printf("%c", *((char*)d.dados));
    }
    printf("\n");
}
