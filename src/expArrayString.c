/**
 * @file expArrayString.c
 * @brief Operações com Arrays e Strings.
 * 
 * - __Nota:__ Todas as funções em expArrayString.c incluem uma libertação de memória (ex: `free(x.dados)`) uma vez que acedemos a um elemento da stack com
 * a função `pop()` para o qual foi alocada memória dinâmica que já não será usada.
 */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Colocação de elementos na stack

DADOS create_array(STACK* s, char* token, DADOS *var)
{
    STACK* array = new_stack();
    char token_token[BUFSIZ]; 

    ++token;
    while(*token){
        token = get_token(token, token_token);

        if (token_token[0] == ']');  //Não faz nada
        else {
            handle_token(array, token_token, var);
        }
    }

    DADOS d = {ARRAY, array};
    s->sp++;
    s->stack[s->sp] = d;
    return d;
}

/**
 * @brief Separa uma string em substrings de acordo com o caracter '\n' (parágrafo), adicionando cada substring a um array que é
 * posteriormente colocado na stack com a função `push_array()`. Como o tipo ARRAY é definido por uma stack, é utilizada a função `new_stack()`
 * para inicializar o "array".
 * 
 * @param s Stack.
 */
void div_newline(STACK *s)
{
    char *a = pop(s).dados;
    char *str = malloc(sizeof(char) * BUFSIZ);
    strcpy(str, a);

    char *token = malloc(sizeof(char) * strlen(a));
    STACK *r = new_stack();
    
    token = strtok(str, "\n");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, "\n");
    }
    
    push_array(s, *r);
}

/**
 * @brief Separa uma string em substrings de acordo com o caracter ' ' (espaço), adicionando cada substring a um array que é
 * posteriormente colocado na stack com a função `push_array()`. Como o tipo ARRAY é definido por uma stack, é utilizada a função `new_stack()`
 * para inicializar o "array".
 * 
 * @param s Stack.
 */
void div_whitespace(STACK *s)
{
    char *a = pop(s).dados;
    char *str = malloc(sizeof(char) * BUFSIZ);
    strcpy(str, a);

    char *token = malloc(sizeof(char) * strlen(a));
    STACK *r = new_stack();
    
    token = strtok(str, " \t\r\n\v\f");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, " \t\r\n\v\f");
    }
    
    push_array(s, *r);
}

/**
 * @brief Quando o input é um inteiro N, cria um ARRAY de inteiros com os elementos no intervalo de 0 até N-1, e coloca-o na stack com a função `push_array()`
 * Caso o input seja um ARRAY, devolve à stack o tamanho do mesmo na forma de inteiro (LONG), utilizando `push_long()`.
 * 
 * @param s Stack.
 */
void range(STACK *s)
{
    DADOS x = pop(s);
    
    if (x.tipo == LONG)
    {
        double *a = x.dados;
        STACK *r = new_stack();

        for (int i=0; i < *a; i++)
            push_long(r, i);

        push_array(s, *r);
    }
    else if (x.tipo == ARRAY)
    {
        STACK *a = x.dados;
        double r = a->sp;

        push_long(s, r);
    }
    else if (x.tipo == STRING)
    {
        char* str = x.dados;
        int i;
        for (i = 0; *(str + i); ++i);
        push_long(s, i);
    }
    else if (x.tipo == BLOCK)
    {
        DADOS y = pop(s);

        if (y.tipo == ARRAY)
            filter_array(s, x, y);
        else
            filter_string(s, x, y);
    }
}

/**
 * @brief Responsável por criar uma nova string, de acordo com o input do programa, que é feito da forma: `"string de exemplo"`.
 * 
 * @param s Stack.
 * @param token Input do programa.
 */
void create_string(STACK *s, char* token)
{
    ++token;
    char* str = malloc(sizeof(char) * BUFSIZ);
    int i;

    for (i = 0; *(token + i) != '"'; ++i)
    {
        *(str+i) = *(token+i); 
    }
    *(str+i) = '\0';

    push_string(s, str);
}

/**
 * @brief Separa uma string em substrings de acordo com um delimitador que é também uma string. As substrings são adicionadas a um array que é
 * posterioremente colocado na stack com a função `push_array()`. Como o tipo ARRAY é definido por uma stack, é utilizada a função `new_stack()` de
 * modo a criar uma nova stack.
 * 
 * - __Exemplo de input:__ `"string-de-exemplo" " " /`
 * 
 * - __Nota:__ Esta função é usada como uma auxiliar de `divide()`.
 * 
 * @param s Stack.
 * @param a String.
 * @param b String delimitadora.
 */
void slash_str(STACK* s, DADOS a, DADOS b)
{
    char *str2 = a.dados;
    char *str1 = b.dados;
    
    STACK *r = new_stack();
    
    int ind;
    while (strstr(str1, str2) != NULL)
    {
        char *aux = malloc(sizeof(char) * BUFSIZ);
        ind = strstr(str1, str2) - str1;

        int i;
        for (i=0; i < ind; i++)
            aux[i] = str1[i];
        aux[i] = '\0';

        push_string(r, aux);
        str1 = str1 + ind + strlen(str2);
    }
    if (str1[0] != '\0')
    {
        char *aux = malloc(sizeof(char) * BUFSIZ);
        strcpy(aux, str1);
        push_string(r, aux);
    }

    push_array(s, *r);
}
