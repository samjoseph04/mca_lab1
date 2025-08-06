//Cirular queue using array
#include <stdio.h>
#define MAX 10

int cqueue[MAX];
front=-1;
rear=-1;

int enqueue(int d){
	if ((front==0 && rear==MAX-1) || (front==rear-1)){
		printf("Queue Overflow: Cannot enqueue\n");
		return;
	}
	if(front==-1){
		front=0;
	}
	rear=(rear+1)%MAX;
	cqueue[rear]=d;
	printf("Enqueued &d",d);
	
}

int dequeue(){
	int d=-1;
	if (front==-1 && rear==-1){
		printf("Queue Underflow: Cannot dequeue\n");
		return;
	}
	d=cqueue[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}else{
		front=(front+1)%MAX;
	}
	printf("Dequeued %d",d);
	return d;
}

void display(){
	int i;
	if(front==-1){
		printf("Queue is empty\n");
	}
	else{
		printf("Queue elements: ");
		i=front;
		while (i!=rear){
			printf("%d\t",cqueue[i]);
			i=(i+1)%MAX;
		}
		printf("%d",cqueue[i]);
	}
}

int main(){
	int ch;
	int d;
	printf("Circular queue\n");
	printf("--------------\n");
	while(1){
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value to Enqueue: ");
				scanf("%d",&d);
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
