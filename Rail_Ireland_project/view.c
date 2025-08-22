#include "view.h"
#include "database.h"
#include "utils.h"

void printNode(DBNode* node) {
    printf("\n== Current values ==\n");
    printf("1. ID: %d\n", node->data.PPS_ID);
    printf("2. First name: %s\n", node->data.firstName);
    printf("3. Second name: %s\n", node->data.secondName);
    printf("4. Year born: %d\n", node->data.yearBorn);
    printf("5. Email: %s\n", node->data.email);
    printf("6. City of departure: %s\n", getCityString(node->data.cityOfDeparture));
    printf("7. Travel class: %s\n",      getTravelClassString(node->data.travelClass));
    printf("8. Travel frequency: %s\n",  getTravelFreqString(node->data.travelFrequency));
}

void printHeader() {
    printf("\n===== Rail Ireland Ltd: Passenger travel statistics =====\n");
    printf("1) Add passenger\n");
    printf("2) Display all passengers\n");
    printf("3) Display passenger details\n");
    printf("4) Update a passenger statistic\n");
    printf("5) Delete passenger\n");
    printf("6) Generate statistic\n");
    printf("7) Generate report file\n");
    printf("8) Print sorted passengers by Year Born\n");
    printf("9) Clear terminal\n");
    printf("0) Exit system\n");
    repeatChar(stdout, '=', 57);
    printf("\n");
}

void repeatChar(FILE* stream, char ch, int count) {
    for (int i = 0; i < count; i++) {
        fputc(ch, stream);
    }
}