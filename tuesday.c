#include "tuesday.h"
#include <stdio.h>

//static int* TUESDAY_DATA[2] = {NULL, NULL};

void tuesdayClockInTime(int clockInTime[10], int tuesday_data_in[10])
{

    //tuesday_data_in = clockInTime;
    //tuesday_data_in[6] = clockInTime[6];
    for(int i=0;i<10;i++)
    {
        tuesday_data_in[i] = clockInTime[i];
    }
}

//void tuesdayClockOutTime(int* clockOutTime, int* tuesday_data_out)
void tuesdayClockOutTime(int clockOutTime[10], int tuesday_data_out[10])
{

    //tuesday_data_out = clockOutTime;
    //tuesday_data_out[6] = clockOutTime[6];
    for(int i=0;i<10;i++)
    {
        tuesday_data_out[i] = clockOutTime[i];
    }

}
