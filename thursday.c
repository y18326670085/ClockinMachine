#include "thursday.h"
#include <stdio.h>

/**
 * @description: this function will be called by clock in on thursday
 * @param int clockInTime[10] the system time by clock in
 * @param int thursday_data_in[10] store clock in data in container
 * @return void
 */
void thursdayClockInTime(int clockInTime[10], int thursday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        thursday_data_in[i] = clockInTime[i];
    }
}

/**
 * @description: this function will be called by clock out on thursday
 * @param int clockOutTime[10] the system time by clock out
 * @param int thursday_data_out[10] store clock out data in container
 * @return void
 */
void thursdayClockOutTime(int clockOutTime[10], int thursday_data_out[10])
{
    for(int i=0;i<10;i++)
    {
        thursday_data_out[i] = clockOutTime[i];
    }
}
