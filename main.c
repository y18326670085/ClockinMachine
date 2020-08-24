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

int main()
{
    //clockin_machine_start();

    int *clockTimeNumer = clockTimeNumber();
    printf("ϵͳsecond ��%d\n", *clockTimeNumer);


    //monday();

    //test();
    //printClockinTime();
    //checkIdentifyCode(110086, 110086);
    //testScanf();
    return 0;
}

void clockin_machine_start()
{
    int num_emp = 0;
    printf("����6λ����Ա����� 110086\n");
    printf("����6λ������֤�� 178087\n\n");

    printf("����6λ����Ա����� : ");
    scanf("%d", &num_emp);
    printf("�����Ա����� ��%d\n", num_emp);

    int identifyCode = 0;
    printf("\n����У���� ��");
    scanf("%d", &identifyCode);
    printf("�����У���� ��%d\n\n", identifyCode);

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("��֤����ȷ");
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
