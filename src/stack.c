/**
 * @file stack.c
 * @brief Funções básicas para o funcionamento da stack.
 */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Declaração de nova stack

/**
 * @brief Aloca espaço na memória *heap* atribuindo um endereço ao pointer __s__ e iniciando o stack pointer (`s->sp`) a 0.
 * 
 * @return s Retorna o endereço da "STACK" declarada em `main()`, agora inicializada.
 */
STACK* new_stack()
{
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    s->cap = 15000;
    s->stack = malloc(sizeof(DADOS) * s->cap);
    return s;
}

// Armazenamento de variáveis

/**
 * @brief Inicializa o array que armazena as variáveis com os seus valores por defeito.
 * 
 * @param var Array que armazena as variáveis.
 */
void initialize_var(DADOS *var)
{   
    int i;

    for (i=0; i<=5; i++)
    {
        double *r = malloc(sizeof(double));
        *r = 10 + i;                    // *r toma valor 11, 12, 13, 14 ou 15 para A, B, C, D, E ou F (respetivamente)
        var[i].tipo = LONG;
        var[i].dados = r;
    }

    char *n = malloc(sizeof(char));
    *n = '\n';                          // *n toma o valor '\n' para N
    var[13].tipo = CHAR;
    var[13].dados = n;

    char *s = malloc(sizeof(char));
    *s = ' ';                           // *s toma o valor ' ' para S
    var[18].tipo = CHAR;
    var[18].dados = s;

    for (i=23; i<26; i++)               // *r toma valor 0, 1 ou 2 para X, Y ou Z (respetivamente).
    {
        double *x = malloc(sizeof(double));
        *x = i - 23;
        var[i].tipo = LONG;
        var[i].dados = x;
    }
}

// Funções de push

/**
 * @brief Introduz um elemento do tipo LONG na stack, incrementando um valor ao stack pointer (`s->sp`), uma vez que o topo da stack aumenta.
 * 
 * Para isso, é alocada memória de modo a suportar o tamanho de um elemento do tipo LONG, uma vez que na stack é apenas guardado o valor do endereço
 * desta memória, e não o elemento em si.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_long(STACK* s, double elem)
{
    double *elemP = malloc(sizeof(double));
    *elemP = elem;
    
    DADOS d = {LONG, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo DOUBLE na stack, incrementando um valor ao stack pointer (`s->sp`), uma vez que o topo da stack aumenta.
 * 
 * Para isso, é alocada memória de modo a suportar o tamanho de um elemento do tipo DOUBLE, uma vez que na stack é apenas guardado o valor do endereço
 * desta memória, e não o elemento em si.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_double(STACK *s, double elem)
{
    double *elemP = malloc(sizeof(double));
    *elemP = elem;

    DADOS d = {DOUBLE, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo CHAR na stack, incrementando um valor ao stack pointer (`s->sp`), uma vez que o topo da stack aumenta.
 * 
 * Para isso, é alocada memória de modo a suportar o tamanho de um elemento do tipo CHAR, uma vez que na stack é apenas guardado o valor do endereço
 * desta memória, e não o elemento em si.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_char(STACK* s, char elem)
{
    char *elemP = malloc(sizeof(char));
    *elemP = elem;
    
    DADOS d = {CHAR, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo STRING na stack, incrementando um valor ao stack pointer (`s->sp`), uma vez que o topo da stack aumenta.
 * 
 * Para isso, é alocada memória de modo a suportar o tamanho de uma string com 50 caracteres, uma vez que na stack é apenas guardado o valor do endereço
 * desta memória, e não o elemento em si.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_string(STACK *s, char* elem)
{   
    DADOS d = {STRING, elem}; // Seria 'DADOS d = {STRING, elemP};' com o código acima.
    s->sp++;
    s->stack[s->sp] = d;
}

void push_array(STACK *s, STACK elem)
{
    STACK *arrayP = new_stack();
    *arrayP = elem;

    DADOS d = {ARRAY, arrayP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento na stack, direcionando para a função push correspondente de acordo com o seu tipo.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push(STACK* s, DADOS elem)
{
    if (elem.tipo == LONG)
    {
        double *n = elem.dados;
        push_long(s, *n);
    }
    else if (elem.tipo == DOUBLE)
    {
        double *n = elem.dados;
        push_double(s, *n);
    }
    else if (elem.tipo == CHAR)
    {
        char *n = elem.dados;
        push_char(s, *n);
    }
    else if (elem.tipo == STRING)
    {
        char *n = elem.dados;
        push_string(s, n);
    }
    else if (elem.tipo == ARRAY)
    {
        STACK *n = elem.dados;
        push_array(s, *n);
    }
}

// Função pop()

/**
 * @brief Retorna o elemento que está na posição atual do stack pointer (`s->sp`) e decrementa o stack pointer, uma vez que o topo da stack diminui.
 * 
 * @param s Stack.
 * @return __d__ - Elemento que se encontra na posição atual do stack pointer.
 */
DADOS pop(STACK* s)
{
    DADOS d = s->stack[s->sp];
    s->sp--;

    return d;
}

/**
 * @brief Verifica se é necessário alocar mais memória para a stack, o que acontece quando esta atinge o limite de capacidade.
 * 
 * @param s Stack.
 * @return DADOS* Retorna o endereço do array de dados da stack.
 */
DADOS* memory_checker(STACK* s)
{
    if (s->sp == s->cap)
    {
        s->cap += MAX_STACK;
        int n = s->cap / MAX_STACK;
        s->stack = realloc(s->stack, sizeof(DADOS) * n);
        return s->stack;
    }
    else
        return s->stack;
}
