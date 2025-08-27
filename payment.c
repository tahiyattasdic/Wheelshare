#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "payment.h"

// Helper function to get integer input safely
int get_safe_int() {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        return atoi(buffer); // Convert string to integer
    }
    return -1; // Return an error value
}

// Helper function to get string input safely
void get_safe_string(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

void payment() {
    srand(time(NULL));
    int max_money = 25, min_money = 3;
    int money_to_be_paid = (rand() % (max_money - min_money + 1)) + min_money;

    printf("Total payment: $%d\n", money_to_be_paid);

    int number_of_people = 0;
    while (number_of_people <= 0 || number_of_people > 6) {
        printf("How many people are travelling? (max 6): ");
        number_of_people = get_safe_int();
    }

    printf("\nThe payment methods are:");
    printf("\n1. Card");
    printf("\n2. PayPal");
    printf("\n3. GooglePay");
    printf("\n4. ApplePay");

    printf("\nChoose your method (enter the number): ");
    int choice = get_safe_int();

    printf("\nProcessing payment...\n");

    switch (choice) {
        case 1: { // Use curly braces for case blocks with variable declarations
            char card_no[17] = "";
            char cvv[4] = "";
            int expiry_month = 0, expiry_day = 0;

            printf("You have chosen to pay with Card.\n");
            while (strlen(card_no) != 16 || strlen(cvv) != 3) {
                printf("Please enter your 16-digit card number: ");
                get_safe_string(card_no, sizeof(card_no));
                printf("Enter 3-digit CVV: ");
                get_safe_string(cvv, sizeof(cvv));
                
                if (strlen(card_no) != 16 || strlen(cvv) != 3) {
                    printf("Invalid card number or CVV length. Please try again.\n");
                }
            }
            printf("Enter Expiry Month: ");
            expiry_month = get_safe_int();
            printf("Enter Expiry Day: ");
            expiry_day = get_safe_int();
            
            printf("Payment successful!\n");
            break;
        }
        case 2:
            printf("You have chosen to pay with PayPal.\n");
            printf("You will be redirected to PayPal to complete your payment.\n");
            printf("Payment successful!\n");
            break;
        case 3:
            printf("You have chosen to pay with GooglePay.\n");
            printf("Redirecting to Google Pay.\n");
            printf("Payment successful!\n");
            break;
        case 4:
            printf("You have chosen to pay with ApplePay.\n");
            printf("Redirecting to Apple Pay.\n");
            printf("Payment successful!\n");
            break;
        default:
            printf("Invalid payment method chosen. Please select from the options provided.\n");
            break;
    }

    printf("\nYour ride for %d people is now booked. Thank you for using WHEELSHARE!\n", number_of_people);
}