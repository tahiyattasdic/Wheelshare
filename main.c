#include <stdio.h>
#include <stdlib.h>

// Include our custom header files
#include "auth.h"
#include "booking.h"
#include "review.h"

int main() {
    FILE *login_info = fopen("login_info.txt", "r+");

    // --- Error Checking ---
    // Check if the file was opened successfully.
    if (login_info == NULL) {
        perror("Error: Could not open login_info.txt");
        return 1; // Exit with an error code
    }

    printf("\n");
    printf("==================================================\n");
    printf("               WHEELSHARE: Ride the Future!\n");
    printf("==================================================\n");
    printf("\n");

    int proceed_or_terminate = 0;

    // Loop until the user successfully signs in or signs up
    while (proceed_or_terminate != 1) {
        proceed_or_terminate = sign_in(login_info);
    }

    book_ride();
    printf("\n");

    review();

    fclose(login_info); // Close the login_info file

    return 0;
}