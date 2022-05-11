/**
 * @file stackBlocks.c
 * @brief Operações com Blocos.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

/**
 * @brief Cria um novo bloco, ou seja, um elemento do tipo BLOCK. `create_block()` recebe não só a stack, mas também uma string token que contém o
 * bloco introduzido no formato: `{ ... }`, onde `...` é um conjunto de operações, estas operações são guardadas numa string, de forma semelhante a como
 * um input do programa é guardado, e constituem os dados de um elemento do tipo BLOCK.
 * 
 * @param s Stack.
 * @param token Bloco introduzido no formato: `{ ... }`.
 * @return DADOS Retorna um elemento do tipo BLOCK.
 */
DADOS create_block(STACK* s, char* token)
{
    char* block = malloc(sizeof(char) * BUFSIZ);

    int index = 0;
    ++token;
    while ( *token == ' ')
        ++token;

    for(int i = 0; *(token + i) != '}'; ++i)
    {
        *(block + index) = *(token + i);
        ++index;
    }
    
    *(block + index - 1) = '\0';
    DADOS d = {BLOCK, block};
    
    s->sp++;
    s->stack[s->sp] = d;
    return d;
}

/**
 * @brief Executa as operações contidas num bloco.
 * 
 * @param s Stack.
 * @param block Bloco.
 */
void execute_block(STACK* s, DADOS block)
{
    char* line = block.dados; 
    char* token = malloc(sizeof(char) * BUFSIZ);

    while ((line = get_token(line, token)) && *line != '\0'){
        s->stack = memory_checker(s);
        handle_token(s, token, &s->stack[0]);
    }
    handle_token(s, token, &s->stack[0]);
}

/**
 * @brief Aplica as operações contidas num bloco a cada elemento de um array e coloca na stack um novo array com os resultados das operações.
 * 
 * @param s Stack.
 * @param block Bloco.
 * @param array Array.
 */
void execute_block_array(STACK* s, DADOS block, DADOS array)
{
    STACK* old_arr = array.dados;

    STACK* new_arr = new_stack();
    new_arr->cap = old_arr->cap;
    new_arr->stack = malloc(sizeof(DADOS) * old_arr->cap);    
    
    char token[BUFSIZ];
    char* line = malloc(sizeof(char) * BUFSIZ);
    line = block.dados;
    for(int i = 1; i <= old_arr->sp; ++i)
    {
        push(new_arr, old_arr->stack[i]);
        while ((line = get_token(line, token)) && *line != '\0'){
            handle_token(new_arr, token, &s->stack[0]);
        }
        handle_token(new_arr, token, &s->stack[0]);
        line = block.dados;
    }
    push_array(s, *new_arr);
}

/**
 * @brief Filtra um array de acordo com a condição contida num bloco. Os elementos do array que cumprem a condição, ou seja, que dão um valor
 * diferente de 0 (true) quando aplicadas as operações, são colocados num novo array que é depois colocado na stack.
 * 
 * @param s Stack.
 * @param b Bloco.
 * @param a Array.
 */
void filter_array(STACK* s, DADOS b, DADOS a)
{
    STACK *array = a.dados;
    STACK *stack = new_stack();
    STACK *r = new_stack();

    char token[BUFSIZ];
    char* line = malloc(sizeof(char) * BUFSIZ);
    line = b.dados;
    for(int i = 1; i <= array->sp; i++)
    {
        push(stack, array->stack[i]);
        while ((line = get_token(line, token)) && *line != '\0'){
            handle_token(stack, token, &s->stack[0]);
        }
        handle_token(stack, token, &s->stack[0]);
        
        double *result = pop(stack).dados;
        if (*result != 0)
            push(r, array->stack[i]);

        line = b.dados;
    }

    push_array(s, *r);
}

/**
 * @brief Filtra uma string de acordo com a condição contida num bloco. A condição é aplicada a cada caracter da string, caso o resultado
 * seja diferente de 0 (true), o caracter é colocado numa nova string que é depois colocada na stack.
 * 
 * @param s Stack.
 * @param block Bloco.
 * @param string String.
 */
void filter_string(STACK* s, DADOS block, DADOS string)
{
    char *str = string.dados;
    STACK *stack = new_stack();
    char *r = malloc(sizeof(str));

    char token[BUFSIZ];
    char* line = malloc(sizeof(char) * BUFSIZ);
    line = block.dados;
    int i, j;
    for(i = 0, j = 0; str[i] != '\0'; i++)
    {
        push_char(stack, str[i]);
        while ((line = get_token(line, token)) && *line != '\0'){
            handle_token(stack, token, &s->stack[0]);
        }
        handle_token(stack, token, &s->stack[0]);
        
        double *result = pop(stack).dados;
        if (*result != 0)
        {
            r[j] = str[i];
            j++;
        }

        line = block.dados;
    }
    r[j] = '\0';

    push_string(s, r);
}
