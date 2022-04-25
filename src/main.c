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
 * - `STACK* s = new_stack();`: __Declaração de uma nova stack.__
 * - `DADOS var[26];`: __Declaração do array responsável por armazenar as variáveis.__
 * - `initialize_var(var);`: __Inicialização do array que armazena as variáveis com os seus valores por defeito.__ 
 * - `if (fgets(line, BUFSIZ, stdin) != NULL)`: __Leitura do input.__
 */
int main()
{
    STACK* s = new_stack();
    DADOS var[26];
    initialize_var(var);
    
    char line[BUFSIZ];
    char token[BUFSIZ];

    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
            handle_token(s, token, var);
        handle_token(s, token, var);
    
        print_stack(s);
    }

    return 0;
}
