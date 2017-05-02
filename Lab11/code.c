#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototypes
void addFun();
void printAll();
void printFun();
void deleteFun();

// structure to store student records
typedef struct student {

	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;
	struct student * next;

} student_t;

// student type pointers
student_t *last = NULL;
student_t *current;
student_t* temp;  // used for delete function
student_t* now;  // used for delete function

int main() {

	int input;

	while(1){

        // print the UI
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
			exit(0);  // stop recording
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

// Add student records
void addFun(){


	current = (student_t *) malloc(sizeof(student_t)); // allocate a memory space

	printf("Enter the batch(11/12/13/14): ");
	scanf("%d", &current -> batch);

	printf("Enter the registration number: ");
	scanf("%d", &current -> regNo);

	printf("Enter the first name: ");
	scanf("%s", current -> firstName);

	printf("Enter the last name: ");
	scanf("%s", current -> lastName);

	printf("Enter the cumulative GPA: ");
	scanf("%f", &current -> cGPA);

	current -> next = last;
	last = current;

}

// Print all student records
void printAll(){

	student_t *new;

	for(new = last ; new != NULL ; new = new -> next) {
		printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %.2f\n\n",new -> firstName,new -> lastName,new -> batch,new -> regNo,new -> cGPA);
	}
}

// print a student record
void printFun(){

    char input[8];

    printf("Enter the registration number: ");
    scanf("%s",&input);   // get the E number from the user

    int batch = (input[2]-48)*10 + (input[3]-48);
    int regNumber = (input[5]-48)*100 + (input[6]-48)*10 + (input[7]-48);

    temp = last;

    while(!((temp -> batch == batch) && (temp -> regNo == regNumber)))
        temp = temp -> next;

    printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %.2f\n\n",temp -> firstName,temp -> lastName,temp -> batch,temp -> regNo,temp -> cGPA);


}

void deleteFun(){

    char input[8];

    printf("Enter the registration number: ");
    scanf("%s",&input);

    int batch = (input[2]-48)*10 + (input[3]-48);
    int regNumber = (input[5]-48)*100 + (input[6]-48)*10 + (input[7]-48);


    now = last;
    if(now -> regNo == regNumber && now -> batch == batch){   // delete the first node
			temp = now -> next;
			free(now);
			last = temp;
    }
    else{

            temp = last;
            now = last -> next;

            while(now -> regNo != regNumber && now -> batch != batch){
                now = now -> next;
                temp = temp -> next;
            }
            if(now -> next == NULL){   // delete the last node
                temp -> next = NULL;
                free(now);
                now = temp;
            }
            else{
                temp -> next = now -> next;   // delete a middle node
                free(now);
                temp = now;
            }

    }
}


