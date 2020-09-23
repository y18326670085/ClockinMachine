#ifndef STRUCT_H
#define STRUCT_H

struct employer
{
    int identify;
    int name;

    int avrHoursOfWorkWeek;
    int ammountOfLateStart;
    int ammountOfEarlierQuit;
    int ammountOfLackOfClock;
};

struct attendanceInfo
{
    int identify;
    int avrHoursOfWorkWeek;
    int ammountOfLateStart;
    int ammountOfEarlierQuit;
    int ammountOfLackOfClock;
};

struct employer EMPARR[] = {
    { 110086, 0, 0, 0, 0, 0 }
};

struct attendanceInfo ATDINFOARR[] = {
    { 110086, 0, 0, 0, 0 }
};

//struct attendanceInfo ATDINFOARR[] = {
//    {110086, 0, 0, 0, 0}
//};


void matchInfoToEmp(int identify,
                    int avrHoursOfWorkWeek, int ammountOfLateStart, int ammountOfEarlierQuit, int ammountOfLackOfClock,
                    struct attendanceInfo atdinfoarr[20], struct employer emparr[20])
{
    for(int i = 0; i < 20; i++)
    {
        if((emparr+i)->identify == identify)
        {
            (emparr+i)->avrHoursOfWorkWeek = avrHoursOfWorkWeek;
            (emparr+i)->ammountOfLateStart = ammountOfLateStart;
            (emparr+i)->ammountOfEarlierQuit = ammountOfEarlierQuit;
            (emparr+i)->ammountOfLackOfClock = ammountOfLackOfClock;
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



#endif // STRUCT_H
