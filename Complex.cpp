#include "Complex.h"

Complex::Complex(){
    _re = Fraction();
    _im = Fraction();
}

Complex::Complex(Fraction re, Fraction im){
    _re = re;
    _im = im;
}

Complex::Complex(int32_t num_re, int32_t denom_re,  int32_t num_im, int32_t denom_im){
    _re = Fraction(num_re, denom_re);
    _im = Fraction(num_im, denom_im);
}