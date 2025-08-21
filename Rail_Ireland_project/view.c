#include "view.h"

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
    repeatChar(stdout, '=', 61);
    printf("\n");
}

void repeatChar(FILE* stream, char ch, int count) {
    for (int i = 0; i < count; i++) {
        fputc(ch, stream);
    }
}