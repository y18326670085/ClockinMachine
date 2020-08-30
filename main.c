/*
 * @Author: your name
 * @Date: 2020-08-23 11:08:33
 * @LastEditTime: 2020-08-30 11:30:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ClockinMachine\main.c
 */
#include <stdio.h>
#include <math.h>
//#include <time.h>
#include <conio.h>


//#include "test.h"
#include "clockTimeNumber.h"
#include "monday.h"
#include "tuesday.h"
#include "wednesday.h"
#include "thursday.h"
#include "friday.h"

void clockin_machine_start();
int checkIdentifyCode(int num_emp, int code);
void printClockinTime();
void writeDataInWeekday();
void printClockTimeWithFormat(int *clockTime);
void printWeekRecord();
int minutesOfWork(int clockIn[10], int clockOut[10]);
void createDataForTest();
void testScanf();

int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

int MONDAY_DATA_IN[10];
int MONDAY_DATA_OUT[10];
int TUESDAY_DATA_IN[10];
int TUESDAY_DATA_OUT[10];
int WEDNESDAY_DATA_IN[10];
int WEDNESDAY_DATA_OUT[10];
int THURSDAY_DATA_IN[10];
int THURSDAY_DATA_OUT[10];
int FRIDAY_DATA_IN[10];
int FRIDAY_DATA_OUT[10];

int main()
{

    int *startTime = clockTimeNumber();

    // get system time of start
    printf("%d-%d-%d %d:%d:%d Weekday : %d\n\n",
           *startTime,
           *(startTime+1),
           *(startTime+2),
           *(startTime+3),
           *(startTime+4),
           *(startTime+5),
           *(startTime+6));

    //createDataForTest();

    //hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT);
    //printf("ammount of work hours in min : %d", hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT));

    // get current system time
    currentTime = clockTimeNumber();

    clockin_machine_start();

    return 0;
}

