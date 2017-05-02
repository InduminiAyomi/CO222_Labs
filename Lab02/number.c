#include<stdio.h>
int main(){

	int num,a=0,b=0,c=0;

	printf("Enter a number: ");
	scanf("%d",&num);
	
	if(num%15==0){
		a=1; //special
		if(num%6==0 && num%18!=0){
			b=1; //weird
		}
	}
	if(num>999)
	c=1; //big
	
	if(a==1 && b==1 && c==1){
		printf("%d is special, big, weird and scary.\n", num);
	}
	else if(a==1 && b==1){
		printf("%d is special, weird and scary but not big.\n", num);
	}
	else if(a==1 && c==1){
		printf("%d is special, big and scary but not weird.\n", num);
	}
	else if(b==1 && c==1){
		printf("%d is weird,big and scary but not special.\n", num);
	}
	else if(a==1){
		printf("%d is special but not scary.\n", num);
	}
	else if(b==1){
		printf("%d is weird and scary but not special and big.\n", num);
	}
	else if(c==1){
		printf("%d is not special, big and scary but not weird.\n", num);
	}
	else {
		printf("%d is not special or not scary.\n", num);
	}
    
    return 0;
}
