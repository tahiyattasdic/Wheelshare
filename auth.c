#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "auth.h"
#include "new_line.h"

// Helper function to read a line safely and remove the trailing newline
void get_safe_input(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove the newline character that fgets reads
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

int sign_in(FILE *file) {
    int proceed = 0;
    char email[100];
    char password[100];
    char login_or_signup[30];
    char buffer[100]; // Buffer for safe input

    printf("Login or Signup: ");
    get_safe_input(login_or_signup, sizeof(login_or_signup));

    for (int i = 0; login_or_signup[i]; i++) {
        login_or_signup[i] = tolower(login_or_signup[i]);
    }

    if (strcmp(login_or_signup, "signup") == 0) {
        printf("\nEnter your email: ");
        get_safe_input(email, sizeof(email));

        rewind(file);
        char file_email[100];
        char file_password[100];
        bool email_exists = false;

        while (fscanf(file, "%s\n%s\n\n", file_email, file_password) == 2) {
            if (strcmp(email, file_email) == 0) {
                email_exists = true;
                break;
            }
        }
        
        if (email_exists) {
            printf("Error: This email is already registered. Please try logging in.\n");
        } else {
            printf("Enter your password: ");
            get_safe_input(password, sizeof(password));

            // --- SECURITY NOTE ---
            // In a real application, passwords should NEVER be stored in plain text.
            // They should be "hashed" and "salted" for security. This implementation
            // is simplified for this educational project.
            
            new_line(file);
            fprintf(file, "%s\n", email);
            fprintf(file, "%s\n\n", password);

            printf("\nCongratulations for joining WHEELSHARE!\n");
            proceed = 1;
        }
    } 
    else if (strcmp(login_or_signup, "login") == 0) {
        printf("Enter your email: ");
        get_safe_input(email, sizeof(email));
        printf("Enter your password: ");
        get_safe_input(password, sizeof(password));

        rewind(file);
        char file_email[100];
        char file_password[100];

        while (fscanf(file, "%s\n%s\n\n", file_email, file_password) == 2) {
            if (strcmp(email, file_email) == 0 && strcmp(password, file_password) == 0) {
                printf("\nLogin successful! Welcome back to WHEELSHARE!\n");
                proceed = 1;
                break;
            }
        }
        if (proceed != 1) {
            printf("Login failed. Incorrect email or password.\n");
        }
    }
    else {
        printf("Please input either 'login' or 'signup'. \n");
    }

    // Clear the input buffer if there's anything left
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return proceed;
}