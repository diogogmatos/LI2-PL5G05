/**
 * @file expMat.c
 * @brief Operações base do projeto.
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
    
    if (x.tipo == LONG && y.tipo == LONG)
    {
        long* xd = x.dados;
        long* yd = y.dados;

        long n = *yd + *xd;
        push_long(s, n);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long* xdi = x.dados;
        double xd = *xdi;
        double* yd = y.dados;
        
        double n = *yd + xd;
        push_double(s, n);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double* xd = x.dados;
        long* ydi = y.dados;
        double yd = *ydi;
        
        double n = yd + *xd;
        push_double(s, n);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double* xd = x.dados;
        double* yd = y.dados;
        
        double n = *yd + *xd;
        push_double(s, n);
    }
    
    free(x.dados);
    free(y.dados);
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
    
    if (x.tipo == LONG && y.tipo == LONG)
    {
        long* xd = x.dados;
        long* yd = y.dados;

        long n = *yd - *xd;
        push_long(s, n);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long* xdi = x.dados;
        double xd = *xdi;
        double* yd = y.dados;
        
        double n = *yd - xd;
        push_double(s, n);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double* xd = x.dados;
        long* ydi = y.dados;
        double yd = *ydi;
        
        double n = yd - *xd;
        push_double(s, n);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double* xd = x.dados;
        double* yd = y.dados;
        
        double n = *yd - *xd;
        push_double(s, n);
    }
    
    free(x.dados);
    free(y.dados);
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
    
    if (x.tipo == LONG && y.tipo == LONG)
    {
        long* xd = x.dados;
        long* yd = y.dados;

        long n = *yd * *xd;
        push_long(s, n);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long* xdi = x.dados;
        double xd = *xdi;
        double* yd = y.dados;
        
        double n = *yd * xd;
        push_double(s, n);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double* xd = x.dados;
        long* ydi = y.dados;
        double yd = *ydi;
        
        double n = yd * *xd;
        push_double(s, n);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double* xd = x.dados;
        double* yd = y.dados;
        
        double n = *yd * *xd;
        push_double(s, n);
    }
    
    free(x.dados);
    free(y.dados);
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
    
    if (x.tipo == LONG && y.tipo == LONG)
    {
        long* xd = x.dados;
        long* yd = y.dados;

        long n = *yd / *xd;
        push_long(s, n);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long* xdi = x.dados;
        double xd = *xdi;
        double* yd = y.dados;
        
        double n = *yd / xd;
        push_double(s, n);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double* xd = x.dados;
        long* ydi = y.dados;
        double yd = *ydi;
        
        double n = yd / *xd;
        push_double(s, n);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double* xd = x.dados;
        double* yd = y.dados;
        
        double n = *yd / *xd;
        push_double(s, n);
    }
    
    free(x.dados);
    free(y.dados);
}

/**
 * @brief `bit_and()` retira dois números da stack utilizando `pop()` e faz AND (&) em todos os bits de dois números.
 *        
 * O resultado de AND é 1 apenas se os dois bits forem 1.
 * No final, o resultado obtido é colocado na stack através da função `push()`.
 */
void bit_and(STACK *s)
{
    long* xd = pop(s).dados;
    long* yd = pop(s).dados;
    long n = *yd & *xd;
    
    free(xd);
    free(yd);
    
    push_long(s, n);
}

/**
 * @brief `bit_or()` retira dois números da stack utilizando `pop()` e faz OR (|) em todos os bits dos dois números.
 *        
 * O resultado de OR é 1 se um dos dois bits for 1.
 * No final, o resultado obtido é colocado na stack através da função `push()`.
 */
void bit_or(STACK *s)
{
    long* xd = pop(s).dados;
    long* yd = pop(s).dados;
    long n = *yd | *xd;
    
    free(xd);
    free(yd);
    
    push_long(s, n);
}

/**
 * @brief `bit_xor()` retira dois números da stack utilizando `pop()` e faz XOR (^) em todos os bits dos dois números.
 *        
 * O resultado de XOR é 1 se os dois bits forem diferentes.
 * No final, o resultado obtido é colocado na stack através da função `push()`.
 */
