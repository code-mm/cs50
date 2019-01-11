#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[]) {
    int shiftNumber;

    if(argc != 2 | atoi(argv[1]) < 0) {
        printf("Error! Provide non-negative number.\n");
        return 1;
    } else {
        shiftNumber = atoi(argv[1]);
        shiftNumber = shiftNumber % 26;
    }

    string text = get_string("plaintext: ");

    for(int i = 0; i < strlen(text); i++) {
        if(text[i] >= 65 & text[i] <= 90) { // capitalized letters
            if(text[i] + shiftNumber <= 90) {
                text[i] = (char) ((short) text[i] + shiftNumber);
            } else {
                short overflow = (shiftNumber + (short) text[i]) - 90;
                text[i] = (char) 64 + overflow;
            }
        } else if(text[i] >= 97 & text[i] <= 122) { // lowercase letters
            if(text[i] + shiftNumber <= 122) {
                text[i] = (char) ((short) text[i] + shiftNumber);
            } else {
                short overflow = (shiftNumber + (short) text[i]) - 122;
                text[i] = (char) 96 + overflow;
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
