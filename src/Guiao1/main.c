#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
// '#include "stack.h"' dá conflicting types uma vez que "expMat.h" já inclui as definições contidas em "stack.h"

int val(STACK* s, char* token)
{
    int val;
    sscanf(token, "%d", &val);
    push(s, val);

    return 1;
}

void handle_token(STACK* s, char* token)
{
    if (strcmp (token, "+") == 0) add(s);
    else if (strcmp (token, "-") == 0) subtract(s);
    else if (strcmp (token, "*") == 0) multiply(s);
    else if (strcmp (token, "/") == 0) divide(s);
    else if (strcmp (token, "&") == 0) bit_and(s);
    else if (strcmp (token, "|") == 0) bit_or(s);
    else if (strcmp (token, "^") == 0) bit_xor(s);
    else if (strcmp (token, "~") == 0) bit_not(s);
    else if (strcmp (token, "(") == 0) decr(s);
    else if (strcmp (token, ")") == 0) incr(s);
    else val(s, token);
}

int main()
{
    STACK* s = new_stack();
    char line[BUFSIZ];
    char token[BUFSIZ];


    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
            handle_token(s, token);
        handle_token(s, token);
    
        for (int i = 1; i <= s->sp; ++i)
            printf("%d", s->stack[i]);
            
        printf("\n");
    }

    return 0;
}

