#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Stack *make_stack(int capacity) {
    Stack *p = malloc(sizeof(Stack));
    
    p->capacity = capacity;
    p->top = -1;
    p->data = malloc(sizeof(double) * capacity);

    return p;
}

bool push(Stack *p, int i) {
    if (!is_full(p)) {
        p->top++;
        p->data[p->top] = i;
        return true;
    } else {
        return false;
    }
}

int pop(Stack *p) {
    if (!is_empty(p)) {
        return p->data[p->top--];
    } else {
        return -1;
    }
}

void make_empty(Stack *p) {
    p->top = -1;
}

bool is_full(Stack *p) {
    return p->top == p->capacity - 1; 
}

bool is_empty(Stack *p) {
    return p->top == -1;
}

void delete_stack(Stack *p) {
    free(p->data);
    free(p);
}
