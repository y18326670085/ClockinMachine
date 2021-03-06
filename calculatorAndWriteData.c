#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "clockAndRecord.h"
#include "monday.h"
#include "tuesday.h"
#include "wednesday.h"
#include "thursday.h"
#include "friday.h"
#include "calculatorAndWriteData.h"

extern int num_emp;
extern int identifyCode;
extern int *currentTime;
extern int clockIn;
extern int clockOut;
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

/**
 * @description:information about number of employee and identify code
 *              input should be the same as the given number
 * @param void
 * @return void
 */
void getEmpInfo()
{
    printf("Number of emplyee 110086\n");
    printf("Identifycode 178087\n\n");

    printf("Give number of employee : ");
    scanf("%d", &num_emp);
    printf("The number of emplyee %d\n", num_emp);

    printf("\nGive the identifycode");
    scanf("%d", &identifyCode);
    printf("The number of identifycode %d\n\n", identifyCode);
}

/**
 * @description: calculate the ammount of work in minutes
 * @param int clockIn[10]
 * @param int clockOut[10]
 * @return int ammount of work a day in minute
 */
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

/**
 * @description:according the user input calculate identifycode
 *              and compare with the identify code from the user
 *              if correct return 1 else return 0
 * @param int num_emp
 * @param int code
 * @return int
 */
