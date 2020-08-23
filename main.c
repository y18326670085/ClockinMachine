#include <stdio.h>

void clockin_machine_start();
void test();

int main()
{
    clockin_machine_start();


    //test();
    return 0;
}

void clockin_machine_start()
{
    int num_emp = 0;
    printf("输入员工编号!\n");
    scanf("%d", &num_emp);
    printf("输入的员工编号 ：%d\n", num_emp);

    printf("Hello World!\n");
}

int checkIdentifyCode(int num_emp, int code)
{

}

void test()
{
    int a;
    printf("input the data : ");
    scanf("%d",&a);//这里多了一个回车符
    printf("%d\n",a);
}
