/* Reverse of a string using stack
   @SamJoseph 29-07 */

#include <stdio.h>
#include <string.h>

char stack[10];
int top = -1;

void push(char c) {
    if (top == 9) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0'; // Fix: return type changed to char
    } else {
        return stack[top--];
    }
}

int main() {
    char str[10];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);  // Fix: safer than gets()

    for (i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}

