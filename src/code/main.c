/**
 * @file main.c
 * @brief Função __main__, responsável por lidar diretamente com os inputs do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

/**
 * @brief ?
 * 
 * @param line String contendo a totalidade do input.
 * @param token String cujo objetivo é armazenar um operador/operando do input individualmente, para que seja depois tratado.
 * @return char* Retorna o endereço da string `line`.
 */
char* get_token(char* line, char token[])
{
    int size=0;
    int index = 0;
    int flag = 0;
    int str_flag = 0;
    int block_flag = 0;

    while (*line != '\n')
    {
        while (*line == ' ')
            line++;

        while ((*line && *line != ' ' && *line != '\n' && (flag == 0 || str_flag == 0 || block_flag == 0)) || 
                (flag > 0 || str_flag > 0 || block_flag > 0))
        {   
            token[index] = *line;
            ++size;

            if (*line == '[')
                ++flag;
            else if (*line == '"' && str_flag == 0)
                ++str_flag;
            else if (*line == '{')
                ++block_flag;
            else if (*line == '"' && str_flag > 0)
                --str_flag;
            else if (*line == '}')
                -- block_flag;
            else if (*line == ']')
                --flag;
            
            index++;
            line++;
        }
        token[index] = '\0';

        return line;
    }
    return line;
}

/**
 * @brief A função __main__ faz a leitura dos inputs e chama as funções necessárias para lidar com os mesmos.
 *        Para isso, está incluído o ficheiro __stack.h__ onde estão declaradas todas as definições e funções adicionais.
 * 
 * - `STACK* s = new_stack();`: __Declaração de uma nova stack.__
 * - `DADOS var[26];`: __Declaração do array responsável por armazenar as variáveis.__
 * - `initialize_var(var);`: __Inicialização do array que armazena as variáveis com os seus valores por defeito.__ 
 * - `if (fgets(line, 10090, stdin) != NULL)`: __Leitura do input.__
 */
int main()
{
    STACK* s = new_stack();
    DADOS* var = malloc(sizeof(DADOS) * 26);
    initialize_var(var);

    char* line = malloc(sizeof(char) * 10090);
    char token[10090];

    if (fgets(line, 10090, stdin) != NULL)
    {
        while ((line = get_token(line, token)) && *line != '\n'){
            s->stack = memory_checker(s);
            handle_token(s, token, var);
        }
        handle_token(s, token, var);
        print_stack(s);
        putchar('\n');
    }
    return 0;
}
