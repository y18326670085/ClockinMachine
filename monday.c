#include "monday.h"
#include <stdio.h>

//Monday::Monday()
//{

//}

//void Monday::getClockinData()
//{
//    printf("调用周一的函数");
//}

void mondayClockInTime(int clockInTime[10], int monday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        monday_data_in[i] = clockInTime[i];
    }
}

//void tuesdayClockOutTime(int* clockOutTime, int* tuesday_data_out)
void mondayClockOutTime(int clockOutTime[10], int monday_data_out[10])
{

    for(int i=0;i<10;i++)
    {
        monday_data_out[i] = clockOutTime[i];
    }

}
