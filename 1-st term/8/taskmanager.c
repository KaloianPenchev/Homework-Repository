#include<stdio.h>
#include"processes.h"

int main(){
    
    printf("1.Create a process\n");
    printf("2.Print processes\n");
    printf("3.Stop a process\n");
    printf("4.Exit\n");
    
    int option;
    
    do{
        printf("Choose an option(1, 2, 3, 4): ");
        scanf("%d", &option);

        char name[30];
        int ID;
        
        switch (option)
        {
        case 1:
            
            printf("Name: ");
            scanf("%s", &name);
            ID = createnewprocess(name);
            if(ID == 0){
                printf("The maximum number of working processes has been reached and in order to create a new process, one of the workers must be stopped.\n");
            }
            break;
        case 2:
            for(int i = 0; i < processescount; i++){
                printf("ID: %lu -> Name: %s\n", processes[i].ID, processes[i].name);
            }

            break;
        case 3:
            printf("ID: ");
            scanf("%d", &ID);
            stopprocess(ID);
            break;
        }
    }while(option != 4);

    return 0;
}