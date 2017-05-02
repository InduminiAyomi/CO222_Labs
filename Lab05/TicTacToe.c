/*
	CO222-2016 Lab05
	Author: E13057

	TicTacToe game
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int b[SIZE][SIZE]);

int main(){

	int inBoard[SIZE][SIZE];	//declaring an array

	printf("Please enter the board:\n");
	scanBoard(inBoard);	//scanBoard
	printf("Here is the board:\n");
	printBoard(inBoard);	//printBoard


	//printing the result
	if(getWinner(inBoard)==0)
		printf("Noughts win\n");
	else if(getWinner(inBoard)==1)
		printf("Crosses win\n");
	else if(getWinner(inBoard)==2)
		printf("There are no winners\n");

	return 0;
}


//scan function
void scanBoard(int board[SIZE][SIZE]){
	//check if the input is 0 || 1 || 2
	//else give the error message "Enter valid input." and terminate the program
    int i,j;
	for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            scanf("%d",&board[i][j]);
        }
	}

	for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]==0 || board[i][j]==1 || board[i][j]==2){
            }else{
                printf("Enter valid input.");
                exit(0);
            }
        }
	}

}


//print function
void printBoard(int board[SIZE][SIZE]){
    //printing board
    int i,j;
    char newArr[SIZE][SIZE];
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]==0){
                newArr[i][j]='o';
            }else if(board[i][j]==1){
                newArr[i][j]='X';
            }else if(board[i][j]==2){
                newArr[i][j]='.';
            }

        }
    }

     for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
           printf("%c",newArr[i][j]);
           printf(" ");
        }
        printf("\n");
    }

}


//find the winner of the game
//assume both two players can't win the game at the same time. It can't happen in a real game
int getWinner(int board[SIZE][SIZE]){

	//if winner is Noughts, winner = 0
	//if winner is Crosses, winner = 1
	//if there is no winner, winner = 2

    int winner=2;
    int i,j;     // i-rows j-columns
    int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0;
    
    //check rows
     for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
			if(board[i][j]==0)
				count0++; 
			if(board[i][j]==1)
				count1++; 
				
			if(count0==SIZE){
				winner = 0;
				break;
			}	
			if(count1==SIZE){
				winner = 1;
				break;
			}	
        }
      
		 count0=0;  count1=0;
        
    }
    
  
 //check columns
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
			if(board[j][i]==0)
				count4++;
			if(board[j][i]==1)
				count5++;
				
			if(count4==SIZE){
				 winner =0;
				 break;
			}	
			if(count5==SIZE){
				winner = 1;
				break;
          }
        }
        
        count4=0;  count5=0;
        
    }
    
 
    //check off diagonal
    for(i=0,j=SIZE-1;i<SIZE && j>=0;i++,j--){
		if(board[i][j]==0)
			count6++;
		if(board[i][j]==1)
			count7++;
			
		if(count6==SIZE){
				winner = 0;
				break;
		}	
		if(count7==SIZE){
				winner = 1;
				break;
	}
}
	//check main diagonal
     for(i=0;i<SIZE;i++){
		  if(board[i][i]==0)
			count2++;
		if(board[i][i]==1)
			count3++;
			
		if(count2==SIZE){
				winner = 0;
				break;
		}	
		if(count3==SIZE){
				winner = 1;
				break;
		}
		 
	}
   





	return  winner;
}
