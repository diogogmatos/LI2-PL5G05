/**
 * @file main.c
 * @brief Função __main__, responsável por lidar diretamente com os inputs do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

/**
 * @brief Get the token object
 * 
 * @param line String contendo a totalidade do input.
 * @param token String cujo objetivo é armazenar um operador/operando do input individualmente, para que seja depois tratado.
 * @return char* Retorna o endereço da string `line`.
 */
char* get_token(char* line, char token[]){
    int index = 0;
    int flag = 0;
    while (*line != '\n'){
        while (*line == ' ')
            line++;

        while ((*line && *line != ' ' && *line != '\n' && flag == 0) || flag > 0){
            if (*line == '['){
                token[index] = *line; 
                ++index;
                ++line;
                ++flag;
            }
            else if (*line == ']'){
                token[index] = *line; 
                ++index;
                ++line;
                --flag;
            }
            else{   
                token[index] = *line;
                index++;
                line++;
            }  
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
 * - `if (fgets(line, BUFSIZ, stdin) != NULL)`: __Leitura do input.__
 */
int main()
{
    STACK* s = new_stack();
    DADOS var[26];
    initialize_var(var);

    char* line = malloc(sizeof(char) * BUFSIZ);
    char token[BUFSIZ];

    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while ((line = get_token(line, token)) && *line != '\n'){
            handle_token(s, token, var);
        }
        handle_token(s, token, var);
        print_stack(s);
        putchar('\n');
    }
    return 0;
}
