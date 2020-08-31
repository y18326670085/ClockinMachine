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
#include "clockAndRecord.h"
#include "calculatorAndWriteData.h"
#include "monday.h"
#include "tuesday.h"
#include "wednesday.h"
#include "thursday.h"
#include "friday.h"


void clockin_machine_start();
//int checkIdentifyCode(int num_emp, int code);
//void printClockinTime();
//void writeDataInWeekday();
//void printClockTimeWithFormat(int *clockTime);
//void printWeekRecord();
//int minutesOfWork(int clockIn[10], int clockOut[10]);
//void createDataForTest();
void testScanf();

int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

// these array are used in clockAndRecord.h
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

    createDataForTest();

    // get current system time
    currentTime = clockTimeNumber();

    clockin_machine_start();

    return 0;
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



void testScanf()
{
    int a;
    printf("input the data : ");
    scanf("%d",&a);//�������һ���س���
    printf("%d\n",a);
}
