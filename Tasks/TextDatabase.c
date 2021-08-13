#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define titleLength 30
#define bodyTextLength 1000
#define maxTexts 1000

struct FingerText{
    char title[titleLength];
    char bodyText[bodyTextLength];
    int year;
};
typedef struct FingerText fingerText;

fingerText createFingerText(char title[], char bodyText[], int year){
    fingerText f1;
    strcpy(f1.title, title);
    strcpy(f1.bodyText, bodyText);
    f1.year = year;
    return f1;
}

void changeTitle(fingerText *f, char newTitle[]);
void createText(fingerText fingerTexts[], int *nrOfTexts);
void printText(fingerText f);
void printTexts(fingerText fingerTexts[], int nrOfTexts);
void printMenu();

int main(void){
    //fingerText f1 = createFingerText("FingerText", "Fingerprints are unique for an individual", 2018);
    fingerText fingerTexts[maxTexts];
    int nrOfTexts = 0;
    char choice;
    int tmpIndex = 0;
    char newTitle[titleLength];
    while(choice != 'q'){
        printMenu();
        scanf(" %c", &choice);
        choice = tolower(choice);

        switch(choice){

            case 'e':
                createText(fingerTexts, &nrOfTexts);
            break;

            case 'p':
                printTexts(fingerTexts, nrOfTexts);
            break;

            case 'c':
                printf("Give position (0 - %d):", (nrOfTexts-1));
                scanf("%d", &tmpIndex);
                printf("New title: ");
                getchar();
                gets(newTitle);
                changeTitle(&fingerTexts[tmpIndex], newTitle);
            break;

        }
    }
    //changeTitle(&f1, "Individual");
    //printText(fingerText);
    printf("END\n");
    return 0;
}

void printMenu(){
    printf("\nEnter text(e)\n");
    printf("Print all texts (p)\n");
    printf("Change title (c)\n");
    printf("Quit (q)\n");
    printf(":");
}

void createText(fingerText fingerTexts[], int *nrOfTexts){
    char title[titleLength];
    char bodyText[bodyTextLength];
    int year = 0;

    getchar();
    printf("Title: ");
    gets(title);

    printf("Body: ");
    gets(bodyText); 

    printf("Year: ");
    scanf("%d", &year);

    fingerTexts[(*nrOfTexts)] = createFingerText(title, bodyText, year);
    (*nrOfTexts)++;
}

void printTexts(fingerText fingerTexts[], int nrOfTexts){

    for(int i = 0; i < nrOfTexts; i++){
        printf("\n%s %d\n", fingerTexts[i].title, fingerTexts[i].year);
        printf("%s\n", fingerTexts[i].bodyText);
    }
}

void changeTitle(fingerText *f, char newTitle[]){
    strcpy(f->title, newTitle);
}

void printText(fingerText f){
    printf("\n%s %d\n", f.title, f.year);
    printf("%s\n", f.bodyText);
}
