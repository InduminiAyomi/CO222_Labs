#include <stdio.h>
#include <ctype.h>
#include <string.h>

int occur(char * word,char * text);


int main(int argc, char** argv){
	
	int i,count=0;
	for(i=2;i<argc;i++){
		
		if(occur(argv[1],argv[i]) == 1){
			count++;
		}	
	}
	
	printf("The occurrences of “%s” in the text is %d.\n",argv[1],count);
	

	return 0;

}


int occur(char * word,char * text){
	
	int i=0,arr[strlen(word)],newArr[strlen(text)];
	
	
	if(strlen(word) == strlen(text)){
		
		for(i=0;i<strlen(word);i++){
			
			if(isupper(word[i])==1){
				int a = word[i] +32;
				word[i] = a;
				arr[i] = word[i];
			}
			else{
				arr[i] = word[i];
			}
			
		}
		
		
		for(i=0;i<strlen(word);i++){
			
			if(isupper(text[i])==1){
				int a = text[i] +32;
				text[i] = a;
				newArr[i] = text[i];
			}
			else{
				newArr[i] = text[i];
			}
			
		}
	}
	
	int count =0;
	for(i=0;i<strlen(word);i++){
		if(arr[i] == newArr[i]){
			count++;
		}
	}
	
	if(count == strlen(word)){
		return 1;
	}
	else{
		return 0;
	}
	
	}

