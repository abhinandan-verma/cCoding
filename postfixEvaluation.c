#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = data;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int isOperand(char c) {
    return (c >= '0' && c <= '9');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

int postfixEvaluation(char *exp) {
    Stack s;
    init(&s);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isOperand(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix evaluation: %d\n", postfixEvaluation(exp));
    return 0;
}
// Output
// Postfix evaluation: -4
// The time complexity of the postfixEvaluation function is O(n) where n is the length of the expression.
