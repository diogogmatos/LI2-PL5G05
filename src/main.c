/*Na main, é onde fazemos a leitura de input e chamamos todas as funções que permitem o funcionamento do programa.
 *Para issom, fazemos include de stack.h onde estão declaradas todas as funções de que precisamos.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

//esta função está encarregue de adicionar à stack os elementos do input 
int val(STACK* s, char* token)
{
    int val;
    sscanf(token, "%d", &val);
    push(s, val);

    return 1;
}

//Nesta função é onde é feita a filtragem dos elementos que vão para a stack dos elementos que representam as operações
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
    else val(s, token);
}

int main()
{
    //Aqui estamos a alocar espaço na memória heap para podermos armazenar a nossa stack
    STACK* s = new_stack();
    char line[BUFSIZ];
    char token[BUFSIZ];

    //Nesta secção é onde a leitura do input é feita
    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
            handle_token(s, token);
        handle_token(s, token);
    
        for (int i = 1; i <= s->sp; ++i)
            printf("%d", s->stack[i]);
            
        printf("\n");
    }

    return 0;
}
