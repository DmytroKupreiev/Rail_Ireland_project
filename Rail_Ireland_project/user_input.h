#pragma once

#include "database.h"

void clearInput(void);
void readPasswordIntoBuffer(char* buffer);
DBNode* inputPassenger(DBNode** head, DBNode* node);