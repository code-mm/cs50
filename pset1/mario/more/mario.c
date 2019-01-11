#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height = 0;

    while(height <= 0 | height > 23) {
        height = get_int("Pyramid height: ");
    }

    for(int i=1; i<=height; i++) {
        //left pyramid spaces
        for(int j=height-i; j>0; j--) {
            printf(" ");
        }

        //left pyramid hash
        for(int k=i; k>0; k--) {
            printf("#");
        }

        //space between pyramids
        printf("  ");

        //right pyramid hash
        for(int k=i; k>0; k--) {
            printf("#");
        }
        printf("\n");
    }
}