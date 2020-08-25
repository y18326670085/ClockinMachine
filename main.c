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
void testScanf();

int *currentTime;
int clockIn = 0;
int clockOut = 0;

int num_emp = 0;
int identifyCode = 0;

//int* TUESDAY_DATA[2] = {NULL, NULL};
int TUESDAY_DATA_IN[10];
int TUESDAY_DATA_OUT[10];

int main()
{

    int *startTime = clockTimeNumber();
    //������λ�ô�ŵ�ʱ���ڼ�����Ϣ
    printf("%d-%d-%d %d:%d:%d ���ڼ� : %d\n\n", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));


    // ����ϵĵ���ʱ�亯��
    currentTime = clockTimeNumber();

    writeDataInWeekday();

//    printf("�ϰ��\n");
//    getch();
//    printf("�ϰ��getch()\n");


    //clockin_machine_start();

    //monday();

    //test();
    //printClockinTime();
    //checkIdentifyCode(110086, 110086);
    //testScanf();
    return 0;
}

void printClockTimeWithFormat(int *clockTime)
{
    printf("%d-%d-%d %d:%d:%d ���ڼ� : %d\n\n", *clockTime, *(clockTime+1), *(clockTime+2), *(clockTime+3), *(clockTime+4), *(clockTime+5), *(clockTime+6));
}

void writeDataInWeekday()
{
    while(*(currentTime+6) == 2 && (clockIn == 0 || clockOut == 0))
    {
        if(clockIn == 0 && clockOut == 0)
        {
            printf("�ϰ��\n");
            // ��console��������
            getch();
            tuesdayClockInTime(currentTime, TUESDAY_DATA_IN);
            printClockTimeWithFormat(currentTime);
            clockIn = 1;
        }
        else if (clockIn == 1 && clockOut == 0) {
            printf("�°��\n");
            getch();
            tuesdayClockOutTime(currentTime, TUESDAY_DATA_OUT);
            printClockTimeWithFormat(currentTime);
            clockOut = 1;
        }
        currentTime = clockTimeNumber();
        //printf("���ڼ� : %d", *(currentTime+6));
    }

    //printf("���ڼ�TUESDAY_DATA_IN : %d", *TUESDAY_DATA_IN);
    printClockTimeWithFormat(TUESDAY_DATA_IN);
    //printf("���ڼ�TUESDAY_DATA : \n");
    //printf("clockIn : %d\n", clockIn);
}


int *doClockInOut()
{
    int *empData = NULL;

    int num_emp = 0;
    printf("����6λ����Ա����� 110086\n");
    printf("����6λ������֤�� 178087\n\n");

    printf("����6λ����Ա����� : ");
    scanf("%d", &num_emp);
    printf("�����Ա����� ��%d\n", num_emp);
    empData[0] = num_emp;

    int identifyCode = 0;
    printf("\n����У���� ��");
    scanf("%d", &identifyCode);
    printf("�����У���� ��%d\n\n", identifyCode);
    empData[1] = identifyCode;

    return empData;
}


void clockin_machine_start()
{
    doClockInOut();

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("��֤����ȷ");
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
