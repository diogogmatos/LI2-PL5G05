/**
 * @file io.c
 * @brief Funções responsáveis por lidar com o input e ouput do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

/**
 * @brief Função auxiliar que verifica se um caracter é um número.
 * 
 * @param c Caracter a ser verificado.
 * @return int Retorna 1 se o caracter for um número, 0 caso contrário.
 */
int isNum(char c)
{
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9');
}

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
 * @brief Esta função está encarregue de adicionar à stack os elementos do input.
 * @param s Stack.
 * @param token String que contém o input do programa.
 */
int val(STACK* s, char* token) // ! - Falta adicionar o caso DOUBLE
{
    char val;
    int i, num, n;
    
    for (n=0; token[n] != '\0'; n++);                    // Calcula tamanho da string token
    for (i=0; token[i] != '\0' && isNum(token[i]); i++); // Verifica se todos os caracteres são números

    if (token[i] == '\0')            // Caso em que o operando é LONG
    {
        sscanf(token, "%d", &num);
        push_long(s, num);
    }
    else if (n == 1)                 // Caso em que o operando é CHAR
    {
        sscanf(token, "%c", &val);
        push_char(s, val);
    }
    else if (n > 1)                  // Caso em que o operando é STRING
    {
        char string[n+1];
        strcpy (string, token);
        push_string(s, string);
    }
    
    return 1;
}

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

/**
 * @brief Nesta função é feita a filtragem dos elementos que vão para a stack e dos elementos que representam as operações.
 * @param s Stack.
 * @param token String que contém o input do programa.
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
    else if (strcmp (token, "l") == 0) new_line(s);
    else if (strcmp (token, "i") == 0) conv_int(s);
    else if (strcmp (token, "f") == 0) conv_double(s);
    else if (strcmp (token, "c") == 0) conv_char(s);
    else if (strcmp (token, "s") == 0) conv_string(s);
    else val(s, token);
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
            printf("%lf", *((double*)d.dados));
        else if (d.tipo == STRING)    // Caso em que o elemento da stack é uma STRING
            print_string((char*)d.dados);
    }
    printf("\n");
}
