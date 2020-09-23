#include <stdio.h>
#include <time.h>
#include "calculatorAndWriteData.h"

#include "struct.h"

extern int MONDAY_DATA_IN[10];
extern int MONDAY_DATA_OUT[10];
extern int TUESDAY_DATA_IN[10];
extern int TUESDAY_DATA_OUT[10];
extern int WEDNESDAY_DATA_IN[10];
extern int WEDNESDAY_DATA_OUT[10];
extern int THURSDAY_DATA_IN[10];
extern int THURSDAY_DATA_OUT[10];
extern int FRIDAY_DATA_IN[10];
extern int FRIDAY_DATA_OUT[10];

extern int num_emp;


void printClockinTime()
{
    char len[20] = {0};

    time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

    snprintf(len, 20, "%d-%d-%d %d:%d:%d",
             1900 + p->tm_year,
             1 + p->tm_mon,
             p->tm_mday,
             8 + p->tm_hour,
             p->tm_min,
             p->tm_sec);

    printf("\n%s\n", len);
}

/**
 * @description:transfor clock time in an integer array and stored each number in an element
 * @param NULL
 * @return int* an integer array in which number of time als a element stored
 */
int *clockTimeNumber()
{
    static int clockTimeNumber[10] = {0};

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

/**
 * @description:
 * @param {type}
 * @return {type}
 */
void printClockTimeWithFormat(int *clockTime)
{
    printf("%d-%d-%d %d:%d:%d / day in week : %d / extra work hours in minute %d / ammount of late to work in minutes %d / if early quick %d\n",
           *clockTime, // seconds
           *(clockTime+1), // minutes
           *(clockTime+2), // hours
           *(clockTime+3), // day
           *(clockTime+4), // month
           *(clockTime+5), // year
           *(clockTime+6),// day in week
           *(clockTime+7),// extra work hours in minute
           *(clockTime+8),// ammount of late to work in minutes
           *(clockTime+9));// if early quick
}

/**
 * @description:print out week record
 * @param NULL
 * @return void
 */
void printWeekRecord()
{
    printf("\n\n");

    printf("Monday Clock In : ");
    printClockTimeWithFormat(MONDAY_DATA_IN);
    printf("Monday Clock Out : ");
    printClockTimeWithFormat(MONDAY_DATA_OUT);
    printf("\n\n");

    printf("Tuesday Clock In: ");
    printClockTimeWithFormat(TUESDAY_DATA_IN);
    printf("Tuesday Clock Out : ");
    printClockTimeWithFormat(TUESDAY_DATA_OUT);
    printf("\n\n");

    printf("Wednesday Clock In: ");
    printClockTimeWithFormat(WEDNESDAY_DATA_IN);
    printf("Wednesday Clock Out : ");
    printClockTimeWithFormat(WEDNESDAY_DATA_OUT);
    printf("\n\n");

    printf("Thursday Clock In : ");
    printClockTimeWithFormat(THURSDAY_DATA_IN);
    printf("thursday Clock Out : ");
    printClockTimeWithFormat(THURSDAY_DATA_OUT);
    printf("\n\n");

    printf("Friday Clock In : ");
    printClockTimeWithFormat(FRIDAY_DATA_IN);
    printf("Friday Clock Out : ");
    printClockTimeWithFormat(FRIDAY_DATA_OUT);
    printf("\n\n");


    int hoursOfWorkWeek = 0;
    hoursOfWorkWeek = minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)
            + minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)
            + minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)
            + minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)
            + minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
    int avrHoursOfWorkWeek = 0;
    avrHoursOfWorkWeek = hoursOfWorkWeek / 5;


    int ammountOfLateStart = 0;
    if(MONDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(TUESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(WEDNESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(THURSDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(FRIDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;


    int ammountOfEarlierQuit = 0;
    if(MONDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(TUESDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(WEDNESDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(THURSDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(FRIDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;


    int ammountOfLackOfClock = 0;
    if(MONDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(TUESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(WEDNESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(THURSDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(FRIDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;





    matchInfoToEmp(num_emp,
                        avrHoursOfWorkWeek, ammountOfLateStart, ammountOfEarlierQuit, ammountOfLackOfClock,
                        ATDINFOARR, EMPARR);
//    ATDINFO110086.avrHoursOfWorkWeek = avrHoursOfWorkWeek;






    printf("######################################\n");
    printf("average hours of work week : %d\n", avrHoursOfWorkWeek);
    printf("amount of late start : %d\n", ammountOfLateStart);
    printf("amount of early quick : %d\n", ammountOfEarlierQuit);
    printf("ammount of lack of clock : %d\n", ammountOfLackOfClock);
    printf("######################################\n");

}

/**
 * @description:initiate data for test
 * @param NULL
 * @return void
 */
void createDataForTest()
{
    MONDAY_DATA_IN[0] = 21;
    MONDAY_DATA_IN[1] = 30;
    MONDAY_DATA_IN[2] = 6;
    MONDAY_DATA_IN[3] = 24;
    MONDAY_DATA_IN[4] = 8;
    MONDAY_DATA_IN[5] = 2020;
    MONDAY_DATA_IN[6] = 1; // day in week
    MONDAY_DATA_IN[7] = 0; // extra work hours in minuntes
    MONDAY_DATA_IN[8] = 0; // if late to work
    MONDAY_DATA_IN[9] = 0; // if early quick

    MONDAY_DATA_OUT[0] = 11;
    MONDAY_DATA_OUT[1] = 30;
    MONDAY_DATA_OUT[2] = 15;
    MONDAY_DATA_OUT[3] = 24;
    MONDAY_DATA_OUT[4] = 8;
    MONDAY_DATA_OUT[5] = 2020;
    MONDAY_DATA_OUT[6] = 1;
    MONDAY_DATA_OUT[7] = 0;
    MONDAY_DATA_OUT[8] = 0;
    MONDAY_DATA_OUT[9] = 0;

    TUESDAY_DATA_IN[0] = 21;
    TUESDAY_DATA_IN[1] = 20;
    TUESDAY_DATA_IN[2] = 7;
    TUESDAY_DATA_IN[3] = 25;
    TUESDAY_DATA_IN[4] = 8;
    TUESDAY_DATA_IN[5] = 2020;
    TUESDAY_DATA_IN[6] = 2;
    TUESDAY_DATA_IN[7] = 680;
    TUESDAY_DATA_IN[8] = 20;
    TUESDAY_DATA_IN[9] = 0;

    TUESDAY_DATA_OUT[0] = 11;
    TUESDAY_DATA_OUT[1] = 40;
    TUESDAY_DATA_OUT[2] = 18;
    TUESDAY_DATA_OUT[3] = 25;
    TUESDAY_DATA_OUT[4] = 8;
    TUESDAY_DATA_OUT[5] = 2020;
    TUESDAY_DATA_OUT[6] = 2;
    TUESDAY_DATA_OUT[7] = 680;
    TUESDAY_DATA_OUT[8] = 20;
    TUESDAY_DATA_OUT[9] = 0;

//    WEDNESDAY_DATA_IN[0] = 21;
//    WEDNESDAY_DATA_IN[1] = 30;
//    WEDNESDAY_DATA_IN[2] = 7;
//    WEDNESDAY_DATA_IN[3] = 26;
//    WEDNESDAY_DATA_IN[4] = 8;
//    WEDNESDAY_DATA_IN[5] = 2020;
//    WEDNESDAY_DATA_IN[6] = 3;
//    WEDNESDAY_DATA_IN[7] = 0;
//    WEDNESDAY_DATA_IN[8] = 0;
//    WEDNESDAY_DATA_IN[9] = 1;

//    WEDNESDAY_DATA_OUT[0] = 11;
//    WEDNESDAY_DATA_OUT[1] = 30;
//    WEDNESDAY_DATA_OUT[2] = 12;
//    WEDNESDAY_DATA_OUT[3] = 26;
//    WEDNESDAY_DATA_OUT[4] = 8;
//    WEDNESDAY_DATA_OUT[5] = 2020;
//    WEDNESDAY_DATA_OUT[6] = 3;
//    WEDNESDAY_DATA_OUT[7] = 0;
//    WEDNESDAY_DATA_OUT[8] = 0;
//    WEDNESDAY_DATA_OUT[9] = 1;

    THURSDAY_DATA_IN[0] = 11;
    THURSDAY_DATA_IN[1] = 30;
    THURSDAY_DATA_IN[2] = 10;
    THURSDAY_DATA_IN[3] = 27;
    THURSDAY_DATA_IN[4] = 8;
    THURSDAY_DATA_IN[5] = 2020;
    THURSDAY_DATA_IN[6] = 4;
    THURSDAY_DATA_IN[7] = 10;
    THURSDAY_DATA_IN[8] = 0;
    THURSDAY_DATA_IN[8] = 0;

    THURSDAY_DATA_OUT[0] = 21;
    THURSDAY_DATA_OUT[1] = 40;
    THURSDAY_DATA_OUT[2] = 19;
    THURSDAY_DATA_OUT[3] = 27;
    THURSDAY_DATA_OUT[4] = 8;
    THURSDAY_DATA_OUT[5] = 2020;
    THURSDAY_DATA_OUT[6] = 4;
    THURSDAY_DATA_OUT[7] = 10;
    THURSDAY_DATA_OUT[8] = 0;
    THURSDAY_DATA_OUT[8] = 0;

    FRIDAY_DATA_IN[0] = 21;
    FRIDAY_DATA_IN[1] = 0;
    FRIDAY_DATA_IN[2] = 7;
    FRIDAY_DATA_IN[3] = 28;
    FRIDAY_DATA_IN[4] = 8;
    FRIDAY_DATA_IN[5] = 2020;
    FRIDAY_DATA_IN[6] = 5;
    FRIDAY_DATA_IN[7] = 90;
    FRIDAY_DATA_IN[8] = 0;
    FRIDAY_DATA_IN[9] = 0;

    FRIDAY_DATA_OUT[0] = 11;
    FRIDAY_DATA_OUT[1] = 30;
    FRIDAY_DATA_OUT[2] = 17;
    FRIDAY_DATA_OUT[3] = 28;
    FRIDAY_DATA_OUT[4] = 8;
    FRIDAY_DATA_OUT[5] = 2020;
    FRIDAY_DATA_OUT[6] = 5;
    FRIDAY_DATA_OUT[7] = 90;
    FRIDAY_DATA_OUT[8] = 0;
    FRIDAY_DATA_OUT[9] = 0;
}


