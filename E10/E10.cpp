/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <iostream>
#include <vector>
#include <string>
#include <ios>

using namespace std;

void displayMenu() {
    cout << "\n***************Menu******************\n";
    cout << "1. Insert an Element at the End\n";
    cout << "2. Delete an Element\n";
    cout << "3. Search for an Element\n";
    cout << "4. Modifying an Element\n";
    cout << "5. Reverse Vector\n";
    cout << "6. Exit the Program.\n";
    cout << "*************************************\n";
} 

void displayVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "Vector is empty." << endl;
        return;
    }

    cout << "Updated Vector: ";

    for (int i = 0; i < vec.size() -1; i++)
    {
        cout << vec[i] << (i == vec.size() ? "" : " ");
    }
    cout << endl;

}

int findElement(const vector<int>& vec, int elementToFind) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == elementToFind) {
            return i;
        }
    }
    return -1;
}

void reverseVector(vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    int start = 0;
    int end = vec.size() - 1;

    while (start < end) {
        int temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;

        start++;
        end--;
    }
}  

int getInput(const string& prompt) {
    int temp;
    cout << prompt;
    cin >> temp; 
    cout << endl;
    return temp;
}

int main() {
    int numElements;
    vector<int> vec;


    cout << "Enter the number of elements in the vector: ";
    cin >> numElements;
    
    if (numElements > 0) {
        cout << "Enter " << numElements << ": ";
        for (int i = 0; i < numElements; ++i) {
            int element;
            cin >> element;
            vec.push_back(element);
        }
    }

    int choice;
    do {
        displayMenu();
        choice = getInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                int num = getInput("Enter the element to insert: ");
                vec.push_back(num); 
                displayVector(vec);
                break;
            }

            case 2: {
                int elDelete = getInput("Enter the element to delete: ");
                int indexDel = findElement(vec, elDelete);

                if (indexDel != -1) {
                    vec.erase(vec.begin() + indexDel);
                    displayVector(vec);
                } else {
                    cout << "Element Not Found.";
                }
                break;
            }

            case 3: {
                int elSearch = getInput("Enter the element to search for: ");
                int index = findElement(vec, elSearch);

                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element Not Found";
                }
                break;
            }

            case 4: {
                int index = getInput("Enter the index to modify: ");

                if (index >= 0 && index < vec.size()) {
                    int newNum = getInput("Enter the new value: ");
                    vec[index] = newNum;
                    displayVector(vec);
                } else {
                    cout << "Invalid Index." << endl;
                } 
                break;
            }

            case 5: {
                reverseVector(vec);
                displayVector(vec);
                break;
            }

            case 6: {
                cout << "Exiting the program ..." << endl;
                break;
            }

            default: {
                cout << "Enter numner between 1 and 6." << endl;
                break;
            }
        }
    } while (choice != 6);
    return 0;
}