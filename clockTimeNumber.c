#include <stdio.h>
#include <time.h>


void printClockinTime()
{
    char len[20] = {0};

    time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

    snprintf(len, 20, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);

    printf("\n%s\n", len);
}

int *clockTimeNumber()
{
    static int clockTimeNumber[10] = {0};

    char len[20] = {0};

    time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

    //sprintf(len, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);

    *clockTimeNumber = p->tm_sec;
    *(clockTimeNumber+1) = p->tm_min;
    *(clockTimeNumber+2) = 8 + p->tm_hour;
    *(clockTimeNumber+3) = p->tm_mday;
    *(clockTimeNumber+4) = 1 + p->tm_mon;
    *(clockTimeNumber+5) = 1900 + p->tm_year;

    *(clockTimeNumber+6) = p->tm_wday;

    return clockTimeNumber;
}
