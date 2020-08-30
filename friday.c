#include "friday.h"
#include <stdio.h>


void fridayClockInTime(int clockInTime[10], int friday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        friday_data_in[i] = clockInTime[i];
    }
}


void fridayClockOutTime(int clockOutTime[10], int friday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        friday_data_out[i] = clockOutTime[i];
    }
}
