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
int hoursOfWork(int clockIn[10], int clockOut[10]);
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
    //第六个位置存放的时星期几的信息
    printf("%d-%d-%d %d:%d:%d 星期几 : %d\n\n", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));

    createDataForTest();
    //hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT);
    //printf("周一工作时间min ：%d", hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT));

    // 不间断的调用时间函数
    currentTime = clockTimeNumber();

    clockin_machine_start();

    return 0;
}

void createDataForTest()
{
    MONDAY_DATA_IN[0] = 21;
    MONDAY_DATA_IN[1] = 30;
    MONDAY_DATA_IN[2] = 6;
    MONDAY_DATA_IN[3] = 24;
    MONDAY_DATA_IN[4] = 8;
    MONDAY_DATA_IN[5] = 2020;
    MONDAY_DATA_IN[6] = 1; //星期
    MONDAY_DATA_IN[7] = 0; //加班min
    MONDAY_DATA_IN[8] = 0; //迟到
    MONDAY_DATA_IN[9] = 0; //早退

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
    TUESDAY_DATA_IN[1] = 30;
    TUESDAY_DATA_IN[2] = 7;
    TUESDAY_DATA_IN[3] = 25;
    TUESDAY_DATA_IN[4] = 8;
    TUESDAY_DATA_IN[5] = 2020;
    TUESDAY_DATA_IN[6] = 2;
    //TUESDAY_DATA_IN[7] = 550;

    TUESDAY_DATA_OUT[0] = 11;
    TUESDAY_DATA_OUT[1] = 40;
    TUESDAY_DATA_OUT[2] = 18;
    TUESDAY_DATA_OUT[3] = 25;
    TUESDAY_DATA_OUT[4] = 8;
    TUESDAY_DATA_OUT[5] = 2020;
    TUESDAY_DATA_OUT[6] = 2;
    //TUESDAY_DATA_OUT[7] = 550;

    WEDNESDAY_DATA_IN[0] = 21;
    WEDNESDAY_DATA_IN[1] = 30;
    WEDNESDAY_DATA_IN[2] = 7;
    WEDNESDAY_DATA_IN[3] = 26;
    WEDNESDAY_DATA_IN[4] = 8;
    WEDNESDAY_DATA_IN[5] = 2020;
    WEDNESDAY_DATA_IN[6] = 3;
    WEDNESDAY_DATA_IN[7] = 0;
    WEDNESDAY_DATA_IN[8] = 0;

    WEDNESDAY_DATA_OUT[0] = 11;
    WEDNESDAY_DATA_OUT[1] = 30;
    WEDNESDAY_DATA_OUT[2] = 12;
    WEDNESDAY_DATA_OUT[3] = 26;
    WEDNESDAY_DATA_OUT[4] = 8;
    WEDNESDAY_DATA_OUT[5] = 2020;
    WEDNESDAY_DATA_OUT[6] = 3;
    WEDNESDAY_DATA_OUT[7] = 0;
    WEDNESDAY_DATA_OUT[8] = 0;

//    THURSDAY_DATA_IN[0] = 11;
//    THURSDAY_DATA_IN[1] = 30;
//    THURSDAY_DATA_IN[2] = 10;
//    THURSDAY_DATA_IN[3] = 27;
//    THURSDAY_DATA_IN[4] = 8;
//    THURSDAY_DATA_IN[5] = 2020;
//    THURSDAY_DATA_IN[6] = 4;

//    THURSDAY_DATA_OUT[0] = 21;
//    THURSDAY_DATA_OUT[1] = 40;
//    THURSDAY_DATA_OUT[2] = 19;
//    THURSDAY_DATA_OUT[3] = 27;
//    THURSDAY_DATA_OUT[4] = 8;
//    THURSDAY_DATA_OUT[5] = 2020;
//    THURSDAY_DATA_OUT[6] = 4;

    FRIDAY_DATA_IN[0] = 21;
    FRIDAY_DATA_IN[1] = 0;
    FRIDAY_DATA_IN[2] = 7;
    FRIDAY_DATA_IN[3] = 28;
    FRIDAY_DATA_IN[4] = 8;
    FRIDAY_DATA_IN[5] = 2020;
    FRIDAY_DATA_IN[6] = 5;

    FRIDAY_DATA_OUT[0] = 11;
    FRIDAY_DATA_OUT[1] = 30;
    FRIDAY_DATA_OUT[2] = 17;
    FRIDAY_DATA_OUT[3] = 28;
    FRIDAY_DATA_OUT[4] = 8;
    FRIDAY_DATA_OUT[5] = 2020;
    FRIDAY_DATA_OUT[6] = 5;
}

