#include "monday.h"
#include <stdio.h>

//Monday::Monday()
//{

//}

//void Monday::getClockinData()
//{
//    printf("调用周一的函数");
//}

static int* MONDAY_DATA[2] = {NULL, NULL};

void mondayClockInTime(int* clockInTime)
{

    MONDAY_DATA[0] = clockInTime;

    printf("调用monday函数");
}

void mondayClockOutTime(int* clockOutTime)
{

    MONDAY_DATA[1] = clockOutTime;

}
