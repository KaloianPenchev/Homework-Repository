#include<stdio.h>

int main(){
    unsigned char lights = 0;
    
    printf("1.Switch lights\n");
    printf("2.Print state\n");
    printf("3.Exit\n");
    
    int option;
    
    do{
        printf("Choose an option(1, 2, 3): ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
            int light;
            printf("Enter a number of a room(1 to 8): ");
            scanf("%d", &light);
            lights = lights ^ (1 << (light - 1));
            break;
        case 2:
            printf("Lights that are turned ON: ");
            for(int i = 0; i <= 7; i++){
                if((lights >> i) & 1){
                    printf("%d ", i+1);
                }
            }
            printf("\n");
            break;
        }
    }while(option != 3);

    return 0;
}