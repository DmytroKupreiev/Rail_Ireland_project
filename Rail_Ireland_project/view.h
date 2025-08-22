#pragma once

#include "database.h"
#include <stdio.h>

void printTableHeader(FILE* output, const char* label);
void printDBNode(FILE* output, DBNode* node);
void printMenuNode(DBNode* node);
void printMenuHeader();
void repeatChar(FILE* stream, char ch, int count);
void printTravelClassStatistic(FILE* output, DBNode* head);
void printAllNodes(DBNode* db, const char* header, FILE* stream);