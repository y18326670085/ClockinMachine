#include <stdio.h>
#include <math.h>
//#include <time.h>


//#include "test.h"
#include "clockTimeNumber.h"
#include "monday.h"

void clockin_machine_start();
int checkIdentifyCode(int num_emp, int code);
void printClockinTime();
void testScanf();

int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

int main()
{

    int *startTime = clockTimeNumber();
    //第六个位置存放的时星期几的信息
    printf("%d-%d-%d %d:%d:%d 星期几 : %d", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));


    // 不间断的调用时间函数
    currentTime = clockTimeNumber();


    //clockin_machine_start();

    //monday();

    //test();
    //printClockinTime();
    //checkIdentifyCode(110086, 110086);
    //testScanf();
    return 0;
}

void writeDataInWeekday()
{
    while(*(currentTime+6) == 1 && (clockIn != 1 || clockOut != 1))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("上班打卡\n");
            mondayClockInTime(currentTime);
            clockIn = 1;
        }
        else if (clockOut == 1 && clockOut == 0) {
            printf("下班打卡\n");
            mondayClockOutTime(currentTime);
            clockOut = 1;
        }
    }
}


int *doClockInOut()
{
    int *empData = NULL;

    int num_emp = 0;
    printf("输入6位数的员工编号 110086\n");
    printf("输入6位数的验证码 178087\n\n");

    printf("输入6位数的员工编号 : ");
    scanf("%d", &num_emp);
    printf("输入的员工编号 ：%d\n", num_emp);
    empData[0] = num_emp;

    int identifyCode = 0;
    printf("\n输入校验码 ：");
    scanf("%d", &identifyCode);
    printf("输入的校验码 ：%d\n\n", identifyCode);
    empData[1] = identifyCode;

    return empData;
}


void clockin_machine_start()
{
//    int num_emp = 0;
//    printf("输入6位数的员工编号 110086\n");
//    printf("输入6位数的验证码 178087\n\n");

//    printf("输入6位数的员工编号 : ");
//    scanf("%d", &num_emp);
//    printf("输入的员工编号 ：%d\n", num_emp);

//    int identifyCode = 0;
//    printf("\n输入校验码 ：");
//    scanf("%d", &identifyCode);
//    printf("输入的校验码 ：%d\n\n", identifyCode);

//    int num_emp = *doClockInOut();
//    int identifyCode = *(doClockInOut()+1);

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("验证码正确");
        //判断是周几
        //记录打卡时间到static int* MONDAY_DATA[2]
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
