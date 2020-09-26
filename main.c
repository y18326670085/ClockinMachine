/*
 * @Author: Lin Ye
 * @Date: 2020-08-23 11:08:33
 * @LastEditTime: 2020-08-30 11:30:28 
 * @Description: This programm get employee clock in and out time according week day. At the start
 *               you get information to give number of employee and identify code as they are displayed
 *               in the screen. With the conincident of both numer you will be asked to print enter to
 *               simulate punch. Wenn the work hours less than nine, user will be asked to give punch
 *               again, and in the case if the input is 1 then you can punch again otherwise the program
 *               will end the punch action. On Friday after clock out a record of the whole week will
 *               be generated.
 * @FilePath: \ClockinMachine\main.c
 */
#include <stdio.h>
#include <math.h>
//#include <time.h>
#include <conio.h>


//#include "test.h"
#include "clockAndRecord.h"
#include "calculatorAndWriteData.h"
#include "monday.h"
#include "tuesday.h"
#include "wednesday.h"
#include "thursday.h"
#include "friday.h"

#include "struct.h"


void clockin_machine_start();


int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

// these arrays are used in clockAndRecord.h
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

int s_index;


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

    createDataForTest();

    // get current system time
    currentTime = clockTimeNumber();

    clockin_machine_start();

    return 0;
}

/**
 * @description:at first you get employee information and then check if
 *              the input identify code correct or not. if it is correct
 *              then call function and wirte clock in and out data in
 *              container. If wrong and the user will be asked to give
 *              identify code again till three times
 * @param void
 * @return void
 */
void clockin_machine_start()
{
    getEmpInfo();

    int ammountOfInput = 0;

    CHECKIDENTIFYCODE:

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("Identifycode is correct\n\n");
        writeDataInWeekday();
    }
    else if(ammountOfInput < 2){
       printf("Identify code is wrong, input again\n");
       scanf("%d", &identifyCode);
       ammountOfInput++;
       goto CHECKIDENTIFYCODE;
    }
    else
    {
        printf("Identify code is wrong and end the program\n");
    }

    printf("\n\ns_index is %d\n", s_index);
    printEmpInfo(EMPARR[s_index]);
}



