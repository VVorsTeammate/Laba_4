#include "fraction.h"

Fraction::Fraction(){
    _num = 0;
    _denom = 1;
}

Fraction::Fraction(int32_t num, int32_t denom){
    _num = num;
    SetDenom(denom);

}

void Fraction::Diskr(Fraction a, Fraction b, Fraction c){
    *this = ((b^2.0) - ((a * c) * 4));
}

Fraction::Fraction(int32_t num, int32_t denom, bool xlam){
    int32_t temp = nod(fabs(num), fabs(denom));
    if (temp > 1){
        num /= temp;
        denom /= temp;
    }
    if ((num < 0 && denom < 0) || (denom < 0)){
        num *= -1;
        denom *= -1;
    }
    _num = num;
    SetDenom(denom);  
}

Fraction::Fraction(double n){
    int32_t cel = 0;
    int32_t num = 0;
    int32_t denom = 1;

    if (n >= 0){
        cel = floor(n);
        if((n - static_cast<double>(cel)) == 0.0){
            _num = 1*cel;
            SetDenom(1);
        }
        else{
            num = (int)(round((n - cel)*10000000));
            denom = 10000000;
            if (denom < 0){
                num *= -1;
                denom *= -1;
            }
            int32_t temp_t = nod(fabs(num), fabs(denom));
            if (temp_t > 1){
                num /= temp_t;
                denom /= temp_t;
            }
            std::cout<< cel<<std::endl;
            _num = num + cel*denom;
            SetDenom(denom);
        }
    }
    else{
        cel = ceil(n);
        if(n - static_cast<double>(cel) == 0.0){
            _num = 1*cel;
            SetDenom(1);
        }
        else{
            num = (-1) * (int)(ceil((n - cel)*10000000));
            denom = 10000000;
            if (denom < 0){
                num *= -1;
                denom *= -1;
            }
            int32_t temp_t = nod(fabs(num), fabs(denom));
            if (temp_t > 1){
                num /= temp_t;
                denom /= temp_t;
            }
            _num = num + cel*denom;
            SetDenom(denom);
        }
    }
}

void Fraction::SetDenom(int32_t newDenom){
    if(newDenom == 0)
        throw "Denomirate can't be zero";
    _denom = newDenom;
}

void Fraction::Enter_coef(){
    int32_t num = 0;
    int32_t denom = 1;
    std::cout << "Enter num" << std::endl;
    std::cin >> num;
    std::cout << "Enter denom" << std::endl;
    std::cin >> denom;
    *this = Fraction(num, denom, true);
}