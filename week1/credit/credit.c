#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* This program accepts only Mastercard numbers starting with 51-55. */

int main(void) {
    long long card_number = 0;

    /+ input card number */
    while(card_number <=0 | card_number > pow(10,16)) {
        card_number = get_long_long("Number: ");
    }

    /* calculate the checksum of the card number */
    long long temp_card_number = card_number;
    long long total_checksum = 0;
    while(temp_card_number) {
        total_checksum += temp_card_number % 10;
        temp_card_number /= 10;

        /* execute only if there is a value greater 10 */
        if(temp_card_number) {
            int checksum = (temp_card_number % 10) * 2;

            /* check if calculated checksum is greater than 9, if so subtract 9 */
            if(checksum > 9) {
                total_checksum += checksum - 9;
            } else {
                total_checksum += checksum;
            }
            temp_card_number /= 10;
        }
    }

    /* exit if checksum invalid */
    if(total_checksum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }

    /* count digits of the card number */
    long long card_number_temp = card_number;
    int card_number_length = 0;
    while(card_number_temp > 0) {
        card_number_temp /= 10;
        card_number_length++;
    }

    /* shorten the card number to last two digits */
    temp_card_number = card_number;
    for(int i = 0; i < card_number_length - 2; i++) {
        temp_card_number /= 10;
    }

    /* check for credit card company */
    if((card_number_length == 15) & (temp_card_number == 34 | temp_card_number == 37)) {  // AMEX
        printf("AMEX\n");
    } else if(card_number_length == 16 & temp_card_number >= 51 & temp_card_number <= 55) {  // MasterCard
        printf("MASTERCARD\n");
    } else if((card_number_length == 13 | card_number_length == 16) & (temp_card_number / 10 == 4)) {  // Visa
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}