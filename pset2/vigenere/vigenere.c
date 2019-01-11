#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[]) {
    string keyword;
   
    if(argc != 2) {
        printf("Error! Provide alphabetical keyword.\n");
        return 1;
    }

    for(int i = 0; i < strlen(argv[1]); i++) {
        if(!isalpha(argv[1][i])) {
            printf("Error! Provide alphabetical keyword.\n");
            return 1;
        }
    }

    string text = get_string("plaintext: ");

    keyword = argv[1];
    short keywordCounter = 0;

    // go through the text and replace characters according to keyword
    for(int i = 0; i < strlen(text); i++) {
        short shiftNumber;
        // calculate shift depending on keyword letter
        if(keyword[keywordCounter] >= 65 & keyword[keywordCounter] <= 90) {
            shiftNumber = (short) keyword[keywordCounter] - 65;
        } else if(keyword[keywordCounter] >= 97 & keyword[keywordCounter] <= 122) {
            shiftNumber = (short) keyword[keywordCounter] - 97;
        }

        if(text[i] >= 65 & text[i] <= 90) { // capitalized letters
            // check if shift would overflow the alphabet
            if(text[i] + shiftNumber > 90) {
                short overflow = ((short) text[i] + shiftNumber) - 90;
                text[i] = 64 + overflow;
            } else {
                text[i] = text[i] + shiftNumber;
            }
        } else if(text[i] >= 97 & text[i] <= 122) { // lowercase letters
            // check if shift would overflow the alphabet
            if(text[i] + shiftNumber > 122) {
                short overflow = ((short) text[i] + shiftNumber) - 122;
                text[i] = 96 + overflow;
            } else {
                text[i] = text[i] + shiftNumber;
            }
        }

        // increment or reset the keyword counter if current character is letter
        if(isalpha(text[i])) { 
            if(keywordCounter == strlen(keyword) - 1) {
                keywordCounter = 0;
            } else {
                keywordCounter++;
            }
        }
    }

    printf("ciphertext: %s\n", text); 

    return 0;
}
