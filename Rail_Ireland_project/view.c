#include "view.h"
#include "database.h"
#include "utils.h"

void printAllNodes(DBNode* head, const char* header, FILE* stream)
{
    if (head == NULL) {
        printf("\nTable is empty.\n");
        return;
    }

    DBNode* current = head;

    printTableHeader(stream, header);
    while (current != NULL) {
        printDBNode(stream, current);
        current = current->next;
    }
}

void printMenuNode(DBNode* node) {
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

void printMenuHeader() {
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

void printTableHeader(FILE* output, const char* label) {
    fprintf(output, "\n");
    repeatChar(output, '=', 52);
    fprintf(output, "  %-15s ", label);
    repeatChar(output, '=', 57);
    fprintf(output, "\n");

    fprintf(output, "%-15s %-15s %-15s %-15s %-25s %-12s %-10s %-10s\n",
        "PPS", "First Name", "Second Name", "Year Born", "Email", "City", "Class", "Frequency");

    repeatChar(output, '=', 128);
    fprintf(output, "\n");
}

void printTravelClassStatistic(FILE* output, DBNode* head) {
    int total = getLength(head);

    if (total == 0) {
        fprintf(output, "No machines in database.\n");
        return;
    }

    int totalValidPassengers = 0;
    float statistic[6][3] = {
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f}
    };
    

    calculateTravelClassStatistic(head, statistic, &totalValidPassengers);

    fprintf(output, "\n");
    fprintf(output, "+-----------------------------+-------------+-------------+\n");
    fprintf(output, "| Breakdown Statistics        | Economy     | First       |\n");
    fprintf(output, "+-----------------------------+-------------+-------------+\n");

    for (int cityInx = 1; cityInx <= Munster; cityInx++)
    {
        fprintf(output, "| %-28s| %-9.2f%%  |%-9.2f%%   |\n", getCityString(cityInx), 
                                                                               statistic[cityInx][Economy], 
                                                                               statistic[cityInx][First]);
        fprintf(output, "+-----------------------------+-------------+-------------+\n");
    }

    fprintf(output, "| Total Valid Passengers      | %-23d   |\n", totalValidPassengers);
    fprintf(output, "+-----------------------------+---------------------------+\n");
    fprintf(output, "| Total Passengeres           | %-23d   |\n", total);
    fprintf(output, "+-----------------------------+---------------------------+\n\n");
}

void printDBNode(FILE* output, DBNode* node) {
    fprintf(output, "%-15d %-15s %-15s %-15d %-25s %-12s %-10s %-10s\n",
      node->data.PPS_ID,
      node->data.firstName,
      node->data.secondName,
      node->data.yearBorn,
      node->data.email,
      getCityString(node->data.cityOfDeparture),
      getTravelClassString(node->data.travelClass),
      getTravelFreqString(node->data.travelFrequency));
}

void repeatChar(FILE* stream, char ch, int count) {
    for (int i = 0; i < count; i++) {
        fputc(ch, stream);
    }
}