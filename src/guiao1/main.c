/**
 * @file main.c
<<<<<<< HEAD
 * @author Daniel Pereira, Diogo Matos, João Fernandes, Rodrigo Gomes
 * @brief Na main, é onde fazemos a leitura de input e chamamos todas as funções que permitem o funcionamento do programa.
 * Para isso, fazemos include de stack.h onde estão declaradas todas as funções de que precisamos.
 * @version 0.1
 * @date 2022-04-14
=======
 * @brief Este ficheiro incluí apenas a função __main__, responsável por lidar diretamente com os inputs do programa.
>>>>>>> main
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
    int val;
    sscanf(token, "%d", &val);
    push(s, val);

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
    else val(s, token);
}

/**
 * @brief A função __main__ faz a leitura dos inputs e chama as funções necessárias para lidar com os mesmos.
 *        Para isso, está incluído o ficheiro __stack.h__ onde estão declaradas todas as definições e funções adicionais.
 * 
 * - `STACK* s = new_stack();` - __Declaração de uma nova stack.__
 * - `if (fgets(line, BUFSIZ, stdin) != NULL)` - __Leitura do input.__
 */
int main()
{
    STACK* s = new_stack();

    char line[BUFSIZ];
    char token[BUFSIZ];

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
