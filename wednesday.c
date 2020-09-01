#include "wednesday.h"
#include <stdio.h>

/**
 * @description: this function will be called by clock in on wednesday
 * @param int clockInTime[10] the system time by clock in
 * @param int wednesday_data_in[10] store clock in data in container
 * @return void
 */
void wednesdayClockInTime(int clockInTime[10], int wednesday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        wednesday_data_in[i] = clockInTime[i];
    }
}

/**
 * @description: this function will be called by clock out on wednesday
 * @param int clockOutTime[10] the system time by clock out
 * @param int wednesday_data_out[10] store clock out data in container
 * @return void
 */
void wednesdayClockOutTime(int clockOutTime[10], int wednesday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        wednesday_data_out[i] = clockOutTime[i];
    }
}
