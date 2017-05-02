#include<stdio.h>
int main(){
	
	int a,b,c,d,e,f;
	int x,y,z; 
	printf("Enter the color: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if((a<=255 && a>=0) && (b<=255 && b>=0) && (c<=255 && c>=0)){
	x = a-(255-a);
	if(x<0)
	x = -1*x;
	
	y = b-(255-b);
	if(y<0)
	y = -1*y;
	
	z = c-(255-c);
	if(z<0)
	z = -1*z;
	
	 //complement of 1st component
	if(x<=32){
		
		if(a+128 > 255){
			d = a - 128;
		}
		else{
			d = a + 128;
		}
	}
	else{
		d = 255 - a;
	}
	
	//complement of 2nd component
	if(y<=32){
		
		if(b+128 > 255){
			e = b - 128;
		}
		else{
			e = b + 128;
		}
	}
	else{
		e = 255 - b;
	}
	
	//complement of 3rd component
	if(z<=32){
		
		if(c+128 > 255){
			f = c - 128;
		}
		else{
			f = c + 128;
		}
	}
	else{
		f = 255 - c;
	}
	

	printf("The complement: %d %d %d\n",d,e,f);
	}
	else{
		printf("Enter valid input");
	}
	
	return 0;
}
