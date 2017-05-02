#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addFun();
void deleteFun();
void printFun();
void printAll();

// structure to store student records
typedef struct _ {

	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;

} student_t;

student_t arr[1000];  // student_t type array to store student records
int count=0; // to count the number of records in the student_t array

int main(){

	int input;


	while(1){

		puts("----------------------------------------------\n");
		puts("A VOLATILE STUDENTS RECORD MAINTENANACE SYSTEM\n");
		puts("----------------------------------------------\n");

		puts("0. Quit\n");
		puts("1. Insert a Student Record\n");
		puts("2. Print a Student Record \n");
		puts("3. Print all Student Records\n");
		puts("4. Delete a Student Record\n");

		scanf("%d",&input);

		if(input == 0){
			exit(0);  //
		}
		else if(input == 1){
			addFun(); // call the add function
		}
		else if(input == 2){
			printFun();  // call the print function
		}
		else if(input == 3){
            printAll(); // call the print all function
		}
		else if(input == 4){
			deleteFun();  // call the delete function
		}

	}

	return 0;

}

// add student records to the structure
void addFun(){

	printf("Enter the batch(11/12/13/14): ");
	scanf("%d", &arr[count].batch);

	printf("Enter the registration number: ");
	scanf("%d", &arr[count].regNo);

	printf("Enter the first name: ");
    scanf("%s", arr[count].firstName);

	printf("Enter the last name: ");
    scanf("%s", arr[count].lastName);

	printf("Enter the cumulative GPA: ");
	scanf("%f", &arr[count].cGPA);

	count++;

}

// print a selected record of student
void printFun(){

    char input[8];
    int i=0;

    printf("Enter the registration number: ");
	scanf("%s",input);


    int batch = (input[2]-48)*10 + (input[3]-48);
    int regNumber = (input[5]-48)*100 + (input[6]-48)*10 + (input[7]-48);


    while(!((arr[i].batch == batch) && (arr[i].regNo == regNumber)))
        i++;

    printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %.2f\n\n",arr[i].firstName,arr[i].lastName,arr[i].batch,arr[i].regNo,arr[i].cGPA);

}

// print all records in the student_t structure
void printAll(){

    int i=0;
    while(arr[i].batch != '\0'){
        printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %.2f\n\n",arr[i].firstName,arr[i].lastName,arr[i].batch,arr[i].regNo,arr[i].cGPA);
        i++;
    }
}

// delete a student record from the student_t structure
void deleteFun(){

    char input[8];
    int i=0;

    printf("Enter the registration number: ");
	scanf("%s",input);


    int batch = (input[2]-48)*10 + (input[3]-48);
    int regNumber = (input[5]-48)*100 + (input[6]-48)*10 + (input[7]-48);


    while(!((arr[i].batch == batch) && (arr[i].regNo == regNumber)))
        i++;

    while(arr[i].batch != '\0'){
        arr[i].batch = arr[i+1].batch;
        arr[i].regNo = arr[i+1].regNo;

        int j=0,k=0;
        while(arr[i].firstName[j] != '\0'){
            arr[i].firstName[j] = arr[i+1].firstName[j+1];
            j++;
        }
        while(arr[i].firstName[k] != '\0'){
            arr[i].lastName[k] = arr[i+1].lastName[k+1];
            k++;
        }
        arr[i].cGPA = arr[i+1].cGPA;
        i++;
    }
    count--;

}
