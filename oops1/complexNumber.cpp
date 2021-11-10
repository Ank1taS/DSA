// A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).

#include <iostream>
using namespace std;
// #include "ComplexNumbers.h"

class ComplexNumbers {
private:
    int real;
    int imaginary;

public:
    ComplexNumbers(int real, int imaginary)
        :   real{real}, imaginary{imaginary} {}

    void plus(ComplexNumbers const &c) {
        this -> real = real + c.real;
        this -> imaginary = imaginary + c.imaginary;
    }

    void multiply(ComplexNumbers const &c) {
        int temp = real;
        this -> real = (real * c.real) - (imaginary * c.imaginary);
        this -> imaginary = (temp * c.imaginary) + (imaginary * c.real);
    }

    void print() {
        cout << real << " + i" << imaginary << endl;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}