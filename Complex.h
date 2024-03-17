#pragma once
#include  "fraction.h"

class Complex{
private:
    Fraction _re;
    Fraction _im;

public:

    Complex();

    Complex(Fraction re, Fraction im);

    Complex(int32_t num_re, int32_t denom_re,  int32_t num_im, int32_t denom_im);

    friend std::ostream& operator<<(std::ostream& os, const Complex& tmp){
        Fraction temp = tmp._im;
        os << tmp._re;
        if(static_cast<double>(tmp._im) > 0)
        os << " + " << tmp._im << " i" << std::endl;
        else
        os << " - " << ~(temp) << " i" << std::endl;
        return os;
    }

    Complex operator+(const Complex& tmp) const{
        Fraction new_re = _re + tmp._re;
        Fraction new_im = _im + tmp._im;
        return Complex(new_re, new_im);
    }

    Complex operator-(const Complex& tmp) const{
        Fraction new_re = _re - tmp._re;
        Fraction new_im = _im - tmp._im;
        return Complex(new_re, new_im);
    }
};