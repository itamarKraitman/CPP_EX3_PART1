#include <iostream>
#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int nominator, int denominator) : nominator(nominator), denominator(denominator) {}
    int Fraction::getNominator() const {}
    int Fraction::geDenominator() const {}

    // overloading +,-,*,/,==,>,<,<=,>=,++,--,<<,>>
    Fraction Fraction::operator+(const Fraction &other) {}
    Fraction Fraction::operator-(const Fraction &other) {}
    Fraction Fraction::operator*(const Fraction &other) {}
    Fraction Fraction::operator/(const Fraction &other) {}

    Fraction Fraction::operator*(double floatNumber) {}
    Fraction Fraction::operator+(double floatNumber) {}
    Fraction Fraction::operator-(double floatNumber) {}
    Fraction Fraction::operator/(double floatNumber) {}

    Fraction Fraction::operator++(int dummy_flag) {}
    Fraction Fraction::operator--(int dummy_flag) {}
    Fraction &Fraction::operator++() {}
    Fraction &Fraction::operator--() {}
    

    bool operator+(double floatNumber, const Fraction &f1) {}
    bool operator-(double floatNumber, const Fraction &f1) {}
    bool operator*(double floatNumber, const Fraction &f1) {}
    bool operator/(double floatNumber, const Fraction &f1) {}

    bool operator==(const Fraction &f1, const Fraction &f2) {}
    bool operator>=(const Fraction &f1, const Fraction &f2) {}
    bool operator<=(const Fraction &f1, const Fraction &f2) {}
    bool operator>(const Fraction &f1, const Fraction &f2) {}
    bool operator<(const Fraction &f1, const Fraction &f2) {}
    bool operator==(const Fraction &f1, double floatNumber) {}
    bool operator>=(const Fraction &f1, double floatNumber) {}
    bool operator<=(const Fraction &f1, double floatNumber) {}
    bool operator>(const Fraction &f1, double floatNumber) {}
    bool operator<(const Fraction &f1, double floatNumber) {}

    std::ostream &operator<<(std::ostream &output, const Fraction &f) {}
    std::istream &operator>>(std::istream &input, Fraction &f) {}
}