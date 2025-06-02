#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utility.h"

int convertStringToDateTime(const char *datetimeStr, struct tm *result) {
    return sscanf(datetimeStr, "%d-%d-%d %d:%d:%d",
           &result->tm_year, &result->tm_mon, &result->tm_mday,
           &result->tm_hour, &result->tm_min, &result->tm_sec) == 6;
}

void convertDateTimeToString(const struct tm *t, char *buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%04d-%02d-%02d %02d:%02d:%02d",
             t->tm_year, t->tm_mon, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec);
}

void readLine(char* buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

