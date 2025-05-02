#include <stdio.h>
#include "Info.h"
Info Get_Info(){
Info T1;

printf("Enter First Name: ");
scanf("%19s", T1.First_Name);

printf("Enter Last Name: ");
scanf("%19s", T1.Last_Name);

printf("Enter Contact Number: ");
scanf("%ld", &T1.Contact_Num);

printf("Enter SSN: ");
scanf("%ld", &T1.SSN);

return T1;
}