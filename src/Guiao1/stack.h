#define MAX_STACK  1000

typedef struct{
    int stack[MAX_STACK];   //Array para armazenar os elementos da stack com um tamanho maximo de 1000
    int sp;                 //Stack pointer que vai apontar para a stack
}STACK;

STACK* new_stack();

void push(STACK *s, int elem);
int pop(STACK *s);

void add (STACK *s);
void subtract (STACK *s);
void multiply (STACK *s);
void divide (STACK *s);
