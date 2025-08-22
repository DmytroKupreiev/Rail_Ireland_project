#pragma once

#include "database.h"

void clearInput(void);
void readPasswordIntoBuffer(char* buffer);
void inputPath(char* buffer, int size, const char* prompt);
DBNode* inputPassenger(DBNode** head, DBNode* node);