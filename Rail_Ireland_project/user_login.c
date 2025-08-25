#include <stdio.h>
#include <stdlib.h>
#include "user_login.h"

UserNode* newUser();

UserNode* loadUsers(const char* path) {

    UserNode* users = NULL;

    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Failed to open login file");
        return NULL;
    }

    for (int i = 0; i < MAX_USERS; i++) {

        UserNode* newU = newUser();

        if (fscanf(file, "%99s %6s", newU->data.username, newU->data.password) != 2) {
            printf("User must contain login and password\n");
            free(newU);
            continue;
        }

        users = addUser(users, newU);
    }

    fclose(file);
    return users;
}

int authenticate(UserNode* users, const char* username, const char* password) {
    UserNode* current = users;

    while(current != NULL) {
        if (strcmp(username, current->data.username) == 0 &&
            strcmp(password, current->data.password) == 0) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void freeUsers(UserNode* users) {
    if (users == NULL) {
        return;
    }

    UserNode* next;
    UserNode* current = users;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    users = NULL;
}

UserNode* newUser() {
    UserNode* user = malloc(sizeof(UserNode));

    if (user != NULL) {
        user->next = NULL;
        user->data.password[0] = '\0';
        user->data.username[0] = '\0';
    }

    return user;
}

UserNode* addUser(UserNode* users, UserNode* newUser) {
    if (newUser == NULL) { return users; }
    if (users == NULL) { return newUser; }

    UserNode* current = users;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newUser;
    newUser->next = NULL;

    return users;
}