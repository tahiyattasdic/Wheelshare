# Wheelshare: A Command-Line Ride-Sharing App

Wheelshare is a command-line ride-sharing application developed in C. It simulates the core functionalities of a ride-sharing service, including user authentication, ride booking, payment processing, and a review system. [cite_start]This project was created for the CSE 1320 "Intermediate Programming" course at the University of Texas at Arlington[cite: 991, 1000].

![Project Logo](https://i.imgur.com/s4d91u5.png)

## Features

* [cite_start]**User Authentication**: Users can either sign up for a new account or log in with existing credentials[cite: 1049].
* [cite_start]**Persistent Data**: User login information and reviews are saved to and read from external text files (`login_info.txt`, `review.txt`) for data persistence across sessions[cite: 1043, 1050, 1053].
* [cite_start]**Ride Booking**: Users can enter a pickup and destination location to book a ride[cite: 89].
* [cite_start]**Dynamic Ride Details**: The app assigns a random driver and calculates a random arrival time for each ride[cite: 1038].
* [cite_start]**Payment Simulation**: A random fare is generated, and users can choose from multiple simulated payment methods (Card, PayPal, etc.)[cite: 1055, 1057].
* [cite_start]**Rating and Review System**: After a ride, users can provide a 1-5 star rating and leave a text review[cite: 1052].

## Technologies Used

* **Language**: C
* **Compiler**: GCC

## How to Compile and Run

1.  **Clone the repository:**
    ```bash
    git clone <your-repository-url>
    ```
2.  **Navigate to the project directory:**
    ```bash
    cd Wheelshare-Project
    ```
3.  **Compile all source files:**
    ```bash
    gcc main.c auth.c booking.c payment.c review.c new_line.c -o wheelshare
    ```
4.  **Run the executable:**
    ```bash
    ./wheelshare
    ```

## Security Note

**Important**: User passwords are currently stored in plain text in `login_info.txt`. This is a known security vulnerability and was implemented this way for simplicity within the scope of this academic project. For any real-world application, passwords must be securely **hashed and salted**.

## Future Improvements

* [cite_start]**UI Graphics**: Develop a graphical user interface instead of a command-line interface[cite: 1069].
* [cite_start]**Encrypted Credentials**: Implement password hashing and salting for secure storage of user credentials[cite: 1070].
* [cite_start]**Admin Dashboard**: Create a dashboard for administrators to manage users, rides, and reviews[cite: 1071].