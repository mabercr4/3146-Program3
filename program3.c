
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>



int main(){
    pid_t child_pid;
    child_pid=fork();
    if (child_pid==-1){     //if fail
        printf("Failed to fork\n"); return 1;
    }    
    int x=0,y=0;
    
    if (child_pid==0){ /*child code*/
        x = getpid();
    }
    else
        y = getpid();
    
    //  time_t rawtime;
    //         struct tm * timeinfo;
    //         time ( &rawtime );
    //         timeinfo = localtime ( &rawtime );
    //         printf ( "Current local time and date: %s", asctime (timeinfo) );

  
    



    //working past this point
    
    //Menu
    printf("Parent process ID: %d, Parent's parent ID: \n",x );
    
    
    printf("Enter your choice: ");
    char choice;
    scanf("%c", &choice);
    
    
        
   
   
   
   
    return 0;
}

void menu(char choice){
    
    printf("Choose the function to be performed by the child: \n");
    printf("\t(1) Display current date and time\n");
    printf("\t(2) Display the calendar of the current month\n");
    printf("\t(3) List the files in the current directory\n");
    printf("\t(4) Exit from the program\n");
    
    switch (choice){
        case '1':
            time_t mytime;
            mytime = time(NULL);
            printf(ctime(&mytime));
            
           
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
    
}


