#include <stdio.h> 
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <limits.h>

#include "user_input.h"
#include "types.h"
#include "view.h"

int isValidEmail(const char* email) {

    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0, dotCount = 0;
    int len = strlen(email);

    // check .com at the end
    if (len < 4 || strcmp(email + len - 4, ".com") != 0) {
        return 0;
    }

    // check @ and a full stop
    for (int i = 0; i < len - 4; i++) {
        if (email[i] == '@') atCount++;
        if (email[i] == '.') dotCount++;
    }

    return (atCount == 1 && dotCount >= 1);
}

int isPPSUnique(DBNode* head, int pps) {
    DBNode* current = head;
    while (current != NULL) {
        if (current->data.PPS_ID == pps) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}


void inputStringWithValidation(const char* prompt, char* dest, int minLen, int maxLen) {
    do {
        printf("%s (%d-%d characters): ", prompt, minLen, maxLen);

        fgets(dest, MAX_STRING, stdin);

        dest[strcspn(dest, "\n")] = '\0';
    } while (strlen(dest) < minLen || strlen(dest) > maxLen);
}

void inputIntWithValidation(const char* prompt, int* dest, int minVal, int maxVal) {
    do {
        printf("%s (%d-%d): ", prompt, minVal, maxVal);
        int count = scanf("%d", dest);
        clearInput();
    } while (*dest < minVal || *dest > maxVal);
}

void inputEmailWithValidation(char* email) {
    do {
        printf("Enter email: ");
        fgets(email, MAX_STRING, stdin);
        email[strcspn(email, "\n")] = '\0';

        printf("%s", email);

        if (!isValidEmail(email)) {
            printf("Invalid email format! Must contain @, a full stop and a .com \n");
            email[0] = '\0';
        }
    } while (!isValidEmail(email));
}


void inputID(DBNode* head, int* pps) {
    do {
        printf("Enter ID (integer): ");
        int count = scanf("%d", pps);
        clearInput();

        if (*pps < 1 && *pps > INT_MAX) {
            printf("Error: ID must be positive!\n");
            continue;
        }

        if (!isPPSUnique(head, *pps)) {
            printf("Error: This ID already exists in database!\n");
            *pps = -1;
        }

    } while (*pps < 1 || !isPPSUnique(head, *pps));
}

void inputPath(char* buffer, int size, const char* prompt) {
    clearInput();

    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
    else {
        buffer[0] = '\0';
    }
}

DBNode* inputPassenger(DBNode** head, DBNode* node)
{
    DBNode* nodeToEdit;
   
    if (node == NULL) {
        nodeToEdit = newNode();
    }
    else {
        nodeToEdit = node;
    }

    Passenger* p = &(nodeToEdit->data);
    int choice;
    int tempInt;

    do {
        printMenuNode(nodeToEdit);
        printf("0. Finish\n");

        printf("Enter field to edit: ");

        int len = scanf("%d", &choice);
        clearInput();

        switch (choice) {
        
        case 1: inputID(*head, &p->PPS_ID); break;
        case 2: inputStringWithValidation("Enter First Name", p->firstName, 2, MAX_STRING - 1); break;
        case 3: inputStringWithValidation("Enter Second Name", p->secondName, 2, MAX_STRING - 1); break;
        case 4: inputIntWithValidation("Enter Year Born", &p->yearBorn, 1900, 2025); break;
        case 5: inputEmailWithValidation(p->email); break;
        case 6:
            inputIntWithValidation("Enter City of Departure (1-DUBLIN, 2-LEINSER, 3-CONNACHT, 4-ULSTER, 5-MUNSTER)", &tempInt, 1, 5);
            p->cityOfDeparture = (City)tempInt;
            break;
        case 7:
            inputIntWithValidation("Enter Travel Class (1-ECONOMY, 2-FIRST)", &tempInt, 1, 2);
            p->travelClass = (TravelClass)tempInt;
            break;
        case 8:
            inputIntWithValidation("Enter Travel Frequency (1-LESS THAN THREE, 2-LESS THAN FIVE, 3-MORE THAN FIVE)", &tempInt, 1, 3);
            p->travelFrequency = (TravelFreq)tempInt;
            break;
        case 0:

            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return nodeToEdit;
}


void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readPasswordIntoBuffer(char* buffer) {
    int i = 0;
    char ch;

    while (1) {
        // Reads character without echo
        ch = _getch(); 

        if (ch == '\r' || ch == '\n') {
            buffer[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == '\b' && i > 0) {
            i--;
            printf("\b \b");
        }
        else if (i < PASSWORD_LEN - 1) {
            buffer[i++] = ch;
            printf("*");
        }
    }
}

