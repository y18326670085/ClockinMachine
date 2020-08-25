#include <stdio.h>
#include <math.h>
//#include <time.h>
#include <conio.h>


//#include "test.h"
#include "clockTimeNumber.h"
#include "monday.h"
#include "tuesday.h"

void clockin_machine_start();
int checkIdentifyCode(int num_emp, int code);
void printClockinTime();
void writeDataInWeekday();
void printClockTimeWithFormat(int *clockTime);
void printWeekRecord();
void testScanf();

int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

int MONDAY_DATA_IN[10];
int MONDAY_DATA_OUT[10];
//int* TUESDAY_DATA[2] = {NULL, NULL};
int TUESDAY_DATA_IN[10];
int TUESDAY_DATA_OUT[10];

int main()
{

    int *startTime = clockTimeNumber();
    //第六个位置存放的时星期几的信息
    printf("%d-%d-%d %d:%d:%d 星期几 : %d\n\n", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));


    // 不间断的调用时间函数
    currentTime = clockTimeNumber();

//    writeDataInWeekday();

//    printf("上班打卡\n");
//    getch();
//    printf("上班打卡getch()\n");


    clockin_machine_start();

    //monday();

    //test();
    //printClockinTime();
    //checkIdentifyCode(110086, 110086);
    //testScanf();
    return 0;
}

void printClockTimeWithFormat(int *clockTime)
{
    printf("%d-%d-%d %d:%d:%d 星期几 : %d\n", *clockTime, *(clockTime+1), *(clockTime+2), *(clockTime+3), *(clockTime+4), *(clockTime+5), *(clockTime+6));
}

void printWeekRecord()
{
    printf("周一上班打卡时间 : ");
    printClockTimeWithFormat(MONDAY_DATA_IN);
    printf("周一下班打卡时间 : ");
    printClockTimeWithFormat(MONDAY_DATA_OUT);
    printf("\n\n");

    printf("周二上班打卡时间 : ");
    printClockTimeWithFormat(TUESDAY_DATA_IN);
    printf("周二下班打卡时间 : ");
    printClockTimeWithFormat(TUESDAY_DATA_OUT);
    printf("\n\n");
}


float hoursOfWork(int clockIn[10], int clockOut[10])
{
    float hoursOfWork;

    //上班hours
    int hoursClockIn = *(clockIn+2);
    //上班minutes
    int minClockIn = *(clockIn+1);

    //下班hours
    int hoursClockOut = *(clockOut+2);
    //下班minutes
    int minClockOut = *(clockOut+1);

    if(minClockOut < minClockIn)
    {
        hoursOfWork = ((minClockOut + 60) - minClockIn) / 60;
        hoursOfWork += hoursClockOut - 1 - hoursClockIn;
    }
    else{
        hoursOfWork = (minClockOut - minClockIn) / 60;
        hoursOfWork += hoursClockOut - hoursClockIn;
    }
    return hoursOfWork;
}

void writeDataInWeekday()
{
    while(*(currentTime+6) == 1 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("上班打卡\n");
            getch();
            tuesdayClockInTime(currentTime, MONDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("下班打卡\n");
            getch();
            tuesdayClockOutTime(currentTime, MONDAY_DATA_OUT);
            printClockTimeWithFormat(currentTime);
            clockOut = 1;
        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(MONDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;


    while(*(currentTime+6) == 2 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("上班打卡\n");
            // 从console接收输入
            getch();
            tuesdayClockInTime(currentTime, TUESDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("下班打卡\n");
            getch();
            tuesdayClockOutTime(currentTime, TUESDAY_DATA_OUT);
            printClockTimeWithFormat(currentTime);
            clockOut = 1;
        }
        currentTime = clockTimeNumber();
        //printf("星期几 : %d", *(currentTime+6));
    }

    if(hoursOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)<9)
    {
        printf("\n上班时间不到9小时，实际上班时间为 ：%f\n\n", hoursOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT));
    }

    //printf("星期几TUESDAY_DATA_IN : %d", *TUESDAY_DATA_IN);
    //printClockTimeWithFormat(TUESDAY_DATA_IN);
    //printf("星期几TUESDAY_DATA : \n");
    //printf("clockIn : %d\n", clockIn);

    clockIn = 0;
    clockOut = 0;

    //输出一周的打卡记录
    printWeekRecord();
}


void doClockInOut()
{

    printf("输入6位数的员工编号 110086\n");
    printf("输入6位数的验证码 178087\n\n");

    printf("输入6位数的员工编号 : ");
    scanf("%d", &num_emp);
    printf("输入的员工编号 ：%d\n", num_emp);

    printf("\n输入校验码 ：");
    scanf("%d", &identifyCode);
    printf("输入的校验码 ：%d\n\n", identifyCode);
}


void clockin_machine_start()
{
    doClockInOut();

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("验证码正确\n\n");
        //判断是周几
        //记录打卡时间到static int* MONDAY_DATA[2]
        writeDataInWeekday();
    }
    else{
       printf("验证码不正确");
    }
}

int checkIdentifyCode(int num_emp, int code)
{
    // 员工编号 110086
    // 校验码 := 员工编号除首位反序，再与员工编号求和
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

    // 反序数组除首位 [6,8,0,0,1,1]
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
    scanf("%d",&a);//这里多了一个回车符
    printf("%d\n",a);
}
