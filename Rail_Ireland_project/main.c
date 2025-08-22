#include <stdio.h>

#include "database.h"
#include "app.h"
#include "user_login.h"

void main() {
	User* users		 = loadUsers(USER_PATH);
	DBNode* database = loadDB(DB_PATH);

	run(users, database);

	freeUsers(users);
	freeDB(&database);
}