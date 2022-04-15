/**
 * @file io.c
 * @brief Funções responsáveis por lidar com o input e ouput do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

<<<<<<< HEAD
///esta função está encarregue de adicionar à stack os elementos do input 
=======
/**
 * @brief Esta função está encarregue de adicionar à stack os elementos do input.
 */
>>>>>>> main
int val(STACK* s, char* token)
{
    long val;
    sscanf(token, "%ld", &val);
    push(s, val);

    return 1;
}

<<<<<<< HEAD
///Nesta função é onde é feita a filtragem dos elementos que vão para a stack dos elementos que representam as operações
=======
/**
 * @brief Nesta função é feita a filtragem dos elementos que vão para a stack e dos elementos que representam as operações.
 */
>>>>>>> main
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
    else if (strcmp (token, "f") == 0) convDouble(s);
    else if (strcmp (token, "i") == 0) convLong(s);
    else val(s, token);
}

void printDados(DADOS d)
{
    if (d.tipo == LONG)
    {
        long n = *((long*)d.dados);
        printf("%ld", n);
    }
    else if (d.tipo == DOUBLE)
    {
        double n = *((double*)d.dados);
        printf("%lf", n);
    }
    else if (d.tipo == CHAR)
    {
        char n = *((char*)d.dados);
        printf("%c", n);
    }
}

void printStack(STACK *s)
{
    DADOS d;
    for (int i = 1; i <= s->sp; ++i)
    {
        d = s->stack[i];
        printDados(d);
    }
            
    printf("\n");
}