void printClockTimeWithFormat(int *clockTime)
{
    printf("%d-%d-%d %d:%d:%d / 星期几 : %d / 加班时长 ： %d / 迟到时长 ： %d / 是否早退 ： %d\n",
           *clockTime, //秒
           *(clockTime+1), //分
           *(clockTime+2), //时
           *(clockTime+3), //天
           *(clockTime+4), //月
           *(clockTime+5), //年
           *(clockTime+6),//星期
           *(clockTime+7),//加班的时间，初始值为0,单位minute
           *(clockTime+8),//迟到的时间，初始值为0，单位minute
           *(clockTime+9));//是否早退
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

    printf("周三上班打卡时间 : ");
    printClockTimeWithFormat(WEDNESDAY_DATA_IN);
    printf("周三下班打卡时间 : ");
    printClockTimeWithFormat(WEDNESDAY_DATA_OUT);
    printf("\n\n");

    printf("周四上班打卡时间 : ");
    printClockTimeWithFormat(THURSDAY_DATA_IN);
    printf("周四下班打卡时间 : ");
    printClockTimeWithFormat(THURSDAY_DATA_OUT);
    printf("\n\n");

    printf("周五上班打卡时间 : ");
    printClockTimeWithFormat(FRIDAY_DATA_IN);
    printf("周五下班打卡时间 : ");
    printClockTimeWithFormat(FRIDAY_DATA_OUT);
    printf("\n\n");


    // 周平均工作时间
    int hoursOfWorkWeek = 0;
    hoursOfWorkWeek = hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)
            + hoursOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)
            + hoursOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)
            + hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)
            + hoursOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
    int avrHoursOfWorkWeek = 0;
    avrHoursOfWorkWeek = hoursOfWorkWeek / 5;

    // 迟到次数
    int ammountOfLateStart = 0;
    if(MONDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(TUESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(WEDNESDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(THURSDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;
    if(FRIDAY_DATA_OUT[8] > 0) ammountOfLateStart += 1;

    //早退次数
    int ammountOfEarlierQuit = 0;
    if(MONDAY_DATA_OUT[9] == 1) ammountOfEarlierQuit += 1;
    if(TUESDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(WEDNESDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(THURSDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;
    if(FRIDAY_DATA_OUT[9] == 1) ammountOfLateStart += 1;

    //缺卡次数
    int ammountOfLackOfClock = 0;
    if(MONDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(TUESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(WEDNESDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(THURSDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;
    if(FRIDAY_DATA_OUT[5] == 0) ammountOfLackOfClock += 1;


    printf("######################################\n");
    printf("周平均上班时长 : %d\n", avrHoursOfWorkWeek);
    printf("周迟到次数 : %d\n", ammountOfLateStart);
    printf("周早退次数 : %d\n", ammountOfEarlierQuit);
    printf("缺卡次数 : %d\n", ammountOfLackOfClock);
    printf("######################################\n");

}


// 获得上班的时长 以minute为单位
int hoursOfWork(int clockIn[10], int clockOut[10])
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

    //###### 周一 #####################################################################################################

    clockIn = 0;
    clockOut = 0;


    //###### 周二 #####################################################################################################


    //###### 周三 #####################################################################################################


    //###### 周四 #####################################################################################################

    while(*(currentTime+6) == 4 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("上班打卡\n");
            getch();
            thursdayClockInTime(currentTime, THURSDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);
            // 判断是否迟到（用函数），迟到时间写入到 WEDNESDAY_DATA_IN 里面
            // 迟到的计算要加上前一天超出9小时的工作时间



            if(THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                THURSDAY_DATA_IN[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                printf("THURSDAY_DATA_OUT[8] 迟到 %d 分钟\n\n",  THURSDAY_DATA_OUT[8]);
            }

            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("下班打卡\n");
            getch();
            wednesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);



            while(hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)<9*60)
            {
                printf("\n上班时间不到9小时，实际上班时间为 ：%f\n\n", (float)(hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)/60));
                int leaveEarly = 9*60 - hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT);
                printf("早退%d分钟\n\n", leaveEarly);

                //询问早退是否要重新打卡
                printf("要重新下班打卡么？(1/0)\n");

//                char againClockOut;
//                scanf("%c",&againClockOut);
//                printf("againClockOut : %c\n", againClockOut);

                int againClockOut;
                scanf("%d",&againClockOut);
                printf("againClockOut : %d\n", againClockOut);

                if(againClockOut == 1)
                {
                    tuesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);
                    printClockTimeWithFormat(THURSDAY_DATA_OUT);
                }
                else{
                    //早退的数据存储上下班都存储
                    THURSDAY_DATA_OUT[9] = 1;
                    THURSDAY_DATA_IN[9] = 1;

                    //这里要给迟到时间赋值
                    //前面调用tuesdayClockOutTime 把这个位置赋值为0
                    THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            //加班时长为正值参与计算
            THURSDAY_DATA_OUT[7] = hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 > 0 ? hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 : 0 ;
            THURSDAY_DATA_IN[7] = hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 > 0 ? hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT) - 9*60 : 0 ;

        }
        currentTime = clockTimeNumber();
    }

    //printClockTimeWithFormat(MONDAY_DATA_IN);

    clockIn = 0;
    clockOut = 0;

    //#################################################################################################################







    clockIn = 0;
    clockOut = 0;



    //输出一周的打卡记录
    printWeekRecord();
}


void getEmpInfo()
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
    getEmpInfo();

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
