#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

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
