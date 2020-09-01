#include "friday.h"
#include <stdio.h>

/**
 * @description: this function will be called by clock in on friday
 * @param int clockInTime[10] the system time by clock in
 * @param int friday_data_in[10] store clock in data in container
 * @return void
 */
void fridayClockInTime(int clockInTime[10], int friday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        friday_data_in[i] = clockInTime[i];
    }
}

/**
 * @description: this function will be called by clock out on friday
 * @param int clockOutTime[10] the system time by clock out
 * @param int friday_data_out[10] store clock out data in container
 * @return void
 */
void fridayClockOutTime(int clockOutTime[10], int friday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        friday_data_out[i] = clockOutTime[i];
    }
}
