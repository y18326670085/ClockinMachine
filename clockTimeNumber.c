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

    //char len[20] = {0};

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


    // ��ƽ������ʱ��
    int hoursOfWorkWeek = 0;
    hoursOfWorkWeek = minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)
            + minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)
            + minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)
            + minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)
            + minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
    int avrHoursOfWorkWeek = 0;
    avrHoursOfWorkWeek = hoursOfWorkWeek / 5;

    // �ٵ�����
    int ammountOfLateStart = 0;
    if(MONDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(TUESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(WEDNESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(THURSDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(FRIDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;

    //���˴���
    int ammountOfEarlierQuit = 0;
    if(MONDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(TUESDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(WEDNESDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(THURSDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(FRIDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;

    //ȱ������
    int ammountOfLackOfClock = 0;
    if(MONDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(TUESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(WEDNESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(THURSDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(FRIDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;


    printf("######################################\n");
    printf("average hours of work week : %d\n", avrHoursOfWorkWeek);
    printf("late start in minutes : %d\n", ammountOfLateStart);
    printf("early quick in minutes : %d\n", ammountOfEarlierQuit);
    printf("ammount of lack of clock : %d\n", ammountOfLackOfClock);
    printf("######################################\n");

}

