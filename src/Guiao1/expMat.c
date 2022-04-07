#include "stack.h"

void add (STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y + x);
}

void subtract (STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y - x);
}

void multiply (STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y * x);
}

void divide (STACK *s)
{
    int x = pop (s);
    int y = pop (s);
    push (s, y / x);
}