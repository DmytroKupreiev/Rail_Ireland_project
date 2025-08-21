#pragma once

#include "types.h"

User*	loadUsers(const char* path);
void	freeUsers(User* users);

int		authenticate(User* users, const char* username, const char* password);
void	getHiddenPassword(char* buffer);
