#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#define __USE_XOPEN
#define _GNU_SOURCE
#include <time.h>

int main() {
    char date_1[18];
    char date_2[18];
    fgets(date_1, 18 * sizeof(char), stdin);
    struct tm tm_1;
    struct tm tm_2;
    memset(&tm_1, 0, sizeof(tm_1));
    strptime(date_1, "%F %R", &tm_1);
    tm_1.tm_isdst = -1;
    time_t time_1 = mktime(&tm_1);
    while (fgets(date_2, 18 * sizeof(char), stdin)) {
        memset(&tm_2, 0, sizeof(tm_2));
        strptime(date_2, "%F %R", &tm_2);
        tm_2.tm_isdst = -1;
        time_t time_2 = mktime(&tm_2);
        printf("%ld\n", (time_2 - time_1) / 60);
        time_1 = time_2;
    }
    return 0;
}