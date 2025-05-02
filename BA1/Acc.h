#ifndef ACC_H
#define ACC_H
typedef struct acc
{
long int Acc_Num;
char Acc_Type[10];
double Balance;
} Acc;
Acc Create_Acc();
int Get_Bonus(Acc);
#endif