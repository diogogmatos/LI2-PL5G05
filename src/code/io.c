/**
 * @file io.c
 * @brief Funções responsáveis por lidar com o input e ouput do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

// Colocação de elementos na stack

/**
 * @brief Esta função está encarregue de adicionar à stack os elementos do input.
 * @param s Stack.
 * @param token String que contém o input do programa.
 */
void val(STACK* s, char* token)
{
    int i, n = strlen(token);

    if (token[0] == '"')               // Caso em que o operando é STRING
    {
       char string[n-1];
       int j=0;
       for (i=1; token[i] != '"'; i++, j++)
       {
           string[j] = token[i];
       }
       push_string(s, string);
    }
    else
    {
        for (i=0; token[i] != '\0' && token[i] != '.'; i++);
        if (i != n)                  // Caso em que o operando é DOUBLE
        {
            double d;
            sscanf(token, "%lf", &d);
            push_double(s, d);
        }
        else                           // Caso em que o operando é LONG
        {
            long num;
            sscanf(token, "%li", &num);
            push_long(s, num);
        }
    }
}

// Funções de input/output (operadores 'l', 't' e 'p')

/**
 * @brief Esta função representa a ação do comando 'l', que recebe uma nova linha de input por cada ocorrência do comando.
 * @param s Stack.
 */
void new_line (STACK *s)
{
    char line[BUFSIZ];
    if (fgets (line, BUFSIZ, stdin) != NULL)
        push_string (s,line);
}

// Handling de inputs

/**
 * @brief Nesta função é feita a filtragem dos elementos que vão para a stack e dos elementos que representam as operações.
 * @param s Stack.
 * @param token String que contém o input do programa.
 */
void handle_token(STACK* s, char* token)
{
    if (token[0] == '+') add(s);
    else if (token[0] == '-') subtract(s);
    else if (token[0] == '*') multiply(s);
    else if (token[0] == '/') divide(s);
    else if (token[0] == '&') bit_and(s);
    else if (token[0] == '|') bit_or(s);
    else if (token[0] == '^') bit_xor(s);
    else if (token[0] == '~') bit_not(s);
    else if (token[0] == '(') decr(s);
    else if (token[0] == ')') incr(s);
    else if (token[0] == '%') mod(s);
    else if (token[0] == '#') expo(s);
    else if (token[0] == 'l') new_line(s);
    else if (token[0] == 'i') conv_int(s);
    else if (token[0] == 'f') conv_double(s);
    else if (token[0] == 'c') conv_char(s);
    else if (token[0] == 's') conv_string(s);
    else if (token[0] == '_') dup(s);
    else if (token[0] == '@') spin(s);
    else if (token[0] == ';') popS(s);
    else if (token[0] == '\\') swap(s);
    else if (token[0] == '$') ncopy(s);
    else val(s, token);
}

// Impressão da stack

/**
 * @brief Função auxiliar para dar print duma string na stack.
 * 
 * @param s String a sujeita ao print
 */
void print_string(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i)
    {
        printf("%c", s[i]);
    }
}

/**
 * @brief Esta função imprime o conteúdo da stack.
 * @param s Stack.
 */
void print_stack(STACK *s) // ! - Possível problema na impressão de uma string
{
    DADOS d;
    for (int i = 1; i <= s->sp; ++i)
    {
        d = s->stack[i];
        if (d.tipo == LONG)           // Caso em que o elemento da stack é um LONG
            printf("%li", *((long*)d.dados));
        else if (d.tipo == CHAR)      // Caso em que o elemento da stack é um CHAR
            printf("%c", *((char*)d.dados));
        else if (d.tipo == DOUBLE)    // Caso em que o elemento da stack é um DOUBLE
            printf("%g", *((double*)d.dados));
        else if (d.tipo == STRING)    // Caso em que o elemento da stack é uma STRING
            print_string((char*)d.dados);
    }
    printf("\n");
}
