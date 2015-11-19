#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void display (int choice){
    //exception case (to prevent forking and printing pids)
    if (choice == 4) return;
    
    //new process creation for tasks
    pid_t pid = fork();
    
    //Handles forking failure
    if (pid < 0) {
        perror("Fork Failed");
        return;
    }
    
            /*  ------ CHILD ------  */
    if (pid == 0){
        printf("Child process ID %d; Parent ID %d\n",(int)getpid(), (int)getppid());

        switch (choice){
            case 1:
                system("date");
            break;
            case 2:
                system("cal");
            break;
            case 3:
                system("ls -l");
            break;
        }
        //terminates child process
        exit(0);
    }
    else{   /*  ------ PARENT ------  */
        //waits until child finishes processing before returning to main()
        wait(NULL);
        return;
    }
}

void menu (){
    
    printf("Choose the function to be performed by the child: \n");
    printf("\t(1) Display current date and time\n");
    printf("\t(2) Display the calendar of the current month\n");
    printf("\t(3) List the files in the current directory\n");
    printf("\t(4) Exit from the program\n");
    printf("\nEnter your choice: ");
    
}

int main(int argc, int *argv[]){
    printf("Parent process ID: %d, Parent's parent ID: %d\n", (int)getpid(), (int)getppid());
int choice = 0;
do{
    //displays menu options
    menu();
    
    //asks for menu choice
    scanf("%d", &choice);
    
    //calls method to create process and execute choice
    
    display(choice);
    
    printf("\nCurrent process PID %d\n", (int)getpid());
}while (choice !=4);
    
    //Terminate
    printf("Program terminated\n");
}
