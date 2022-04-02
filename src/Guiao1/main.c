#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int val(STACK* s, char* token)
{
    int val;
    sscanf(token, "%d", &val);
    push(s, val);

    return 1;
}

void handle_token(STACK* s, char* token)
{
    val(s, token) || //ADICIONAR AQUI AS RESTANTES OPERACOES  
}

int main()
{
    STACK* s = new_stack();
    char line[BUFSIZ];
    char token[BUFSIZ];


    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%c%[^\n]", token) == 2)
            handle_token(s, token);
        handle_token(s, token);
    
        for (int i = 0; i <= s->sp; ++i)
            printf("%d", s->stack[i]);
            
        printf("\n");
    }

    return 0;
}
