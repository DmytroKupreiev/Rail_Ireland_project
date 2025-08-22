#include "app.h"
#include "user_input.h"
#include "user_login.h"
#include "view.h"
#include "database.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addPassenger(DBNode** db);
void displayAll(DBNode* db);
void displayDetails(DBNode* db);
void updatePassengerStatistic(DBNode** db);
void deletePassenger(DBNode** db);
void generateStatistic(DBNode* db);
void generateReportFile(DBNode* db);
void printSortedDB(DBNode* db);

void run(User* users, DBNode* database) {
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
        case 1: addPassenger(&database);             break;
        case 2: displayAll(database);                break;
        case 3: displayDetails(database);            break;
        case 4: updatePassengerStatistic(&database); break;
        case 5: deletePassenger(&database);          break;
        case 6: generateStatistic(database);         break;
        case 7: generateReportFile(database);        break;
        case 8: printSortedDB(database);             break;
        case 9: system("cls");                       break;
        case 0: printf("Saving data and exiting...\n"); break;
        default:printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    saveDB(database, DB_PATH);
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


void addPassenger(DBNode** db) 
{
    DBNode* newNode = inputPassenger(db, NULL);

    if (newNode != NULL) {
        *db = addByKey(*db, newNode);
    }
}

void displayAll(DBNode* db) 
{

}

void displayDetails(DBNode* db)
{

}

void updatePassengerStatistic(DBNode** db) 
{
    int pps;

    clearInput();
    do {
        printf("\n=== Update Passenger Details ===\n");
        printf("Enter ID (\"-1\" for exit): ");
        int count = scanf("%d", &pps);
        clearInput();

        if (pps == -1) { return; }

        DBNode* node = findByKey(*db, pps);

        if (node == NULL) {
            printf("Key not found!\n");
            continue;
        }

        inputPassenger(db, node);
    } while (1);
}

void deletePassenger(DBNode** db) 
{

}

void generateStatistic(DBNode* db) 
{

}

void generateReportFile(DBNode* db)
{

}

void printSortedDB(DBNode* db) 
{

}