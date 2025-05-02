/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <stdio.h>
#include "Info.h"
#include "Acc.h"

int main(void) {

FILE *infoFile, *accFile;

Info people[5];
Acc accounts[5];

infoFile = fopen("Info.csv", "w");
if (infoFile == NULL) {
    printf("Error opening Info.csv\n");
    return 1;
}


accFile = fopen("Acc.csv", "w");
if (accFile == NULL) {
    printf("Error opening Acc.csv\n");
    return 1;
}

for (int i = 0; i < 5; i++) {

    Info person = people[i];
    Acc account = accounts[i];

    person = Get_Info();
    account = Create_Acc();

    fprintf(infoFile, "%s,%s,%ld,%ld\n", person.First_Name, person.Last_Name, person.Contact_Num, person.SSN);
    fprintf(accFile, "%ld, %s, %.2f,%ld\n", account.Acc_Num, account.Acc_Type, account.Balance, person.SSN);

}

fclose(infoFile);
fclose(accFile);

/* Part-2: Creating output file Report.csv using Info.csv and Acc.csv Files */
/* To Do */
extern int Bonus; // Shared External variable from the file "Acc.c"
/* Declare File pointer for the file "Report.csv" */
/* Open Files “Info.csv" and "Acc.csv" in read mode */
/* Open File “Report.csv" in write mode */
/* Read one record at a time from both input files in their respective structure variable.
You may use the same array of variables of type Info and Acc from Part-1 */
/* Use required data available in both struct variable */
/* Call function Get_Bonus() from "Acc.c" to get the updated value of the Bonus */
/* Process the additional data required by creating local variables */
/* Write the record in the desired format in the output file */
/* Calculate and store Total_Previous, Total_Bonus, Total_New, at the end
(after copying all records from the input files to the output file). */
/* Write the Totals in the desired format at the end of the output file */
/* Close all files once all records from input files are copied to the output file */

FILE *reportFile;
Info currPerson;
Acc currAccount;

double prevBalance, bonusAmt, newBalance;
double totalPrevious = 0.0;
double totalBonus = 0.0;
double totalNew = 0.0;
int currentBonusPercent;






infoFile = fopen("Info.csv", "r");
accFile = fopen("Acc.csv", "r");
reportFile = fopen("Report.csv", "w");
if (reportFile == NULL) {
    printf("Error opening Report.csv");
    return 1;
}

fprintf(reportFile, "Acc_Num,Last_Name,First_Name,SSN,Prev_Balance,%% Bonus,Bonus_Amt,New_Balance\n");

long tempSSN;

while (fscanf(infoFile, "%19[^,],%19[^,],%ld,%ld\n", currPerson.First_Name, currPerson.Last_Name, &currPerson.Contact_Num, &currPerson.SSN) == 4 && fscanf(accFile, "%ld, %9[^,],%lf,%ld\n", &currAccount.Acc_Num, currAccount.Acc_Type, &currAccount.Balance, &tempSSN) == 4) {

    prevBalance = currAccount.Balance;
    currentBonusPercent = Get_Bonus(currAccount);
    bonusAmt = prevBalance * currentBonusPercent / 100.0;
    newBalance = prevBalance + bonusAmt;

    fprintf( reportFile, "%ld,%s,%s,%ld,%.2f,%d%%,%.2f,%.2f\n", currAccount.Acc_Num, currPerson.Last_Name, currPerson.First_Name, currPerson.SSN,
    prevBalance, currentBonusPercent, bonusAmt, newBalance);

    totalPrevious += prevBalance;
    totalBonus += bonusAmt;
    totalNew += newBalance;
}

fprintf(reportFile, "\nTotal_Previous: %.2f\tTotal_Bonus: %.2f\tTotal_New: %.2f\n", totalPrevious, totalBonus, totalNew);

fclose(infoFile);
fclose(accFile);
fclose(reportFile);

return 0;
}