int checkIdentifyCode(int num_emp, int code)
{
    // employee number 110086
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

    // idrArr has elements [6,8,0,0,1,1]
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

/**
 * @description:clock in and out data will be writen in related container
 *              according to from which week day. clockIn and ClockOut expressed
 *              if in of our of word is already done
 * @param NULL
 * @return void
 */
void writeDataInWeekday()
{

    //###### Monday #####################################################################################################

    while(*(currentTime+6) == 1 && (clockIn == 0 || clockOut == 0))
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
                printf("Amount of late to work in ( %d ) minutes\n\n",  MONDAY_DATA_IN[8]);
            }
            clockIn = 1;
            printf("\n\nData of today\n\n");
            printClockTimeWithFormat(MONDAY_DATA_IN);
            printf("\n\n");
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out? \n");
            getch();
            wednesdayClockOutTime(currentTime, MONDAY_DATA_OUT);
            while(minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT) < 9*60)
            {
                printf("work hours %f\n", (float)(minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)/60));
                int leaveEarly = 9*60 - minutesOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT);
                printf("leave early ( %d ) minutes\n\n", leaveEarly);

                //ask to clock out again if work hours less than 9
                printf("Clock out again? (1/0)\n");

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

            printf("\n\nTUESDAY_DATA_OUT\n");
            printClockTimeWithFormat(TUESDAY_DATA_OUT);

        }
        currentTime = clockTimeNumber();

        clockIn = 0;
        clockOut = 0;
    }

    //###### Tuesday #####################################################################################################

    while(*(currentTime+6) == 2 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In? \n");
            getch();
            tuesdayClockInTime(currentTime, TUESDAY_DATA_IN);
            printClockTimeWithFormat(TUESDAY_DATA_IN);

            // get ammount of late to work
            if(TUESDAY_DATA_IN[2]*60 + TUESDAY_DATA_IN[1] - MONDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                TUESDAY_DATA_IN[8] = TUESDAY_DATA_IN[2]*60 + TUESDAY_DATA_IN[1] - MONDAY_DATA_OUT[7] - 7*60;
                printf("Ammount of late to work %d minutes\n\n",  TUESDAY_DATA_IN[8]);
            }
            clockIn = 1;

            printf("\n\nTUESDAY_DATA_IN\n\n");
            printClockTimeWithFormat(TUESDAY_DATA_IN);
            printf("\n\n");
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out?\n");
            getch();
            tuesdayClockOutTime(currentTime, TUESDAY_DATA_OUT);
            while(minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT) < 9*60)
            {
                printf("Ammount of work of day %d minutes\n", minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT);
                printf("Ammount of leaving ealy %d minutes\n\n", leaveEarly);


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

            printf("\n\nTUESDAY_DATA_OUT\n\n");
            printClockTimeWithFormat(TUESDAY_DATA_OUT);
        }
        currentTime = clockTimeNumber();
    }

    clockIn = 0;
    clockOut = 0;

    //###### Wednesday #####################################################################################################

    while(*(currentTime+6) == 3 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In?\n");
            getch();
            wednesdayClockInTime(currentTime, WEDNESDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);

            // get ammount of late to work
            if(WEDNESDAY_DATA_IN[2]*60 + WEDNESDAY_DATA_IN[1] - TUESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                WEDNESDAY_DATA_IN[8] = WEDNESDAY_DATA_IN[2]*60 + WEDNESDAY_DATA_IN[1] - TUESDAY_DATA_OUT[7] - 7*60;
                printf("Ammount of late to work %d minutes\n\n",  WEDNESDAY_DATA_IN[8]);
                printf("\n\WEDNESDAY_DATA_IN\n\n");
                printClockTimeWithFormat(WEDNESDAY_DATA_IN);
                printf("\n\n");
            }
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out\n");
            getch();
            wednesdayClockOutTime(currentTime, WEDNESDAY_DATA_OUT);
            while(minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)<9*60)
            {
                printf("Ammount of work of day %d minutes\n", minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT);
                printf("Ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf("Clock Out again?(1/0)\n");

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);
                printf("\n");

                if(againClockOut == 1)
                {
                    wednesdayClockOutTime(currentTime, WEDNESDAY_DATA_OUT);
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

            printf("\n\nWEDNESDAY_DATA_OUT\n\n");
            printClockTimeWithFormat(WEDNESDAY_DATA_OUT);
        }
        currentTime = clockTimeNumber();
    }
    clockIn = 0;
    clockOut = 0;

    //###### Thursday #####################################################################################################

    while(*(currentTime+6) == 4 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("Clock In?\n");
            getch();
            thursdayClockInTime(currentTime, THURSDAY_DATA_IN);
            printClockTimeWithFormat(THURSDAY_DATA_IN);

            // get ammount of late to work
            if(THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                THURSDAY_DATA_IN[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                printf("Ammount of late to work %d minutes\n\n",  THURSDAY_DATA_IN[8]);
            }
            clockIn = 1;
            printf("\n\nTHURSDAY_DATA_IN\n\n");
            printClockTimeWithFormat(THURSDAY_DATA_IN);
            printf("\n\n");
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out? \n");
            getch();
            wednesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);
            while(minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)<9*60)
            {
                printf("Ammount of work of day %d minutes\n", minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT);
                printf("Ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf("Clock Out again? (1/0)\n");

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

            printf("\n\THURSDAY_DATA_OUT\n\n");
            printClockTimeWithFormat(THURSDAY_DATA_OUT);
        }
        currentTime = clockTimeNumber();
    }

    clockIn = 0;
    clockOut = 0;

   //###### Friday ######################################################################################################

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
                printf("Ammount of late to work %d minutes\n\n",  FRIDAY_DATA_IN[8]);
            }
            clockIn = 1;
            printf("\n\nFRIDAY_DATA_IN\n\n");
            printClockTimeWithFormat(FRIDAY_DATA_IN);
            printf("\n\n");
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("Clock Out :\n");
            getch();
            fridayClockOutTime(currentTime, FRIDAY_DATA_OUT);
            while(minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT) < 9*60)
            {
                printf("Ammount of work of day %d minutes\n", minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT));
                int leaveEarly = 9*60 - minutesOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
                printf("Ammount of leaving ealy %d minutes\n\n", leaveEarly);

                printf("Clock out later? (1/0)\n");


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

        printf("\n\nFRIDAY_DATA_OUT\n\n");
        printClockTimeWithFormat(FRIDAY_DATA_OUT);
    }

    clockIn = 0;
    clockOut = 0;

//    if(currentTime[6] >= 5)
//    {
//        printWeekRecord();
//    }
    printWeekRecord();
}

