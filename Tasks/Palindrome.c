#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define maxLength 30

bool isPalindrome(char word[]);
void convertToLowerCase(char word[]);

int main(void){
    char word[maxLength];
    printf("Skriv in ett ord: ");
    scanf("%s", word);
    convertToLowerCase(word);

    if(isPalindrome(word)){
        printf("Ordet %s är ett palindrom\n", word);
    }else{
        printf("Ordet %s är inte ett palindrom\n", word);
    }
}

void convertToLowerCase(char word[]){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
}

bool isPalindrome(char word[]){
    int length = strlen(word);
    char tmp[length];

    for(int i = 0; word[i] != '\0'; i++){
        tmp[i] = word[(length - 1) - i];
    }
    tmp[length] = '\0';

    if(strcmp(word, tmp) == 0){
        return true;
    }else{
        return false;
    }
}

