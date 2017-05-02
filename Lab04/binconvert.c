#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
     int i,value=0,j=1;
     if(argc==4){

         //input format-Hexadecimal
    if(argv[1][1]=='H'){

        int hex_val = atoi(argv[3]); //convert char input to integer
       int keep; // use for keep corresponding integer values of hexadecimals

        if(argv[2][1]=='I')        // Hexadecimal --> Integer
        {

            for(i=strlen(argv[3])-1; i>=0; i--){

                 switch(argv[3][i])
                {
                case '0':
                    keep=0;
                    break;
                case '1':
                    keep=1;
                    break;
                case '2':
                    keep=2;
                    break;
                case '3':
                    keep=3;
                    break;
                case '4':
                    keep=4;
                    break;
                case '5':
                    keep=5;
                    break;
                case '6':
                    keep=6;
                    break;
                case '7':
                    keep=7;
                    break;
                case '8':
                    keep=8;
                    break;
                case '9':
                    keep=9;
                    break;
                case 'A':
                   keep=10;
                    break;
                case 'B':
                    keep=11;
                    break;
                case 'C':
                    keep=12;
                    break;
                case 'D':
                    keep=13;
                    break;
                case 'E':
                   keep=14;
                    break;
                case 'F':
                   keep=15;
                    break;
                }
                value = value + keep*j;
                j=j*16;
                 }

            printf("%d",value);
            }




        else if(argv[2][1]=='B')     //Hexadecimal --> Binary
        {
            //char a[4];
            for(i=0; i<sizeof(argv[3]); i++)
            {
                switch(argv[3][i])
                {
                case '0':
                    printf("0000");
                    break;
                case '1':
                    printf("0001");
                    break;
                case '2':
                    printf("0010");
                    break;
                case '3':
                    printf("0011");
                    break;
                case '4':
                    printf("0100");
                    break;
                case '5':
                    printf("0101");
                    break;
                case '6':
                    printf("0110");
                    break;
                case '7':
                    printf("0111");
                    break;
                case '8':
                    printf("1000");
                    break;
                case '9':
                    printf("1001");
                    break;
                case 'A':
                    printf("1010");
                    break;
                case 'B':
                    printf("1011");
                    break;
                case 'C':
                    printf("1100");
                    break;
                case 'D':
                    printf("1101");
                    break;
                case 'E':
                    printf("1110");
                    break;
                case 'F':
                    printf("1111");
                    break;
                }
            }



        }
        else if(argv[2][1]=='H'){ //Hexadecimal --> Hexadecimal
            printf("%s",argv[3]);
        }

        }


        // input format --> Integer
         if(argv[1][1]=='I')
        {
        int int_val = atoi(argv[3]);
            if(argv[2][1]=='B') {      // Integer --> Binary

            int arr[32];
            i=0;
            if(int_val>0){ //when integer value > 0
            while(int_val!=0)
            {
                arr[i++]= int_val%2;
                int_val = int_val/2;
            }
               printf("0");

             for(j = i -1 ;j>= 1;j--){

                printf("%d",arr[j]);


             }
            }
            else if(int_val==0){ // when integer value = 0
            printf("0000");
            }
            else{                   // when integer value < 0
                int_val = int_val*(-1);

                while(int_val!=0)
            {
                arr[i++]= int_val%2;
                int_val = int_val/2;
            }

            printf("1");
             for(j = i -1 ;j>= 1;j--){

                printf("%d",arr[j]);


             }
            }

             }




        else if(argv[2][1]=='H') //Integer --> Hexadecimal
        {
            printf("0x");
            char arr[16];
            i=0;
            char sign;


            if(int_val<0){
                    int x = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
                int_val = int_val + x;
            }

            while(int_val!=0)
            {
                switch(int_val%16){
                    case 0:
                    sign='0';
                    break;
                case 1:
                    sign='1';
                    break;
                case 2:
                    sign='2';
                    break;
                case 3:
                    sign='3';
                    break;
                case 4:
                    sign='4';
                    break;
                case 5:
                    sign='5';
                    break;
                case 6:
                    sign='6';
                    break;
                case 7:
                    sign='7';
                    break;
                case 8:
                    sign='8';
                    break;
                case 9:
                    sign='9';
                    break;
                case 10:
                    sign='A';
                    break;
                case 11:
                    sign='B';
                    break;
                case 12:
                    sign='C';
                    break;
                case 13:
                    sign='D';
                    break;
                case 14:
                    sign='E';
                    break;
                case 15:
                    sign='F';
                    break;
                }
                arr[i++]= sign;
                int_val = int_val/16;
            }
             for(j = i -1 ;j>= 0;j--)
                printf("%c",arr[j]);

        }

         else if(argv[2][1]=='I'){      // Integer --> Integer
            printf("%s",argv[3]);

        }
        else if(argv[2][1]=='F'){      // Integer --> Float
            printf("%s",argv[3]);
            printf(".00");

        }

        }

            //input format-Binary
    if(argv[1][1]=='B'){

        int bin_val = atoi(argv[3]);

        if(argv[2][1]=='I') { // Binary --> Integer

            for(i=strlen(argv[3])-1;i>=1;i--){
            if((argv[3][i])==48 || (argv[3][i])==49){
                value = value + (argv[3][i]-48)*j;
                j = j*2;
            }
            }
            switch(argv[3][0]-48){
                case 0:  printf("%d\n",value); break;
                case 1: value= -1*value; printf("%d\n",value); break;
                default : break;
            }
        }
        else if(argv[2][1]=='B'){  // Binary --> Binary
            printf("%s",argv[3]);

        }
        else if(argv[2][1]=='H'){ // Binary --> Hexadecimal

        int arr[32];
        for(i=0;i<=31;i++){
            if(argv[3][i]=='0')
                arr[i]=0;
            else if(argv[3][i]=='1')
                arr[i]=1;
        }
        printf("0x");
        for(i=0;i<=31;i=i+4){
        if(arr[i]==0 && arr[i+1]==0 && arr[i+2]==0 && arr[i+3]==0 )
                printf("0");
        else if(arr[i]==0 && arr[i+1]==0 && arr[i+2]==0 && arr[i+3]==1 )
                printf("1");
        else if(arr[i]==0 && arr[i+1]==0 && arr[i+2]==1 && arr[i+3]==0 )
                printf("2");
        else if(arr[i]==0 && arr[i+1]==0 && arr[i+2]==1 && arr[i+3]==1 )
                printf("3");
        else if(arr[i]==0 && arr[i+1]==1 && arr[i+2]==0 && arr[i+3]==0 )
                printf("4");
        else if(arr[i]==0 && arr[i+1]==1 && arr[i+2]==0 && arr[i+3]==1 )
                printf("5");
        else if(arr[i]==0 && arr[i+1]==1 && arr[i+2]==1 && arr[i+3]==0 )
                printf("6");
        else if(arr[i]==0 && arr[i+1]==1 && arr[i+2]==1&& arr[i+3]==1 )
                printf("7");
        else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==0 && arr[i+3]==0 )
                printf("8");
        else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==0 && arr[i+3]==1 )
                printf("9");
        else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==1 && arr[i+3]==0 )
                printf("A");
        else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==1 && arr[i+3]==1 )
                printf("B");
        else if(arr[i]==1&& arr[i+1]==1 && arr[i+2]==0 && arr[i+3]==0 )
                printf("C");
        else if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==0 && arr[i+3]==1 )
                printf("D");
        else if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==1 && arr[i+3]==0 )
                printf("E");
        else if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==1 && arr[i+3]==1 )
                printf("F");
        }

    }


}

//input format-Float
if(argv[1][1]=='F'){
    if(argv[2][1]=='I'){   // Float --> Integer
        for(i=0;i<strlen(argv[3])-3;i++){
            printf("%c",argv[3][i]);
        }
    }
    else if (argv[2][1]=='F'){  // Float --> Float
        printf("%s",argv[3]);
    }
}





     return EXIT_SUCCESS;


}
     else {

        printf("Usage: ./binconvert -<input format> -<output format> <input>");
        return EXIT_FAILURE;
     }



}

