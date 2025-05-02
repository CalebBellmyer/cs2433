#include <stdio.h>
#include "Acc.h"

int Bonus = 3; // External variable, Default Bonus is 3%.

Acc Create_Acc() {

Acc T2;

printf("Enter Account Number: ");
scanf("%ld", &T2.Acc_Num);

printf("Enter Account Type: ");
scanf("%9s", T2.Acc_Type);

printf("Enter Balance: ");
scanf("%lf", &T2.Balance);

return T2;
}

int Get_Bonus(Acc Temp) {


Bonus = 3;

if (Temp.Balance >= 50000) {
    Bonus = 11;
} else if (Temp.Balance >= 25000 && Temp.Balance < 50000) {
    Bonus = 9;
} else if (Temp.Balance >= 10000 && Temp.Balance < 25000) {
    Bonus = 7;
} else if (Temp.Balance >= 5000 && Temp.Balance < 10000) {
    Bonus = 5;
}

return Bonus;
}