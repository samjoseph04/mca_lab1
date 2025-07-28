/*Stack Operations
@SamJoseph 29-07*/
#include <stdio.h>

int stack[10];
int top=-1;

void push(int val){
	if(top==9){
		printf("Stack Overflow\n");
	}
	else{
		stack[++top]=val;
		printf("%d is pushed to stack",val);
	}
}

void pop(){
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		printf("%d popped from stack",stack[top--]);
	}
}
void peek(){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("%d is the top element",stack[top]);
	}
}

void disp(){
	int i;
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("Stack elements are: ");
		for(i=top;i>=0;i--){
			printf("%d\t",stack[i]);
		}
	}
}

int main(){
	int ch, val;
	while(1){
		printf("\nStack options: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    	
		switch(ch){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                disp();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

	
