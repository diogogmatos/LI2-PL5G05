#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Dá-nos o valor lógico correspondente a se o segundo elemento a contar do topo da stack é maior que o do topo, 0 se for falsa 1 se for verdadeiro.
 * 
 * @param s Stack.
 */

void bigger(STACK *s)
{
   
   DADOS x = pop(s);
   long *a = x.dados;
   long n = *a;
   DADOS y = pop(s);
   long *b = y.dados;
   long n1 = *b;
   
   if (n1 > n)
   {
     push_long(s,1);
   }
   else if (n1 <= n)
   {
     push_long(s,0);
   }
   free (x.dados);
   free (y.dados);

}


/**
 * @brief Inverte o valor lógico do elemento do topo da stack ou seja se este for 0 passa a ser 1 e se for diferente de 0 passa a ser 0.
 * 
 * @param s Stack.
 */


void lnot(STACK *s)
{

   DADOS x = pop(s);
   long *a = x.dados;
   long n = *a;

   if (n == 0)
   {
       push_long(s,1);
   }
   else if (n != 0)
   {
       push_long(s,0);
   }

   free(x.dados);
}


/**
 * @brief Simula a conjunção lógica dos 2 valores lógicos do topo da stack, ou seja se um ou mais desses elementos for 0 dá push a 0 caso contrário dá push ao elemento do topo;
 * 
 * @param s Stack.
 */


void and(STACK *s)
{
   DADOS x = pop(s);
   long *a = x.dados;
   long n = *a;
   DADOS y = pop(s);
   long *b = y.dados;
   long n1 = *b;

   if (n != 0 && n1 != 0)
   {
       push_long(s,n);
   }
   else 
   {
       push_long(s,0);
   }

}