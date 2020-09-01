#include "tuesday.h"
#include <stdio.h>

/**
 * @description: this function will be called by clock in on tuesday
 * @param int clockInTime[10] the system time by clock in
 * @param int tuesday_data_in[10] store clock in data in container
 * @return void
 */
void tuesdayClockInTime(int clockInTime[10], int tuesday_data_in[10])
{
    for(int i=0;i<10;i++)
    {
        tuesday_data_in[i] = clockInTime[i];
    }
}

/**
 * @description: this function will be called by clock out on tuesday
 * @param int clockOutTime[10] the system time by clock out
 * @param int tuesday_data_out[10] store clock out data in container
 * @return void
 */
void tuesdayClockOutTime(int clockOutTime[10], int tuesday_data_out[10])
{

    for(int i=0;i<10;i++)
    {
        tuesday_data_out[i] = clockOutTime[i];
    }

}
