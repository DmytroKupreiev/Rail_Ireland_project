#pragma once 

#include "types.h"

typedef struct DBNode {
	Passenger data;
	struct DBNode* next;
} DBNode;

DBNode* newNode();
DBNode* copyNode(const DBNode* source);
DBNode* add(DBNode* head, DBNode* newNode);
DBNode* addByKey(DBNode* head, DBNode* newNode);
DBNode* deleteByKey(DBNode* head, const int key);
DBNode* findByKey(DBNode* head, const int key);

DBNode* getLast(DBNode* head);
int		getLength(DBNode* head);

DBNode* loadDB(const char* filePath);
void	saveDB(DBNode* head, const char* path);
void    freeDB(DBNode** head);