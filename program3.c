
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>



int main(){
   
    printf("Choose the function to be performed by the child: \n");
    printf("\t(1) Display current date and time\n");
    printf("\t(2) Display the calendar of the current month\n");
    printf("\t(3) List the files in the current directory\n");
    printf("\t(4) Exit from the program\n");
    
    char choice;
    scanf("%c", &choice);
    
    switch (choice){
        case '1':
        break;
        case '2':
        break;
        case '3':
        break;
        case '4':
            printf("Program terminated\n");
            exit(0);
        break;
        
    }
   
   
   
    return 0;
}


