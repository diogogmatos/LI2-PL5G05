/**
 * @file stack.h
 * @brief Declaração de funções e definição de estruturas de dados.
 */

// Definição de stack

#define MAX_STACK  900000

/**
 * @brief Definição de um tipo "__TIPO__" que representa o tipo do elemento da stack (long, double, char ou string).
 * 
 */
typedef enum{LONG, DOUBLE, CHAR, STRING, ARRAY} TIPO;

/**
 * @brief Definição de uma estrutura "__DADOS__" que constitui os elementos da stack.
 * 
 * - `tipo`: __Tipo do elemento, definido em 'TIPO'.__
 * - `dados`: __ Endereço do elemento.__
 * 
 * - __Nota:__ O endereço do elemento é do tipo `void` para que possa alocar um elemento de qualquer tipo. Por este motivo, sempre que se pretende
 * aceder ao conteúdo deste endereço, ou seja, ao conteúdo do elemento, deve-se explicitar o seu tipo. Por exemplo: `long n = *((long*)d.dados)`.
 */
typedef struct
{
    TIPO tipo;
    void *dados;
} DADOS;

/**
 * @brief Definição da estrutura da stack, denominada "__STACK__".
 * 
 * "STACK" é contituída por: 
 * - Um array de 'DADOS' `stack[]` de tamanho 1000, que representa a stack;
 * - Um inteiro `sp` que representa o topo da stack.
 */
typedef struct
{
    DADOS stack[MAX_STACK];
    int sp;
} STACK;

// Declarações de funções

// stack.c

STACK* new_stack();
void remove_elem(STACK* s, int pos);
void initialize_var(DADOS *var);
void push_double(STACK *s, double elem);
void push_long(STACK *s, double elem);
void push_char(STACK *s, char elem);
void push_string(STACK *s, char elem[]);
void push_array(STACK *s, STACK elem);
void push(STACK *s, DADOS elem);
DADOS pop(STACK *s);

// expMat.c

void s_add(STACK *s);
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

char* get_token(char* line, char token[]);
void val(STACK* s, char* token);
void handle_token(STACK* s, char* token, DADOS *var);
void print_stack(STACK *s);
void new_line (STACK *s);
void all_lines (STACK *s);

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

// expLogic.c

void equal(STACK *s);
void is_smaller(STACK *s);
void is_bigger(STACK *s);
void lnot(STACK *s);
void and(STACK *s);
void or(STACK *s);
void bigger(STACK *s);
void smaller(STACK *s);
void if_else(STACK* s);

// expArrayString.c

void div_newline(STACK *s);
void div_whitespace(STACK *s);
void range(STACK *s);
int substrings(STACK *s, DADOS a, DADOS b);
void create_string(STACK *s, char* token);
