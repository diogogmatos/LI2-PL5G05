/**
 * @file expMat.c
 * @brief Operações matemáticas.
 * 
 * - __Nota:__ Todas as funções em expMat.c incluem uma libertação de memória (ex: `free(x.dados)`) uma vez que acedemos a um elemento da stack com
 * a função `pop()` para o qual foi alocada memória dinâmica que já não será usada.
 */

#include "stack.h"
#include <stdlib.h>
#include <math.h>

/** 
 * @brief A função `add()` soma dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 */
void add(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    double *a = x.dados;
    double *b = y.dados;

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long ri = *b + *a;
        
        double r = ri;
        push_long(s, r);
    }
    else
    {
        double r = *b + *a;
        push_double(s, r);
    }
    
    free(a);
    free(b);
}

/**
 * @brief A função `subtract()` calcula a diferença entre dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 * Assim, __x__ será o segundo valor introduzido pelo utilizador e __y__ o primeiro, pelo que fazemos __y - x__.
 */
void subtract(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    double *a = x.dados;
    double *b = y.dados;

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long ri = *b - *a;
        
        double r = ri;
        push_long(s, r);
    }
    else
    {
        double r = *b - *a;
        push_double(s, r);
    }
    
    free(a);
    free(b);
}

/**
 * @brief A função `multiply()` multiplica dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 */
void multiply(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    double *a = x.dados;
    double *b = y.dados;

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long ri = *b * *a;
        
        double r = ri;
        push_long(s, r);
    }
    else
    {
        double r = *b * *a;
        push_double(s, r);
    }
    
    free(a);
    free(b);
}

/**
 * @brief A função `divide()` calcula o quociente entre dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 * Assim, __x__ será o segundo valor introduzido pelo utilizador e __y__ o primeiro, pelo que fazemos __y - x__.
 */
void divide(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    double *a = x.dados;
    double *b = y.dados;

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long ri = *b / *a;
        
        double r = ri;
        push_long(s, r);
    }
    else
    {
        double r = *b / *a;
        push_double(s, r);
    }
    
    free(a);
    free(b);
}

/**
 * @brief `bit_and()` retira dois números da stack utilizando `pop()` e faz AND (&) em todos os bits de dois números.
 *        
 * O resultado de AND é 1 apenas se os dois bits forem 1.
 * No final, o resultado obtido é colocado na stack através da função `push_long()`.
 */
void bit_and(STACK *s)
{
    double *ai = pop(s).dados;
    long a = *ai;
    double *bi = pop(s).dados;
    long b = *bi;

    double r = b & a;
    push_long(s, r);

    free(ai);
    free(bi);
}

/**
 * @brief `bit_or()` retira dois números da stack utilizando `pop()` e faz OR (|) em todos os bits dos dois números.
 *        
 * O resultado de OR é 1 se um dos dois bits for 1.
 * No final, o resultado obtido é colocado na stack através da função `push_long()`.
 */
void bit_or(STACK *s)
{
    double *ai = pop(s).dados;
    long a = *ai;
    double *bi = pop(s).dados;
    long b = *bi;
    
    double r = b | a;
    push_long(s, r);

    free(ai);
    free(bi);
}

/**
 * @brief `bit_xor()` retira dois números da stack utilizando `pop()` e faz XOR (^) em todos os bits dos dois números.
 *        
 * O resultado de XOR é 1 se os dois bits forem diferentes.
 * No final, o resultado obtido é colocado na stack através da função `push_long()`.
 */
void bit_xor(STACK *s)
{
    double *ai = pop(s).dados;
    long a = *ai;
    double *bi = pop(s).dados;
    long b = *bi;
    
    double r = b ^ a;
    push_long(s, r);

    free(ai);
    free(bi);
}

/**
 * @brief `bit_not()` retira um número da stack utilizando `pop()` e faz NOT (`~`) em todos os bits desse número.
 *        
 * O resultado de NOT é a a inversão de todos os bits desse número.
 * No final, o resultado obtido é colocado na stack através da função `push_long()`.
 * 
 * - __Nota:__ No caso de o input ser um ARRAY, a função `bit_not()` coloca na stack todos os elementos do mesmo. É usada a mesma
 * função para ambas estas operações uma vez que os operadores (`~`) são idênticos.
 */
void bit_not(STACK *s)
{
    DADOS x = pop(s);
    
    if (x.tipo == ARRAY)      // Coloca na stack todos os elementos do ARRAY
    {
        STACK *a = x.dados;
        
        for (int i=1; i <= a->sp; i++)
        {
            DADOS r = a->stack[i];
            push(s, r);
        }
    }
    else                      // Operação NOT binária
    {
        double *ai = x.dados;
        long a = *ai;
        
        double r = ~ a;
        push_long(s, r);
    }

    free(x.dados);
}

/**
 * @brief `decr()` tem como função subtrair uma unidade ao elemento que se encontrar no topo da stack.
 *        
 * Para tal, é utilizada a função `pop()`, retirando da stack o elemento a ser trabalhado.
 * No final, após a subtração, o resultado obtido é colocado na stack através da função `push_long()` ou `push_double()`.
 */
void decr(STACK *s)
{
    DADOS x = pop(s);

    if (x.tipo == LONG)
        push_long(s, (*(double*)x.dados) - 1);
    else if (x.tipo == CHAR)
        push_char(s, (*(char*)x.dados) - 1);
    else
        push_double(s, (*(double*)x.dados) - 1);
    
    free(x.dados);
}

/**
 * @brief `incr()` tem como função adicionar uma unidade ao elemento que se encontrar no topo da stack.
 *        
 * Para tal, é utilizada a função `pop()`, retirando da stack o elemento a ser trabalhado.
 * No final, após a adição, o resultado obtido é colocado na stack através da função `push_long()` ou `push_double()`.
 */
void incr(STACK *s)
{
    DADOS x = pop(s);
    
    if (x.tipo == LONG)
        push_long(s, (*(double*)x.dados) + 1);
    else if (x.tipo == CHAR)
        push_char(s, (*(char*)x.dados) + 1);
    else
        push_double(s, (*(double*)x.dados) + 1);
    
    free(x.dados);
}

/**
 * @brief A função `mod()` dá-nos o módulo da divisão do segundo número da stack a contar do topo pelo que se encontra no topo.
 *        
 * Para esse fim usa `pop()` para obter os mesmos e `push()` para returnar o resultado da operação.
 */
 void mod(STACK *s)
{
    double *ai = pop(s).dados;
    long a = *ai;

    double *bi = pop(s).dados;
    long b = *bi;

    double r = b % a;
    push_long(s, r);
    
    free(ai);
    free(bi);
}

/**
 * @brief Esta função tem como objetivo obter a exponenciação de valores da stack.
 *        
 * Este valor é obtido elevando o segundo número a contar de cima da stack por o do topo.
 */
 void expo(STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    if (x.tipo == LONG && y.tipo == LONG)
    {
        double r = 1;

        double ai = *((double*)x.dados);
        long a = ai;

        double bi = *((double*)y.dados);
        long b = bi;

        while (a > 0)
        {
          r = r * b;
          (a)--;
        }
        
        push_long(s, r);
    }
    else
    {
        double a = *((double*)x.dados);
        double b = *((double*)y.dados);

        double r = pow(b, a);
        push_double(s, r);
    }

    free(x.dados);
    free(y.dados);
}
