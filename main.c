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
    //������λ�ô�ŵ�ʱ���ڼ�����Ϣ
    printf("%d-%d-%d %d:%d:%d ���ڼ� : %d", *startTime, *(startTime+1), *(startTime+2), *(startTime+3), *(startTime+4), *(startTime+5), *(startTime+6));


    // ����ϵĵ���ʱ�亯��
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
            printf("�ϰ��\n");
            mondayClockInTime(currentTime);
            clockIn = 1;
        }
        else if (clockOut == 1 && clockOut == 0) {
            printf("�°��\n");
            mondayClockOutTime(currentTime);
            clockOut = 1;
        }
    }
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
//    int num_emp = 0;
//    printf("����6λ����Ա����� 110086\n");
//    printf("����6λ������֤�� 178087\n\n");

//    printf("����6λ����Ա����� : ");
//    scanf("%d", &num_emp);
//    printf("�����Ա����� ��%d\n", num_emp);

//    int identifyCode = 0;
//    printf("\n����У���� ��");
//    scanf("%d", &identifyCode);
//    printf("�����У���� ��%d\n\n", identifyCode);

//    int num_emp = *doClockInOut();
//    int identifyCode = *(doClockInOut()+1);

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("��֤����ȷ");
        //�ж����ܼ�
        //��¼��ʱ�䵽static int* MONDAY_DATA[2]
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
