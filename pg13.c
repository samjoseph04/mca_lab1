/*Reverse of a String
@SamJoseph 29-07*/
#include <stdio.h>
#include <string.h>

int main() {
	int i,len;
    char str[10];

    printf("Enter a string: ");
    scanf("%s", str);
	len=strlen(str);

    printf("Reversed string: ");
    for(i=len-1;i>=0;i--){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}

