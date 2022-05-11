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
#include <stdio.h>
#include <string.h>

/** 
 * @brief A função `add()` soma dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 */
void s_add(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    if (x.tipo == ARRAY && y.tipo == ARRAY)
    {
        STACK *array1 = y.dados;
        STACK *array2 = x.dados;

        STACK *r = new_stack();

        int i,j,k;

        for (i=1; i <= array1->sp; i++)
        {
            *(r->stack + i) = *(array1->stack + i);
            r->sp++;
        }

        for (j=i,k=1;k <= array2->sp;j++,k++)
        {
            *(r->stack + j) = *(array2->stack + k);
            r->sp++;
        }

        push_array(s, *r);
    }
    else if (x.tipo == CHAR && y.tipo == ARRAY)
    {
        STACK *array = y.dados;
        char *a = x.dados;
        double c = *a;

        STACK *r = new_stack();

        int i;
        for (i=1; i <= array->sp; i++)
        {
            *(r->stack + i) = *(array->stack + i);
            r->sp++;
        }

        push_char(r, c);
        push_array(s, *r);
    }
    else if (x.tipo == ARRAY && y.tipo == CHAR)
    {
        STACK *array = x.dados;
        char *a = y.dados;
        double c = *a;

        STACK *r = new_stack();
        int i;

        push_char(r,c);

        for (i=2; i <= array->sp + 1; i++)
        {
            *(r->stack + i) = *(array->stack + i -1);
            r->sp++;
        }
        push_array(s, *r);
    }
    else if ((x.tipo == LONG || x.tipo == DOUBLE) && y.tipo == ARRAY)
    {
        STACK *array = y.dados;
        push(array, x);
        push_array(s, *array);
    }
    else if (x.tipo == ARRAY && (y.tipo == LONG || y.tipo == DOUBLE))
    {
        STACK *array = x.dados;
        STACK *r = new_stack();
        
        push(r, y);
        int i;
        for (i=2; i <= array->sp + 1; i++)
        {
            *(r->stack + i) = *(array->stack + i -1);
            r->sp++;
        }
        push_array(s, *r);
        
    }
    else if (x.tipo == STRING && y.tipo == STRING)
    {
            char* r = malloc(sizeof(x.dados) + sizeof(y.dados) + sizeof(char) + BUFSIZ);
            char* a = x.dados;
            char* b = y.dados;
            memcpy(r, b, strlen(b));
            strcat(r, a);
            push_string(s, r);
    }  
    else if (x.tipo == CHAR && y.tipo == STRING)
    {
        char *a = x.dados;
        double c = *a;

        char *str = y.dados;
        char *r = malloc (sizeof(x.dados) + sizeof(y.dados) + sizeof(char));
        int tam = strlen(str);
        
        int i;
        for (i=0; *(str + i); i++)
        {
            *(r+i) = *(str + i);
        }

        *(r + tam) = c;
        *(r + tam + 1) = '\0';

        push_string (s, r);
    }
    else if (x.tipo == STRING && y.tipo == CHAR)
    {
        char *a = y.dados;
        double c = *a;

        char *str = x.dados;
        char *r = malloc (sizeof(x.dados) + sizeof(y.dados) + sizeof(char));
        int tam = strlen(str);
        int i,j=0;

        *r = c;

        for (i=1; *(str + j); i++,j++)
        {
            *(r+i) = *(str + j);
        }

        *(r + tam + 1) = '\0';
        
        push_string (s, r);
    }
    else if (x.tipo == LONG && y.tipo == LONG)
    {
        double *a = x.dados;
        double *b = y.dados;

        long ri = *b + *a;
        
        double r = ri;
        push_long(s, r);
    }
    else
    {
        double *a = x.dados;
        double *b = y.dados;

        double r = *b + *a;
        push_double(s, r);
    }
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
 * 
 * - __Nota:__ Caso o primeiro operando do input seja um ARRAY ou uma STRING, a função `multiply()` cria um novo array/string que contém 'n' cópias
 * do array/string original, onde 'n' é o valor do segundo operando. Por exemplo, o input `$ [ 1 2 3 ] 2 *` teria como resultado: `123123`, tal
 * como `$ "abc" 2 *` teria como resultado `abcabc`.
 * 
 */
void multiply(STACK *s)
{   
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    if (y.tipo == ARRAY)
    {
        double *a = x.dados;
        long n = *a;
        STACK *array = y.dados;

        STACK *r = new_stack();

        int i, j, k;
        for (i=1; i <= n * array->sp; )
        {
            for (j=i, k=1; j < i + array->sp; j++, k++)
            {
                r->stack[j] = array->stack[k];
            }
            r->sp += array->sp;
            i = r->sp+1;
        }

        push_array(s, *r);
    }
    else if (y.tipo == STRING)
    {
        double *a = x.dados;
        long n = *a;
        char *str = y.dados;

        int tam = strlen(str) * n;
        char *r = malloc(sizeof(char) * tam);

        int i, j, k;
        for (i=0; i < tam; )
        {
            int max = i + strlen(str);
            for (j=i, k=0; j < max; j++, k++)
                r[j] = str[k];
            i = j;
        }
        r[tam] = '\0';

        push_string(s, r);
    }
    else
    {
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
    }
    
    free(x.dados);
    free(y.dados);
}

/**
 * @brief A função `divide()` calcula o quociente entre dois números inteiros contidos na stack.
 *        
 * Faz uso da função `pop()` para aceder aos operandos, ou seja, ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste.
 * Assim, __x__ será o segundo valor introduzido pelo utilizador e __y__ o primeiro, pelo que fazemos __y - x__.
 * 
 * - __Nota:__ Caso os operandos sejam strings, a função `divide()` irá executar o operador de strings `/`, que está definido e documentado na função
 * auxiliar `slash_str()`.
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
    else if (x.tipo == STRING && y.tipo == STRING)
        slash_str(s, x, y);
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
    else if (x.tipo == BLOCK)
    {
        execute_block(s, x);
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
    {
        push_long(s, (*(double*)x.dados) - 1);
    }
    else if (x.tipo == CHAR)
    {
        push_char(s, (*(char*)x.dados) - 1);
    }
    else if (x.tipo == ARRAY)
    {
        STACK *array = x.dados;
        STACK *new_array = new_stack();

        new_array->sp = array->sp-1;
        for (int i=2, j=1; i <= array->sp; i++, j++)
            new_array->stack[j] = array->stack[i];
        
        push_array(s, *new_array);
        push(s, array->stack[1]);

        free(array);
    }
    else if (x.tipo == STRING)
    {
        char *str = x.dados;
        char elem = *str;

        push_string(s, ++str);
        push_char(s, elem);
    }
    else
    {
        push_double(s, (*(double*)x.dados) - 1);
    }
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
    else if (x.tipo == ARRAY)
    {
        STACK* new_array = x.dados;
        DADOS elem = new_array->stack[new_array->sp];
        new_array->sp--;
        
        push_array(s, *new_array);
        push(s, elem);
    }
    else if (x.tipo == STRING)
    {
        char *str = x.dados;
        char elem;
        int i;
        for (i = 0; *(str+i) != '\0'; ++i);
        elem = *(str+i-1);
        *(str+i-1) = '\0';
        push_string(s, str);
        push_char(s, elem);
    }
    else
        push_double(s, (*(double*)x.dados) + 1);
}

/**
 * @brief A função `mod()` dá-nos o módulo da divisão do segundo número da stack a contar do topo pelo que se encontra no topo.
 *        
 * Para esse fim usa `pop()` para obter os mesmos e `push()` para returnar o resultado da operação.
 */
 void mod(STACK *s)
{
    DADOS x = pop(s);

    DADOS y = pop(s);

    if (x.tipo == BLOCK)
        execute_block_array(s, x, y);
    else
    {
        double *ai = x.dados;
        long a = *ai;
        double *bi = y.dados;
        long b = *bi;

        double r = b % a;
        push_long(s, r);
        free(x.dados);
        free(y.dados);
    }
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

        free(x.dados);
        free(y.dados);
    }
    else if (x.tipo == STRING && y.tipo == STRING)
    {
        char *a = x.dados;
        char *b = y.dados;

        if (strstr(b, a) == NULL)
            push_long(s, -1);
        else
            push_long(s, strstr(b, a) - b);

        free(x.dados);
        free(y.dados);
    }
    else
    {
        double a = *((double*)x.dados);
        double b = *((double*)y.dados);

        double r = pow(b, a);
        push_double(s, r);

        free(x.dados);
        free(y.dados);
    }
}
