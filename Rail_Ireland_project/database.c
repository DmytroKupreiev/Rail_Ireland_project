#include "database.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


DBNode* newNode() {
    DBNode* node = (DBNode*)malloc(sizeof(DBNode));
    if (node != NULL) {
        node->next = NULL;
        node->data.PPS_ID = 0;
        node->data.yearBorn = 0;
        node->data.firstName[0] = '\0';
        node->data.secondName[0] = '\0';
        node->data.email[0] = '\0';
        node->data.cityOfDeparture = -1;
        node->data.travelClass     = -1;
        node->data.travelFrequency = -1;
    }
    return node;
}

DBNode* copyNode(const DBNode* source) {
    if (source == NULL) return NULL;

    DBNode* copy = newNode();
    if (copy != NULL) {
        copy->data = source->data;
        copy->next = NULL;
    }

    return copy;
}

DBNode* add(DBNode* head, DBNode* newNode) {
    if (newNode == NULL) return head;

    if (head == NULL) {
        return newNode;
    }

    DBNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = NULL;
    return head;
}

DBNode* addByKey(DBNode* head, DBNode* newNode) {
    if (newNode == NULL) return head;

    if (head == NULL || newNode->data.PPS_ID < head->data.PPS_ID) {
        newNode->next = head;
        return newNode;
    }

    DBNode* current = head;
    while (current->next != NULL && current->next->data.PPS_ID < newNode->data.PPS_ID) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

DBNode* deleteByKey(DBNode* head, const int key) {
    if (head == NULL) return head;

    DBNode* current = head;
    DBNode* prev = NULL;

    while (current != NULL && current->data.PPS_ID != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return head;


    if (prev == NULL) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }

    free(current);
    return head;
}

DBNode* findByKey(DBNode* head, const int key) {
    if (head == NULL) return NULL;

    DBNode* current = head;
    while (current != NULL) {
        if (current->data.PPS_ID == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

DBNode* getLast(DBNode* head) {
    if (head == NULL) return NULL;

    DBNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

int getLength(DBNode* head) {
    int count = 0;
    DBNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

DBNode* loadDB(const char* filePath) {
    FILE* db_file = fopen(filePath, "r");

    if (db_file == NULL) {
        printf("DB file open error\n");
        return NULL;
    }

    DBNode* head = NULL;

    while (!feof(db_file)) {
        DBNode* newItem = newNode();

        if (fscanf(db_file, "%d %99s %99s %d %99s %d %d %d",
            &newItem->data.PPS_ID,
            newItem->data.firstName,
            newItem->data.secondName,
            &newItem->data.yearBorn,
            newItem->data.email,
            (int*)&newItem->data.cityOfDeparture,
            (int*)&newItem->data.travelClass,
            (int*)&newItem->data.travelFrequency) != 8) {

            free(newItem);
            break;
        }

        head = add(head, newItem);
    }

    fclose(db_file);
    return head;
}

void saveDB(DBNode* head, const char* path) {
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        return;
    }

    DBNode* current = head;
    while (current != NULL) {
        fprintf(file, "%d %s %s %d %s %d %d %d\n",
            current->data.PPS_ID,
            current->data.firstName,
            current->data.secondName,
            current->data.yearBorn,
            current->data.email,
            current->data.cityOfDeparture,
            current->data.travelClass,
            current->data.travelFrequency);

        current = current->next;
    }

    fclose(file);
}

void freeDB(DBNode** head) {
    if (head == NULL || *head == NULL) return;

    DBNode* current = *head;
    DBNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void calculateTravelClassStatistic(DBNode* head, float stats[6][3], int* totalPasWithValidInfo) {
 
    int countPassengersByCity[6] = {0, 0, 0, 0, 0, 0};
    DBNode* current = head;

    while (current != NULL) {

        City city = current->data.cityOfDeparture;
        TravelClass cls = current->data.travelClass;

        if (city >= Dublin && city <= Munster && cls >= Economy && cls <= First) {
            stats[city][cls]++;
            countPassengersByCity[city]++;
        }
        current = current->next;
    }

    int totalCount = 0;
    for (int cityIdx = 1; cityIdx <= Munster; cityIdx++) {
        for (int clsInx = 1; clsInx <= First; clsInx++) {
            stats[cityIdx][clsInx] = (float)stats[cityIdx][clsInx] / countPassengersByCity[cityIdx] * 100;
        }
        totalCount += countPassengersByCity[cityIdx];
    }

    *totalPasWithValidInfo = totalCount;
}