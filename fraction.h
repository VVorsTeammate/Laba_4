#pragma once
#include<iostream>
#include<math.h>
#include "nod.h"

class Fraction{
private:
    int32_t _num = 1;
    int32_t _denom = 2;

public:

    void Diskr(Fraction a, Fraction b, Fraction c);

    Fraction(double n);

    Fraction(int32_t num, int32_t denom, bool xlam);
    Fraction(int32_t num, int32_t denom);
    void Enter_coef();

    void SetDenom(int32_t newDenom);
    Fraction();
    operator double() const {
        return static_cast<double>(_num)/_denom;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){
        os << tmp._num << "/" << tmp._denom;
        return os;
    }

    Fraction operator+(const Fraction& fraction) const { //1
        int32_t new_num = _num * fraction._denom + fraction._num * _denom;
        int32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    Fraction operator/(const Fraction& fraction) const { //2
        int32_t new_num = _num * fraction._denom;
        int32_t new_denom = _denom * fraction._num;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    Fraction operator*(const Fraction& fraction) const { //3
        int32_t new_num = _num * fraction._num;
        int32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    Fraction operator*(const int& abc) const { //3
        int32_t new_num = _num * abc;
        Fraction res = Fraction(new_num, _denom, true);
        return res;
    }

    Fraction operator-(const Fraction& fraction) const { //4
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        int32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    Fraction operator^(double a) const { //5
        double new_num = pow(_num, a);
        double new_denom = pow(_denom, a);
        //std::cout<< new_denom <<std::endl;
        double preres = new_num/new_denom;
        Fraction res = Fraction(preres);
        return res;
    }

    Fraction& operator=(const Fraction& fraction){ //6
        _num = fraction._num;
        _denom = fraction._denom;
        return *this;
    }

    bool operator<=(const Fraction& fraction) const { //7
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        if(new_num <= 0) return true;
        else return false;
    }

    bool operator>=(const Fraction& fraction) const { //8
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        if(new_num >= 0) return true;
        else return false;
    }

    bool operator<(const Fraction& fraction) const { //9
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        if(new_num < 0) return true;
        else return false;
    }

    bool operator>(const Fraction& fraction) const { //10
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        if(new_num > 0) return true;
        else return false;
    }

    bool operator==(const Fraction& fraction) const { //11
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        if(new_num == 0) return true;
        else return false;
    }

    Fraction& operator++() { //12 префиксный
        _num += _denom;
        return *this;
    }

    Fraction& operator--() { //13 префиксный
        _num -= _denom;
        return *this;
    }

    Fraction operator++(int32_t xlam) { //14 постфиксный
        Fraction copy {*this};
        ++(*this);
        return copy;
    }

    Fraction operator--(int32_t xlam) { //15 постфиксный
        Fraction copy {*this};
        --(*this);
        return copy;
    }

    Fraction& operator~() { //16
        _num *= -1;
        return *this;
    }


    ~Fraction(){
        std::cout << "Destructor -> " << this << std::endl;
    }
};