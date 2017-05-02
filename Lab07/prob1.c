#include <stdio.h>

int main(){
	
	int n,i,j,k=65,a;
	printf("Enter N: ");
	scanf("%d",&n);
	
    printf("\n");
    
    
	for(i=0;i<=n;i++){
		for(j=0;j<i;j++){
				if(k<=90){
					printf("%c",k);
					k++;
			    }
			    else{
					a=65;
					while(j<i){
					printf("%c",a);
					j++;
					a++;
					}
					break;
				}
			}
			k=65;
			printf("\n");
		}
		
		
		

	
	for(i=n;i>=0;i--){
		for(j=i-1;j>0;j--){
			if(k<=90){
					printf("%c",k);
					k++;
			    }
			    else{
					a=65;
					while(j>0){
					printf("%c",a);
					j--;
					a++;
					}
					break;
				}
		}
		k=65;
		printf("\n");
	}
	
	
	

	return 0;
}
