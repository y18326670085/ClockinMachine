#include <stdio.h>
#include "struct.h"

extern int s_index;

struct employer EMPARR[] = {
    { 0, 110086, 0, 0, 0, 0, 0 }
};

struct attendanceInfo ATDINFOARR[] = {
    { 0, 110086, 0, 0, 0, 0 }
};

void matchInfoToEmp(int identify,
                    int avrHoursOfWorkWeek, int ammountOfLateStart, int ammountOfEarlierQuit, int ammountOfLackOfClock,
                    struct attendanceInfo *atdinfoarr, struct employer *emparr)
{

//    s_index = emparr[0].index;
//    emparr[0].avrHoursOfWorkWeek = avrHoursOfWorkWeek;
//    emparr[0].ammountOfLateStart = ammountOfLateStart;
//    emparr[0].ammountOfEarlierQuit = ammountOfEarlierQuit;
//    emparr[0].ammountOfLackOfClock = ammountOfLackOfClock;

    for(int i = 0; i < 20; i++)
    {
        if((emparr+i)->identify == identify)
        {
            (emparr+i)->avrHoursOfWorkWeek = avrHoursOfWorkWeek;
            (emparr+i)->ammountOfLateStart = ammountOfLateStart;
            (emparr+i)->ammountOfEarlierQuit = ammountOfEarlierQuit;
            (emparr+i)->ammountOfLackOfClock = ammountOfLackOfClock;

            s_index = (emparr+i)->index;
        }

        if((atdinfoarr+i)->identify == identify)
        {
            (atdinfoarr+i)->avrHoursOfWorkWeek = avrHoursOfWorkWeek;
            (atdinfoarr+i)->ammountOfLateStart = ammountOfLateStart;
            (atdinfoarr+i)->ammountOfEarlierQuit = ammountOfEarlierQuit;
            (atdinfoarr+i)->ammountOfLackOfClock = ammountOfLackOfClock;
        }
    }
}

void printEmpInfo(struct employer str_emp)
{

//    int identify;
//    int name;

//    int avrHoursOfWorkWeek;
//    int ammountOfLateStart;
//    int ammountOfEarlierQuit;
//    int ammountOfLackOfClock;
    printf("identify\tname\tavrHoursOfWorkWeek\tammountOfLateStart\tammountOfEarlierQuit\tammountOfLackOfClock\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",str_emp.identify,str_emp.name,str_emp.avrHoursOfWorkWeek,str_emp.ammountOfLateStart,str_emp.ammountOfEarlierQuit,str_emp.ammountOfLackOfClock);

}
