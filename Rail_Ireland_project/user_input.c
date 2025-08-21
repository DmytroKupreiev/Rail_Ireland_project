#include <stdio.h> 
#include <ctype.h>
#include <conio.h>

#include "user_input.h"
#include "types.h"

void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readPasswordIntoBuffer(char* buffer) {
    int i = 0;
    char ch;

    while (1) {
        // Reads character without echo
        ch = _getch(); 

        if (ch == '\r' || ch == '\n') {
            buffer[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == '\b' && i > 0) {
            i--;
            printf("\b \b");
        }
        else if (i < PASSWORD_LEN - 1) {
            buffer[i++] = ch;
            printf("*");
        }
    }
}