void createDataForTest()
{
//    MONDAY_DATA_IN[0] = 21;
//    MONDAY_DATA_IN[1] = 30;
//    MONDAY_DATA_IN[2] = 6;
//    MONDAY_DATA_IN[3] = 24;
//    MONDAY_DATA_IN[4] = 8;
//    MONDAY_DATA_IN[5] = 2020;
//    MONDAY_DATA_IN[6] = 1; // day in week
//    MONDAY_DATA_IN[7] = 0; // extra work hours in minuntes
//    MONDAY_DATA_IN[8] = 0; // if late to work
//    MONDAY_DATA_IN[9] = 0; // if early quick

//    MONDAY_DATA_OUT[0] = 11;
//    MONDAY_DATA_OUT[1] = 30;
//    MONDAY_DATA_OUT[2] = 15;
//    MONDAY_DATA_OUT[3] = 24;
//    MONDAY_DATA_OUT[4] = 8;
//    MONDAY_DATA_OUT[5] = 2020;
//    MONDAY_DATA_OUT[6] = 1;
//    MONDAY_DATA_OUT[7] = 0;
//    MONDAY_DATA_OUT[8] = 0;
//    MONDAY_DATA_OUT[9] = 0;

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

    WEDNESDAY_DATA_IN[0] = 21;
    WEDNESDAY_DATA_IN[1] = 30;
    WEDNESDAY_DATA_IN[2] = 7;
    WEDNESDAY_DATA_IN[3] = 26;
    WEDNESDAY_DATA_IN[4] = 8;
    WEDNESDAY_DATA_IN[5] = 2020;
    WEDNESDAY_DATA_IN[6] = 3;
    WEDNESDAY_DATA_IN[7] = 0;
    WEDNESDAY_DATA_IN[8] = 0;
    WEDNESDAY_DATA_IN[9] = 1;

    WEDNESDAY_DATA_OUT[0] = 11;
    WEDNESDAY_DATA_OUT[1] = 30;
    WEDNESDAY_DATA_OUT[2] = 12;
    WEDNESDAY_DATA_OUT[3] = 26;
    WEDNESDAY_DATA_OUT[4] = 8;
    WEDNESDAY_DATA_OUT[5] = 2020;
    WEDNESDAY_DATA_OUT[6] = 3;
    WEDNESDAY_DATA_OUT[7] = 0;
    WEDNESDAY_DATA_OUT[8] = 0;
    WEDNESDAY_DATA_OUT[9] = 1;

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

//    FRIDAY_DATA_IN[0] = 21;
//    FRIDAY_DATA_IN[1] = 0;
//    FRIDAY_DATA_IN[2] = 7;
//    FRIDAY_DATA_IN[3] = 28;
//    FRIDAY_DATA_IN[4] = 8;
//    FRIDAY_DATA_IN[5] = 2020;
//    FRIDAY_DATA_IN[6] = 5;
//    FRIDAY_DATA_IN[7] = 90;
//    FRIDAY_DATA_IN[8] = 0;
//    FRIDAY_DATA_IN[9] = 0;

//    FRIDAY_DATA_OUT[0] = 11;
//    FRIDAY_DATA_OUT[1] = 30;
//    FRIDAY_DATA_OUT[2] = 17;
//    FRIDAY_DATA_OUT[3] = 28;
//    FRIDAY_DATA_OUT[4] = 8;
//    FRIDAY_DATA_OUT[5] = 2020;
//    FRIDAY_DATA_OUT[6] = 5;
//    FRIDAY_DATA_OUT[7] = 90;
//    FRIDAY_DATA_OUT[8] = 0;
//    FRIDAY_DATA_OUT[9] = 0;
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


// minutes of work long
int minutesOfWork(int clockIn[10], int clockOut[10])
{
    float hoursOfWork;

    //ClockIn of hours
    int hoursClockIn = *(clockIn+2);
    //ClockIn of minutes
    int minClockIn = *(clockIn+1);

    //ClockOut in hours
    int hoursClockOut = *(clockOut+2);
    //ClockOut in minutes
    int minClockOut = *(clockOut+1);

    if(minClockOut < minClockIn)
    {
        hoursOfWork = minClockOut + 60 - minClockIn;
        hoursOfWork += (hoursClockOut - 1 - hoursClockIn)*60;
    }
    else{
        hoursOfWork = minClockOut - minClockIn;
        hoursOfWork += (hoursClockOut - hoursClockIn)*60;
    }
    return hoursOfWork;
}


void writeDataInWeekday()
{

    //###### Monday #####################################################################################################

    while(*(currentTime+6) == 0 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In? \n");
            getch();
            thursdayClockInTime(currentTime, MONDAY_DATA_IN);
            printClockTimeWithFormat(MONDAY_DATA_IN);

            // if late to work based on 7 o'clock
            if(MONDAY_DATA_IN[2]*60 + MONDAY_DATA_IN[1] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                // amount of late to work in minutes
                MONDAY_DATA_IN[8] = MONDAY_DATA_IN[2]*60 + MONDAY_DATA_IN[1] - 7*60;
                printf("amount of late to work in ( %d ) minutes\n\n",  MONDAY_DATA_IN[8]);
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out? \n");
            getch();
            wednesdayClockOutTime(currentTime, MONDAY_DATA_OUT);
            while(minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)<9*60)
            {
                printf("work hours %f\n", (float)(minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)/60));
                int leaveEarly = 9*60 - minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT);
                printf("leave early ( %d ) minutes\n\n", leaveEarly);

                //ask to clock out again if work hours less than 9
                printf("clock out again? (1/0)\n");

//                char againClockOut;
//                scanf("%c",&againClockOut);
//                printf("againClockOut : %c\n", againClockOut);

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    tuesdayClockOutTime(currentTime, MONDAY_DATA_OUT);
                    printClockTimeWithFormat(MONDAY_DATA_OUT);
                }
                else{
                    // write 1 exprssing early quick in both data container
                    MONDAY_DATA_OUT[9] = 1;
                    MONDAY_DATA_IN[9] = 1;

                    // if late to work
                    // write amount of late to work in out container
                    MONDAY_DATA_OUT[8] = MONDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            //extra work
            MONDAY_DATA_OUT[7] = minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT) - 9*60 : 0 ;
            MONDAY_DATA_IN[7] = minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT) - 9*60 : 0 ;
        }
        currentTime = clockTimeNumber();
    }

    printf("\n\nData of today\n\n");
    printClockTimeWithFormat(MONDAY_DATA_IN);
    printClockTimeWithFormat(MONDAY_DATA_OUT);

    clockIn = 0;
    clockOut = 0;


    //###### �ܶ� #####################################################################################################

    while(*(currentTime+6) == 2 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In? \n");
            getch();
            thursdayClockInTime(currentTime, TUESDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);

            // get ammount of late to work
            if(TUESDAY_DATA_IN[2]*60 + TUESDAY_DATA_IN[1] - MONDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                TUESDAY_DATA_IN[8] = TUESDAY_DATA_IN[2]*60 + TUESDAY_DATA_IN[1] - TUESDAY_DATA_OUT[7] - 7*60;
                printf("ammount of late to work %d minutes\n\n",  TUESDAY_DATA_IN[8]);
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out?\n");
            getch();
            wednesdayClockOutTime(currentTime, TUESDAY_DATA_OUT);
            while(minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)<9*60)
            {
                printf("ammount of work of day %d minutes\n", minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT);
                printf("ammount of leaving ealy %d minutes\n\n", leaveEarly);


                printf("Clock Out again?(1/0)\n");

//                char againClockOut;
//                scanf("%c",&againClockOut);
//                printf("againClockOut : %c\n", againClockOut);

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    tuesdayClockOutTime(currentTime, TUESDAY_DATA_OUT);
                    printClockTimeWithFormat(TUESDAY_DATA_OUT);
                }
                else{
                    // if leave early
                    TUESDAY_DATA_OUT[9] = 1;
                    TUESDAY_DATA_IN[9] = 1;

                    // amount of late to work
                    TUESDAY_DATA_OUT[8] = TUESDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            // attain extra work time
            TUESDAY_DATA_OUT[7] = minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT) - 9*60 : 0 ;
            TUESDAY_DATA_IN[7] = minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT) - 9*60 : 0 ;
        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(TUESDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;

    //###### ���� #####################################################################################################

    while(*(currentTime+6) == 3 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In?\n");
            getch();
            thursdayClockInTime(currentTime, WEDNESDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);

            // get ammount of late to work
            if(WEDNESDAY_DATA_IN[2]*60 + WEDNESDAY_DATA_IN[1] - TUESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                WEDNESDAY_DATA_IN[8] = WEDNESDAY_DATA_IN[2]*60 + WEDNESDAY_DATA_IN[1] - TUESDAY_DATA_OUT[7] - 7*60;
                printf("ammount of late to work %d minutes\n\n",  WEDNESDAY_DATA_IN[8]);
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out\n");
            getch();
            wednesdayClockOutTime(currentTime, WEDNESDAY_DATA_OUT);
            while(minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)<9*60)
            {
                printf("ammount of work of day %d minutes\n", minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT);
                printf("ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf("Clock Out again?(1/0)\n");

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    tuesdayClockOutTime(currentTime, WEDNESDAY_DATA_OUT);
                    printClockTimeWithFormat(WEDNESDAY_DATA_OUT);
                }
                else{
                    // if leave early
                    WEDNESDAY_DATA_OUT[9] = 1;
                    WEDNESDAY_DATA_IN[9] = 1;

                    // amount of late to work
                    WEDNESDAY_DATA_OUT[8] = WEDNESDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            // attain extra work time
            WEDNESDAY_DATA_OUT[7] = minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT) - 9*60 : 0 ;
            WEDNESDAY_DATA_IN[7] = minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT) - 9*60 : 0 ;
        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(WEDNESDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;
    //###### ���� #####################################################################################################

    while(*(currentTime+6) == 4 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In?\n");
            getch();
            thursdayClockInTime(currentTime, THURSDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);

            // get ammount of late to work
            if(THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                THURSDAY_DATA_IN[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                printf("ammount of late to work %d minutes\n\n",  THURSDAY_DATA_IN[8]);
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out? \n");
            getch();
            wednesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);
            while(minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)<9*60)
            {
                printf("ammount of work of day %d minutes\n", minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT);
                printf("ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf("Clock Ont again? (1/0)\n");

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    tuesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);
                    printClockTimeWithFormat(THURSDAY_DATA_OUT);
                }
                else{
                    // if leave early
                    THURSDAY_DATA_OUT[9] = 1;
                    THURSDAY_DATA_IN[9] = 1;

                    // amount of late to work
                    THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            // attain extra work time
            THURSDAY_DATA_OUT[7] = minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 : 0 ;
            THURSDAY_DATA_IN[7] = minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 : 0 ;
        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(THURSDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;

   //###### ���� ######################################################################################################

    while(*(currentTime+6) == 5 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In? \n");
            getch();
            fridayClockInTime(currentTime, FRIDAY_DATA_IN);
            printClockTimeWithFormat(FRIDAY_DATA_IN);

            // get ammount of late to work
            if(FRIDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - FRIDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                FRIDAY_DATA_IN[8] = FRIDAY_DATA_IN[2]*60 + FRIDAY_DATA_IN[1] - THURSDAY_DATA_OUT[7] - 7*60;
                printf("ammount of late to work %d minutes\n\n",  FRIDAY_DATA_IN[8]);
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out :\n");
            getch();
            fridayClockOutTime(currentTime, FRIDAY_DATA_OUT);
            while(minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT)<9*60)
            {
                printf("ammount of work of day %d minutes\n", minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
                printf("ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf(" want to clock out later? (1/0)\n");


                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    fridayClockOutTime(currentTime, FRIDAY_DATA_OUT);
                    printClockTimeWithFormat(FRIDAY_DATA_OUT);
                }
                else{
                    // if leave early
                    FRIDAY_DATA_OUT[9] = 1;
                    FRIDAY_DATA_IN[9] = 1;

                    // amount of late to work
                    FRIDAY_DATA_OUT[8] = FRIDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            // attain extra work time
            FRIDAY_DATA_OUT[7] = minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT) - 9*60 : 0 ;
            FRIDAY_DATA_IN[7] = minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT) - 9*60 > 0 ? minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT) - 9*60 : 0 ;
        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(FRIDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;

    if(currentTime[6] >= 5)
    {
        printWeekRecord();
    }
}


void getEmpInfo()
{

    printf("number of emplyee 110086\n");
    printf("identifycode 178087\n\n");

    printf("give number of employee : ");
    scanf("%d", &num_emp);
    printf("the number of emplyee %d\n", num_emp);

    printf("\n give the identifycode");
    scanf("%d", &identifyCode);
    printf("the number of identifycode %d\n\n", identifyCode);
}


void clockin_machine_start()
{
    getEmpInfo();

    int ammountOfInput = 0;

    CHECKIDENTIFYCODE:

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("identifycode is correct\n\n");
        writeDataInWeekday();
    }
    else if(ammountOfInput < 2){
       printf("identify code is wrong, input again\n");
       scanf("%d", &identifyCode);
       ammountOfInput++;
       goto CHECKIDENTIFYCODE;
    }
    else
    {
        printf("identify code wrong and end the program\n");
    }
}

int checkIdentifyCode(int num_emp, int code)
{
    // Ա����� 110086
    // У���� := Ա����ų���λ��������Ա��������
    // 110086 + 68001 = 178087
    int identifyCode = num_emp;
    int idtArr[6];
    int position = 0;

    while(position < 6)
    {
        idtArr[position] = identifyCode % 10;
        position++;
        identifyCode = identifyCode / 10;
    }

    identifyCode = 0;

    // �����������λ [6,8,0,0,1,1]
    for(int i=0; i<5; i++)
    {
        identifyCode += idtArr[i]*pow(10,5-i-1);
    }

    identifyCode += num_emp;

    if(code == identifyCode)
        return 1;
    else
        return 0;
}


void testScanf()
{
    int a;
    printf("input the data : ");
    scanf("%d",&a);//�������һ���س���
    printf("%d\n",a);
}
