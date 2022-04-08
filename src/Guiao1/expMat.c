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

void bit_and(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y&x);
}

void bit_or(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y|x);
}

void bit_xor(STACK *s)
{
    int x = pop(s);
    int y = pop(s);
    push(s, y^x);
}

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

void mod(STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push(s, y % x);
}

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