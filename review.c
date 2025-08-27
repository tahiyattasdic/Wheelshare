#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "review.h"
#include "new_line.h"

void review() {
    FILE *reviews = fopen("review.txt", "a+");
    if (reviews == NULL) {
        perror("Error: Could not open review.txt");
        return;
    }

    char review_text[1000];
    char buffer[100];
    int rating = 0;

    while (rating < 1 || rating > 5) {
        printf("Please rate your experience from 1-5: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            rating = atoi(buffer);
        }
        if (rating < 1 || rating > 5) {
            printf("Invalid rating. Please enter a number between 1 and 5.\n");
        }
    }

    printf("Please leave a review: ");
    if (fgets(review_text, sizeof(review_text), stdin) != NULL) {
        review_text[strcspn(review_text, "\n")] = 0; // Remove newline
    }

    new_line(reviews);
    fprintf(reviews, "%d\n", rating);
    fprintf(reviews, "%s\n\n", review_text);

    fclose(reviews);
}