#include <stdio.h>
#include "monday.h"

/**
 * @description: this function will be called by clock in on monday
 * @param int clockInTime[10] the system time by clock in
 * @param int monday_data_in[10] store clock in data in container
 * @return void
 */
void mondayClockInTime(int clockInTime[10], int monday_data_in[10])
{

    for(int i=0;i<10;i++)
    {
        monday_data_in[i] = clockInTime[i];
    }
}

/**
 * @description: this function will be called by clock out on monday
 * @param int clockOutTime[10] the system time by clock out
 * @param int monday_data_out[10] store clock out data in container
 * @return void
 */
void mondayClockOutTime(int clockOutTime[10], int monday_data_out[10])
{

    for(int i=0;i<10;i++)
    {
        monday_data_out[i] = clockOutTime[i];
    }

}
