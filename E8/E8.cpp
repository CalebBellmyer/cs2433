/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <iostream>
using namespace std;

class Complex {
    public:

        int real;
        int imag;

        Complex() {
            real = 0;
            imag = 0;
        }

        Complex(int realInt, int imagInt) {
            real = realInt;
            imag = imagInt;
        }

        ~Complex() {}

        void print() const {
            cout << real << " + " << "i" << imag << endl;
        }

        Complex operator+(const Complex &other) const {
            return Complex(this->real + other.real, this->imag + other.imag);
        }

        Complex operator-(const Complex &other) const {
            return Complex(this->real - other.real, this->imag - other.imag);
        }

};


int main()
{
    Complex complex1;
    Complex complex2;
    Complex addComplex;
    Complex subComplex;

    int x;
    int y;

    for (int i = 0; i < 2; i++) {
        cout << "Enter Complex Number-" << i + 1 << endl;
        cin >> x >> y;
        if (i == 0) 
            complex1 = Complex(x, y);
        else
            complex2 = Complex(x, y);
        
    }


    cout << "Addition of Complex Numbers = ";
    addComplex = complex1 + complex2;
    addComplex.print();

    cout << "Subtraction of Complex Numbers = ";
    subComplex = complex1 - complex2;
    subComplex.print();


    return 0;
}
