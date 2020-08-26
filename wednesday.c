#include "wednesday.h"
#include <stdio.h>

void wednesdayClockInTime(int clockInTime[10], int wednesday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        wednesday_data_in[i] = clockInTime[i];
    }
}


void wednesdayClockOutTime(int clockOutTime[10], int wednesday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        wednesday_data_out[i] = clockOutTime[i];
    }
}
