#include "fraction.h"
#include "Complex.h"

int main(){
    Fraction a, b, c, D;
    Fraction x1, x2;
    int32_t temp = 0;
    int32_t* pointer_temp = &temp;
    std::cout<< "Enter coefficient a:";
    std::cout<<std::endl;
    a.Enter_coef();
    std::cout<< "Enter coefficient b:";
    std::cout<<std::endl;
    b.Enter_coef();

    // std::cout<<std::endl;
    // Fraction res = (a^2.0) - (b * 2);
    // std::cout<< res <<std::endl;
    std::cout<< "Enter coefficient c:";
    std::cout<<std::endl;
    c.Enter_coef();

    D.Diskr(a, b, c);
    std::cout<< D;
    std::cout<<std::endl;

    if(static_cast<double>(D) == 0.0) {
        Fraction x = (~b) / (a * 2);
        std::cout<< "x1 = " << x << " ; x2 = " << x;
        return 0;
    }

    if(static_cast<double>(D) > 0.0){
        Fraction x1 = ((~b) + (D^0.5))/(a * 2);
        Fraction x2 = (b - (D^0.5))/(a * 2);
        std::cout<< "x1 = " << x1 << "x2 = " << x2;
        return 0;
    }

    else{
        Fraction x1r = ((~b)/(a * 2));
        Fraction x1i = (((~D)^0.5))/(a * 2);
        Fraction x2r = (b)/(a * 2);
        Fraction x2i = ~(((D^0.5))/(a * 2));
        Complex x1 = Complex(x1r, x1i);
        Complex x2 = Complex(x2r, x2i);
        std::cout<< "x1 = " << x1 << "x2 = " << x2;
        return 0;
    }




    // std::cout<< a;
    // std::cout<<std::endl;
    // std::cout<< b;
    // std::cout<<std::endl;
    // std::cout<< c;
    // std::cout<<std::endl;

}