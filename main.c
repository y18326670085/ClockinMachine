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
    printf("����Ա�����!\n");
    scanf("%d", &num_emp);
    printf("�����Ա����� ��%d\n", num_emp);

    printf("Hello World!\n");
}

int checkIdentifyCode(int num_emp, int code)
{

}

void test()
{
    int a;
    printf("input the data : ");
    scanf("%d",&a);//�������һ���س���
    printf("%d\n",a);
}