void bit_xor(STACK *s)
{
    long* xd = pop(s).dados;
    long* yd = pop(s).dados;
    long n = *yd ^ *xd;
    
    free(xd);
    free(yd);
    
    push_long(s, n);
}

/**
 * @brief `bit_not()` retira um número da stack utilizando `pop()` e faz NOT (~) em todos os bits desse número.
 *        
 * O resultado de NOT é a a inversão de todos os bits desse número.
 * No final, o resultado obtido é colocado na stack através da função `push()`.
 */
void bit_not(STACK *s)
{
    long* xd = pop(s).dados;
    long n = ~ *xd;
    
    free(xd);
    
    push_long(s, n);
}

/**
 * @brief `decr()` tem como função subtrair uma unidade ao elemento que se encontrar no topo da stack.
 *        
 * Para tal, é utilizada a função `pop()`, retirando da stack o elemento a ser trabalhado.
 * No final, após a subtração, o resultado obtido é colocado na stack através da função `push()`.
 */
void decr(STACK *s)
{
    DADOS xd = pop(s);
    if (xd.tipo == DOUBLE)
        push_double(s, (*(double*)xd.dados) - 1);
    else if (xd.tipo == CHAR)
        push_char(s, (*(char*)xd.dados) - 1);
    else if (xd.tipo == LONG)
        push_long(s, (*(long*)xd.dados) - 1);
    
    free(xd.dados);
}

/**
 * @brief `incr()` tem como função adicionar uma unidade ao elemento que se encontrar no topo da stack.
 *        
 * Para tal, é utilizada a função `pop()`, retirando da stack o elemento a ser trabalhado.
 * No final, após a adição, o resultado obtido é colocado na stack através da função `push()`.
 */
void incr(STACK *s)
{
    DADOS xd = pop(s);
    if (xd.tipo == DOUBLE)
        push_double(s, (*(double*)xd.dados) + 1);
    else if (xd.tipo == CHAR)
        push_char(s, (*(char*)xd.dados) + 1);
    else if (xd.tipo == LONG)
        push_long(s, (*(long*)xd.dados) + 1);
    
    free(xd.dados);
}

/**
 * @brief A função `mod()` dá-nos o módulo da divisão do segundo número da stack a contar do topo pelo que se encontra no topo.
 *        
 * Para esse fim usa `pop()` para obter os mesmos e `push()` para returnar o resultado da operação.
 */
 void mod(STACK *s)
{
    long* xd = pop(s).dados;
    long* yd = pop(s).dados;
    long n = *yd % *xd;
    
    free(xd);
    free(yd);
    
    push_long(s, n);
}

/**
 * @brief Esta função tem como objetivo obter a exponenciação de valores da stack.
 *        
 * Este valor é obtido elevando o segundo número a contar de cima da stack por o do topo.
 */
 void expo(STACK *s)
{
    DADOS xd = pop(s);
    DADOS yd = pop(s);

    if (xd.tipo == DOUBLE && yd.tipo == DOUBLE)
    {
        double x = *((double*)xd.dados);
        double y = *((double*)yd.dados);

        double n = pow(y, x);
        push_double(s, n);
    }
    else if (xd.tipo == LONG && yd.tipo == DOUBLE)
    {
        long* xp = xd.dados;
        double x = *xp;
        double* y = yd.dados;

        double n = pow(*y, x);
        push_double(s, n);
    }
    else if (xd.tipo == DOUBLE && yd.tipo == LONG)
    {
        long* yp = yd.dados;
        double y = *yp;
        double* x = xd.dados;

        double n = pow(y, *x);
        push_double(s, n);
    }
    else if (xd.tipo == LONG && yd.tipo == LONG)
    {
        int a = 1;
        long x = *((long*)xd.dados);
        long y = *((long*)yd.dados);

        while (x > 0)
        {
          a = a * y;
          (x)--;
        }
        
        push_long(s, a);
    }

    free(xd.dados);
    free(yd.dados);
}
