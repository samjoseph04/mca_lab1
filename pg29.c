//Queue using array
#include <stdio.h>
#define MAX 10

int a[MAX];
int front=-1;
int rear=-1;

int enqueue(int b){
	int data=-1;
	if (rear==MAX-1){
		printf("Queue Overflow: Cannot enqueue value\n");
		return;
	}
	if (front==-1){
		front=0;
	}
	rear++;
	a[rear]=b;
	printf("Enqueued %d\n",b);
}

int dequeue(){
	int data=-1;
	if (front==-1){
		printf("Queue Underflow: Cannot dequeue value\n");
		return;
	}
	data=a[front];
	if (front==rear){
		front=-1;
		rear=-1;
	}
	else{
		front++;
	}
	printf("Dequeued %d\n",data);
	return data;
}
void display(){
	if (front==-1){
		printf("Queue Underflow: Empty\n");
		return;
	}
	int i;
	printf("Queue:  ");
	for(i=front;i<=rear;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
int main(){
	int d,ch;
	printf("Queue Operation\n");
	printf("----------------");
	while (1){
		printf("\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter an Option:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the value to be Enqueued: ");
				scanf("%d",&d);
				printf("\n");
				enqueue(d);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid Option\n");
				break;
		}
	}
	
	return 0;
}
