//Matthew Abercrombie
//ITCS 3146 Child-Parent Cooperation (Merge-Sort)
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define SIZE 800

int comp(const void *a, const void *b){
    int A = *((int*)a);
    int B = *((int*)b);
    if      (A==B)  return 0;
    else if (A < B) return -1; 
    else            return 1;
}

void brancher( int array[SIZE]){
    int i=0;
    
    pid_t child;
    pid_t parent;
    parent = getpid();
    
    for (i; i<3; i++){
        child = fork();
        
        if (child < 0){
            perror("Fork Failed");
            exit(1);
        }else if (child > 0){        
            continue;
        }else{
            continue;
        }
    }
    
    if (parent != getpid()){
        kill (getpid(), SIGUSR1);
    }
    
    qsort(array, SIZE, sizeof(array[0]), comp);
}

int main(){
    
    char file_name[40];
    int array[SIZE]={0};    
    int i=0;
    
    printf("Enter file name: ");
    scanf("%s", file_name);
    
    
    //reads file --- move to method later to simplify
    FILE *fptr = fopen(file_name, "r");
    long int val;
    do{
        array[i] = val;
        fscanf( fptr, "%ld", &val);
        i++;
    }while (!feof(fptr));
    fclose(fptr);
    
    //creates branches 3 times (800 -> 400 -> 200 -> 100)
    brancher(array);
    
    for (i=0; i<sizeof(array)/4; i++){
        printf("%d \n", array[i]);
    }
    
    return 0;
}