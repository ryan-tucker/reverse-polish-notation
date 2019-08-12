#include <stdbool.h>

typedef struct Stack {
    int capacity;
    int top;
    int *data; 
} Stack;

Stack *make_stack(int capacity);
bool push(Stack *p, int i);
int pop(Stack *p);
void make_empty(Stack *p);
bool is_full(Stack *p);
bool is_empty(Stack *p);
void delete_stack(Stack *p);

