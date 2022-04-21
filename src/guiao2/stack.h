/**
 * @file stack.h
 * @brief Declaração de funções e definição de estruturas de dados.
 */

// Definição de stack

#define MAX_STACK  1000

/**
 * @brief Definição de um tipo __TIPO__ que representa o tipo do elemento (long, double, char ou string).
 * 
 */
typedef enum{LONG, DOUBLE, CHAR, STRING} TIPO;

/**
 * @brief Definição de uma estrutura DADOS que constitui os elementos da stack.
 * 
 * - `tipo`: __Tipo do elemento, definido em 'TIPO'.__
 * - `dados`: __ Endereço do elemento.__
 */
typedef struct
{
    TIPO tipo;
    void *dados;
} DADOS;

/**
 * @brief Definição da estrutura da stack.
 * 
 * - `stack[MAX_STACK]`: __Array para armazenar os elementos da stack com um tamanho maximo de 1000.__
 * - `sp`: __Stack pointer que vai apontar para a stack.__
 */
typedef struct
{
    DADOS stack[MAX_STACK];
    int sp;
} STACK;

// Declarações de funções

// stack.c

STACK* new_stack();
void push_double(STACK *s, double elem);
void push_long(STACK *s, long elem);
void push_char(STACK *s, char elem);
void push_string(STACK *s, char elem[]);
void push(STACK *s, DADOS elem);
DADOS pop(STACK *s);

// expMat.c

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

// io.c

void val(STACK* s, char* token);
void handle_token(STACK* s, char* token);
void print_stack(STACK *s);

// conversions.c

void conv_double(STACK *s);
void conv_int(STACK *s);
void conv_char(STACK *s);
void conv_string(STACK *s);

// expStack.c 

void dup(STACK *s);
void spin(STACK *s);
void popS(STACK *s);
void swap(STACK *s);
void ncopy(STACK *s);