#include "expMat.h"
#include <stdlib.h>
#include <string.h>

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
