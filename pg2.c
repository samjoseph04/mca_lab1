#include <stdio.h>
int a[5]; 
int pos=-1;
void insert(int e){
	if ( pos+1==5 ){
		printf("Error: Array is full\n");
	}
	else{
		a[++pos]=e;
	}
}
void search(int e){
	int i;
	for(i=0;i<=pos;i++){
		if (a[i]==e){
			printf("Element found at position %d\n",pos);
			break;
		}
	}
}
void delete(){
	if ( pos+1==0 ){
		printf("Error: Array is full\n");
	}
	else{
		printf("%d\n",a[pos--]);
	}
}
void sort(){
    int i, j, t;
    for(i=0;i<pos;i++){
        for(j=0;j<pos-i;j++){
            if(a[j]>a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void disp(){
	int i;
	for(i-0;i<=pos;i++){
		printf("%d\t",a[i]);
	}
}

int main(){
	int ch,e;
		do{
	printf("--------------------");
	printf("\n|1.INSERT          |\n|2.DELETE          |\n|3.SEARCH          |\n|4.SORT            |\n|5.EXIT            |\n");
	printf("--------------------\n");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			printf("Enter value to insert: ");
			scanf("%d",&e);
			insert(e);
			printf("New Array: ");
			disp();
			printf("\n");
			break;
		case 2:
			delete();
			printf("New Array:\n");
			disp();
			printf("\n");
			break;
		case 3:
			printf("Enter value to search: ");
			scanf("%d",&e);
			search(e);
			break;
		case 4:
			sort();
			printf("New Array: ");
			disp();
			printf("\n");
			break;
		default:
			break;
	}
}while(ch!=5);
	return 0;
}
