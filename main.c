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
    printf("系统second ：%d\n", *clockTimeNumer);


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
    printf("输入6位数的员工编号 110086\n");
    printf("输入6位数的验证码 178087\n\n");

    printf("输入6位数的员工编号 : ");
    scanf("%d", &num_emp);
    printf("输入的员工编号 ：%d\n", num_emp);

    int identifyCode = 0;
    printf("\n输入校验码 ：");
    scanf("%d", &identifyCode);
    printf("输入的校验码 ：%d\n\n", identifyCode);

    if(checkIdentifyCode(num_emp, identifyCode) == 1)
    {
        printf("验证码正确");
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
