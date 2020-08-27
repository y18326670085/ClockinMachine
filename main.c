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
    //������λ�ô�ŵ�ʱ���ڼ�����Ϣ
    printf("%d-%d-%d %d:%d:%d ���ڼ� : %d\n\n", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));

    createDataForTest();
    //hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT);
    //printf("��һ����ʱ��min ��%d", hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT));

    // ����ϵĵ���ʱ�亯��
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
    MONDAY_DATA_IN[6] = 1; //����
    MONDAY_DATA_IN[7] = 0; //�Ӱ�min
    MONDAY_DATA_IN[8] = 0; //�ٵ�
    MONDAY_DATA_IN[9] = 0; //����

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
    printf("%d-%d-%d %d:%d:%d / ���ڼ� : %d / �Ӱ�ʱ�� �� %d / �ٵ�ʱ�� �� %d / �Ƿ����� �� %d\n",
           *clockTime, //��
           *(clockTime+1), //��
           *(clockTime+2), //ʱ
           *(clockTime+3), //��
           *(clockTime+4), //��
           *(clockTime+5), //��
           *(clockTime+6),//����
           *(clockTime+7),//�Ӱ��ʱ�䣬��ʼֵΪ0,��λminute
           *(clockTime+8),//�ٵ���ʱ�䣬��ʼֵΪ0����λminute
           *(clockTime+9));//�Ƿ�����
}

void printWeekRecord()
{
    printf("��һ�ϰ��ʱ�� : ");
    printClockTimeWithFormat(MONDAY_DATA_IN);
    printf("��һ�°��ʱ�� : ");
    printClockTimeWithFormat(MONDAY_DATA_OUT);
    printf("\n\n");

    printf("�ܶ��ϰ��ʱ�� : ");
    printClockTimeWithFormat(TUESDAY_DATA_IN);
    printf("�ܶ��°��ʱ�� : ");
    printClockTimeWithFormat(TUESDAY_DATA_OUT);
    printf("\n\n");

    printf("�����ϰ��ʱ�� : ");
    printClockTimeWithFormat(WEDNESDAY_DATA_IN);
    printf("�����°��ʱ�� : ");
    printClockTimeWithFormat(WEDNESDAY_DATA_OUT);
    printf("\n\n");

    printf("�����ϰ��ʱ�� : ");
    printClockTimeWithFormat(THURSDAY_DATA_IN);
    printf("�����°��ʱ�� : ");
    printClockTimeWithFormat(THURSDAY_DATA_OUT);
    printf("\n\n");

    printf("�����ϰ��ʱ�� : ");
    printClockTimeWithFormat(FRIDAY_DATA_IN);
    printf("�����°��ʱ�� : ");
    printClockTimeWithFormat(FRIDAY_DATA_OUT);
    printf("\n\n");


    // ��ƽ������ʱ��
    int hoursOfWorkWeek = 0;
    hoursOfWorkWeek = hoursOfWork(MONDAY_DATA_IN, MONDAY_DATA_OUT)
            + hoursOfWork(TUESDAY_DATA_IN, TUESDAY_DATA_OUT)
            + hoursOfWork(WEDNESDAY_DATA_IN, WEDNESDAY_DATA_OUT)
            + hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)
            + hoursOfWork(FRIDAY_DATA_IN, FRIDAY_DATA_OUT);
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
    printf("��ƽ���ϰ�ʱ�� : %d\n", avrHoursOfWorkWeek);
    printf("�ܳٵ����� : %d\n", ammountOfLateStart);
    printf("�����˴��� : %d\n", ammountOfEarlierQuit);
    printf("ȱ������ : %d\n", ammountOfLackOfClock);
    printf("######################################\n");

}


// ����ϰ��ʱ�� ��minuteΪ��λ
int hoursOfWork(int clockIn[10], int clockOut[10])
{
    float hoursOfWork;

    //�ϰ�hours
    int hoursClockIn = *(clockIn+2);
    //�ϰ�minutes
    int minClockIn = *(clockIn+1);

    //�°�hours
    int hoursClockOut = *(clockOut+2);
    //�°�minutes
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

    //###### ��һ #####################################################################################################

    clockIn = 0;
    clockOut = 0;


    //###### �ܶ� #####################################################################################################


    //###### ���� #####################################################################################################


    //###### ���� #####################################################################################################

    while(*(currentTime+6) == 4 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("�ϰ��\n");
            getch();
            thursdayClockInTime(currentTime, THURSDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);
            // �ж��Ƿ�ٵ����ú��������ٵ�ʱ��д�뵽 WEDNESDAY_DATA_IN ����
            // �ٵ��ļ���Ҫ����ǰһ�쳬��9Сʱ�Ĺ���ʱ��



            if(THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] > 7*60)
            {
                //THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                THURSDAY_DATA_IN[8] = THURSDAY_DATA_IN[2]*60 + THURSDAY_DATA_IN[1] - WEDNESDAY_DATA_OUT[7] - 7*60;
                printf("THURSDAY_DATA_OUT[8] �ٵ� %d ����\n\n",  THURSDAY_DATA_OUT[8]);
            }

            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("�°��\n");
            getch();
            wednesdayClockOutTime(currentTime, THURSDAY_DATA_OUT);



            while(hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)<9*60)
            {
                printf("\n�ϰ�ʱ�䲻��9Сʱ��ʵ���ϰ�ʱ��Ϊ ��%f\n\n", (float)(hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT)/60));
                int leaveEarly = 9*60 - hoursOfWork(THURSDAY_DATA_IN, THURSDAY_DATA_OUT);
                printf("����%d����\n\n", leaveEarly);

                //ѯ�������Ƿ�Ҫ���´�
                printf("Ҫ�����°��ô��(1/0)\n");

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
                    //���˵����ݴ洢���°඼�洢
                    THURSDAY_DATA_OUT[9] = 1;
                    THURSDAY_DATA_IN[9] = 1;

                    //����Ҫ���ٵ�ʱ�丳ֵ
                    //ǰ�����tuesdayClockOutTime �����λ�ø�ֵΪ0
                    THURSDAY_DATA_OUT[8] = THURSDAY_DATA_IN[8];
                    break;
                }
            }

            clockOut = 1;

            printClockTimeWithFormat(currentTime);

            //�Ӱ�ʱ��Ϊ��ֵ�������
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



    //���һ�ܵĴ򿨼�¼
    printWeekRecord();
}


void getEmpInfo()
{

    printf("����6λ����Ա����� 110086\n");
    printf("����6λ������֤�� 178087\n\n");

    printf("����6λ����Ա����� : ");
    scanf("%d", &num_emp);
    printf("�����Ա����� ��%d\n", num_emp);

    printf("\n����У���� ��");
    scanf("%d", &identifyCode);
    printf("�����У���� ��%d\n\n", identifyCode);
}


void clockin_machine_start()
{
    getEmpInfo();

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("��֤����ȷ\n\n");
        //�ж����ܼ�
        //��¼��ʱ�䵽static int* MONDAY_DATA[2]
        writeDataInWeekday();
    }
    else{
       printf("��֤�벻��ȷ");
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
