/**
 * @file main.c
 * @brief Função __main__, responsável por lidar diretamente com os inputs do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

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
    
        print_stack(s);
    }

    return 0;
}
