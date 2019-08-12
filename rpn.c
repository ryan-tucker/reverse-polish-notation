#include "input.h"
#include "stack.h"
#include <ctype.h>

double calculate_current(char sign, int first, int second);

int calculate_rpn() {
    Stack *stack = make_stack(50);
    printf("Please Enter an equation in reverse polish notation. e.g. 5 4 3 + -\n");
    char *input = malloc(100);
    char *token = malloc(100);
    fgets(input, 100, stdin);
    int index = 0;
    while (next_token(input,&index,token)) {
        if (!isdigit(token[0])) {
            int num1 = pop(stack);
            int num2 = pop(stack);
            push(stack, calculate_current(token[0], num1, num2));
        } else {
            push(stack, atof(token));   
        }
    }
    printf("Answer: %d\n", pop(stack));

    
    delete_stack(stack);
    free(input);
    free(token);

    return 0;

}

double calculate_current(char sign, int first, int second) {
    switch(sign) {
        case '+':
            return first + second;
        case '-':
            return second - first;
        case '*':
            return first * second;
        case '/':
            return second / first;
        default:
            return -1;
    }
}

int main(int argc, char *argv[]) {
    calculate_rpn();
}
