#ifndef INFO_H
#define INFO_H
typedef struct info
    {
    char First_Name[20];
    char Last_Name[20];
    long int Contact_Num;
    long int SSN;
    } Info;
Info Get_Info();
#endif
