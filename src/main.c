/*Na main, é onde fazemos a leitura de input e chamamos todas as funções que permitem o funcionamento do programa.
 *Para isso, fazemos include de stack.h onde estão declaradas todas as funções de que precisamos.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"


int main()
{
    ///Aqui estamos a alocar espaço na memória heap para podermos armazenar a nossa stack
    STACK* s = new_stack();
    char line[BUFSIZ];
    char token[BUFSIZ];

    ///Nesta secção é onde a leitura do input é feita
    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
            handle_token(s, token);
        handle_token(s, token);
    
        printStack(s);
    }

    return 0;
}
