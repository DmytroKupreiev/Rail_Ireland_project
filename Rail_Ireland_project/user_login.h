#pragma once

#include "types.h"

typedef struct UserNode {
	User data;
	struct UserNode* next;
}UserNode;


UserNode* loadUsers(const char* path);
void  freeUsers(UserNode* users);
int	  authenticate(UserNode* users, const char* username, const char* password);

UserNode* addUser(UserNode* users, UserNode* newUser);