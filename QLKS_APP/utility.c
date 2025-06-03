#include <stdio.h>
#include <string.h>
#include "utility.h"
int readInt(const char *prompt) {
    char buffer[20];
    int value;
    while (1) {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        printf("Gia tri khong hop le. Vui long nhap lai.\n");
    }
}
void readLine(char *buffer, int size) {
    if (buffer == NULL || size <= 0) return;
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}
