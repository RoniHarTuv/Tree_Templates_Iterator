#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double r, double i) : real(r), imag(i) {}
        double get_real() const { return real; }
        double get_imag() const { return imag; }
        
        friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
            if(c.imag>=0){
            os << c.real << "+" << c.imag << "i";
            return os;
            }
            else{
                os << c.real << " " << c.imag << "i";
            return os;
            }
        }
        bool operator==(const Complex &c) const {
            return real == c.real && imag == c.imag;
        }
        bool operator>(const Complex &c) const {// add in order to sort the complex in the heap iterator
            return real > c.real && imag > c.imag;
        }
        
};

#endif