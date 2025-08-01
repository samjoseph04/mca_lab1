#include <stdio.h>

#define MAX 20

int top = -1;
char stack[MAX];
char postfix[MAX];
char infix[MAX];

void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;  
}

int isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9')) {
        return 1;
    }
    return 0;
}

int main() {
    int i = 0, j = 0;
    char item;

    printf("Enter an expression: ");
    fgets(infix, MAX, stdin);

    while (infix[i] != '\0') {
        if (infix[i] == '\n') {
            infix[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;  

    while ((item = infix[i]) != '\0') {
        if (isOperand(item)) {
            postfix[j++] = item;
        }
        else if (item == '(') {
            push(item);
        }
        else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();  
            } else {
                printf("Invalid Expression: Mismatched parentheses\n");
                return 1;
            }
        }
        else {  
            while (top != -1 && priority(stack[top]) >= priority(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf(" Mismatched parentheses\n");
            return 1;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

