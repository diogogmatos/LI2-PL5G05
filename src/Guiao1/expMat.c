/*
 * Neste ficheiro estão incluídas as operações base do projeto
 */

#include "stack.h"

void add(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y + x);
}

void subtract(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y - x);
}

void multiply(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y * x);
}

void divide(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y / x);
}

/*bitwise AND retira dois números da stack utilizando o pop() e faz AND em todos os bits de dois números. O resultado de AND é 1 apenas se os dois bits forem 1.
 *No final, o resultado obtido é colocado na stack através da função push().
*/

void bit_and(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y&x);
}

/*bitwise OR retira dois números da stack utilizando o pop() e faz OR em todos os bits dos dois números. O resultado de OR é 1 se um dos dois bits for 1.
 * No final, o resultado obtido é colocado na stack através da função push().
 */
void bit_or(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y|x);
}

/*bitwise XOR retira dois números da stack utilizando o pop() e faz XOR em todos os bits dos dois números. O resultado de XOR é 1 se os dois bits forem diferentes.
 * No final, o resultado obtido é colocado na stack através da função push().
 */
void bit_xor(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y^x);
}

/*bitwise NOT retira um número da stack utilizando o pop() e faz NOT em todos os bits desse número. O resultado de NOT é a a inversão de todos os bits desse número.
 */
void bit_not(STACK *s)
{
    int x = pop(s);
    push(s, ~x);
}

void decr(STACK *s)
{
    int x = pop(s);
    push(s, x-1);
}

void incr(STACK *s)
{
    int x = pop(s);
    push(s, x+1);
}
/*a função mod dá-nos o módulo da divisão do segundo número da stack a contar do topo pelo que se encontra no topo, para esse fim usa pop() para obter os mesmos e o push() para returnar o resultado da operação.
 */
 void mod(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push(s, y % x);
}
/*esta função tem como objetivo obter a exponenciação de valores da stack, sendo este valor feito elevando o segundo número a contar de cima da stack pelo do topo.
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

