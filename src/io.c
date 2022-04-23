/**
 * @file io.c
 * @brief Funções responsáveis por lidar com o input e ouput do programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

// Colocação de elementos na stack

/**
 * @brief Esta função está encarregue de adicionar à stack os elementos do input.
 * 
 * Para isso, a função:
 * 1. Verifica o tipo do elemento introduzido pelo utilizador;
 * 2. Introduz o elemento na stack utilizando a função de push respetiva.
 * 
 * @param s Stack.
 * @param token String que contém o input do programa.
 */
void val(STACK* s, char* token)
{
    int i, n = strlen(token);

    if (token[0] == '"')                // Caso em que o operando é STRING (o input encontra-se entre aspas)
    {
       char string[n-1];
       int j=0;
       for (i=1; token[i] != '"'; i++, j++)
       {
           string[j] = token[i];
       }
       push_string(s, string);
    }
    else
    {
        for (i=0; token[i] != '\0' && token[i] != '.'; i++);
        if (i != n)                    // Caso em que o operando é DOUBLE (o input contém um '.')
        {
            double d;
            sscanf(token, "%lf", &d);
            push_double(s, d);
        }
        else                           // Caso em que o operando é LONG (o input é apenas constituído por números)
        {
            long num;
            sscanf(token, "%li", &num);
            push_long(s, num);
        }
    }
}

// Funções de input/output (operadores 'l', 't' e 'p')

/**
 * @brief Esta função representa a ação do comando `l`, que recebe uma nova linha de input por cada ocorrência do comando.
 * 
 * @param s Stack.
 */
void new_line (STACK *s)
{
    char line[BUFSIZ];
    if (fgets (line, BUFSIZ, stdin) != NULL)
        push_string (s,line);
}

// Handling de inputs

/**
 * @brief Função auxiliar que verifica se um caracter é uma letra maiúscula, ou seja, uma variável.
 * 
 * @param c Carcater a ser verificado.
 * @return int Retorna 1 (True) ou 0 (False).
 */
int isVar(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

/**
 * @brief Lida com o input de variáveis, determinando se devemos guardar um elemento na variável ou introduzir na stack o seu conteúdo.
 * 
 * Para isso, a função:
 * 1. Verifica se o input contém `:X`, ou seja, se queremos guardar o topo da stack na variável X, sendo X uma variável qualquer de A a Z;
 * 2. Caso contrário, o input é apenas uma variável pelo que introduzimos na stack o seu conteúdo.
 * 
 * - __Nota:__ A função recebe o array `var` como argumento, que é responsável por armazenar as variáveis.
 * Este array é declarado e inicializado na função `main()`.
 * 
 * @param s Stack.
 * @param token String que contém o input do programa.
 * @param var Array que armazena as variáveis.
 */
void handle_variables(STACK* s, char* token, DADOS *var)
{   
    if (token[0] == ':')
    {
        DADOS d = pop(s);
        int n = token[1];
        var[n-65] = d;
        push(s, d);
    }
    else
    {
        char n = token[0];
        if (n >= 'A' && n <= 'Z')
            push(s, var[n-65]);
    }
}

/**
 * @brief Lida com os inputs do programa, determinando que função deve ser utilizada para lidar com cada um deles.
 * 
 * Para isso, a função:
 * 1. Verifica se o input é um operador ou uma variável, executando a função correspondente se o mesmo se verificar;
 * 2. Caso contrário, o input será um operando e é introduzido na stack com a função `val()`.
 * 
 * @param s Stack.
 * @param token String que contém o input do programa.
 * @param var Array que armazena as variáveis.
 */
void handle_token(STACK* s, char* token, DADOS *var)
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
    else if (strcmp (token, "%") == 0) mod(s);
    else if (strcmp (token, "#") == 0) expo(s);
    else if (strcmp (token, "l") == 0) new_line(s);
    else if (strcmp (token, "i") == 0) conv_int(s);
    else if (strcmp (token, "f") == 0) conv_double(s);
    else if (strcmp (token, "c") == 0) conv_char(s);
    else if (strcmp (token, "s") == 0) conv_string(s);
    else if (strcmp (token, "_") == 0) dup(s);
    else if (strcmp (token, "@") == 0) spin(s);
    else if (strcmp (token, ";") == 0) popS(s);
    else if (strcmp (token, "\\") == 0) swap(s);
    else if (strcmp (token, "$") == 0) ncopy(s);
    else if (token[0] == ':' || isVar(token[0])) handle_variables(s, token, var);
    else if (strcmp (token, ">") == 0) bigger(s);
    else if (strcmp (token, "!") == 0) lnot(s);
    else if (strcmp (token, "e&") == 0) and(s);
    else if (strcmp (token, "e>") == 0) maior2(s);
    else if (strcmp (token, "e<") == 0) menor2(s);
    else val(s, token);
}

// Impressão da stack

/**
 * @brief Esta função imprime o conteúdo da stack.
 * 
 * Para isso:
 * 1. Percorre o array de dados da stack, desde a primeira posição até à posição atual do "stack pointer" (`s->sp`);
 * 2. Imprime o conteúdo de cada elemento, de acordo com o seu tipo.
 * 
 * @param s Stack.
 */
void print_stack(STACK *s) // ! - Possível problema na impressão de uma string
{
    DADOS d;
    for (int i = 1; i <= s->sp; ++i)
    {
        d = s->stack[i];
        if (d.tipo == LONG)           // Caso em que o elemento da stack é um LONG
            printf("%li", *((long*)d.dados));
        else if (d.tipo == CHAR)      // Caso em que o elemento da stack é um CHAR
            printf("%c", *((char*)d.dados));
        else if (d.tipo == DOUBLE)    // Caso em que o elemento da stack é um DOUBLE
            printf("%g", *((double*)d.dados));
        else if (d.tipo == STRING)    // Caso em que o elemento da stack é uma STRING
            printf("%s", (char*)d.dados);
    }
    printf("\n");
}
