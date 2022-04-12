/*
 * Neste ficheiro estão incluídas as operações base do projeto
 */

#include "stack.h"

/* A função 'add' soma dois números inteiros contidos na stack. Faz uso da função 'pop()' para aceder aos operandos, ou seja, ao valor que se encontra
 * no topo da stack e ao valor que se encontra abaixo deste.
 */
void add(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y + x);
}

/* A função 'subtract' calcula a diferença entre dois números inteiros contidos na stack. Faz uso da função 'pop()' para aceder aos operandos, ou seja,
 * ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste. Assim, 'x' será o segundo valor introduzido pelo utilizador e 'y'
 * o primeiro, pelo que fazemos 'y - x'.
 */
void subtract(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y - x);
}

/* A função 'multiply' multiplica dois números inteiros contidos na stack. Faz uso da função 'pop()' para aceder aos operandos, ou seja, ao valor que
 * se encontra no topo da stack e ao valor que se encontra abaixo deste.
 */
void multiply(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y * x);
}

/* A função 'divide' calcula o quociente entre dois números inteiros contidos na stack. Faz uso da função 'pop()' para aceder aos operandos, ou seja,
 * ao valor que se encontra no topo da stack e ao valor que se encontra abaixo deste. Assim, 'x' será o segundo valor introduzido pelo utilizador e 'y'
 * o primeiro, pelo que fazemos 'y / x'.
 */
void divide(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y / x);
}

/* Bitwise AND retira dois números da stack utilizando o pop() e faz AND em todos os bits de dois números. O resultado de AND é 1 apenas se os dois bits forem 1.
 * No final, o resultado obtido é colocado na stack através da função push().
 */

void bit_and(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y&x);
}

/* Bitwise OR retira dois números da stack utilizando o pop() e faz OR em todos os bits dos dois números. O resultado de OR é 1 se um dos dois bits for 1.
 * No final, o resultado obtido é colocado na stack através da função push().
 */
void bit_or(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y|x);
}

/* Bitwise XOR retira dois números da stack utilizando o pop() e faz XOR em todos os bits dos dois números. O resultado de XOR é 1 se os dois bits forem diferentes.
 * No final, o resultado obtido é colocado na stack através da função push().
 */
void bit_xor(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y^x);
}

/* Bitwise NOT retira um número da stack utilizando o pop() e faz NOT em todos os bits desse número. O resultado de NOT é a a inversão de todos os bits desse número.
 */
void bit_not(STACK *s)
{
    int x = pop(s);
    push(s, ~x);
}

/* Decr tem como função subtrair uma unidade ao elemento que se encontrar no topo da stack. Para tal, é utilizada a função pop(), retirando da stack o elemento a ser trabalhado.
 * No final, após a subtração, o resultado obtido é colocado na stack através da função push().
 */
void decr(STACK *s)
{
    int x = pop(s);
    push(s, x-1);
}

/* Incr tem como função adicionar uma unidade ao elemento que se encontrar no topo da stack. Para tal, é utilizada a função pop(), retirando da stack o elemento a ser trabalhado.
 * No final, após a adição, o resultado obtido é colocado na stack através da função push().
 */
void incr(STACK *s)
{
    int x = pop(s);
    push(s, x+1);
}

/* A função mod dá-nos o módulo da divisão do segundo número da stack a contar do topo pelo que se encontra no topo, para esse fim usa pop() para obter os mesmos e o push() para returnar o resultado da operação.
 */
 void mod(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push(s, y % x);
}

/* Esta função tem como objetivo obter a exponenciação de valores da stack, sendo este valor feito elevando o segundo número a contar de cima da stack pelo do topo.
 */
 void expo(STACK *s)
{
    int a = 1;
    int x = pop (s);
    int y = pop (s);

    while (x > 0)
    {
      a = a * y;
      x--;
    }
    push(s, a);
}