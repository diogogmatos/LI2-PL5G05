#include "stack.h"


void dup(STACK *s)
{
  int x = pop(s);
  push([s,x], x );
}