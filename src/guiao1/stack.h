/**
 * @file stack.h
 * @brief Declaração de funções e definição de estruturas de dados.
 */

#define MAX_STACK  1000

/**
 * @brief Definição da estrutura da stack.
 * 
 * - `stack[MAX_STACK]` - __Array para armazenar os elementos da stack com um tamanho maximo de 1000.__
 * - `sp` - __Stack pointer que vai apontar para a stack.__
 */
typedef struct
{
    int stack[MAX_STACK];
    int sp;
} STACK;

STACK* new_stack();

void push(STACK *s, int elem);
int pop(STACK *s);

void add(STACK *s);
void subtract(STACK *s);
void multiply(STACK *s);
void divide(STACK *s);
void bit_and(STACK *s);
void bit_or(STACK *s);
void bit_xor(STACK *s);
void bit_not(STACK *s);
void decr(STACK *s);
void incr(STACK *s);
void mod(STACK *s);
void expo(STACK *s);

