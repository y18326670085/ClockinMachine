#include "thursday.h"
#include <stdio.h>



void thursdayClockInTime(int clockInTime[10], int thursday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        thursday_data_in[i] = clockInTime[i];
    }
}


void thursdayClockOutTime(int clockOutTime[10], int thursday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        thursday_data_out[i] = clockOutTime[i];
    }
}
