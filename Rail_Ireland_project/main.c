#include <stdio.h>

#include "types.h"
#include "menu.h"
#include "user_login.h"

void main() {
	User* users = loadUsers(USER_PATH);

	run(users);

	freeUsers(users);
}