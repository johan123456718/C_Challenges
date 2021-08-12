#include <stdio.h>
#include <ctype.h>
int main(void){
    char choice;
    int value1,value2;
    while(choice != 'Q'){
        printf("Operation (A,O,Q): ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        if(choice == 'A'){
            
            printf("Value 1 (1,0): ");
            scanf("%d", &value1);

            printf("Value 2 (1,0): ");
            scanf("%d", &value2);
            
            if(value1 == 1 && value2 == 1){
                printf("Result: 1\n");
            }else{
                printf("Result: 0\n");
            }
        }

        if(choice == 'O'){
            printf("Value 1 (1,0): ");
            scanf("%d", &value1);
            printf("Value 2 (1,0): ");
            scanf("%d", &value2);
            if(value1 == 1 || value2 == 1){
                printf("Result: 1\n");
            }else{
                printf("Result: 0\n");
            }
        }
    }
    printf("QUIT\n");
    return 0;
}