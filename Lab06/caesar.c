/*
	CO222-2016 Lab06
	Author: E13057

	Caesar Cipher
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//declare prototypes of the functions
int rotateright(int);  
int rotateleft(int);
int encode(int,int);

int main(){
	 
	 int shiftNum,i=0,j; 
	 char textArr[200],c;
	
	 
	 printf("Enter shift: ");
	 scanf("%d",&shiftNum);  // get the shift number from user
	 
	 printf("Enter text:\n");
	 
	 //take the user input text to array
	 while(c != -1){
		 
		c = getchar();
		textArr[i] = c;
		i++;
	 }
	 
	 printf("\n");
	 printf("Here is the encoded text:\n");
	 
	 
	 for(j=1;j<i-1;j++){
		 int val = encode(textArr[j], shiftNum);  // call the encode function and get the return value
		 printf("%c",val);   // print the character for relavant ascii value
	}
	 printf("\n");	
	
	  
	 
	 return 0;
 }
 
 // rotate a alphabetic character one step to the right
int rotateright(int ch){
	if((ch>=65 && ch<90) || (ch>=97 && ch<122)){  //check characters
			++ch; 
	}
	else if(ch == 90){  // check character A and return Z
		 ch = 'A';
	}
	else if(ch == 122){  // check character a and return z
		ch = 'a';
	}
	return ch;
}

 // rotate a alphabetic character one step to the left
int rotateleft(int ch){
	if((ch>65 && ch<=90) || (ch>97 && ch<=122)){  // check characters
		--ch;
	}
	else if(ch == 65){  // check character Z and return A
		ch = 'Z';
	}
	else if(ch == 97){  // check character z and return a
		ch = 'z';
	}
	return ch;
}

// rotate the specified number of shift
int encode(int ch, int shift){
	int i;
	if(shift>0){
		for(i=1;i<=shift;i++){
			ch = rotateright(ch);
		}
	}
	else if(shift<0){
		shift = (-1)*shift;
		for(i=1;i<=shift;i++){
			ch = rotateleft(ch);
		}
	}
	return ch;
}
