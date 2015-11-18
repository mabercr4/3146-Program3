#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void display (char choice){
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork Failed");
    }
    
    if (pid == 0){
        printf("Child process ID %d; Parent ID %d\n",(int)getpid(), (int)getppid());

        switch (choice){
            case '1':
                system("date");
            break;
            case '2':
                system("cal");
            break;
            case '3':
                system("ls -l");
            break;
        }
        exit(0);
    }
    else{
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

    //UNsure after this point
    menu();
    
    //answer menu
    char choice = 'a';
    scanf("%c", &choice);
    
    //call method to execute choice
    display(choice);
    
    printf("\nCurrent process PID %d\n", (int)getpid());
    
    printf("Program terminated\n");
}
