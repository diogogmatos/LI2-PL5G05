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
void execute_block(STACK* s, DADOS block, DADOS *var)
{
    char* line = block.dados; 
    char* token = malloc(sizeof(char) * BUFSIZ);

    while ((line = get_token(line, token)) && *line != '\0'){
        s->stack = memory_checker(s);
        handle_token(s, token, var);
    }
    handle_token(s, token, var);
}

/**
 * @brief Aplica as operações contidas num bloco a cada elemento de um array e coloca na stack um novo array com os resultados das operações.
 * 
 * @param s Stack.
 * @param block Bloco.
 * @param array Array.
 */
void execute_block_array(STACK* s, DADOS block, DADOS array, DADOS *var)
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
            handle_token(new_arr, token, var);
        }
        handle_token(new_arr, token, var);
        line = block.dados;
    }
    push_array(s, *new_arr);
} 

void execute_block_string(STACK* s, DADOS block, DADOS string, DADOS *var)
{
    char* str = string.dados;
    STACK* new_arr = new_stack();
    
    for (int i = 0; *(str + i); ++i)
        push_char(new_arr, *(str+i));
    
    free(string.dados);

    push_array(s, *new_arr);
    push_block(s, block.dados);
    mod(s, var);
}

/**
 * @brief Filtra um array de acordo com a condição contida num bloco. Os elementos do array que cumprem a condição, ou seja, que dão um valor
 * diferente de 0 (true) quando aplicadas as operações, são colocados num novo array que é depois colocado na stack.
 * 
 * @param s Stack.
 * @param b Bloco.
 * @param a Array.
 */
void filter_array(STACK* s, DADOS b, DADOS a, DADOS *var)
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
            handle_token(stack, token, var);
        }
        handle_token(stack, token, var);
        
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
void filter_string(STACK* s, DADOS block, DADOS string, DADOS *var)
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
            handle_token(stack, token, var);
        }
        handle_token(stack, token, var);
        
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

/**
 * @brief Aplica as operações contidas num bloco iterativamente aos elementos de um array. Por exemplo, o input: `[ 1 2 3 ] { + } *` daria o output: `6`
 * (soma de todos os elemetnos do array). 
 * 
 * @param s Stack.
 * @param b Bloco.
 * @param a Array.
 */
void fold_array(STACK* s, DADOS b, DADOS a, DADOS *var)
{
    STACK *array = a.dados;
    STACK *stack = new_stack();

    char token[BUFSIZ];
    char* line = malloc(sizeof(char) * BUFSIZ);
    line = b.dados;

    push(stack, array->stack[1]);
    for(int i = 2; i <= array->sp; i++)
    {
        push(stack, array->stack[i]);
        while ((line = get_token(line, token)) && *line != '\0'){
            handle_token(stack, token, var);
        }
        handle_token(stack, token, var);

        line = b.dados;
    }
    
    push(s, pop(stack));
}

int is_truthy (STACK* s) 
{
    DADOS x = pop(s);

    if (x.tipo == STRING)
    {
        char *str = x.dados;
        if (strlen(str) == 0) return 0;
        else return 1;
    }
    else if (x.tipo == ARRAY)
    {
        STACK *r = x.dados;
        if (r->sp == 0) return 0;
        else return 1;
    }
    else if (x.tipo == LONG || x.tipo == DOUBLE)
    {
        double *n = x.dados;
        double p = *n;
        if (p == 0) return 0;
        else return 1;
    }

    return 0;
}

void truthy (STACK* s, DADOS *var)
{
    DADOS x = pop(s);
    execute_block(s,x,var);

    while(is_truthy(s))
    {
        execute_block(s,x,var);
    }
}

void swap_sort(STACK* s, int i)
{
    DADOS t = s->stack[i];

    s->stack[i] = s->stack[i+1]; 
    s->stack[i+1] = t;
}

void bubble_sort(STACK* target, STACK* tool, int N)
{
    double a, b;

    int i, j;
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N - i; ++j)
        {
            a = *(double*)(tool->stack[j].dados);
            b = *(double*)(tool->stack[j+1].dados);
            if (a > b)
            {
                swap_sort(target, j);
                swap_sort(tool, j);
            }
        }
    }
}

STACK* copy_stack(STACK* original, STACK* new_array)
{
    for (int i = 1; i <= original->sp; ++i)
    {
        if (original->stack[i].tipo == ARRAY)
        {
            STACK* array = new_stack();
            array = copy_stack(original->stack[i].dados, array);

            new_array->stack = memory_checker(new_array);
            push_array(new_array, *array);
        }
        else
        {
            new_array->stack = memory_checker(new_array);
            push(new_array, original->stack[i]); 
        
        }
    }
    return new_array;
}

void sort(STACK* s, DADOS array, DADOS block, DADOS *var)
{
    STACK* target = new_stack();
    target = copy_stack(array.dados, target);

    if (array.tipo == STRING)
    {
        STACK* new_array = new_stack();
        char* str = array.dados;
        for (int i = 1; *(str+i); ++i)
        
            push_char(new_array, *(str+i));
        array.dados = new_array;
    }

    push_array(s, *(STACK*)array.dados);
    push_block(s, block.dados);
    mod(s, var);

    STACK* tool = pop(s).dados;
    
    bubble_sort(target, tool, tool->sp);

    push_array(s, *target);
}
