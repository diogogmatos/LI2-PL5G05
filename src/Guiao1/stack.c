#include <stdlib.h>
#include "stack.h"

STACK *new_stack()
{
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    return s;
}

void push(STACK* s, int elem)
{
    s->sp++;
    s->stack[s->sp] = elem;
}

int pop(STACK* s)
{
    int ret = s->stack[s->sp];
    s->sp--;
    return ret;
}


