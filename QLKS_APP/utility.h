#ifndef UTILITY_H
#define UTILITY_H

#include <time.h>
#include <stdio.h>
#include <string.h>

int convertStringToDateTime(const char *datetimeStr, struct tm *result);
void convertDateTimeToString(const struct tm *t, char *buffer, int bufferSize);



void readLine(char* buffer, int size);

#endif

