#ifndef STRUCT_H
#define STRUCT_H


struct employer
{
    int index;

    int identify;
    int name;

    int avrHoursOfWorkWeek;
    int ammountOfLateStart;
    int ammountOfEarlierQuit;
    int ammountOfLackOfClock;
};

struct attendanceInfo
{
    int index;

    int identify;
    int avrHoursOfWorkWeek;
    int ammountOfLateStart;
    int ammountOfEarlierQuit;
    int ammountOfLackOfClock;
};


struct employer EMPARR[1];
struct attendanceInfo ATDINFOARR[1];


//struct employer EMPARR[] = {
//    { 0, 110086, 0, 0, 0, 0, 0 }
//};

//struct attendanceInfo ATDINFOARR[] = {
//    { 0, 110086, 0, 0, 0, 0 }
//};


void matchInfoToEmp(int identify,
                    int avrHoursOfWorkWeek, int ammountOfLateStart, int ammountOfEarlierQuit, int ammountOfLackOfClock,
                    struct attendanceInfo *atdinfoarr, struct employer *emparr);
//{
//    for(int i = 0; i < 20; i++)
//    {
//        if((emparr+i)->identify == identify)
//        {
//            (emparr+i)->avrHoursOfWorkWeek = avrHoursOfWorkWeek;
//            (emparr+i)->ammountOfLateStart = ammountOfLateStart;
//            (emparr+i)->ammountOfEarlierQuit = ammountOfEarlierQuit;
//            (emparr+i)->ammountOfLackOfClock = ammountOfLackOfClock;
//        }

//        if((atdinfoarr+i)->identify == identify)
//        {
//            (atdinfoarr+i)->avrHoursOfWorkWeek = avrHoursOfWorkWeek;
//            (atdinfoarr+i)->ammountOfLateStart = ammountOfLateStart;
//            (atdinfoarr+i)->ammountOfEarlierQuit = ammountOfEarlierQuit;
//            (atdinfoarr+i)->ammountOfLackOfClock = ammountOfLackOfClock;
//        }
//    }
//}

void printEmpInfo(struct employer str_emp);



#endif // STRUCT_H
