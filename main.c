#include <stdio.h>
#include <math.h>
#include <time.h>

void clockin_machine_start();
void printClockinTime();
void test();

int main()
{
    //clockin_machine_start();

    printClockinTime();

    //test();
    return 0;
}

void clockin_machine_start()
{
    int num_emp = 0;
    printf("����6λ����Ա����� : ");
    scanf("%d", &num_emp);
    printf("�����Ա����� ��%d\n", num_emp);

    int identifyCode = 0;
    printf("\n����У���� ��");
    scanf("%d", &identifyCode);
    printf("�����У���� ��%d\n", identifyCode);

    //printf("Hello World!\n");
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

void printClockinTime()
{
    char len[20] = {0};

    time_t timep;
    time(&timep);

    struct tm *p;
    p = gmtime(&timep);

    snprintf(len, 20, "%d-%d-%d %d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);

    printf("\n%s\n", len);
}

void test()
{
    int a;
    printf("input the data : ");
    scanf("%d",&a);//�������һ���س���
    printf("%d\n",a);
}
