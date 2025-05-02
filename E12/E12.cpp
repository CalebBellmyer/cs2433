/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T>
void swap(T& var1, T& var2, T& var3) {
    T tmp1 = var1;
    T tmp2 = var2;

    var1 = var3;
    var2 = tmp1;
    var3 = tmp2;
    
}

template <typename T>
void write(T& var1, T& var2, T& var3) {
    cout << "\nBefore Shifting: " << endl;
    cout << "Var1 = " << var1 << endl;
    cout << "Var2 = " << var2 << endl;
    cout << "Var3 = " << var3 << endl;

    swap(var1, var2, var3);

    cout << "\nAfter Shifting: " << endl;
    cout << "Var1 = " << var1 << endl;
    cout << "Var2 = " << var2 << endl;
    cout << "Var3 = " << var3 << endl;
    cout << endl;
}

int menu() {
    int selection;
    cout << "***************Menu****************" << endl;
    cout << "1. For Integer Elements\n2. For Double Elements\n3. For Char Elements\n4. Exit" << endl;
    cout << "**************************************\n" << endl;

    cout << "Enter your choice: " << endl;

    cin >> selection;

    return selection;
}

template <typename T>
void getInput(T& var1, T& var2, T& var3) {
    while (!(cin >> var1 >> var2 >> var3)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    

    while(true) {
        

        int selection = menu();
        if (selection == 4) {
            cout << "Exitng the Program!\n" << endl;
            break;
        }

        if (selection == 1) {
            int var1, var2, var3; 
            getInput(var1, var2, var3); 
            write(var1, var2, var3); // Call write for integers
        } else if (selection == 2) {
            double var1, var2, var3;
            getInput(var1, var2, var3);
            write(var1, var2, var3);
        } else if (selection == 3) {
            char var1, var2, var3;
            getInput(var1, var2, var3);
            write(var1, var2, var3);
        }   
    }
    
    return 0;
}

