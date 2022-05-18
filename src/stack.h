#include<stdlib.h>
/**
 * @file stack.h
 * @brief Declaração de funções e definição de estruturas de dados.
 */

// Definição de stack

#define MAX_STACK 100000 

/**
 * @brief Definição de um tipo "__TIPO__" que representa o tipo do elemento da stack (long, double, char ou string).
 * 
 */
typedef enum{LONG, DOUBLE, CHAR, STRING, ARRAY, BLOCK} TIPO;

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
    DADOS* stack;
    int sp;
    int cap;
} STACK;

// Declarações de funções

// stack.c

DADOS* memory_checker(STACK* s);
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
void push_block(STACK* s, char* elem);

// expMat.c

void s_add(STACK *s);
void subtract(STACK *s);
void multiply(STACK *s, DADOS *var);
void divide(STACK *s);
void bit_and(STACK *s);
void bit_or(STACK *s);
void bit_xor(STACK *s);
void bit_not(STACK *s, DADOS *var);
void decr(STACK *s);
void incr(STACK *s);
void mod(STACK *s, DADOS *var);
void expo(STACK *s);

// io.c

char* get_token(char* line, char token[]);
char* get_token2(char* line, char *token, int* size, int* index,int* flag, int* str_flag, int*block_flag);
char* get_token3(char* line, char *token, int* size, int* index,int* flag, int* str_flag, int*block_flag);
void val(STACK* s, char* token);
void handle_token(STACK* s, char* token, DADOS *var);
void handle_token2(STACK* s, char* token, DADOS *var);
void handle_token3(STACK* s, char* token, DADOS *var);
void handle_token4(STACK* s, char* token, DADOS *var);
void print_stack(STACK *s);
void new_line (STACK *s);
void all_lines (STACK *s);
char type_to_char(DADOS x);

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
void ncopy(STACK *s, DADOS *var);

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

DADOS create_array(STACK* s, char* token, DADOS *var);
void div_newline(STACK *s);
void div_whitespace(STACK *s);
void range(STACK *s, DADOS *var);
int substrings(STACK *s, DADOS a, DADOS b);
void create_string(STACK *s, char* token);
void slash_str(STACK* s, DADOS a, DADOS b);
void add_arrays(STACK *s, DADOS x, DADOS y);
void add_char_array(STACK *s, DADOS x, DADOS y);
void add_num_array(STACK *s, DADOS x, DADOS y);
void add_strings(STACK *s, DADOS x, DADOS y);
void add_char_string(STACK *s, DADOS x, DADOS y);

// stackBlocks.c

DADOS create_block(STACK* s, char* token);
void execute_block_array(STACK* s, DADOS block, DADOS array, DADOS *var);
void execute_block(STACK* s, DADOS block, DADOS *var);
void execute_block_string(STACK* s, DADOS block, DADOS string, DADOS *var);
void filter_array(STACK* s, DADOS b, DADOS a, DADOS *var);
void filter_string(STACK* s, DADOS b, DADOS a, DADOS *var);
void fold_array(STACK* s, DADOS b, DADOS a, DADOS *var);
void truthy(STACK* s, DADOS *var);
int is_truthy(STACK* s);
void sort(STACK* s, DADOS array, DADOS block, DADOS *var);
