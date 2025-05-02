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

        Complex(int x, int y) {
            real = x;
            imag = y;
        }

        ~Complex() {};

        Complex operator+(Complex &other) {
            return Complex(this->real + other.real, this->imag + other.imag);
        }

        void print() {
            cout << real << " + i" << imag << endl; 
        }
};

int main() {

    Complex complex1(5, 3);
    Complex complex2(5, 7);
    Complex complex3 = complex1 + complex2;
    complex3.print();

    return 0;
}