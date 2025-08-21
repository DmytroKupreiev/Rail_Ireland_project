#include "menu.h"
#include "user_input.h"
#include "user_login.h"
#include "view.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run(User* users) {
    int access = login(users);

    if (!access) {
        printf("Access denied. Exiting...\n");
        return;
    }

    int choice = -1;

    do {
        printHeader();
        printf("Enter your choice (1-9): ");
        int countValue = scanf("%d", &choice);

        if (countValue != 1) {
            printf("Invalid input.\n");
            clearInput();
            continue;
        }

        switch (choice) {
        case 1:  break;
        case 2:  break;
        case 3:  break;
        case 4:  break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
        case 8:  break;
        case 9: system("cls"); break;
        case 0: printf("Saving data and exiting...\n"); break;
        default:printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int login(User* users) {
    char username[MAX_STRING];
    char password[PASSWORD_LEN];
    int attempts = 3; 

    while (attempts > 0) {
        printf("\n=== Login System ===\n");
        printf("Username: ");
        if (fgets(username, MAX_STRING, stdin) == NULL) {
            clearInput();
            continue;
        }
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        readPasswordIntoBuffer(password);

        if (authenticate(users, username, password)) {
            printf("\nWelcome, %s!\n", username);
            return 1;
        }

        printf("\nInvalid credentials. Attempts left: %d\n", --attempts);
    }
    return 0;
}