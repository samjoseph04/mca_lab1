#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int top = -1;
char stack[MAX];
char infix[MAX], prefix[MAX];

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

int isOperand(char ch) {
    return isalnum(ch);  // letters or digits
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void reverseString(char* str) {
    int i;
	int len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char revInfix[MAX], postfix[MAX];
    int i, j = 0;

    strcpy(revInfix, infix);
    reverseString(revInfix);

    // Replace '(' with ')' and vice versa
    for (i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    top = -1;  // Reset stack
    i = 0;
    while (revInfix[i] != '\0') {
        char item = revInfix[i];
        if (isOperand(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();  // Remove '('
            } else {
                printf("Invalid Expression: Mismatched parentheses\n");
                return;
            }
        } else {  // Operator
            while (top != -1 && priority(stack[top]) >= priority(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid Expression: Mismatched parentheses\n");
            return;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline if any
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}

