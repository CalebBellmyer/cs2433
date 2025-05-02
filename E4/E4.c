
/*
 * Name: Caleb Bellmyer
 * CWID: 11638131
 * Email-ID: caleb.bellmyer@okstate.edu
 */

#include <stdio.h>
#include <string.h>

int GetChoice() {
    int choice;
    printf("Please Enter your choice:\n");
    scanf("%d", &choice);
    getchar();
    return choice;
}

int DisplayMenu () {
    printf("*************** MENU ***************\n");
    printf("1. Display the Sum of digits.\n");
    printf("2. Display the Multiplication of digits.\n");
    printf("3. Display the average of digits.\n");
    printf("4. Display the Reverse of the Number.\n");
    printf("**************************************\n");


    return GetChoice();
}

void SumDigits(char input[]) {
    int sum = 0;
    
       
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
                sum += input[i] - '0';
        }
    }

    printf("The sum of your number %s = %d\n", input, sum);
}

void MultDigits(char input[]) {
    int answer = 1;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] > '0' && input[i] <= '9') {
            answer *= input[i] - '0';
        }
    }

    printf("The multiplication of the number %s = %d\n", input, answer);
    
}

void AvgDigits(char input[]) {
    int sum = 0;
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            sum += input[i] - '0';
            count++;
        }
    }

    printf("The Average of digits in the number %s = %f\n", input, (double)sum / count);


}

void ReverseDigits(char input[], int index) {
    if (index < 0) {
        return;
    }
    if (input[index] >= '0' && input[index] <= '9') {
        printf("%c", input[index]);
    }

    ReverseDigits(input, index - 1);
}



int main() {
    char input[100];

    printf("Enter a Number: ");

    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
    }

    int choice = DisplayMenu();
    switch (choice) {
        case 1:
            SumDigits(input);
            break;
        case 2:
            MultDigits(input);
            break;
        case 3:
            AvgDigits(input);
            break;
        case 4:
            printf("the Reversed digits in the number %s = ", input);
            ReverseDigits(input, strlen(input) - 1);
            printf("\n");
            break;
        default:
            printf("Invalid Choice! \n");
    }
    

    return 0;
}
