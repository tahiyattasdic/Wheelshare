#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "booking.h"
#include "payment.h" // booking needs to call the payment function

// Helper function to read a line safely and remove the trailing newline
void get_safe_input_booking(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

void book_ride(void) {
    char pickup[100];
    char destination[100];

    const char *driver_names[] = {
        "James", "Abdul", "Hernandez", "Shuvojeet", "Mary",
        "Pearl", "Kim", "John", "Lopez", "Jacob"
    };
    int num_drivers = sizeof(driver_names) / sizeof(driver_names[0]);

    srand(time(NULL));
    int arriving_time = (rand() % 15) + 1; // Random time between 1 and 15
    const char *random_driver = driver_names[rand() % num_drivers];

    printf("\n-------------------------\n");
    printf("      Book a Ride\n");
    printf("-------------------------\n");

    printf("Enter pickup location: ");
    get_safe_input_booking(pickup, sizeof(pickup));
    printf("Enter destination: ");
    get_safe_input_booking(destination, sizeof(destination));

    printf("\nRide details:\n");
    printf("Pickup: %s\n", pickup);
    printf("Destination: %s\n", destination);
    printf("\n");

    payment(); // Call the payment function

    printf("\nBooking confirmed. A WHEELSHARE will be arriving in %d minutes!\n", arriving_time);
    printf("Your driver: %s\n", random_driver);
    printf("-------------------------\n");
}