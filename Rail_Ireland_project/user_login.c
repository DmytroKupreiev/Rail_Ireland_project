#include <stdio.h>
#include <stdlib.h>
#include "user_login.h"

User* loadUsers(const char* path) {

    User* users = (User*)malloc(MAX_USERS * sizeof(User));
    if (!users) {
        printf("Memory allocation failed");
        return NULL;
    }

    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Failed to open login file");
        free(users);
        return NULL;
    }

    for (int i = 0; i < MAX_USERS; i++) {
        if (fscanf(file, "%99s %6s", users[i].username, users[i].password) != 2) {
            printf("User must contain login and password\n");

            free(users);
            fclose(file);          
            return NULL;
        }
    }

    fclose(file);
    return users;
}

void freeUsers(User* users) {
    if (users != NULL) {
        free(users);
    }
}

int authenticate(User* users, const char* username, const char* password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }

    return 0;
}